#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    /* Цей код запише введені дані в mat.dat та pet.dat текстові файли

    // В нас мають бути два вектори met та pet з введеними даними

    // Відкрити файл для запису
    string filename = "mat.dat";
    ofstream fout(filename);

    // Перевірка, чи файл успішно відкритий
    if(!fout.is_open())
    {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return 1; // Помилка відкриття файлу
    }
    for(const auto& str : met)
    {
        fout << str << '\n';
    }
    fout.close();

    filename = "pet.dat";
    fout.open(filename);

    // Перевірка, чи файл успішно відкритий
    if(!fout.is_open())
    {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return 1; // Помилка відкриття файлу
    }
    for(const auto& str : pet)
    {
        fout << str << '\n';
    }
    fout.close();*/

    vector<string> met, pet, metAndPet;

    string filename = "mat.dat"; 
    ifstream fin(filename);

    string words;
    while(getline(fin, words))
    {
        met.push_back(words);
    }
    fin.close();

    filename = "pet.dat";
    fin.open(filename);

    while(getline(fin, words))
    {
        pet.push_back(words);
    }
    fin.close();

    sort(met.begin(), met.end());
    sort(pet.begin(), pet.end());

    merge(met.begin(), met.end(), pet.begin(), pet.end(), back_inserter(metAndPet));
    metAndPet.erase(unique(metAndPet.begin(), metAndPet.end()), metAndPet.end());

    filename = "MatAndPet.dat";
    ofstream fout(filename);

    for(auto name : metAndPet)
    {
        fout << name << endl;
    }

    return 0;
}