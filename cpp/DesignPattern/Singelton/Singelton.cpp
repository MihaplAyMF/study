#include <iostream>

class Singleton {
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;


    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void showMessage() {
        std::cout << "Singleton instance at: " << this << std::endl;
    }

private:
    Singleton() {
        std::cout << "Singleton created\n";
    }

    ~Singleton() {
        std::cout << "Singleton destroyed\n";
    }
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    s1.showMessage();
    s2.showMessage();

    return 0;
}

