//
// Created by Trojan on 07.12.2020.
//

#include "Node/BaseNode.h"

void BaseNode::fromJSON(const nlohmann::json& j)
{
    if (j.is_object() && j.contains(NodeConsts::ID_PROP) && j[NodeConsts::ID_PROP].is_number())
    {
        m_properties[NodeConsts::ID_PROP] = std::to_string(j[NodeConsts::ID_PROP].get<int>());
    }
}

std::string BaseNode::getStringProperty(const std::string& name)
{
    std::string sRes;
    auto it = m_properties.find(name);
    if (it != m_properties.end())
    {
        sRes = m_properties[name];
    }

    return sRes;
}

int BaseNode::getIntProperty(const std::string& name)
{
    int nRes = -1;
    auto it = m_properties.find(name);
    if (it != m_properties.end())
    {
        nRes = std::stoi(m_properties[name]);
    }
    return nRes;
}
