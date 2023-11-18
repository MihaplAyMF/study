#include <iostream>
#include <filesystem>
#include <fstream>
#include <limits>
#include <string>

namespace fs = std::filesystem;
using namespace std;

void PrintFile();
void OpenFile();
void CreateFile();

int main()
{
    setlocale(LC_ALL, "");

    int _steateMenu;
    bool exit = false;

    while (!exit)
    {
        cout << "Виберіть операцію: " << endl
            << "1) Вийти з програми" << endl
            << "2) Ввести список файлів" << endl
            << "3) Прочитати файл" << endl
            << "4) Створити файл" << endl
            << "Ваш вибір: ";

        while (true)
        {
            if (!(cin >> _steateMenu))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Only numbers allowed! Enter again: ";
                continue;
            } else if (_steateMenu <= 0 || _steateMenu >= 6)
            {
                cout << "Only number in list! Enter again: ";
                continue;
            }
            break;

        }

        switch (_steateMenu)
        {
            case 1:
                system("cls");
                exit = true;
                break;
            case 2:
                system("cls");
                PrintFile();
                break;
            case 3:
                OpenFile();
                system("cls");
                break;
            case 4:
                CreateFile();
                system("cls");
                break;
            default:
                cout << "Only number in list! Enter again: ";
                break;
        }
    }

    return 0;
}

void PrintFile()
{
    // Отримати поточний шлях, де знаходиться програма
    string programPath = fs::current_path().string();

    cout << endl;

    // Перевірка, чи поточний шлях існує і є папкою
    if (fs::exists(programPath) && fs::is_directory(programPath))
    {
        for (const auto& entry : fs::directory_iterator(programPath))
        {
            // Вивести назву файлу
            cout << entry.path().filename().string() << endl;
        }
    } else
    {
        cout << "Папку не знайдено." << endl;
    }

    cout << endl;
}

void OpenFile()
{
    ifstream file;
    string name;
    char ch;

    cout << "Enter name a file: ";
    cin >> name;

    file.open(name);

    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
    } else
    {
        cout << "file \"" << name << "\" open successfully" << endl << endl;
    }

    while (file.get(ch))
        cout << ch;
    
    cout << endl;
    file.close();

    system("pause");
}

void CreateFile()
{
    string name;
    char ch = ' ';

    cout << "Enter name a file: ";
    cin >> name;

    ofstream file(name);
    
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
    } else
    {
        cout << "file \"" << name << "\" open successfully" << endl << endl;
    }

    while ((ch = cin.get()) != 'q')
    {
        file << ch;
    }

    file.close();

    system("pause");
}