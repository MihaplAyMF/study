
#include <iostream>
#include <vector>
#include <future>

void DoFunct(int id) {
    std::cout << "Task " << id << std::endl;
}

int main() {
    std::vector<std::future<void>> futures;

    for (int i = 1; i <= 500; ++i) {
        futures.push_back(std::async(std::launch::async, DoFunct, i));
    }

    for (auto& fut : futures) {
        fut.get();
    }

    return 0;
}

