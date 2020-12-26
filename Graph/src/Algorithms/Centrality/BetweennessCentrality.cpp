//
// Created by Trojan on 15.12.2020.
//

#include <omp.h>
#include <memory>

#include "Algorithms/Centrality/BetweennessCentrality.h"
#include "Algorithms/Path/Dijkstra.h"

void BetweennessCentrality::run()
{
    count_t nodeCnt = m_Graph.getVertexesCount();
    m_NodesScoreData.clear();
    m_NodesScoreData.resize(nodeCnt);

    const int nMaxThreads = omp_get_max_threads();

    std::vector<std::vector<double>> deps(nMaxThreads, std::vector<double>(nodeCnt));
    std::vector<std::unique_ptr<APathAlgorithm>> pathSubTasks;
    pathSubTasks.resize(nMaxThreads);

    #pragma omp parallel
    {
        int threadId = omp_get_thread_num();
        pathSubTasks[threadId] = std::unique_ptr<APathAlgorithm>(new Dijkstra(m_Graph,0));
    }

    auto depFunc = [&](index_t nodeIndex) -> void
    {
        int threadId = omp_get_thread_num();
        std::vector<double>& dep = deps[threadId];

        auto& subTask = *pathSubTasks[threadId];
        subTask.setStartNode(nodeIndex);
        subTask.run();

        auto& nodes = subTask.getSortedNodes();
        for (auto it = nodes.rbegin(); it != nodes.rend(); ++it)
        {
            for (index_t prev : subTask.getPrevious(*it))
            {
                weight_t w = subTask.getCountOfPathsFor(prev) / subTask.getCountOfPathsFor(*it);

                weight_t c = w * (1 + dep[*it]);
                dep[prev] += c;
            }
            if (*it != nodeIndex)
            {
                #pragma omp atomic
                m_NodesScoreData[*it] += dep[*it];
            }
        }
    };

    m_Graph.parallelForNodes(depFunc);

    m_bHasRun = true;
}