#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
//#include "person.h"

using namespace std;

/* --- LIST --- */

class Person
{
public:
	Person() { cout << "Constructor" << endl; }
	~Person() { cout << "Destructor" << endl; }
};

#pragma region PrototypeMethod
void Show(const list<int>& vector);
void ShowList(const list<int>& vector);

void Containers();
void AllConstructor();
void Destructor();
void Methods();
void ContainerAliasses();
void ONotation();

#pragma endregion PrototypesMethods

int main()
{
	//Containers();
	//AllConstructor();
	//Destructor();
	//Methods();
	//ONotation();

	return 0;
}

#pragma region Methods

void Show(const list<int>& list)
{
	cout << endl << "--- LIST INFO ---" << endl;
	cout << " Elements: ";
	if(list.empty())
	{
		cout << "none";
	}
	else
	{
		for(auto iter = list.begin(); iter != list.end(); iter++)
		{
			cout << *iter << " ";
		}
	}
	cout << endl;
	cout << " Size: " << list.size() << endl;
	cout << "-------------------" << endl;
}

void ShowList(const list<int>& list)
{
	for(auto iter = list.begin(); iter != list.end(); iter++)
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
	list<int> v1;
	Show(v1);

	// 2. Конструктор за замовчуванням, який приймає користувацький алокатор
	allocator<int> myAllocator; // Я поки не знаю що таке алокатор
	list<int> list2(myAllocator);
	Show(list2);

	// 3. Коструктор, приймаючий std::initializer_list
	list<int> list3 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Show(list3);

	// 4. Конструктор копії
	list<int> list4(list3);
	Show(list4);

	// 5. Констуктор переміщення
	list<int> list5(move(list4));
	Show(list4); // Як ми можемо бачити він пустий
	Show(list5);

	// 6. Констуктор, який приймає кількість елементів
	list<int> list6(10);
	Show(list6);

	// 7. Констуктор, який приймає кількість елементів і їх значення
	list<int> list7(3, 100);
	Show(list7);

	// 8. Констуктор, який примає 2 ітератори
	vector<int> vector {10, 20, 30};
	list<int> list8(vector.begin(), vector.end());
	Show(list8);
}

void Destructor()
{
	cout << "--- DESTRUCTOR ----" << endl;

	// У класі vector є деструктор, в якому вся пам'ять під виділені елементи на кучі
	// автоматично змільняється/видаляється. Вам не потрібно викликати деструктор явно.

	list<Person> v1(2); // Як тільки ми вийдемо за локальну видимість, деструктор викличеться
	// v1.~vector(); // Викликати його явно не потрібно
}

