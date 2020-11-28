#ifndef BANDWIDTHGRAPH_NODECOMMON_H
#define BANDWIDTHGRAPH_NODECOMMON_H

class INode;

typedef std::vector<INode*> NodeList;

enum NodeType
{
    NodeType_Default = 0,
    NodeType_UserSource,
    NodeType_UserEnd,
    NodeType_Router
};

#endif //BANDWIDTHGRAPH_NODECOMMON_H
