#include <iostream>

#include "omp.h"

#include "Graph/WeightedGraphGenerator.h"
#include "Algorithms/Path/Dijkstra.h"
#include "Algorithms/Centrality/BetweennessCentrality.h"

#include "third_party/fort/fort.hpp"

int main() {
    fort::char_table Result_table;
    Result_table.set_cell_text_align(fort::text_align::center);
    Result_table.set_border_style(FT_BASIC2_STYLE);
    Result_table << fort::header << "Nodes" << "Edges" << "1 thread";

    int maxThreadsCount = omp_get_max_threads();

    for (int i = 2; i <= maxThreadsCount; ++i)
    {
        Result_table << std::to_string(i) + " threads";
    }
    Result_table << fort::endr;

    Graph g;


    std::vector<count_t> sizes{50, 100, 150, 200, 250, 300, 350};
    for (auto size : sizes)
    {
        WeightedGraphGenerator::generate(g, size);
        Result_table << g.getVertexesCount() << g.getEdgesCount();
        for (int numThreads = 1; numThreads <= maxThreadsCount; ++numThreads)
        {
            omp_set_num_threads(numThreads);
            std::cout << "Starting BetweennessCentrality with threads = " << numThreads
            << ", nodes = " << g.getVertexesCount() << ", edges = " << g.getEdgesCount() << std::endl;
            BetweennessCentrality b(g);
            b.run();
            Result_table << b.getExecutionTime();
        }
        Result_table << fort::endr;
    }

    std::cout << Result_table.to_string();
    return 0;
}
