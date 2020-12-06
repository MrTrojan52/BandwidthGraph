#include <iostream>
#include "omp.h"

#include "Graph/BaseGraph.h"

int main() {
    /*std::cout << "Hello, World!" << std::endl;
    #pragma omp parallel num_threads(3)
    {
        std::cout << omp_get_num_threads();
    };
    return 0;*/
    BaseGraph g;
    g.fromJSONFile("test.json");
}
