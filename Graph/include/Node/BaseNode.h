//
// Created by Trojan on 07.12.2020.
//

#ifndef BANDWIDTHGRAPH_BASENODE_H
#define BANDWIDTHGRAPH_BASENODE_H

#include "Node/INode.h"

#include "nlohmann/json.hpp"

class BaseNode : public INode
{
    public:
        void fromJSON(const nlohmann::json& j) override;
        std::string getStringProperty(const std::string& name) override;
        int getIntProperty(const std::string& name) override;
        virtual ~BaseNode() {};

    protected:
        std::unordered_map<std::string, std::string> m_properties;
};

#endif //BANDWIDTHGRAPH_BASENODE_H
