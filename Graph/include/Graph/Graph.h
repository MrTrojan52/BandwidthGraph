//
// Created by Trojan on 06.12.2020.
//

#ifndef BANDWIDTHGRAPH_GRAPH_H
#define BANDWIDTHGRAPH_GRAPH_H

#include <omp.h>
#include <nlohmann/json.hpp>
#include <set>
#include <unordered_map>

#include "common/GraphCommon.h"
#include "Arc/Edges.h"

class INode;



class Graph
{
    public:
        Graph()
        : m_nVertexesCount(0)
        , m_nEdgesCount(0)
        , m_MaxEdgeWeight(0.0)
        { }

        ~Graph() = default;

        void addNode(index_t id);
        void addWeightedEdgesAndNodes(std::initializer_list<WeightedEdge> edges);
        void addEdge(index_t from, index_t to, weight_t weight = defaultWeight);
        void fromJSONFile(const std::string& sFileName);
        count_t getVertexesCount() const;
        count_t getEdgesCount() const;
        bool hasNode(index_t nodeIndex) const;
        std::vector<WeightedEdge> getEdgesFrom(index_t nodeIndex);

        template <typename func_obj>
        void forNeighbours(index_t nodeIndex, bool bInvert, func_obj func) const;

        template <typename func_obj>
        void parallelForNodes(func_obj func) const;

private:
        void addArcsFromJSONForNode(int from, const nlohmann::json& j);
        void clearGraph();

        std::unordered_map<index_t, bool> m_ActiveNodes;

        std::set<WeightedEdge, WeightedEdgeSetCmp> m_EdgesOut;
        count_t m_nVertexesCount;
        count_t m_nEdgesCount;
        weight_t m_MaxEdgeWeight;

friend class WeightedGraphGenerator;
};

template <typename func_obj>
void Graph::forNeighbours(index_t nodeIndex, bool bInvert, func_obj func) const
{
    auto it = std::find_if(m_EdgesOut.begin(), m_EdgesOut.end(),
                           [nodeIndex](const WeightedEdge& e1) { return (e1.from == nodeIndex);});

    while (it != m_EdgesOut.end() && (it->from == nodeIndex))
    {
        weight_t w = bInvert ? (std::abs(it->weight - m_MaxEdgeWeight) + 1) : it->weight;
        func(it->to, w);
        it++; // Go forward because all items are sorted
    }
}

template <typename func_obj>
void Graph::parallelForNodes(func_obj func) const
{
    int i;
    #pragma omp parallel for schedule(guided) private(i)
    for (i = 0; i < m_ActiveNodes.size(); ++i)
    {
        auto it = std::next(m_ActiveNodes.cbegin(), i);
        if (it->second)
        {
            func(it->first);
        }
    }
}

#endif //BANDWIDTHGRAPH_GRAPH_H
