//
// Created by Trojan on 07.12.2020.
//

#include "common/NodeCommon.h"

NodeType getNodeTypeEnumByName(const std::string& name)
{
    if (name == "start")
    {
        return NODETYPE_START;
    }
    else if (name == "end")
    {
        return NODETYPE_END;
    }
    else if (name == "router")
    {
        return NODETYPE_ROUTER;
    }
    else
    {
        return NODETYPE_UNDEFINED;
    }
}

std::string getNodeNameByEnum(NodeType type)
{
    switch (type)
    {
        case NODETYPE_START:
            return "start";
        case NODETYPE_END:
            return "end";
        case NODETYPE_ROUTER:
            return "router";

        default:
            return "";
    }
}