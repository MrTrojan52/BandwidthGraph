//
// Created by Trojan on 06.12.2020.
//

#include "Factory/BaseJsonFactory.h"
#include "Node/RouterNode.h"
#include "Node/StartNode.h"
#include "Node/EndNode.h"

BaseJSONFactory& BaseJSONFactory::GetInstance()
{
    static BaseJSONFactory instance;
    return instance;
}

INode* BaseJSONFactory::createNode(const nlohmann::json& j)
{
    INode* pRes = nullptr;
    if (j.is_object())
    {
        if (j.contains(NodeConsts::TYPE_PROP))
        {
            auto jType = j[NodeConsts::TYPE_PROP];
            if (jType.is_string())
            {
                auto sType = jType.get<std::string>();
                NodeType type = getNodeTypeEnumByName(sType);
                switch (type)
                {
                    case NODETYPE_START:
                        pRes = new StartNode(j);
                        break;
                    case NODETYPE_END:
                        pRes = new EndNode;
                        break;
                    case NODETYPE_ROUTER:
                        pRes = new RouterNode(j);
                        break;

                    default:
                        return nullptr;
                }
            }
        }
    }
    return pRes;
}
