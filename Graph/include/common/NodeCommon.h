//
// Created by Trojan on 06.12.2020.
//

#ifndef BANDWIDTHGRAPH_NODECOMMON_H
#define BANDWIDTHGRAPH_NODECOMMON_H

#include <string>

namespace NodeConsts
{
    const std::string TYPE_PROP = "type";
    const std::string ARCS_PROP = "arcs";
    const std::string ID_PROP = "id";
    const std::string BANDWIDTH_PROP = "bw";
}

namespace ArcConsts
{
    const std::string FROM_TAG = "f";
    const std::string TO_TAG = "t";
    const std::string WEIGHT_TAG = "w";
}

enum NodeType
{
    NODETYPE_UNDEFINED = -1,
    NODETYPE_START,
    NODETYPE_END,
    NODETYPE_ROUTER
};

NodeType getNodeTypeEnumByName(const std::string& name);

std::string getNodeNameByEnum(NodeType type);

#endif //BANDWIDTHGRAPH_NODECOMMON_H
