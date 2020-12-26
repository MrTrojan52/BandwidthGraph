//
// Created by Trojan on 15.12.2020.
//

#ifndef BANDWIDTHGRAPH_BETWEENNESSCENTRALITY_H
#define BANDWIDTHGRAPH_BETWEENNESSCENTRALITY_H

#include "Centrality.h"

class BetweennessCentrality : public Centrality
{
    public:
        BetweennessCentrality(const Graph& Graph, bool bNormalized = false)
        : Centrality(Graph, bNormalized)
        { }

        void run() override;


};

#endif //BANDWIDTHGRAPH_BETWEENNESSCENTRALITY_H
