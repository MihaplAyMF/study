#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
#include "emp.h"

using namespace std;
namespace kind
{
    enum kind
    {
        Abstr_emp,
        Employee,
        Manager,
        Fink, 
        HighFink  
    };
}

int main()
{
    vector<std::unique_ptr<Abstr_emp>> pc;
    string filename = "MyData.bin";
    ifstream fin(filename, ios::app | ios::binary);
    int variable, type; 

    if(fin.is_open())
    {
        // Якщо дані вже є у файлі записуємо їх у вектор та виводимо 

        fin.read(reinterpret_cast<char*>(&variable), sizeof(int));


        if(variable > 0 && variable < 10)
        {
            cout << "The list has " << variable << "/10 seats" << endl;

            for(size_t i = 0; i < variable; i++)
            {
                fin.read(reinterpret_cast<char*>(&type), sizeof(int));
                switch(type)
                {
                case kind::Abstr_emp:
                {
                    unique_ptr<Abstr_emp> tempEmp = make_unique<Abstr_emp>();
                    tempEmp->ReadFromStream(fin);
                    pc.push_back(move(tempEmp));
                    break;
                }
                case kind::Employee:
                {
                    unique_ptr<Employer> tempEmp = make_unique<Employer>();
                    tempEmp->ReadFromStream(fin);
                    pc.push_back(move(tempEmp));
                    break;
                }
                case kind::Manager:
                {
                    unique_ptr<Manager> tempEmp = make_unique<Manager>();
                    tempEmp->ReadFromStream(fin);
                    pc.push_back(move(tempEmp));
                    break;
                }
                case kind::Fink:
                {
                    unique_ptr<Fink> tempEmp = make_unique<Fink>();
                    tempEmp->ReadFromStream(fin);
                    pc.push_back(move(tempEmp));
                    break;
                }
                case kind::HighFink:
                {
                    unique_ptr<HighFink> tempEmp = make_unique<HighFink>();
                    tempEmp->ReadFromStream(fin);
                    pc.push_back(move(tempEmp));
                    break;
                }
                }
            }
        }
        else
        {
            cout << "The list has 0/10 seats" << endl;
        }
        fin.close();
    }
    else
    {
        cerr << "EROOR1!! File not found" << endl;
        return 1;
    }

    for(const auto& emp : pc)
    {
        emp->ShowAll();
    }


    // Якщо немає даємо можливість ввести
    char input;
    if(pc.size() <= 10)
    {
        cout << "\nPlease choose type(q - quit)" << endl;
        cout << "1. Employer\t2. Manager" << endl;
        cout << "3. Fink    \t4. HighFink" << endl;
        cout << "->";
        cin >> input;
        cin.ignore(LLONG_MAX, '\n');
    }
    else
    {
        cout << "List already full" << endl;
        input = 'q';
    }
  
    while(input != 'q')
    {
        if(pc.size() >= 10)
        {
            cout << "List already full" << endl;
            input = 'q';
        }

        switch (input - '0')
        {
        case 1: 
        {    
            auto employer = std::make_unique<Employer>();
            employer->SetAll();
            pc.push_back(std::move(employer));
            break;
        }
        case 2:
        { 
            auto manager = std::make_unique<Manager>();
            manager->SetAll();
            pc.push_back(std::move(manager));
            break; 
        }
        case 3:
        {
            auto fink = std::make_unique<Fink>();
            fink->SetAll();
            pc.push_back(std::move(fink));
            break;
        }
        case 4:
        {
            auto hughfink = std::make_unique<HighFink>();
            hughfink->SetAll();
            pc.push_back(std::move(hughfink));
            break;
        }
        default:
            cout << "Incorrect input! Plest try again: ";
            cin >> input;
            cin.ignore(LLONG_MAX, '\n');
            continue;
        }

        cout << "\nPlease choose type(q - quit)" << endl;
        cout << "1. Employer\t2. Manager" << endl;
        cout << "3. Fink    \t4. HighFink" << endl;
        cout << "->";
        cin >> input;
        cin.ignore(LLONG_MAX, '\n');
    }

    for(const auto& emp : pc)
    {
        emp->ShowAll();
    }

    ofstream fout(filename);      
    variable = static_cast<int>(pc.size());

    if(fout.is_open())
    {
        fout.write(reinterpret_cast<const char*>(&variable), sizeof(int));

        for(const auto& emp : pc)
        {
            emp->WriteToStream(fout);
        }

        fout.close();
    }
    else
    {
        cerr << "EROOR2!! File not found" << endl;
        return 1;
    }

    return 0;
}
