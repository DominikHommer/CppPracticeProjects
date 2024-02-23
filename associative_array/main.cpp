#include "associative_array.h"

int main() {
    associative_array<std::string, int> mat_nr;
    mat_nr["student"] = 123;
    const auto& const_mat_nr = mat_nr;
    try {
        std::cout << const_mat_nr["student"] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

