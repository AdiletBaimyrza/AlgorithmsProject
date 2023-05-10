#include <iostream>

#include "rabin_karp.h"
#include "z_algorithm.h"
// random text
std::string text
{
    "Colors bounced around in her head."
    "They mixed and threaded themselves together."
    "Even colors that had no business being together."
    "They were all one, yet distinctly separate at the same time."
    "How was she going to explain this to the others?"
};

std::string pattern{"the"};

int main() {
    std::cout << rabin_karp::search(pattern, text).size() << std::endl;
    std::cout << z_algorithm::search(pattern, text).size() << std::endl;
    return 0;
}
