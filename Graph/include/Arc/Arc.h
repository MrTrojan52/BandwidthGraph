//
// Created by Trojan on 06.12.2020.
//

#ifndef BANDWIDTHGRAPH_ARCINFO_H
#define BANDWIDTHGRAPH_ARCINFO_H

struct Arc
{
    public:
        Arc(int from, int to, int weight = 0)
        : m_FromID(from),
          m_ToID(to),
          m_Weight(weight)
        { }

        Arc() : Arc(-1, -1, 0) { }

        bool operator==(const Arc& rhs) const
        {
            return ((m_FromID == rhs.m_FromID) && (m_ToID == rhs.m_ToID));
        }

        bool operator<(const Arc& rhs) const
        {
            return (m_FromID < rhs.m_FromID) || ((m_FromID == rhs.m_FromID) && (m_ToID < rhs.m_ToID));
        }

        int m_FromID;
        int m_ToID;
        int m_Weight;
};

#endif //BANDWIDTHGRAPH_ARCINFO_H
