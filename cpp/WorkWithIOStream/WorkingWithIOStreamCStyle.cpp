#include <iostream>
#include <string>
#include <direct.h> // для _mkdir() та _wmkdir()
#include <cerrno>

using namespace std;

void ShowErrorMessage()
{
    cerr << "Error code: " << errno << endl;
    cerr << "Message: ";

    //cerr << std::strerror(errno) << endl;
    if(errno == EEXIST)
    {
        cerr << "Folder already exists" << endl;
    }
    else if(errno == ENOENT)
    {
        cerr << "Path in incorrect" << endl;

    }
    cerr << endl;
}

struct Person
{
    char name[50] {};
    int age;
};

void CreateFolder()
{
    const char* folderOneName = R"(D:\1\123\My folder)";
    const wchar_t* folderTwoName = L"Моя папка";

    int creationResult;

    creationResult = _mkdir(folderOneName);

    if(creationResult != 0)
    {
        cerr << "Error! Could not create folder." << endl;
        ShowErrorMessage();
    }


    creationResult = _wmkdir(folderTwoName);
    if(creationResult != 0)
    {
        cerr << "Error! Could not create folder." << endl;
        ShowErrorMessage();
    }

}
void RenameFolder()
{
    const char* oldName = "Filder";
    const char* newName = "Folder";
    
    int renamingResult = rename(oldName, newName);
    if(renamingResult != 0)
    {
        cout << "Folder could not been renamed." << endl;
    }

}
void DeleteFolder()
{
    const char* folderPath = "empty";
    string removeCommand = "rmdir";
    removeCommand += folderPath;

    // system("rmdir empty");

    int removingResult = system(removeCommand.c_str());
    if(removingResult != 0)
    {
        cout << "Folder could not been removed." << endl;
    }
}

