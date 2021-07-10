#pragma once

#include <chrono>
#include <iostream>
#include <string>

#define UNIQ_ID_IMPL(line_line) _A_LOCAL_VAR_##line_line
#define UNIQ_ID(line_line) UNIQ_ID_IMPL(line_line)

class LogDuration {
    std::chrono::steady_clock::time_point m_start;
    std::string m_message;

public:
    explicit LogDuration(const std::string &msg = {})
    : m_start(std::chrono::steady_clock::now())
    , m_message(msg) {}

    ~LogDuration() {
        using namespace std::chrono;
        auto finish = steady_clock::now();
        auto duration = finish - m_start;

        std::cerr << m_message << ": "
            << duration_cast<milliseconds>(duration).count()
            << " ms" << std::endl;
    }
};

#define LOG_DURATION(message) LogDuration UNIQ_ID(__LINE__){message};
