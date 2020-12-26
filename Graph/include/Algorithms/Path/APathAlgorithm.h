//
// Created by Trojan on 15.12.2020.
//

#ifndef BANDWIDTHGRAPH_APATHALGORITHM_H
#define BANDWIDTHGRAPH_APATHALGORITHM_H

#include <vector>
#include <unordered_map>

#include "common/GraphCommon.h"
#include "Algorithms/BaseAlgorithm.h"

class APathAlgorithm : public BaseAlgorithm
{
    public:
        APathAlgorithm(const Graph& rGraph, index_t startV, index_t endV)
        : BaseAlgorithm(rGraph)
        , m_nStartV(startV)
        , m_nEndV(endV)
        , m_dDistSum(0.)
        { }

        void run() override = 0;

        weight_t getDistanceTo(index_t nodeIndex) { return m_Distances[nodeIndex]; }

        const std::unordered_map<index_t, weight_t>& getDistances() { return m_Distances; }
        std::vector<index_t>& getPrevious(index_t nodeIndex);
        const std::vector<index_t>& getSortedNodes();
        uint64_t getCountOfPathsFor(index_t nodeIndex);

        void setStartNode(index_t nodeIndex);
        void setEndNode(index_t nodeIndex);

    protected:
        index_t m_nStartV;
        index_t m_nEndV;
        double m_dDistSum;
        std::unordered_map<index_t, weight_t> m_Distances;
        std::unordered_map<index_t, std::vector<index_t>> m_Previous;
        std::vector<index_t> m_SortedNodes;
        std::unordered_map<index_t, uint64_t> m_CountOfPaths;
};

#endif //BANDWIDTHGRAPH_APATHALGORITHM_H