void CreateFile() 
{
    // Функція створення/відкриття файлів fopen():
    // Прототип:            FILE* fopen(const char* filename, const char* mode)
    // Параметри:           dilename - шлях до файлу разом з назвою файлу та розширенням
    //                      mode     - режим відкриття файлу
    // Повертаюче значення: вказівник на відритий файл. nullptr - файл не можливо відкрити/створити.
    //
    // Замітка: для типу wchar_t існує функція _wfopen()
    //
    // FILE - це структура, яка містить лише одне поле - вказівник на файл.
    //
    // УВАГА: Компілятор Visual Studio за замовчуванням не дозволяє використовувати  
    //        функцію fopen(), бо вважає її застарілою. Він рекомендує використовувати  
    //        натомість функцію fopen_s().
    //
    // Функція створення/відкриття файлів fopen_s():
    // Прототип:            errno_t fopen_s(FILE* stream, const char* filename, const char* mode)
    // Параметри:           stream   - адреса на вказівник типу File, до якого прив'яжеться файл
    //                      filename - шлях до файлу разом з назвою файлу та розширення
    //                      mode     - режим відкриття файлу
    // Повертаюче значення: 0 - файл успішно відкритий, значення EINVAL в інших випадках.
    //
    // Замітка: для типу wchar_t існує функція _wfopen_s()
    //
    // Режими відкриття файлу, параметр mode: 
    // "r"  - відкриває файл тільки для читання. Якщо файл не існує чи його неможливо найти,
    //        повертається nullptr
    // "w"  - відкриває пустий файл для запису. Якщо файл існує, то його вміст видаляється.
    // "a"  - відкриває файл для запису в його кінець. Створює файл, якщо його не існує.
    // "r+" - відкриває для читання і для запису. Файл має існувати.
    // "w+" - відкриває пустий файл для читання і для запису. Якщо файл існує,
    //        то його вміст видаляється.
    // "a+" - відкриває файл для читання і для запису в кінець. Створює файл якщо, він не існує.
    //  
    // b - binary. Якщо працюємо з бінарними файлами то додаємо b до тих режимів що є вище.
    //     Наприклад: "rb", "rb+" тощо.
    // 
    // Варіант відкриття через fopen():
    // FILE* file1;
    // file1 = fopen("sdaagf.txt", "r"); 
    // if(file1 == nullptr)
    // {
    //      cerr << "File could not been opened << endl;
    // }
    //    
    // Варіант відкриття через fopen_s():
    // FILE* file2;
    // errno_t openingResult fopen_s(&file2, "sdaagf.txt", "r"); 
    // if(errno_t != 0)
    // {
    //      cerr << "File could not been opened << endl;
    // }
    //
}
void DeleteFile()
{
    const char* filename = "MyFolderForDelete.txt";
    int deleteResult = remove(filename);

    if(deleteResult != 0)
    {
        cout << "Folder could not been deleted." << endl;
    }
}
void CloseFile()
{
    // Відкрили файл і з'єднали з потоком.
    const char* filename = "SomeFile.txt";
    FILE* file;
    fopen_s(&file, filename, "wb");

    // -------------------
    // Працювати з файлом.
    // -------------------

    // Закрити файл, від'єднати потік.
    fclose(file); // не забути написати!
}
void ReadFromFile()
{
    // Є декілька функцій для читання інформації з файлу:
    //
    // 1. Прототип:            int fgetc(FILE* stream)
    //    Опис:                читає і повертає наступний символ з потоку.
    //    Параметри:           stream - потік на файл.
    //    Повертаючі значення: зчитаний символ, якщо вийшло зчитати.
    //                         Інакше EOF.
    // 
    // 2. Прототип:            char* fgets(char* str, int count, FILE* stream)   
    //    Опис:                читає максимум (count - 1) символів із потокуі зберігає
    //                         їх в масиві str. Зчитування зупиняється, якщо зустрічається
    //                         символ \n або кінець файлу. Дописує нуль-символ в кінець
    //                         зчитаної послідовності.
    //    Параметри:           str    - масив, куди записуються символи
    //                         count  - розмір масиву str 
    //                         stream - потік на файл.
    //    Повертаюче значення: str, якщо успішно вдалося зчитати послідовність.
    //                         nullptr, якщо виникла проблема.                    
    //
    // 3. Прототип             size_t fread(void* iuffer, size_t size, size_t count, FILE* stream)
    //    Опис:                зчитує максимум count байтів в казаний buffer із потоку stream
    //    Параметри:           buffer - вказівник, куди запишуться байти
    //                         size    - розмір кожного елементу послідовності даних, які треба зчитати
    //                         count   - кількість байтів для зчитування 
    //                         stream  - потік на файл
    //    Повертаюче значення: кількість успішно зчитаних байтів.
    
    // Приклад викоирстання функції fgetc():
    /*{
        const char* filename = "Text.txt";
        FILE* fileStream;
        fopen_s(&fileStream, filename, "r");
        if(fileStream == nullptr)
        {
            cerr << "Could not open the file" << endl;
            return;
        }

        int character = fgetc(fileStream);
        while(character != EOF)
        {
            cout << static_cast<char>(character);
            character = fgetc(fileStream);
        }
        fclose(fileStream);
    }*/

    // Приклад викоирстання функції fgets():
    /* {
        const char* filename = "Text.txt";
        FILE* fileStream;
        fopen_s(&fileStream, filename, "r");
        if(fileStream == nullptr)
        {
            cerr << "Could not open the file" << endl;
            return;
        }

        const size_t SIZE = 100;
        char string[SIZE] {};
    
        while(fgets(string, SIZE, fileStream) != nullptr)
        {
            cout << string;
        }

        fclose(fileStream);
    }*/

    // Приклад викоирстання функції fgetc():   
    /* {
        // Створюємо дані з якими будемо працювати
        int intVariable = 10;
        const size_t SIZE = 3;
        char charArray[SIZE] = {'A', 'B', 'C'};
        Person mihail {"Mihail", 19};

        // Спочатку запишемо дані у файл:

        FILE* fileStream {};
        const char* filename = "Data.bin";
        
        // Перевірямо чи файл уже існує
        if(fopen_s(&fileStream, filename, "rb") != 0)
        {
            // файл не існу
            fopen_s(&fileStream, filename, "ab");
        } 
        else 
        {
           // файл існує
           fclose(fileStream);
           fopen_s(&fileStream, filename, "wb");
        }

        if(fileStream != nullptr)
        {
            fwrite(&intVariable, sizeof(int), 1, fileStream);
            fwrite(&charArray, sizeof(char), SIZE, fileStream);
            fwrite(&mihail, sizeof(Person), 1, fileStream);

            fclose(fileStream);
        }

        // Обнулемо дані, щоб потім перевірити чи спрацює читання з файлу
        intVariable = 0;
        charArray[0] = '\n';
        mihail.age = 0;
        mihail.name[0] = '\n';

        // Тепер зчитуємо дані з файлу для перевірки.

        fopen_s(&fileStream, filename, "rb");
        if(fileStream != nullptr) 
        {
            fread(&intVariable, sizeof(int), 1, fileStream);
            fread(&charArray, sizeof(char), SIZE, fileStream);
            fread(&mihail, sizeof(Person), 1, fileStream);

            fclose(fileStream);
        }
        
        // Перевіряємо чи зчиталося добре
        
        cout << "intVariable = " << intVariable << endl;
        
        cout << "charArreay = [ ";
        for(size_t i = 0; i < SIZE; i++)
        {
            cout << charArray[i] << " ";
        }
        cout << "]" << endl;
    
        cout << "mihail.name = " << mihail.name << endl;
        cout << "mihail.age = "  << mihail.age  << endl;
    }*/
}
void WriteIntoFile()
{
    // Є декілька функцій для запису інформації у файл:
    //
    // 1. Прототип:            int fputc(int ch, FILE* stream)
    //    Опис:                записує символ ch в файловий потік stream
    //    Параметри:           ch     - символ
    //                         stream - потік, зв'язаний з файлом
    //    Повертаючі значення: якщо символ успішно записався - повертає символ.
    //                         Інакше EOF.
    // 
    // 2. Прототип:            char* fputs(const char* str, FILE* stream)   
    //    Опис:                записує рядок str в файловий потік stream
    //    Параметри:           str    - рядок
    //                         stream - потік, зв'язаний з файлом
    //    Повертаюче значення: якщо рядок успішно записався - повертає ненульове значення.
    //                         Інакше EOF.  
    //
    // 3. Прототип             size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream)
    //    Опис:                записує дані, на які вказує buffer, в файловий потік stream
    //    Параметри:           buffer  - вказівник на да дані які треба записати
    //                         size    - розмір кожного елементу даних, які треба записати
    //                         count   - кількість елементів даних, які треба записати 
    //                         stream  - потік, зв'язаний з файлом
    //    Повертаюче значення: Кількість об'єктів, які записалися успішно.
    //                         Якщо це значення менше за count - щось пішло не так.

    // Приклад використання fputc()
    {
        FILE* fileStream = nullptr;
        const char* filename = "Characters.txt";
        
        fopen_s(&fileStream, filename, "w");
        if(fileStream != nullptr)
        {
            fputs("My name is ", fileStream);
            fputs("Mihail\n", fileStream);
            fputs("And I am trying to put some string into file", fileStream);

            fclose(fileStream);
        }
    }

    // Приклад використання fwrite()
    {
        FILE* fileStream = nullptr;
        const char* filename = "Numbers.txt";

        fopen_s(&fileStream, filename, "w");
        if(fileStream != nullptr)
        {
            const size_t SIZE = 4;
            int numbers[SIZE] = {1, 2, 3, 4};


            fwrite(numbers, sizeof(int), 4, fileStream);

            fclose(fileStream);
        }
    }
}

