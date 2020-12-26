//
// Created by Trojan on 15.12.2020.
//

#ifndef BANDWIDTHGRAPH_IALGORITHM_H
#define BANDWIDTHGRAPH_IALGORITHM_H

class IAlgorithm
{
    public:
        virtual ~IAlgorithm() = default;

        virtual bool hasFinished() = 0;
        virtual void run() = 0;
};

#endif //BANDWIDTHGRAPH_IALGORITHM_H
