//
// Created by Trojan on 07.12.2020.
//

#ifndef BANDWIDTHGRAPH_BASEBANDWIDTHNODE_H
#define BANDWIDTHGRAPH_BASEBANDWIDTHNODE_H

#include "Node/BaseNode.h"

class BaseBandwidthNode : public BaseNode
{
    public:
        virtual ~BaseBandwidthNode() {};
        void fromJSON(const nlohmann::json& j) override;
};

#endif //BANDWIDTHGRAPH_BASEBANDWIDTHNODE_H
