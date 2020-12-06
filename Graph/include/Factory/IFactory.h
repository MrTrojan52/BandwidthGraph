//
// Created by Trojan on 06.12.2020.
//

#ifndef BANDWIDTHGRAPH_IFACTORY_H
#define BANDWIDTHGRAPH_IFACTORY_H

#include <nlohmann/json.hpp>

class INode;

class IJSONFactory
{
    public:
        virtual INode* createNode(const nlohmann::json& j);
};

#endif //BANDWIDTHGRAPH_IFACTORY_H
