#include <iostream>
#include <functional>
#include <vector>

class Command {
    std::vector<std::function<void()>> history;
public:
    void Submit(std::function<void()> command) {
        command(); 
        history.push_back(command); 
    }
};

class Light {
public:
    void On()  { std::cout << "Light is ON\n"; }
    void Off() { std::cout << "Light is OFF\n"; }
};

int main() {
    Light myLight;
    Command remote;

    remote.Submit([&]() { myLight.On(); });
    remote.Submit([&]() { myLight.Off(); });

    return 0;
}