void FilePosition()
{
    // Оскільки у файла є вказівник на наступні символи для зчитування, то ми можемо
    // працювати з ними. Наприклад коли ми використовуємо функції для читання чи запису,
    // то після проведених операцій ці функції переміщують ці вказівники далі.
    // 
    // Бувають ситуації, коли нам треба знати місцезнаходження цих вказівників, або
    // коли нам треба перемістити ці вказівники назад чи вперед.
    // 
    // Для роботи з вказівниками є наступні функції:
    // 1. long ftell   (FILE* stream)                          - повертає позицію файлового вказівника 
    // 2. int  fseek   (FILE* stream, long offset, int origin) - встановлює позицію файлового вказівника
    // 3. int  fgetpos (FILE* stream, fpos_t* pos)             - запису позицію файлового вказівника в pos.
    // 4. int  fsetpos (FILE* stream, const fpo s_t* pos)       - переписує позицію файлового вказівника з pos.
    // 5. void rewind  (FILE* stream)                          - вертає позицію файлового вказівника на початок файлу.
    //
    // Приклад: є файл з текстовими даними. Найти всі букви "а" і замінити їх на букви "А". 
    {
        FILE* fileStream = nullptr;
        const char* filename = "Good text.txt";

        fopen_s(&fileStream, filename, "r+");
        if(fileStream != nullptr)
        {
            int character;
            while((character = fgetc(fileStream)) != EOF)
            {
                if(character == 'a')
                {
                    fseek(fileStream, -1, SEEK_CUR);
                    fputs("A", fileStream);
                    fseek(fileStream, 1, SEEK_CUR);
                }
            }

            fclose(fileStream)
        }
    }
}
int main()
{
    return 0;
}
