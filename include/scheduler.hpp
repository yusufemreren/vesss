#pragma once
#include <functional>
#include <vector>
#include <chrono>
#include <thread>

class scheduler {
public:
    using task = std::function<void()>;

    void add_task(task task, int32_t interval_ms, int32_t priority);
    void run();

private:
    struct scheduled_task {
        task task;
        int32_t internal_ms;
        int32_t priority;
        std::chrono::steady_clock::time_point last_run;
    };

    std::vector<scheduled_task> tasks;
};