//
// Created by Trojan on 06.12.2020.
//

#ifndef BANDWIDTHGRAPH_BASEGRAPH_H
#define BANDWIDTHGRAPH_BASEGRAPH_H

#include <set>
#include <unordered_map>
#include <nlohmann/json.hpp>

#include "Graph/IGraph.h"

class BaseGraph : public IGraph
{
    public:
        BaseGraph() = default;
        ~BaseGraph() noexcept override;

        void addNode(INode* pNode) override;
        void removeNode(int id) override;
        void addArc(Arc arc) override;
        void removeArc(int from, int to) override;
        void fromJSONFile(const std::string& sFileName) override;

    private:
        void addArcsFromJSONForNode(int from, const nlohmann::json& j);

        std::unordered_map<int, INode*> m_Nodes;
        std::set<Arc> m_Arcs;
};

#endif //BANDWIDTHGRAPH_BASEGRAPH_H
