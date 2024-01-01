#include <iostream>

using namespace std;

struct Box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void PrintBox(Box box);
void SetVolume(Box& box);

void NumSet(float& num);

int main()
{
    setlocale(LC_ALL, "");

    Box box;
    cout << "Введіть дані виробника Box: ";
    cin.getline(box.maker, 40);

    cout << "Введіть height: ";
    NumSet(box.height);

    cout << "Введіть width: ";
    NumSet(box.width);

    cout << "Введіть length: ";
    NumSet(box.length);

    SetVolume(box);
    PrintBox(box);

    return 0;
}

void PrintBox(Box box)
{
    cout << box.maker << endl
        << box.height << endl
        << box.width << endl
        << box.length << endl
        << box.volume << endl;
}

void SetVolume(Box& box)
{
    box.volume = box.height * box.width * box.length;
}

void NumSet(float& num) 
{
    while (!(cin >> num))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Дозволено лише цифри! Спробуйте ще раз: ";
    }
}
