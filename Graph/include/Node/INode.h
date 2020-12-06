#ifndef BANDWIDTHGRAPH_INODE_H
#define BANDWIDTHGRAPH_INODE_H

#include <vector>
#include <nlohmann/json.hpp>
#include "common/NodeCommon.h"

// Interface Node class
class INode
{
    public:
        virtual void fromJSON(const nlohmann::json& j) = 0;
        virtual ~INode() = default;
        virtual std::string getStringProperty(const std::string& name) = 0;
        virtual int getIntProperty(const std::string& name) = 0;
        virtual NodeType getNodeType() = 0;
};

#endif //BANDWIDTHGRAPH_INODE_H
