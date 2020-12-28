#include <iostream>
#include <fstream>

#include "omp.h"

#include "Graph/WeightedGraphGenerator.h"
#include "Algorithms/Path/Dijkstra.h"
#include "Algorithms/Centrality/BetweennessCentrality.h"

#include "third_party/fort/fort.hpp"

enum property
{
    prop_Time = 0,
    prop_Acceleration,
    prop_Efficiency,

    prop_COUNT // Should be last
};

std::vector<double> calcProperty(const std::vector<double>& avgTimes, property prop)
{
    std::vector<double> res(avgTimes.size(), 0.0);
    if (res.size() > 0)
    {
        switch (prop)
        {
            case prop_Acceleration:
            {
                for (int i = 0; i < res.size(); ++i)
                {
                    res[i] = avgTimes[0] / avgTimes[i]; // T1 / Tp
                }
                break;
            }
            case prop_Efficiency:
            {
                for (int i = 0; i < res.size(); ++i)
                {
                    res[i] = (avgTimes[0] / avgTimes[i]) / (i + 1); // (T1 / Tp) / n
                }
                break;
            }
        }
    }
    return res;
}

std::string getPropertyName(property prop, bool bShort = true)
{
    std::string res;
    switch (prop)
    {
        case prop_Time:
            res = bShort ? "T" : "Time";
            break;

        case prop_Acceleration:
            res = bShort ? "S" : "Acceleration";
            break;

        case prop_Efficiency:
            res = bShort ? "E" : "Efficiency";
            break;
    }

    return res;
}

int main() {
    const uint64_t RUN_COUNT = 10;
    const std::string OUT_FILE_NAME = "out.txt";

    std::ofstream outFile(OUT_FILE_NAME, std::ios_base::out | std::ios_base::trunc);
    if (!outFile.is_open())
    {
        throw std::runtime_error("Unable to open file: " + OUT_FILE_NAME);
    }

    fort::char_table Result_table;
    Result_table.set_cell_text_align(fort::text_align::center);
    Result_table.set_border_style(FT_DOUBLE_STYLE);
    Result_table << fort::header << "Nodes" << "Edges" << "1 thread";

    int maxThreadsCount = omp_get_max_threads();

    for (int i = 2; i <= maxThreadsCount; ++i)
    {
        Result_table << std::to_string(i) + " threads";
    }
    Result_table << fort::endr;

    Graph g;


    std::vector<count_t> sizes{10, 20, 50, 100, 150, 200, 250, 300, 350};
    for (auto size : sizes)
    {
        WeightedGraphGenerator::generate(g, size);
        Result_table << g.getVertexesCount() << g.getEdgesCount();
        std::vector<double> avgTimes(maxThreadsCount, 0.0);
        for (int numThreads = 1; numThreads <= maxThreadsCount; ++numThreads)
        {
            omp_set_num_threads(numThreads);

            double execTime = 0.0;
            for (int c = 0; c < RUN_COUNT; ++c)
            {
                std::cout << '[' << c+1 << "] " <<"Starting BetweennessCentrality with threads = " << numThreads
                << ", nodes = " << g.getVertexesCount() << ", edges = " << g.getEdgesCount() << std::endl;

                BetweennessCentrality b(g);
                b.run();
                execTime += b.getExecutionTime();
            }
            avgTimes[numThreads-1] = execTime / RUN_COUNT;
        }
        for (auto time : avgTimes)
        {
            Result_table << getPropertyName(static_cast<property>(prop_Time)) + ": " + std::to_string(time);
        }
        Result_table << fort::endr;

        for (int prop = prop_Acceleration; prop < prop_COUNT; ++prop)
        {
            auto propVals = calcProperty(avgTimes, static_cast<property>(prop));
            Result_table << "" << "";
            for (auto propVal : propVals)
            {
                Result_table << getPropertyName(static_cast<property>(prop)) + ": " + std::to_string(propVal);
            }
            Result_table << fort::endr;
        }
        Result_table << fort::separator;
        outFile.seekp(std::ios_base::beg);
        outFile << Result_table.to_string();
        outFile.flush();
    }
    outFile.close();
    std::cout << Result_table.to_string();
    return 0;
}
