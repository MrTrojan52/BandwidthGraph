//
// Created by Trojan on 07.12.2020.
//

#include "Node/BaseBandwidthNode.h"


void BaseBandwidthNode::fromJSON(const nlohmann::json& j)
{
    BaseNode::fromJSON(j);

    if (j.is_object() && j.contains(NodeConsts::BANDWIDTH_PROP) && j[NodeConsts::BANDWIDTH_PROP].is_number())
    {
        m_properties[NodeConsts::BANDWIDTH_PROP] = std::to_string(j[NodeConsts::BANDWIDTH_PROP].get<int>());
    }
}