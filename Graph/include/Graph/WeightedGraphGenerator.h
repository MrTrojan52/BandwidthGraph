//
// Created by Trojan on 21.12.2020.
//

#ifndef BANDWIDTHGRAPH_WEIGHTEDGRAPHGENERATOR_H
#define BANDWIDTHGRAPH_WEIGHTEDGRAPHGENERATOR_H

#include <random>

#include "Graph.h"

class WeightedGraphGenerator
{
    public:
        static void generate(Graph& g, count_t nodes, int probability = 50)
        {
            g.clearGraph();
            std::mt19937 prob(70);
            std::uniform_int_distribution<unsigned> distrib(0, 100);

            std::mt19937 weight(13);
            std::uniform_int_distribution<unsigned> weightDistrib(1, 100);

            for (int i = 1; i <= nodes; ++i)
            {
                g.addNode(i);
            }

            for (int i = 1; i <= nodes; ++i)
            {
                for (int j = 1; j <= nodes; ++j)
                {
                    if ((i!=j) && (distrib(prob) < probability))
                    {
                        g.addEdge(i, j, weightDistrib(weight));
                    }
                }
            }
        }
};

#endif //BANDWIDTHGRAPH_WEIGHTEDGRAPHGENERATOR_H
