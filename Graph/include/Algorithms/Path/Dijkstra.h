//
// Created by Trojan on 15.12.2020.
//

#ifndef BANDWIDTHGRAPH_DIJKSTRA_H
#define BANDWIDTHGRAPH_DIJKSTRA_H

#include "APathAlgorithm.h"

class Dijkstra : public APathAlgorithm
{
    public:
        Dijkstra(const Graph& rGraph, index_t startV, bool bInvertWeights = false, index_t endV = emptyIndex);

        void run() override;

    private:
        bool m_bInvertWeights;
};


#endif //BANDWIDTHGRAPH_DIJKSTRA_H
