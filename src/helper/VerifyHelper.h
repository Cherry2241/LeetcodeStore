#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace helper {

template <typename T>
std::string JoinVector(const std::vector<T>& values) {
    std::ostringstream oss;
    for (size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            oss << ", ";
        }
        oss << values[i];
    }
    return oss.str();
}

template <typename T>
bool VerifyVectorEqual(const char* caseName,
                       const std::vector<T>& expected,
                       const std::vector<T>& actual,
                       std::string& message) {
    if (actual == expected) {
        return true;
    }

    std::ostringstream oss;
    oss << caseName << " failed. expected=[" << JoinVector(expected)
        << "], actual=[" << JoinVector(actual) << "]";
    message = oss.str();
    return false;
}

}  // namespace helper
