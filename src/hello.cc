#include "hello.hh"
#include <iostream>

void hello() { 
    std::cout << "hello world!" << '\n';
}

void hello(const char* helloString) {
    std::cout << helloString << '\n';
}

void hello(std::string helloString) {
    std::cout << helloString << '\n';
}