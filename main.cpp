#include <iostream>

#include "rabin_karp.h"
#include "z_algorithm.h"

std::string text
{
    "Sure! In Rabin-Karp algorithm, we use hash function to calculate the hash value of the pattern,"
    "which is used to compare with the hash values of substrings of the given text. If a substring's hash"
    "value matches with the pattern's hash value, then we compare the substring and pattern character by character to"
    "check if they are actually equal.\n"
    "\n"
    "A simple hash function that can be used for Rabin-Karp algorithm is to treat the characters of the pattern as digits"
    "in a base-radix number system, where radix.....A is the number of distinct characters in the input alphabet. For example, if the input alphabet"
    "is {a, b, c, d, e}, then the radix is 5. Then, we can use a polynomial hash function to calculate the hash value of the pattern:\n"
    "\n"
    "hash(pattern) = (p[0]*radix^(m-1) + p[1]*radix^(m-2) + ... + p[m-1]*radix^0) mod q\n"
    "\n"
    "where p[i] is the numerical value of the i-th character in the pattern (i.e., its position in the input alphabet), m is"
    "the length of the pattern, radix is the base..... of the adie number system (i.e., the size of the input alphabet), and q is a large prime"
    "number that is used as the modulus to avoid overflow."
};

std::string pattern{".."};

int main() {
    std::cout << rabin_karp::search(pattern, text).size() << std::endl;
    std::cout << z_algorithm::search(pattern, text).size() << std::endl;
    return 0;
}
