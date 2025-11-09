#include <iostream>
#include <string>

using namespace std;

int main()
{ 
    string line;

    while(cin.peek() != '$')
        line += cin.get();

    cout << line.size() << endl; // якщо включно з символом '$' то додаємо одиницю
    
    return 0;
}
