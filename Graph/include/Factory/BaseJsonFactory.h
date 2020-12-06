//
// Created by Trojan on 06.12.2020.
//

#ifndef BANDWIDTHGRAPH_BASEJSONFACTORY_H
#define BANDWIDTHGRAPH_BASEJSONFACTORY_H
#include "Factory/IFactory.h"

class BaseJSONFactory : public IJSONFactory
{
    public:
        static BaseJSONFactory& GetInstance();
        INode* createNode(const nlohmann::json& j) override;

    private:
        BaseJSONFactory() = default;
        BaseJSONFactory(const BaseJSONFactory&);
        BaseJSONFactory& operator=( BaseJSONFactory& ) = default;
};


#endif //BANDWIDTHGRAPH_BASEJSONFACTORY_H
