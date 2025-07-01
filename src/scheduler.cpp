#include "..\include\scheduler.hpp"
#include <algorithm>

void scheduler::add_task(task task, int32_t interval_ms, int32_t priority) {
    tasks.push_back( { task, interval_ms, priority, std::chrono::steady_clock::now() } );

    std::sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
        return a.priority > b.priority;
    });
}

void scheduler::run() {
    while (true) {

        auto now = std::chrono::steady_clock::now();

        for (auto& t : tasks) {
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - t.last_run).count();
            if (elapsed >= t.internal_ms) {
                t.task();
                t.last_run = now;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}