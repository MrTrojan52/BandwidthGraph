#include <iostream>
#include "omp.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    #pragma omp parallel num_threads(3)
    {
        std::cout << omp_get_num_threads();
    };
    return 0;
}
