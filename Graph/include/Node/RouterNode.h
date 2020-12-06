//
// Created by Trojan on 07.12.2020.
//

#ifndef BANDWIDTHGRAPH_ROUTERNODE_H
#define BANDWIDTHGRAPH_ROUTERNODE_H

#include "Node/BaseBandwidthNode.h"

class RouterNode : public BaseBandwidthNode
{
    public:
        RouterNode() = default;
        virtual ~RouterNode() {};
        explicit RouterNode(const nlohmann::json& j) { BaseBandwidthNode::fromJSON(j); };
        NodeType getNodeType() override { return NODETYPE_ROUTER; }
};

#endif //BANDWIDTHGRAPH_ROUTERNODE_H
