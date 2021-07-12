#include <iostream>
#include <thread>

#include "profiler.hpp"

int main() {
    LOG_DURATION("full time: ");
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        LOG_DURATION("4: ");

        std::this_thread::sleep_for(std::chrono::seconds(1));
        LOG_DURATION("3: ");

        std::this_thread::sleep_for(std::chrono::seconds(1));
        LOG_DURATION("2: ");

        std::this_thread::sleep_for(std::chrono::seconds(1));
        LOG_DURATION("1: ");

        std::this_thread::sleep_for(std::chrono::seconds(1));
        LOG_DURATION("0: ");
    }
}
