#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{

    /*
    ---------------------------- Ієрархія потоків вводу / виводу в с++ ----------------------------

    // ios
    Є такий файл ios. В ньому є клас ios_base. В ньому находяться основні
    методи і константи, які мають підтримувати всі потоки вводу/виводу.
    Наприклад тут ви можете зустріти маніпулятори boolalpha, dec,
    defaultfloat, fixed і інші.

    Також ви можете зутріти сутність std::ios, яка являється всевдонімом
    до std::basic_ios<char, char_trains<char>>.

    // ostream
    Наступний файл ostream (output stream). В ньому уже находиться
    клас basic_stream. Цей клас наслідується від калсу ios, а отже має
    всі ті самі маніпулятори і методи на подобі clear, fill і інших. Але
    цей клас відповідає тепер за конкретний потік ВИВОДУ. Тобто його треба
    викиорстовувати, щоб ВИВОДИТИ інформацію звідкись. Цей клас уже
    добавляє свої маніпулятори, такі як я ednl, ends та flush, а також
    безліч перезавантажень для оператора <<.

    Ви часто використовуєте std::cout? Так от, cout - це глобальний об'єкт класу iostream.
    Він створюється завдяки псевдоніму std::ostream = basic_ostream<char, char_trains<char>>;

    // istream
    Наступний файл istream (input stream). В ньому уже находиться
    клас basic_stream. Тут ситуація аналогічна: він також наслідується
    від калсу ios, а отже має всі ті самі маніпулятори і методи.
    Але цей клас відповідає тепер за конкретний потік ВВОДУ. Тобто його треба
    викиорстовувати, щоб ВВОДИТИ інформацію кудись. Цей клас уже
    добавляє свої маніпулятори, такі як я ws, а також безліч перезавантажень
    для оператора >>.

    Ви часто використовуєте std::cin? Так от, cout - це глобальний об'єкт класу iostream.
    Він створюється завдяки псевдоніму std::istream = basic_isteam<char, char_trains<char>>;

    Також у файлі isteam находиться клас basic_iostream, який очевидно наслідується від
    двох класів basic_istream та basic_ostream. Ну і очевидно, що він в собі
    комбінує ввід і вивід інформацію

    //iostream
    Як я вже писав, глобальні об'єкти std::cin та std::cout створються в файлі iostream.
    Цей файл який зазвичай підключється першим до консольних проектів. Від підклює всі
    попередні файли а також безліч інших. Саме тому його і підключаємо.

    В цьому файлі також є інші об'єкти, такі як std::cerr і std::clog.
    Чим вони відрізняються від std::cout?

    1. std::cout - це стандартний потів виводу, який використовується для нормального
    виводу інформації у програмі. Він буферизується, що означає, що дані зберігаються
    в пам'яті перед їх надсиланням в консоль/термінал. Це може покращити продуктивність,
    оскільки кілька операторів виводу можна об'єднати в одну операцію.

    2. std::cerr - це стандартний потік виводу помилок, який використовується для
    повідомлень про помилки та діагностичного виведення. Він не буферизується, що
    означає, що дані надсилаються безпосередньо до косолі, як тільки вони записуються.
    Це гаранує, що повідомлення про помикли відображає миттєво та не втрачається
    в разі збою програми.

    3. std::clog - це стандартний потік логування, який використовується для реєстрації
    повідомлень. Він беферизується як std::cout, але зазвичай використовується для
    реєстрації інформації, яка не є критичною для роботи програми.

    -----------------------------------------------------------------------------------------------

    В ієрархії потоків вводу/виводу є ще файл fstream (file stream). В цьому файлі
    находиться зразу 3 класи:
    1. ifstream (input file stream)  - клас, який відповідає за ЗЧИТУВАННЯ даних з файлу.
    2. ofstream (output file stream) - клас, який відповідає за ЗАПИС даних у файл.
    3. fstream (file stream)         - клас, який є об'єднанням двох класів ifstream та ofstream

    клас ifstream наслідується від basic_istream, а отже має той самий інтерфейс + декілька
    нових методів для роботи конкретно з файлами (наприклад open, is_open).

    Аналогічно з класом ofstream. Він наслідується від basic_ostream.

    Клас fstream наслідується від класу basic_iostream і комбінує в собі ввід та вивід
    інформації з файлу чи у файл.

    -------------------------------------- Як поламати потік? -------------------------------------

    в кожному класі з нашої ієрархії є поле, яке називається _Mystate. Воно має тип int і відповідає
    за стан потоку. Стан може бути добрим (полагодженим / з яким можна працювати) або поганим (який
    треба або полагодити або перестати працювати). В ньому записується одне з 4 можливих значень:
    1. std::ios::goodbit - відповідає за те, що поток працює нормально. Встановлюється
                           за замовчуванням при створенні потокую
    2. std::ios::eofbit  - встановлються тоді, коли при зчитуванні даних з потоку ми зустріли кінець
                           файлу (EOF - End Of File)
                           Наприклад коли потік не може читати чи записувати дані із-за тимчасового
                           збою в мережі чи дані не відповідають очікуваному формату.
    3. std::ios::failbit - встановлються тоді, коли відбулася помилка, яку можна виправити.
                           Наприклад коли потік не може читати чи записувати дані із-за тимчасового
                           збою в мережі чи дані не відповідають очікуваному формату.
    4. std::ios::badbit  - встановлюється тоді, коли відбулася помилка, яку не можна виправити.
                           Наприклад коли потік не може зчитувати/записувати дані із-за апаратного
                           збою, чи потік неочікувано закрився.

    Щоб перевірити стан потоку, існують 4 методи: good(), eof(), fail(), bad().
    Вони повертають true, якщо встановлюється один з 4 бітів.  */

    // Ось приклад на перевірку цих бітів:
    {
        /*cout << "Enter a number: ";
        int number;
        cin >> number;

        if(cin.good())
        {
            cout << "Your number = " << number << endl;
        }
        else
        {
            cout << "Oops. Something went wrong" << endl;

            if(cin.bad())
            {
                cout << "cin.bad() == true" << endl;
            }
            else if(cin.fail())
            {
                cout << "cin.fail() == true" << endl;
            }
            else if(cin.eof())
            {
                cout << "cin.eof() == true" << endl;
            }
        }*/
    }


    /*
    ------------------------------------- Як полагодити потік? ------------------------------------

    1. Якщо стан потоку має значення std::ios::eofbit, то в такому випадку
       потік дійшов кінця запису/зчитування і вам треба його закрити та заново
       відкрити. Робиться це методом close та open. Це відбувається зазвичай
       при роботі з файлами

    2. Якщо стан потоку має значення std::ios::fail, то в такому випадку ви
       можете спочатку викликати метод clear(), який встановлює стан потоку заново
       в значення std::ios::goodbit, а потім почистити потік методом inignore(),
       який витягне звідти символи, але не запише їх в потік. Після цього
       можна продовжити роботу

    3. Якщо стан потоку має значення std::ios::bad, то в такому випадку ви
       можете викликати метод clear(), але це не гарантує, що потік зможе спокійно
       працювати далі, так як такий біт встановлюється у "неправильних" ситуаціях.
       Тут рекомендується більше не працювати з потоком, а відкрити новий.

    */

    //Ось приклад на полагодження потоку:
    {
        /*cout << "Enter a number: ";
        int number;
        cin >> number;

        while(!cin.good() && cin.fail())
        {
            cin.clear();
            cout << "You entered incorrect value. Enter only one integer number." << endl;
            cin.ignore(LLONG_MAX, '\n');

            cout << "Your number = " << number << endl;
            cin >> number;
        }*/
    }

    /*
    ------------------------------------- Режим відкриття файлу --------------------------------------

    1. std::ios::in     - відкрити файл для читання. Якщо файлне існує - потік "ламається".
    2. std::ios::out    - відкрити файл для запису. Якщо файл існує - його вміст очищається.
                          Якщо не існує - файл створюється
    3. std::ios::app    - відкрити файл для запису в кінець. Якщо файлне існує - файл створюється.
    4. std::ios::trunc  - використовується з режимом out. Заставляє файл очиститися, якщо в ньому
                          щось було до відкриття.
    5. std::ios::ate    - використовується з іншими режимами. Переміщає вказівник зчитування
                          в кінець файлу.
    6. std::ios::binary - відкрити фалй у бінарному режимі. Використовується з іншими режимами.

    ------------------------------------ Позиція у файлі та EOF --------------------------------------

    При роботі з файлами інструментами мови с++ все працює так само, як і з інструментами мови С.
    При з'єднанні файлового потоку з файлом у файлі появляється вказівник на конкретний елемент
    у файлі. Будемо називати його позиція у файлі. Якщо ви відкрили цей файл для читання завдяки
    режиму std::ios::in, то позиція указує на нульовий елемент. Аналогічно з std::ios::out.
    При зчитуванні/записі інформації у файл ця позиція переміщується завжди вперед, допокине зустріне
    спеціальний символ, який символізує кінець файлу. Він називається EOF (End Of File). Тому часто
    при зчитуванні інформації з файлу треба писати код, в якому зчитування має відбуватися до цього
    символу.
    */

    //---------------------------------- Як зчитати текст з файлу? -----------------------------------

    //Текст можна читати з файлу такими способами:

    //1. Посимвольно.
    {
        /*string filename = "MyTextFile.txt";
        ifstream fileStream(filename);

        if(!fileStream.is_open())
        {
            cerr << "Couldn't open the file" << endl;
            return 1;
        }

        char character;
        while(fileStream.get(character))
        {
            cout << character;
        }

        if(fileStream.eof())
        {
            cout << "\n\nWe reached the end of foile/" << endl;
        }*/
    }

    //2. Порядково
    {
        /*string filename = "MyTextFile.txt";
        ifstream fileStream(filename);

        if(!fileStream.is_open())
        {
            cerr << "Couldn't open the file" << endl;
            return 1;
        }

        string line;
        while(getline(fileStream, line, '\r'))
        {
            cout << line;
        }

        if(fileStream.eof())
        {
            cout << "\n\nWe reached the end of foile/" << endl;
        }*/
    }

    //3. Побайтово
    {
        /*string filename = "MyTextFile.txt";
        ifstream fileStream(filename, ios::binary);

        if(!fileStream.is_open())
        {
            cerr << "Couldn't open the file" << endl;
            return 1;
        }

        // Визначити кількість байтів у файлі:
        fileStream.seekg(0, std::ios::end);
        size_t fileSize = fileStream.tellg();
        fileStream.seekg(0, std::ios::beg);

        // Створити тимчасовий масив
        size_t bufferLenght = fileSize + 1;
        char* buffer = new char[bufferLenght];
        fileStream.read(buffer, fileSize);
        buffer[fileSize] = '\0';

        if(fileStream.gcount() != fileSize)
        {
            cerr << "Error reading file" << endl;
            return 1;
        }

        cout << buffer;

        delete[] buffer;*/
    }

    //4. Завдяки перезавантаженому оператору >> так само, як ви це робиться з ctd<<cin
    {
        /*string filename = "MyTextFile.txt";
        ifstream fileStream(filename);

        if(!fileStream.is_open())
        {
            cerr << "Couldn't open the file" << endl;
            return 1;
        }

        string word;
        while(fileStream >> word)
        {
            cout << word << " ";
        }*/
    }

    //---------------------------------- Як записати текст у файл? -----------------------------------

    //Текст можна записати у файлу такими способами:
    
    //1. Посимвольно
    {
        /*string filename = "MyTextFile.txt";
        ofstream fileStream(filename);

        if(!fileStream.is_open())
        {
            cerr << "Couldn't open the file" << endl;
            return 1;
        }
        
        cout << "Enter some text: ";
        string text;
        getline(cin, text);

        size_t textLenght = text.length();
        for(size_t i = 0; i < textLenght; i++)
        {
            fileStream.put(text[i]);
        }*/
    }

    //2.  Завдяки перезавантаженому оператору << так само, як ви це робиться з ctd<<cout
    {
        /*string filename = "MyTextFile.txt";
        ofstream fileStream(filename);

        if(!fileStream.is_open())
        {
            cerr << "Couldn't open the file" << endl;
            return 1;
        }

        string line1 = "Today is a good day!";
        string line2 = "Because I am learning c++";

        fileStream << line1 << '\n' << line2 << '\n' << 1000;*/
    }

    //3. Побайтово
    {
       /* string filename = "MyTextFile.txt";
        ofstream fileStream(filename, ios::binary);

        if(!fileStream.is_open())
        {
            cerr << "Couldn't open the file" << endl;
            return 1;
        }

        string line = "Some line of text";
        fileStream.write(line.c_str(), line.length());*/
    }
    
    //-------------------------------- Як записувати НЕ текст у файл? --------------------------------

    {
        /*// Візьмемо декілька данихрізних типів:
        int variable = 10;
        double array[3] = {1.123, 2.456, 3.789};
        
        class Point
        {
        private:
            float x;
            float y;

        public:
            Point(float x = 0, float y = 0)
                : x(x), y(y)
            { }
        };
    
        Point myPoint(12.3f, 54.6f);

        vector<int> myVector = {1, 2, 3, 4, 5};

        // Всі вони записуються завдяки методу write. Все що треба зрозуміти - це
        // те, що цей метод записує дані в байтах, тобто йому треба відправляти адресу 
        // типу char (так як розмір типу char відповідає за розмір одного байту) 
        //
        // Тому вам треба перетворювати ваші дані в адресу на цей тип і відправляти
        // цьому методу.
        // 
        // Спробуємо створити файл, в який запишемо всі ці дані, послідовно.
        // 
        
        string filename = "MyData.bin";
        ofstream fileStream(filename, ios::binary);

        if(fileStream.is_open())
        {
            cerr << "Couldn't open the file" << endl;
            return 1;
        }

        fileStream.write(reinterpret_cast<const char*>(&variable), sizeof(variable));

        fileStream.write(reinterpret_cast<const char*>(&array), sizeof(double) * 3);

        fileStream.write(reinterpret_cast<const char*>(&myPoint), sizeof(Point));
        
        fileStream.write(reinterpret_cast<const char*>(myVector.data()), sizeof(int) * myVector.size());*/
    }

    //---------------------------------- Як зчитати НЕ текст з файл? ---------------------------------

    {
        /*// Візьмемо декілька данихрізних типів:
        int variable;
        double array[3];

        class Point
        {
        private:
            float x;
            float y;

        public:
            Point(float x = 0, float y = 0)
                : x(x), y(y)
            { }
            float X() { return x; }
            float Y() { return y; }
        };

        Point myPoint;

        vector<int> myVector(5);

        // А тепер завдяки методу read ми зчитуємо ці дані в такому ж порядку, як і записували.
        // Порядок запису потрібно знати
        
        string filename = "MyData.bin";
        ifstream fileStream(filename, ios::binary);

        if(fileStream.is_open())
        {
            cerr << "Couldn't open the file" << endl;
            return 1;
        }

        fileStream.read(reinterpret_cast<char*>(&variable), sizeof(variable));

        fileStream.read(reinterpret_cast<char*>(&array), sizeof(double) * 3);

        fileStream.read(reinterpret_cast<char*>(&myPoint), sizeof(Point));

        fileStream.read(reinterpret_cast<char*>(myVector.data()), sizeof(int) * myVector.size());
        
        cout << "variable = " << variable << endl;

        cout << "array = ";
        for(size_t i = 0; i < 3; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
        
        cout << "Point: [x = " << myPoint.X() << ", y = " << myPoint.Y() << "]" << endl;

        cout << "vector = ";
        for(auto val : myVector)
        {
            cout << val << " ";
        }
        cout << endl;
        */
    }

    //----------------------------------- Як закрити файловий потік ----------------------------------
    
    {
        /*// Якщо ви працювали з потоком і більше не плануєте з ним працювати до кінця його
        // області видимості, ви можете закрити його. Закрити означає відв'язати поток
        // від файлу, щоб файлом могли користуватися інші потоки. 
        // Для цього використовуйте метод close
        
        // Відкрити потік
        string filename = "SomeFile";
        ifstream fileStream(filename);

        // ... Працювали з потоком ...

        // Закрили потік
        fileStream.close();

        // Також ви маєте знати, що класи std::ifstream, std::ofstream та std::fstream
        // мають деструктор, який автоматично викликає close*/
    }
    
    //--------------------------- Як дізнатися позицію файлу та змінити її ---------------------------

    {
        // Задача: 
        // Є файл Numbers.bin, в якому знаходиться невідома кількість чисел типу int.
        // Кількість цих чисел - це число, яке находиться на першому місці у файлі.
        // Ви маєте найти у цьому масиві число 20 і замітити його на 40.
        // Інший вміст файлу міняти заборонено
        
        // Як вирішити цю задачу? Для початку зчитаємо всю інформацію з файлу

        string filename = "Numbers.bin";
        ifstream fileStream(filename);

        if(fileStream.is_open())
        {
            cerr << "Couldn't open the file" << endl;
            return 1;
        }

        int size;
        fileStream.read(reinterpret_cast<char*>(&size), sizeof(int));

        vector<int> numbers(size);
        
        while(!fileStream.eof())
        {
            int number;
            fileStream.read(reinterpret_cast<char*>(&number), sizeof(int));

            numbers.push_back(number);
        }
        fileStream.close();
        
        // Інформація отримана. Тепер найдемо індекс першої числа 20
        bool isNumberFound = false;
        size_t findIndex;
        for(size_t i = 0; i < numbers.size(); i++)
        {
            if(numbers[i] == 20)
            {
                isNumberFound = true;
                findIndex = i;
                break;
            }
        }

        // Якщо число найдене - відкриваємо файл, але лише для запису
        // не видаляючи інформацію з файлу.
        if(isNumberFound)
        {
            ofstream fileStream(filename, ios::app | ios::binary);
            if(fileStream.is_open())
            {
                cerr << "Couldn't open the file" << endl;
                return 1;
            }
            // Використовуємо ios::app щоб не видаляти вміст файлу, але тепер
            // позиція у файлі вказує на кінець файлу, нам потрібно перемістити
            // його на почато файлу. Для цього виокристовуємо seekp.

            size_t value20Pos = sizeof(int) + sizeof(int) * findIndex;
            fileStream.seekp(ios::beg, value20Pos);
            int newNumber = 40;
            fileStream.write(reinterpret_cast<const char*>(&newNumber), sizeof(int));

            fileStream.close();

            // Задача вирішена
        }
    }

    return 0;
}
