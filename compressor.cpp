#include "compressor.h"
#include <sstream>

std::string compressRLE(const std::string& data) {
    std::ostringstream oss;
    size_t i = 0;

    while (i < data.length()) {
        char current = data[i];
        size_t count = 1;

        while (i + 1 < data.length() && data[i + 1] == current) {
            ++count;
            ++i;
        }

        oss << current << count;
        ++i;
    }

    return oss.str();
}

// Dummy function since threading not supported in your MinGW
void compressInParallel(const std::string& input, int numThreads, std::string& output) {
    // For now just call single-threaded version
    output = compressRLE(input);
}

std::string decompressRLE(const std::string& data) {
    std::ostringstream oss;
    size_t i = 0;

    while (i < data.length()) {
        char current = data[i];
        ++i;

        std::string countStr;
        while (i < data.length() && isdigit(data[i])) {
            countStr += data[i];
            ++i;
        }

        int count = std::stoi(countStr);
        oss << std::string(count, current);
    }

    return oss.str();
}
