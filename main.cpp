#include <iostream>

#include "omp.h"

#include "Graph/Graph.h"
#include "Algorithms/Path/Dijkstra.h"
#include "Algorithms/Centrality/BetweennessCentrality.h"

int main() {
    /*std::cout << "Hello, World!" << std::endl;
    #pragma omp parallel num_threads(3)
    {
        std::cout << omp_get_num_threads();
    };
    return 0;*/
    Graph g;
    g.addWeightedEdgesAndNodes(
            {
               {1, 6, 14},
                {1,2,7},
                {1,3,9},
                {2,3,10},
                {2,4,15},
                {3, 4, 11},
                {3, 6, 2},
                {5,4,6},
                {6,5,9},

                    /*{1,2,3},
                    {1,3,11},
                    {1,4,7},
                    {2,4,15},
                    {2,3,7},
                    {3,5,3},
                    {4,5,5}*/

                   /* {1,2,1},
                    {1,3,2},
                    {2,3,1},
                    {3,4,5}*/
            }
    );

    BetweennessCentrality b(g);
    b.run();
    return 0;

}
