//
// Created by adilet on 09/05/23.
//

#include "rabin_karp.h"
#include <cmath>

std::vector<int> rabin_karp::search(const std::string& pattern, const std::string& text)
{
    std::vector<int> indices{};
    const int base256{256};
    // q is used to prevent overflow
    const int q{static_cast<int>(pow(2, 31) - 2)};
    const auto p_len{static_cast<int>(pattern.length())};
    const auto t_len{static_cast<int>(text.length())};
    // h is a hash coefficient of el to be subtracted from window
    const int h{static_cast<int>(pow(base256, p_len - 1))};
    int hash_p{0};
    int hash_t{0};

    for (auto i = 0; i < p_len; i++)
    {
        hash_p = (base256 * hash_p + pattern[i]) % q;
        hash_t = (base256 * hash_t + text[i]) % q;
    }

    for (auto i = 0; i < t_len - p_len + 1; i++)
    {
        if (hash_t == hash_p && text.substr(i, p_len) == pattern)
        {
            indices.push_back(i);
        }
        if (i < t_len - p_len)
        {
            hash_t = (base256 * (hash_t - text[i] * h) + text[i + p_len]) % q;
        }
    }

    return indices;
}
