//
// Created by Trojan on 06.12.2020.
//

#include <iostream>
#include <fstream>

#include "Graph/BaseGraph.h"
#include "common/GraphCommon.h"
#include "Factory/BaseJsonFactory.h"
#include "Node/INode.h"

using namespace nlohmann;

BaseGraph::~BaseGraph() noexcept
{
    for (auto x : m_Nodes)
    {
        delete x.second;
    }

    m_Nodes.clear();
    m_Arcs.clear();
}

void BaseGraph::addNode(INode* pNode)
{
    m_Nodes[pNode->getIntProperty(NodeConsts::ID_PROP)] = pNode;
}

void BaseGraph::removeNode(int id)
{
    m_Nodes.erase(id);

    // TODO: remove all arcs to and from this node
}

void BaseGraph::addArc(Arc arc)
{
    m_Arcs.insert(arc);
}

void BaseGraph::removeArc(int from, int to)
{
    auto it = m_Arcs.find({from, to});
    if (it != m_Arcs.end())
    {
        m_Arcs.erase(it);
    }
}

void BaseGraph::fromJSONFile(const std::string& sFileName)
{
    std::ifstream iFile(sFileName);
    std::string errorMSG;

    if (iFile.is_open())
    {
        json j;
        iFile >> j;

        iFile.close();

        if (j.contains(GRAPH_TAG))
        {
            auto jGraph = j[GRAPH_TAG];
            if (jGraph.is_array())
            {
                for (auto& jNode : jGraph)
                {
                    if (jNode.is_object())
                    {
                        INode* pNode = BaseJSONFactory::GetInstance().createNode(jNode);
                        if (pNode != nullptr)
                        {
                            addNode(pNode);
                            if (jNode.contains(NodeConsts::ARCS_PROP))
                            {
                                auto jArcs = jNode[NodeConsts::ARCS_PROP];
                                addArcsFromJSONForNode(pNode->getIntProperty(NodeConsts::ID_PROP), jArcs);
                            }
                        }
                    }
                    else
                    {
                        std::cerr << "Node must be an object in " + sFileName;
                    }
                }
            }
            else
            {
                errorMSG = GRAPH_TAG + " must be an array in " + sFileName;
            }
        }
        else
        {
            errorMSG = "JSON file " + sFileName + " doesn't contain " + GRAPH_TAG + " tag!";
        }
    }
    else
    {
        errorMSG = "File " + sFileName + " cannot be opened!";
    }

    if (!errorMSG.empty())
    {
        std::cerr << errorMSG;
    }
}

void BaseGraph::addArcsFromJSONForNode(int from, const json& j)
{
    if (j.is_array())
    {
        for (auto& arc : j)
        {
            if (arc.is_object() && arc.contains(ArcConsts::TO_TAG))
            {
                int to = arc[ArcConsts::TO_TAG].get<int>();
                int weight = 0;
                if (arc.contains(ArcConsts::WEIGHT_TAG))
                {
                    weight = arc[ArcConsts::WEIGHT_TAG].get<int>();
                }
                addArc({from, to, weight});
            }
        }
    }
    else
    {
        std::cerr << "Arcs from " + std::to_string(from) + " cannot be added. Wrong file format!";
    }
}
