//
// Created by Trojan on 28.11.2020.
//

#ifndef BANDWIDTHGRAPH_BASENODE_H
#define BANDWIDTHGRAPH_BASENODE_H

#include "Node/INode.h"

class CBaseNode : public INode
{
    public:
        CBaseNode();

        NodeList& getNeighbours() override { return m_Neighbours; }

        void addNeighbour(INode* pNode) override { m_Neighbours.push_back(pNode); }

        NodeType getNodeType() override { return m_Type; }

    private:
        NodeList m_Neighbours;
        NodeType m_Type;
};

#endif //BANDWIDTHGRAPH_BASENODE_H
