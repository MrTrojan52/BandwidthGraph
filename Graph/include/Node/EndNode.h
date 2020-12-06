//
// Created by Trojan on 07.12.2020.
//

#ifndef BANDWIDTHGRAPH_ENDNODE_H
#define BANDWIDTHGRAPH_ENDNODE_H

#include "Node/INode.h"

class EndNode : public BaseNode
{
    public:
        EndNode() = default;
        virtual ~EndNode() {};
        void fromJSON(const nlohmann::json& j) override {}
        NodeType getNodeType() override { return NODETYPE_END; }
};

#endif //BANDWIDTHGRAPH_ENDNODE_H
