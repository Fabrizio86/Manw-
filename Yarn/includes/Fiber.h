//
// Created by Fabrizio Paino on 2022-01-15.
//

#ifndef YARN_FIBER_H
#define YARN_FIBER_H

#include <vector>
#include "ITask.h"
#include "Workload.h"

namespace YarnBall {

    class Fiber final {
    public:
        Fiber(FiberId id, sQueue queue, SignalDone signalDone, GetFromPending getFromPending);

        ~Fiber();

        ///\brief prevent copy constructor
        Fiber(const Fiber &) = delete;

        /// \brief prevent move semantics
        Fiber(Fiber &&) = delete;

        void execute(sITask task);

        void stop();

        Workload workload();

        [[maybe_unused]] [[nodiscard]] FiberId id() const;

        void markAsTemp();

        OsHandler osHandler();

    private:
        void process();
        void wait();
        bool waitCondition();
        static const unsigned int maxQueueSize;

        bool running;
        bool temp;
        SignalDone signalDone;
        GetFromPending getFromPending;

        std::condition_variable condition;
        sQueue queue;
        std::thread thread;
        std::mutex mu;
        FiberId fiberId;

    };

    using sFiber = std::shared_ptr<Fiber>;
    using Fibers = std::vector<sFiber>;
}

#endif //YARN_FIBER_H
