//
// Created by Trojan on 15.12.2020.
//

#include <queue>

#include "Algorithms/Path/Dijkstra.h"
#include "Graph/Graph.h"

Dijkstra::Dijkstra(const Graph& rGraph, index_t startV, bool bInvertWeights, index_t endV)
: APathAlgorithm(rGraph, startV, endV)
, m_bInvertWeights(bInvertWeights)
{

}

void Dijkstra::run()
{
    m_Distances.clear();
    m_Previous.clear();

    m_dDistSum = 0.;

    m_Distances[m_nStartV] = 0.;

    auto distanceCompare = [this](index_t v1, index_t v2) -> bool
                           {return (m_Distances[v1] > m_Distances[v2]);};

    std::priority_queue<index_t, std::vector<index_t>, decltype(distanceCompare)> pq(distanceCompare);
    pq.push(m_nStartV);

    bool bEndVertexSpecified = (m_nEndV != emptyIndex);

    m_SortedNodes.clear();
    m_SortedNodes.reserve(m_Graph.getVertexesCount());

    m_CountOfPaths.clear();
    m_CountOfPaths[m_nStartV] = 1;

    do {
        index_t curNode = pq.top();
        pq.pop();
        m_dDistSum += m_Distances[curNode];

        if ((bEndVertexSpecified && (m_nEndV == curNode)) ||
            (m_Distances[curNode] == infWeight))
        {
            break;
        }

        m_SortedNodes.push_back(curNode);

        m_Graph.forNeighbours(curNode, m_bInvertWeights, [&](index_t nodeIndex, weight_t w)
        {
            weight_t dist = m_Distances[curNode] + w;
            if (!FIND_IN_CONTAINER(m_Distances, nodeIndex) || (m_Distances[nodeIndex] == infWeight))
            {
                m_Distances[nodeIndex] = dist;
                pq.push(nodeIndex);
                m_Previous[nodeIndex] = {curNode};
                m_CountOfPaths[nodeIndex] = m_CountOfPaths[curNode];
            }
            else if (FIND_IN_CONTAINER(m_Distances, nodeIndex) && m_Distances[nodeIndex] > dist)
            {
                m_Distances[nodeIndex] = dist;
                m_Previous[nodeIndex] = {curNode};
                m_CountOfPaths[nodeIndex] = m_CountOfPaths[curNode];
            }
            else if (FIND_IN_CONTAINER(m_Distances, nodeIndex) && m_Distances[nodeIndex] == dist)
            {
                m_Previous[nodeIndex].push_back(curNode);
                m_CountOfPaths[nodeIndex] += m_CountOfPaths[curNode];
            }
        });

    } while (!pq.empty());

    m_bHasRun = true;
}