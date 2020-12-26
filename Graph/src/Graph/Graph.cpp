//
// Created by Trojan on 06.12.2020.
//

#include <iostream>
#include <fstream>

#include "Graph/Graph.h"
#include "common/GraphCommon.h"
#include "Factory/BaseJsonFactory.h"
#include "Node/INode.h"

using namespace nlohmann;

void Graph::fromJSONFile(const std::string& sFileName)
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
                            //addNode(pNode);
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

void Graph::addArcsFromJSONForNode(int from, const json& j)
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
                addEdge(from, to, weight);
            }
        }
    }
    else
    {
        std::cerr << "Arcs from " + std::to_string(from) + " cannot be added. Wrong file format!";
    }
}

count_t Graph::getVertexesCount() const
{
    return m_nVertexesCount;
}

count_t Graph::getEdgesCount() const
{
    return m_nEdgesCount;
}

void Graph::addEdge(index_t from, index_t to, weight_t weight)
{
    if ((FIND_IN_CONTAINER(m_ActiveNodes, from) && m_ActiveNodes[from]) &&
        (FIND_IN_CONTAINER(m_ActiveNodes, to) && m_ActiveNodes[to]))
    {
        m_EdgesOut.insert({from, to, weight});
        m_EdgesOut.insert({to, from, weight});

        ++m_nEdgesCount;
    }
    else
    {
        throw std::runtime_error("Error: Incorrect edge!");
    }
}

void Graph::addNode(index_t id)
{
    if (!FIND_IN_CONTAINER(m_ActiveNodes, id))
    {
        m_ActiveNodes[id] = true;
        m_nVertexesCount++;
    }
}

bool Graph::hasNode(index_t nodeIndex) const
{
    auto it = m_ActiveNodes.find(nodeIndex);
    return ((it != m_ActiveNodes.end()) && (it->second));
}

void Graph::addWeightedEdgesAndNodes(std::initializer_list<WeightedEdge> edges)
{
    for (auto e : edges)
    {
        addNode(e.from);
        addNode(e.to);
        addEdge(e.from, e.to, e.weight);
    }
}

