//
// Created by Trojan on 15.12.2020.
//

#ifndef BANDWIDTHGRAPH_BASEALGORITHM_H
#define BANDWIDTHGRAPH_BASEALGORITHM_H

#include "IAlgorithm.h"

class Graph;

class BaseAlgorithm : public IAlgorithm
{
    public:
        BaseAlgorithm(const Graph& rGraph)
        : m_Graph(rGraph)
        , m_bHasRun(false)
        { }

        virtual ~BaseAlgorithm() = default;

        virtual void run() override = 0;

        bool hasFinished() override { return m_bHasRun; }

    protected:
        const Graph& m_Graph;
        bool m_bHasRun;
};

#endif //BANDWIDTHGRAPH_BASEALGORITHM_H
