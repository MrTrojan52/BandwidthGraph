//
// Created by Trojan on 29.11.2020.
//

#ifndef BANDWIDTHGRAPH_IGRAPH_H
#define BANDWIDTHGRAPH_IGRAPH_H

#include <string>

#include "Arc/Arc.h"

class INode;

class IGraph
{
public:
        virtual void addNode(INode* pNode) = 0;
        virtual void removeNode(int id) = 0;
        virtual void addArc(Arc arc) = 0;
        virtual void removeArc(int from, int to) = 0;
        virtual void fromJSONFile(const std::string& sFileName) = 0;
        virtual ~IGraph() = default;
};

#endif //BANDWIDTHGRAPH_IGRAPH_H
