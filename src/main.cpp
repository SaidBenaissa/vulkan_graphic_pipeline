#include "first_app.hpp"
#include<stdexcept>
#include<iostream>
#include<cstdlib>

int main() {
    lve::FirstApp app{};

    try {
        app.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}