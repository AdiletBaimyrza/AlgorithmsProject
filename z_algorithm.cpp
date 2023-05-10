//
// Created by adilet on 10/05/23.
//

#include "z_algorithm.h"

std::vector<int> z_algorithm::search(const std::string& pattern, const std::string& text)
{
    auto p_len{static_cast<int>(pattern.length())};
    auto t_len{static_cast<int>(text.length())};
    auto arr_len{p_len + t_len + 1};
    std::vector<int> indices{};
    // $ is used as a distinct char that separates pattern and text strings
    std::string concatenated{pattern + '$' + text};
    std::vector<int> z_array{z_algorithm::make_z_array(concatenated)};

    for (auto i = 0; i < arr_len; i++)
    {
        if (z_array[i] == p_len) {
            indices.push_back(i - p_len - 1);
        }
    }

    return indices;
}

std::vector<int> z_algorithm::make_z_array(const std::string& str)
{
    auto str_len = static_cast<int>(str.length());
    std::vector<int> z_array(str_len);
    int left{0}, right{0};

    for (auto i = 1; i < str_len; i++)
    {
        if (i > right)
        {
            right = left = i;
            while (right < str_len && str[right] == str[right - left])
            {
                right++;
            }
            z_array[i] = right - left;
            right--;
        }
        else
        {
            int k = i - left;
            if (z_array[k] < right - i + 1)
            {
                z_array[i] = z_array[k];
            }
            else
            {
                left = i;
                while (right < str_len && str[right] == str[right - left])
                {
                    right++;
                }
                z_array[i] = right - left;
                right--;
            }
        }
    }

    return z_array;
}