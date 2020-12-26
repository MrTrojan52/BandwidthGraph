//
// Created by Trojan on 15.12.2020.
//

#include <stdexcept>

#include "Algorithms/Path/APathAlgorithm.h"
#include "Graph/Graph.h"

void APathAlgorithm::setStartNode(index_t nodeIndex)
{
    if (!m_Graph.hasNode(nodeIndex))
    {
        throw std::runtime_error("Error: The vertex with id " + std::to_string(nodeIndex) + " is missing in the graph");
    }
    m_nStartV = nodeIndex;
}

void APathAlgorithm::setEndNode(index_t nodeIndex)
{
    if (!m_Graph.hasNode(nodeIndex))
    {
        throw std::runtime_error("Error: The vertex with id " + std::to_string(nodeIndex) + " is missing in the graph");
    }
    m_nEndV = nodeIndex;
}

std::vector<index_t>& APathAlgorithm::getPrevious(index_t nodeIndex)
{
    return m_Previous[nodeIndex];
}

const std::vector<index_t>& APathAlgorithm::getSortedNodes()
{
    return m_SortedNodes;
}

uint64_t APathAlgorithm::getCountOfPathsFor(index_t nodeIndex)
{
    return m_CountOfPaths[nodeIndex];
}
