#include <iostream>
#include <vector>

using namespace std;

/* --- VECTOR --- */

class Person
{
public:
	Person() { cout << "Constructor" << endl; }
	~Person() { cout << "Destructor" << endl; }
};

#pragma region PrototypeMethod
void Show(const vector<int>& vector);
void ShowVec(const vector<int>& vector);

void Containers();
void AllConstructor();
void Destructor();
void Methods();
void ONotation();

#pragma endregion PrototypesMethods

int main()
{
	//Containers();
	//AllConstructor();
	//Destructor();
	Methods();
	
	return 0;
}

#pragma region Methods

void Show(const vector<int>& vector)
{
	cout << endl << "--- VECTOR INFO ---" << endl;
	cout << " Elements: ";
	if(vector.empty())
	{
		cout << "none";
	}
	else
	{
		for(size_t i = 0; i < vector.size(); i++)
		{
			cout << vector[i] << " ";
		}
	}
	cout << endl;
	cout << " Size: " << vector.size() << endl;
	cout << " Capacity: " << vector.capacity() << endl;
	cout << "-------------------" << endl;
}

void ShowVec(const vector<int>& vector)
{
	for(auto iter = vector.begin(); iter != vector.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

}

void Containers()
{
	/*
		В бібліотеці STL є багато контейнерів. 
		Вони поділяються на: 

		Послідовні контейнери (Sequence containers):
		1. vector
		2. list
		3. forward_list
		4. deque
		5. array

		Асоціативні контейнери (Associative containers):
		6. set
		7. map 
		8. multiset
		9. multymap

		Невпорядтокані асоціативні контейнери (Unordered associative containers):
		10. unordered_set
		11. nordered_map
		12. nordered_multiset
		13. nordered_multymap

		Адаптери контейнерів (Conteiner adapptors):
		14. stack
		15. queue
		16. priority_queue

		Бітовий контейре (Bit container):
		17. bitset 
	*/
}

void AllConstructor()
{
	cout << "--- CONSTRUCTOR ---" << endl;
	// 1. Конструктор за замовчуванням
	vector<int> v1;
	Show(v1);

	// 2. Конструктор за замовчуванням, який приймає користувацький алокатор
	allocator<int> myAllocator; // Я поки не знаю що таке алокатор
	vector<int> v2(myAllocator);
	Show(v2);

	// 3. Коструктор, приймаючий std::initializer_list
	vector<int> v3 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Show(v3);

	// 4. Конструктор копії
	vector<int> v4(v3);
	Show(v4);

	// 5. Констуктор переміщення
	vector<int> v5(move(v4));
	Show(v4); // Як ми можемо бачити він пустий
	Show(v5); 

	// 6. Констуктор, який приймає кількість елементів
	vector<int> v6(10);
	Show(v6);
	
	// 7. Констуктор, який приймає кількість елементів і їх значення
	vector<int> v7(3, 100);
	Show(v7);
	
	// 8. Констуктор, який примає 2 ітератори	
	vector<int> v8(v5.begin(), v5.begin() + 4);
	Show(v8);
}

void Destructor()
{
	cout << "--- DESTRUCTOR ----" << endl;
	
	// У класі vector є деструктор, в якому вся пам'ять під виділені елементи на кучі
	// автоматично змільняється/видаляється. Вам не потрібно викликати деструктор явно.
	
	vector<Person> v1(2); // Як тільки ми вийдемо за локальну видимість, деструктор викличиться
	// v1.~vector(); // Викликати його явно не потрібно
}

void Methods()
{
	cout << "----- METHODS -----" << endl;

	vector<int> vector {10, 20, 500, 5, 0}; // Усього 5 елементів

	// 1. front - повертає посилання на перший елемент.
	cout << endl << "------ front ------" << endl;
	cout << "vector[0] = " << vector.front() << endl;
	vector.front() = 100;
	cout << "vector[0] = " << vector.front() << endl;

	// 2. back - повертає посилання на останній елемент.
	cout << endl << "------ back -------" << endl;
	cout << "vector[4] = " << vector.back() << endl;
	vector.back() = 123;
	cout << "vector[4] = " << vector.back() << endl;

	// 3. data - повертає вказівник на внутрішній масив контейнеру.
	cout << endl << "------ data -------" << endl;
	int* ptr = vector.data();
	cout << "vector[2] = " << vector[2] << endl;
	ptr[2] = -5;
	cout << "vector[2] = " << vector[2] << endl; // або ptr[2];

	// 4. operator[] - повертає оператор на елоемент за заданим індексом.
	cout << endl << "--- operator[] ----" << endl;
	cout << "vector[3] = " << vector[3] << endl;

	// 5. at - повертає посилання на елемент за заданим індексом. Кидає виключення
	//		   типу std::out_of_range, якщо індекст виходить за границі масиву.
	cout << endl << "------- at --------" << endl;
	try
	{
		vector.at(100) = 1000;
	}
	catch(out_of_range& exc)
	{
		cout << exc.what() << endl;
	}

	// 6. get_allocator - повертає алокатор, який прив'язаний до контейнера.
	cout << endl << "-- get_allocator --" << endl;
	auto allocator = vector.get_allocator();
	cout << "Я поки не знаю що таке аллокатори" << endl;

	// 7. operator= 
	cout << endl << "---- operator= ----" << endl;
	vector = {1, 2, 3, 4, 5}; cout << "std::initializer_list" << endl;
	vector = std::vector<int>(10, 1); cout << "copy = " << endl;
	vector = vector; cout << "move = " << endl;

	// 8. assign - дозволяє переписувати вміст вектора новими значеннями.
	//             Схожий на опертор =, але має більше можливостей, бо може приймати
	//			   більше одного параметру.
	cout << endl << "----- assign ------" << endl;
	vector.assign(5, 100); cout << "кількість елементів, значення" << endl;
	vector.assign({1, 2, 3, 4, 5}); cout << "std::initializer_list" << endl;
	vector.assign(vector.cbegin(), vector.cend()); cout << "два ітератори" << endl;

	//vector = {10, 20, 500, 5, 0}; // Повертаємо до початкового значення.

	// 9. begin - повертає ітератор на перший елемент контейнеру. Елемент можна міняти через ітератор.
	cout << endl << "------ begin ------" << endl;
	cout << "*vector.begin() = " << *vector.begin() << endl;
	*vector.begin() = 1000;
	cout << "*vector.begin() = " << *vector.begin() << endl;
	
	// 10. end - повертає ітератор на кінець діапазону елементів. Кінець - це наступний елемент за останнім.
	//			 Простими словами це мітка кінця послідовності елментів. 
	cout << endl << "------- end -------" << endl;
	for(auto iter = vector.begin(); iter != vector.end(); iter++)
	{
		*iter *= 2;
		cout << *iter << " ";
	}
	cout << endl;

	// 11. cbegin - повертає константний ітератор на перший елемент контейнеру. Елемент НЕ можна міняти через ітератор.
	cout << endl << "----- сbegin ------" << endl;
	cout << "*vector.сbegin() = " << *vector.begin() << endl;
	// *vector.begin() = 1000; // НЕ МОЖНА.

	// 12. cend - повертає константний ітератор на кінцевий елемент контейнеру.
	cout << endl << "------ сend -------" << endl;
	for(auto iter = vector.cbegin(); iter != vector.cend(); iter++)
	{
		//*iter *= 2; // НЕ МОЖНА.
		cout << *iter << " ";
	}
	cout << endl;

	// 13. rbegin - повертає обернений ітератор на останній елемент контейнеру. Відмінність від begin наступна:
	//				якщо написати ++ до ітератора, який повертає метод begin, то ітератор переміститься вправо.
	//				Але якщо написати ++ до інетартора, який повертає метод rbegin, то інтератор переміститься вліво.
	cout << endl << "----- rbegin ------" << endl;
	cout << "*vector.rbegin() = " << *vector.rbegin() << endl;


	// 14. rend - та же аналогія як rbegin до begin, тільки до методу end.
	cout << endl << "------ rend -------" << endl; 
	for(auto iter = vector.rbegin(); iter != vector.rend(); iter++)
	{
		*iter -= 100;
		cout << *iter << " ";
	}
	cout << endl;

	// 15. crbegin - константний rbegin.
	cout << endl << "----- rcbegin -----" << endl;
	cout << "*vector.rbegin() = " << *vector.crbegin() << endl; // НЕ можна змінювати
	
	// 16. crend - константний rend.
	cout << endl << "------ crend ------" << endl;
	for(auto iter = vector.crbegin(); iter != vector.crend(); iter++)
	{
		//*iter -= 100; // НЕ можна .
		cout << *iter << " "; 
	}
	cout << endl;
	
	// 17. empty - повертає true якщо контейнер пустий.
	cout << endl << "------ empty ------" << endl;
	cout << "Vector is empty? " << (vector.empty() ? "Yes" : "No") << endl;
	
	// 18. size - повертає розмір вектору (кількість елементів, в яких є значення).
	cout << endl << "------ size -------" << endl;
	cout << "Vector size: " << vector.size() << endl;

	// 19. capacity - повертає ємність вектору (кількість елементів, для яких в динамічній пам'яті виділено місце).
	cout << endl << "---- capacity -----" << endl;
	cout << "Vector capacity: " << vector.capacity() << endl;

	// 20. max_size - повертає максимально можливу кількість елементів.
	cout << endl << "---- max_size -----" << endl;
	cout << "Vector max_size: " << vector.max_size() << endl;
	
	// 21. reserve - збільшує (резервуар) об'єм ємності вектору.
	cout << endl << "----- reserve -----" << endl;
	cout << "Vector capacity: " << vector.capacity() << endl;
	vector.reserve(100); cout << "reserve(100)" << endl;
	cout << "Vector capacity: " << vector.capacity() << endl;

	// 22. shrink_to_fit - зменшує (скоротчує) об'єм ємності вектору до розміру.
	cout << endl << "-- shrink_to_fit --" << endl;
	cout << "Vector capacity: " << vector.capacity() << endl;
	vector.shrink_to_fit(); cout << "shrink_to_fit()" << endl;
	cout << "Vector capacity: " << vector.capacity() << endl;
	
	// 23. clear - очищує вектор, звільняючи пам'ять (викликаючи дестуктори) елементів.
	cout << endl << "------ clear ------" << endl; 
	vector.clear();
	cout << "Vector size: " << vector.size() << endl;
	cout << "Vector capacity: " << vector.capacity() << endl;
	cout << "Vector is empty? " << (vector.empty() ? "Yes" : "No") << endl;

	// 24. insert - вставляє нові значення у вектор в задане місце.
	cout << endl << "------ insert -----" << endl; 
	vector = {1, 2, 3, 4, 5};
	vector.insert(vector.cbegin(), {100, 200});
	ShowVec(vector);

	// 25. emplace - кращий варіант методу insert. Для методу insert значення мають бути створені
	//				 в пам'яті ще до вставлення у вектор. А emplace значення можна будувати
	//				 прямо у векторі. Метод є варіантивним шаблоном.
	cout << endl << "----- emplace -----" << endl;
	vector.emplace(vector.cend(), 1000);
	ShowVec(vector);
	
	// 26. push_back - вставити новий елемент в кінець вектору.
	cout << endl << "---- push_back ----" << endl;
	vector.push_back(1000);
	ShowVec(vector);

	// 27. pop_back - видалити кінцевий елемент вектору.
	cout << endl << "----- pop_back ----" << endl;
	vector.pop_back();
	ShowVec(vector);

	// 28. resize - змінює розмівр вектору (НЕ ємність)
	//				Якщо розмір менший за попередні, то вектор скоротчується до нового розміру.
	//				Якщо розмір більший за попередній, то у вектор додаються нові елементи зі значенням за замовчуванням.
	cout << endl << "------ resize -----" << endl;
	vector.resize(5);
	for(auto iter = vector.begin(); iter != vector.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl; 
	vector.resize(10); 
	ShowVec(vector);
	
	// 29. swap	- поміняти вміст двох векторів (розмір та ємність). 
	cout << endl << "------- swap ------" << endl;
	std::vector<int> vector1{1, 2, 3};
	std::vector<int> vector2{4, 5, 6};
	cout << "vector1: "; ShowVec(vector1);
	cout << "vector2: "; ShowVec(vector2);
	vector1.swap(vector2); cout << "spaw()" << endl;
	cout << "vector1: "; ShowVec(vector1);
	cout << "vector2: "; ShowVec(vector2);

	// 30. erase - видалити елементі/діапазон значень із контейнеру.
	cout << endl << "------- erase -----" << endl;
	std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ShowVec(vec);
	vec.erase(vec.cend() - 2, vec.cend());
	ShowVec(vec);
	
	for(auto iter = vec.begin(); iter != vec.end(); iter++)
	{
		if(*iter % 2 != 0)
		{
			iter = vec.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	ShowVec(vec);

	// 31. emplace_back - аналогічний до emplace, тільки вставляє в кінець (кращий аналог методу push_back)
	cout << endl << "--- emplace_back --" << endl;
	vector.emplace_back(1000);
	ShowVec(vector);
	vector.emplace_back(2000);
	ShowVec(vector);
}

void ONotation()
{
	/*
	Constructors
		vector<t> v;                O(1)
		vector<t> v(n);             O(n)
		vector<t> v(n, value);      O(n)
		vector<t> v(begin, end);    O(n)

	Accessors:
		v[i];            O(1)
		v.at(i);         O(1)
		v.size();        O(1)
		v.empty();       O(1)
		v.begin();       O(1)
		v.end();         O(1)
		v.front();       O(1)
		v.back();        O(1)
		v.capacity();    O(1)

	Modifiers:
		v.push_back(value);         O(1) (Амортизована складність)
		v.insert(iterator, value);  O(n)
		v.pop_back();               O(1)
		v.erase(iterator);			O(n)
		v.erase(begin, end);		O(n)

	Підсумок:
		Вставка:   в кінець -> Амортизована O(1), в любе інше місце -> O(n)
		Доступ:	   O(1)
		Видалення: з кінця -> O(1), з любого іншого місця -> O(n)
		Пошук:	   O(n)

	*/
}

#pragma endregion Methods