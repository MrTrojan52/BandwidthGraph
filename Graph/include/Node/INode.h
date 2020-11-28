#ifndef BANDWIDTHGRAPH_INODE_H
#define BANDWIDTHGRAPH_INODE_H

#include <vector>
#include "common/NodeCommon.h"

// Interface Node class
class INode
{
    public:
        virtual NodeList& getNeighbours() = 0;
        virtual void addNeighbour(INode* pNode) = 0;
        virtual NodeType getNodeType() = 0;
};

#endif //BANDWIDTHGRAPH_INODE_H
