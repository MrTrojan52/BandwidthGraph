//
// Created by Trojan on 06.12.2020.
//

#ifndef BANDWIDTHGRAPH_ARCINFO_H
#define BANDWIDTHGRAPH_ARCINFO_H

struct Edge
{
    index_t from;
    index_t to;

    Edge()
    : from(emptyIndex)
    , to(emptyIndex)
    { }

    Edge(index_t f, index_t t)
    {
        from = f;
        to = t;
    }
};

struct WeightedEdge : public Edge
{
    weight_t weight;

    WeightedEdge(index_t f, index_t t, weight_t w)
    : Edge(f, t)
    , weight(w)
    { }

    bool operator==(const WeightedEdge& rhs)
    {
        return ((from == rhs.from) && (to == rhs.to) && (weight == rhs.weight));
    }
};


struct WeightedEdgeSetCmp
{
    bool operator()(const WeightedEdge& e1, const WeightedEdge& e2) const
    {
        return ((e1.from < e2.from) || ((e1.from == e2.from) && (e1.to < e2.to)));
    }
};

#endif //BANDWIDTHGRAPH_ARCINFO_H
