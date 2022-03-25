//
// Created by Fabrizio Paino on 2022-01-16.
//

#ifndef YARN_RANDOMSCHEDULER_H
#define YARN_RANDOMSCHEDULER_H

#include "IScheduler.h"
#include <random>

namespace YarnBall {

    class RandomScheduler : public IScheduler {
    public:
        RandomScheduler();

        ~RandomScheduler() = default;

        int ThreadIndex(int maxValue) override;

    private:
        std::random_device device;
        std::default_random_engine randomEngine;
    };

}

#endif //YARN_RANDOMSCHEDULER_H
