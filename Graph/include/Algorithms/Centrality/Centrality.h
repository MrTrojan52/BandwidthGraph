//
// Created by Trojan on 15.12.2020.
//

#ifndef BANDWIDTHGRAPH_CENTRALITY_H
#define BANDWIDTHGRAPH_CENTRALITY_H

#include <vector>

#include "Algorithms/BaseAlgorithm.h"
#include "Graph/Graph.h"

class Centrality : public BaseAlgorithm
{
    public:
        Centrality(const Graph& Graph, bool bNormalized = false)
        : BaseAlgorithm(Graph)
        , m_bNormalized(bNormalized)
        { }

        ~Centrality() override = default;

        void run() override = 0;

    protected:
        std::vector<double> m_NodesScoreData;
        bool m_bNormalized;
};


#endif //BANDWIDTHGRAPH_CENTRALITY_H
