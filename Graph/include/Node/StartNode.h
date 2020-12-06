//
// Created by Trojan on 07.12.2020.
//

#ifndef BANDWIDTHGRAPH_STARTNODE_H
#define BANDWIDTHGRAPH_STARTNODE_H

#include "Node/BaseBandwidthNode.h"

class StartNode : public BaseBandwidthNode
{
    public:
        StartNode() = default;
        virtual ~StartNode() {};
        explicit StartNode(const nlohmann::json& j) { BaseBandwidthNode::fromJSON(j); }

        NodeType getNodeType() override { return NODETYPE_START; };
};

#endif //BANDWIDTHGRAPH_STARTNODE_H
