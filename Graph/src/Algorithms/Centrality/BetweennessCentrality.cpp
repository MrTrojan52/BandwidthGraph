//
// Created by Trojan on 15.12.2020.
//

#include <omp.h>
#include <memory>
#include <iostream>

#include "Algorithms/Centrality/BetweennessCentrality.h"
#include "Algorithms/Path/Dijkstra.h"

void BetweennessCentrality::run()
{
    m_ExecutionTime = 0.0;
    double dStartTime = omp_get_wtime();
    count_t nodeCnt = m_Graph.getVertexesCount();
    m_NodesScoreData.clear();

    const int nMaxThreads = omp_get_max_threads();

    std::vector<std::unordered_map<index_t, double>> deps(nMaxThreads);
    std::vector<std::unique_ptr<APathAlgorithm>> pathSubTasks;
    pathSubTasks.resize(nMaxThreads);

    #pragma omp parallel
    {
        int threadId = omp_get_thread_num();
        pathSubTasks[threadId] = std::unique_ptr<APathAlgorithm>(new Dijkstra(m_Graph,0, true));
    }

    auto depFunc = [&](index_t nodeIndex) -> void
    {
        int threadId = omp_get_thread_num();
        std::unordered_map<index_t, double>& dep = deps[threadId];

        auto& subTask = *pathSubTasks[threadId];
        subTask.setStartNode(nodeIndex);
        subTask.run();

        auto& nodes = subTask.getSortedNodes();
        for (auto it = nodes.rbegin(); it != nodes.rend(); ++it)
        {
            for (index_t prev : subTask.getPrevious(*it))
            {
                weight_t sigma = static_cast<weight_t>(subTask.getCountOfPathsFor(prev)) / subTask.getCountOfPathsFor(*it);
                dep[prev] += sigma * (1 + dep[*it]);
            }
            if (*it != nodeIndex)
            {
                #pragma omp critical
                m_NodesScoreData[*it] += dep[*it];
            }
        }
       dep.clear();
    };

    m_Graph.parallelForNodes(depFunc);

    m_bHasRun = true;
    double dEndTime = omp_get_wtime();
    m_ExecutionTime = dEndTime - dStartTime;
}