void Methods()
{
	cout << "----- METHODS -----" << endl;
	
	list<int> list {10, 20, 500, 5, 0}; // Усього 5 елементів

	// 1. front - повертає посилання на перший елемент.
	cout << endl << "------ front ------" << endl;
	cout << "vector[0] = " << list.front() << endl;
	list.front() = 13;
	cout << "vector[0] = " << list.front() << endl;

	// 2. back - повертає посилання на останній елемент.
	cout << endl << "------ back -------" << endl;
	cout << "vector[4] = " << list.back() << endl;
	list.back() = 14;
	cout << "vector[4] = " << list.back() << endl;

	// 3. get_allocator - повертає алокатор, який прив'язаний до контейнера.
	cout << endl << "-- get_allocator --" << endl;
	auto allocator = list.get_allocator();
	cout << "Я поки не знаю що таке аллокатори" << endl;

	// 4. operator=
	cout << endl << "---- operator= ----" << endl;
	list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  cout << "std::initializer_list: ";
	ShowList(list);
	list = std::list<int>(10, 1); cout << "copy: ";
	ShowList(list);
	std::list<int> otherList {12, 11, 0};
	list = otherList; cout << "move: ";
	ShowList(list);

	// 5. assign - дозволяє переписувати вміст списку новими значеннями.
	//             Схожий на опертор =, але має більше можливостей, бо може приймати
	//			   більше одного параметру.
	cout << endl << "----- assign ------" << endl;
	list.assign(5, 100); cout << "кількість елементів, значення: ";
	ShowList(list);
	list.assign({1, 2, 3, 4, 5}); cout << "std::initializer_list: ";
	ShowList(list);
	list.assign(list.cbegin(), list.cend()); cout << "два ітератори: ";
	ShowList(list); 

	// 6. begin - повертає ітератор на перший елемент контейнеру. Елемент можна міняти через ітератор.
	// 7. end - повертає ітератор на кінець діапазону елементів. Кінець - це наступний елемент за останнім.
	// 8. cbegin - повертає константний ітератор на перший елемент контейнеру. Елемент НЕ можна міняти через ітератор.
	// 9. cend - повертає константний ітератор на кінцевий елемент контейнеру.
	// 10. rbegin - повертає обернений ітератор на останній елемент контейнеру. 
	// 11. rend - та же аналогія як rbegin до begin, тільки до методу end.
	// 12. crbegin - константний rbegin.
	// 13. crend - константний rend.

	cout << endl << "-------------------" << endl;
	cout << "begin\t end" << endl;
	cout << "cbegin\t cend" << endl;
	cout << "rbegin\t rend" << endl;
	cout << "begin\t end" << endl;
	cout << endl << "РОБЛЯТЬ ТЕ Ж САМЕ ЩО Й У ВЕКТОРА" << endl;

	for(auto iter = list.cbegin(); iter != list.cend(); iter++)
	{
		cout << *iter << " "; // Немає перевизначеного оператора індексації
		// тому для читання даних потрібно використовувати *iter
	}
	cout << endl;

	// 14. empty - повертає true якщо контейнер пустий.
	cout << endl << "------ empty ------" << endl;
	cout << "Vector is empty? " << (list.empty() ? "Yes" : "No") << endl;

	// 15. max_size - повертає максимально можливу кількість елементів.
	cout << endl << "---- max_size -----" << endl;
	cout << "Vector max_size: " << list.max_size() << endl;

	// 16. size - повертає розмір списку (кількість елементів, в яких є значення).
	cout << endl << "------ size -------" << endl;
	cout << "Vector size: " << list.size() << endl;

	// 17. clear - очищує список, звільняючи пам'ять (викликаючи дестуктори) елементів.
	cout << endl << "------ clear ------" << endl;
	list.clear();
	cout << "Vector size: " << list.size() << endl;
	cout << "Vector is empty? " << (list.empty() ? "Yes" : "No") << endl;

	// 18. insert - вставляє нові значення у список в задане місце.
	cout << endl << "------ insert -----" << endl;
	list = {1, 2, 3, 4, 5};
	list.insert(list.cbegin(), {11, 12});
	ShowList(list);
	
	// 19. push_back - вставити новий елемент в кінець списку.
	cout << endl << "---- push_back ----" << endl;
	cout << "push_back(10)" << endl;
	list.push_back(10);
	ShowList(list);
	
	// 20. push_front - вставити новий елемент в початок списку.
	cout << endl << "---- push_front ---" << endl;
	cout << "push_front(9)" << endl;
	list.push_front(9);
	ShowList(list);

	// 21. emplace - кращий варіант методу insert. 
	cout << endl << "----- emplace -----" << endl;
	list.emplace(list.cend(), 6);
	ShowList(list);

	// 22. emplace_back - аналогічний до emplace, тільки вставляє в кінець (кращий аналог методу push_back)
	cout << endl << "--- emplace_back --" << endl;
	list.emplace_back(7);
	ShowList(list);

	// 23. emplace_front - аналогічний до emplace, тільки вставляє в початок (кращий аналог методу push_back)
	cout << endl << "-- emplace_front --" << endl;
	list.emplace_front(8);
	ShowList(list);

	// 24. pop_back - видалити кінцевий елемент списку.
	cout << endl << "----- pop_back ----" << endl;
	list.pop_back();
	ShowList(list);

	// 25. pop_back - видалити кінцевий елемент списку.
	cout << endl << "----- pop_front ---" << endl;
	list.pop_front();
	ShowList(list);

	// 26. resize - змінює розмівр cписку
	cout << endl << "------ resize -----" << endl;
	list.resize(5);
	for(auto iter = list.begin(); iter != list.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	list.resize(10);
	ShowList(list);

	// 27. swap	- поміняти вміст двох списків.
	cout << endl << "------- swap ------" << endl;
	std::list<int> list1 {1, 2, 3};
	std::list<int> list2 {4, 5, 6};
	cout << "list1: "; ShowList(list1);
	cout << "list2: "; ShowList(list2);
	list1.swap(list2); cout << "spaw()" << endl;
	cout << "list1: "; ShowList(list1);
	cout << "list2: "; ShowList(list2);

	// 28. erase - видалити елементі/діапазон значень із контейнеру.
	cout << endl << "------- erase -----" << endl;
	list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ShowList(list);
	auto foundIter = find(list.cbegin(), list.cend(), 5);
	list.erase(foundIter);
	ShowList(list);

	for(auto iter = list.begin(); iter != list.end();)
	{
		if(*iter % 2 != 0)
		{
			iter = list.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	ShowList(list);

	// 29. merge - об'єднює два ВІДСОРТОВАНИХ списки
	cout << endl << "------- merge -----" << endl;
	list1 = {1, 5, 7, 9, 10};
	list2 = {2, 3, 4, 6, 8};

	list1.merge(list2);

	ShowList(list1);
	ShowList(list2); // буде пустим!

	//	УВАГА: якщо списки складаються з елементів ваших класів,
	//		   то щоб скористатися методом merge(список), ваш
	//		   клас має мати перезавантажений оператор <.
	//		   Інакше ви можете викликати версію merge(список, функція_порівняння),
	//         яка має мати наступний заголовок:
	//		   bool ФункціяПорівняння(const ВашКлас& об'єкт1, const ВашКлас& об'єкт2).
	
	// 30. splice - переміщає елементи другого списку в даний список в указане місце
	cout << "------ splice -----" << endl;
	list1 = {100, 101, 99, 102};
	list2 = {1, 2, 3};

	list1.splice(list1.cbegin(), list2);
	ShowList(list1); 
	ShowList(list2);
	
	// 31. remove - видаляє зі списку указане значення
	cout << "------ remove -----" << endl;
	list = {1, 200, 3, 4, 4, 4, 5, 6, 100, 8, 9, 8, 10};
	
	ShowList(list);
	list.remove(4);
	list.remove(8);
	ShowList(list);

	// 32. remove_if - видаляє зі списку указане значення, якщо воно підходить указаній умові
	cout << endl << "---- remove_if ----" << endl;

	list.remove_if([](int value) { return value > 50; });
	ShowList(list);

	// 33. reverse - повертає список (міняючи вказівники на "голову" і "хвіст" місцями).
	cout << endl << "----- reverse -----" << endl;
	list = {1, 2, 3, 4, 5};

	list.reverse();
	ShowList(list);

	// 34. unique - видаляє елементи-дублікати, які йдуть в ряд, залишаючи лише унікальні значення
	cout << endl << "------ unique -----" << endl;
	list = {1, 2, 2, 4, 2, 4};

	list.unique();
	ShowList(list);

	// 35. sort - сортує елементи в списку (швидкість n*log(n)).
	cout << endl << "------- sort ------" << endl;
	list = {4, 1, 3, 2, 10, 7, 8, 5, 9, 6};

	list.sort();
	ShowList(list);

	list.sort([](int value1, int value2) { return value1 > value2; });
	ShowList(list);

	// У класа std::list немає наступних методів:
	// 1. data          (є у std::vector)
	// 2. operator[]    (є у std::vector)
	// 3. at            (є у std::vector)
	// 4. capacity      (є у std::vector)
	// 5. reverse       (є у std::vector)
	// 6. shrink_to_fit (є у std::vector)
}

void ContainerAliasses()
{
	// Приклади
	std::list<int>::value_type value = 10;          // int value = 10;
	std::list<int>::const_reference value = value;  // const int& reference = value;
	std::list<int>::pointer value = &value;         // int* pointer = &value;
	// та інші
}

void ONotation()
{
	/*
		Вставка:   O(1)
		Доступ:	   O(1)/O(n)
		Видалення: O(1)
		Пошук:	   O(n)
	*/
}

#pragma endregion Methods