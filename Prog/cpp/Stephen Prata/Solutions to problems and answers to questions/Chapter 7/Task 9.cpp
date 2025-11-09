#include <iostream>
#include <string>

using namespace std;

struct student
{
    string fullname;
    string hobby;
    int ooplevel;
};

int  getinfo(student pa[], int arrSize);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);

int main()
{
    string name;
    getline(cin, name);
    cout << name;

    cout << "Введіть розмір калсу: ";
    int class_size;
    while (!(cin >> class_size))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Дозволено лише цифри! Спробуйте ще раз: ";
    }
    cin.get();

    student* ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);

    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);

    delete[] ptr_stu;

    cout << "Done.\n";

    return 0;
}

int getinfo(student pa[], int arrSize)
{
    int i;
    for (i = 0; i < arrSize; ++i)
    {
        cout << "\nВведіть повне ім'я: ";
        getline(cin, pa[i].fullname);

        if (pa[i].fullname == "")
            break;

        cout << "Введіть хоббі: ";
        getline(cin, pa[i].hobby);

        cout << "Введіть ООП рівень: ";
        while (!(cin >> pa[i].ooplevel))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Дозволено лише цифри! Спробуйте ще раз: ";
        }
        cin.get();
    }
    cout << endl;
    return i;
}

void display1(student st)
{
    cout << "Повне ім'я: " << st.fullname << std::endl
        << "Хоббі: " << st.hobby << std::endl
        << "ООП рівень: " << st.ooplevel << std::endl
        << std::endl;
}

void display2(const student* ps)
{
    cout << "Повне ім'я: " << ps->fullname << endl
        << "Хоббі: " << ps->hobby << endl
        << "ООП рівень: " << ps->ooplevel << endl
        << endl;
}

void display3(const student pa[], int n)
{
    for (int i = 0; i < n; ++i)
        display1(pa[i]);
}