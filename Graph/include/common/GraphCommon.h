//
// Created by Trojan on 06.12.2020.
//

#ifndef BANDWIDTHGRAPH_GRAPHCOMMON_H
#define BANDWIDTHGRAPH_GRAPHCOMMON_H

#include <string>

#define FIND_IN_CONTAINER(cont, val) (cont.find(val) != cont.end())

const std::string GRAPH_TAG = "graph";

using count_t = uint64_t;
using weight_t = double;
using index_t = uint64_t;

constexpr index_t emptyIndex = std::numeric_limits<index_t>::max(); // Use max possible value
constexpr weight_t infWeight = std::numeric_limits<weight_t>::infinity();
const weight_t defaultWeight = 1.0;

#endif //BANDWIDTHGRAPH_GRAPHCOMMON_H
