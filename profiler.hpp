#pragma once
#include <chrono>
#include <iostream>
#include <string>

namespace al {

class Profiler final {
    std::chrono::steady_clock::time_point m_start;
    std::string m_message;

public:
    explicit Profiler(const std::string &msg = {})
    : m_start(std::chrono::steady_clock::now())
    , m_message(msg) {}

    ~Profiler() {
        using namespace std::chrono;
        auto finish = steady_clock::now();
        auto duration = finish - m_start;

        if (m_message.empty() == false) {
            std::cerr << m_message << ": ";
        }
        std::cerr << duration_cast<milliseconds>(duration).count() << " ms" << std::endl;
    }
};

} // namespace al

#define __UNIQ_ID_IMPL__(counter) _LOCAL_VAR_##counter
#define __UNIQ_ID__(counter) __UNIQ_ID_IMPL__(counter)

#define LOG_DURATION(message) al::Profiler __UNIQ_ID__(__COUNTER__){message}
#define LOG_DURATION_TEXT(text) al::Profiler __UNIQ_ID__(__COUNTER__){#text}
