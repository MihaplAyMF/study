#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

/* --- FORWARD_LIST --- */

class Person
{
public:
	Person() { cout << "Constructor" << endl; }
	~Person() { cout << "Destructor" << endl; }
};

void Show(const forward_list<int>& vector);
void ShowList(const forward_list<int>& vector);

int main()
{
	// Конструктори:
	{
		cout << "--- Constructor ---" << endl;
		// 1. Конструктор за замовчуванням.
		{
			forward_list<int> someList;
			Show(someList);
		}

		// 2. Коструктор, приймаючий std::initializer_list.
		{
			forward_list<int> someList {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			Show(someList);
		}

		// 3. Конструктор, який приймає діапазон значень по ітераторі колекції.
		{
			vector<int> someContainer {1, 2, 3, 4, 5};
			forward_list<int> someList(someContainer.cbegin(), someContainer.cend());
			Show(someList);
		}

		// 4. Конструктор копії
		{
			forward_list<int> otherList {1, 2, 3, 4, 5};
			forward_list<int> someList(otherList);
			Show(someList);
		}
		
		// 5. Констуктор переміщення
		{
			forward_list<int> otherList {1, 2, 3, 4, 5};
			forward_list<int> someList(move(otherList));
			Show(otherList);
			Show(someList);
		}

		// 6. Констуктор, який приймає кількість елементів (розмір), значення яких буде за замовчуванням.
		{
			forward_list<int> someList(10);
			Show(someList);

		}
		
		// 7. Констуктор, який приймає кількість елементів (розмір), і їх значення
		{
			forward_list<int> someList(3, 100);
			Show(someList);
		}
		
		// Я поки не знаю що таке алокатор!

		// 8.  Конструктор, який приймає алокатор
		// 9.  Конструктор, який приймає std::initializer_list і алокатор
		// 10. Конструктор, який приймає діапазон значень по ітераторам колекції і алокатор
		// 11. Конструктор копії разом з алокатором
		// 12. Конструктор переміщення разом з алокатором 
	}

	// Деструктор:
	{
		cout << endl << "--- Destructor ----" << endl;
		forward_list<Person> container(2);
	}

	// Методи:
	{
		cout << endl << "----- Methods -----" << endl;

		forward_list<int> list;
		forward_list<int> otherList {0, 1, 0, 1};
		std::list<int> otherContainers {1000, 999, 888};

		// 1. operator= - переписує вміст контейнера новим набором значень. 

		list = {100, 101, 102, 103};            // operator=(std::initializer_list) 
		ShowList(list);
		ShowList(list);
		list = std::forward_list<int>(10, -1);  // operator=(std::forward_list<int>&&) 
		ShowList(list);
		list = otherList;                       // operator=(const std::forward_list<int>&) 
		ShowList(list);

		// 2. assign - переписує вміст контейнера новим набором значень. Працює аналогічно з operator=,
		//	    	   тільки має інші варіанти присвоєння.
		list.assign(3, 10000);                                         // assign(кількість_елементів, значення) 
		ShowList(list);
		list.assign({1, 2, 3, 4, 5});                                  // assign(std::initializer_list)
		ShowList(list);
		list.assign(otherContainers.cbegin(), otherContainers.cend()); // assign(ітератор_на_початок, ітератор_на_кінець)
		ShowList(list);

		// 3. get_allocator - повертає алокатор, який прив'язаний до контейнера.
		auto allocator = list.get_allocator(); // auto -> std::allocator<int>

		// 4. front - повертає посилання на перший елемент контейнера.
		cout << "First element = " << list.front() << endl;
		list.front() = 100;
		cout << "First element = " << list.front() << endl;

		// 5. begin  - повертає ітератор на початок списку
		// 6. end    - повертає ітератор на кінець списку 
		// 7. cbegin - повертає константний ітератор на початок списку
		// 8. cend   - повертає константний ітератор на кінець списку

		// 9. сlear - очищує вміст контейнеру.
		list.clear();
		ShowList(list);

		// 10. push_front - вставити новий елемент в початок контейнера.
		// 11. pop_front  - видалити пперший елемент контейнера.
		list.push_front(10);
		list.push_front(20);
		list.push_front(30);
		ShowList(list);
		list.pop_front();
		list.pop_front();
		ShowList(list);

		// 12. sort - сортує масив в зростаючому порядку(використовує операто <),
		//			  або по предикату. Швидкість O(n*log(n)).
		list = {1, 4, 3, 10, 9, 2, 5, 8, 7, 6};
		list.sort();
		ShowList(list);
		list.sort([](int value1, int value2) { return value1 > value2; });
		ShowList(list);

		// 13. unique - видаляє елементи-дублікати, які йдуть в ряд, залишаючи лише унікальні значення
		list = {1, 2, 2, 4, 2, 4};
		list.unique();
		ShowList(list);

		// 14. reverse - повертає список (міняючи вказівники на "голову" і "хвіст" місцями).
		list = {1, 2, 3, 4, 5};
		ShowList(list);
		list.reverse();
		ShowList(list);

		// 15. swap	- поміняти вміст двох списків.
		std::forward_list<int> list1 {1, 2, 3};
		std::forward_list<int> list2 {4, 5, 6};
		cout << "list1: "; ShowList(list1);
		cout << "list2: "; ShowList(list2);
		list1.swap(list2); cout << "spaw()" << endl;
		cout << "list1: "; ShowList(list1);
		cout << "list2: "; ShowList(list2);

		// 16. resize - змінює розмівр вектору 
		//				Якщо розмір менший за попередні, то контейнер скоротчується до нового розміру.
		//				Якщо розмір більший за попередній, то у контейнер додаються нові елементи зі значенням за замовчуванням.
		list.resize(1);
		ShowList(list);
		list.resize(10);
		ShowList(list);

		// 17. remove - видаляє зі списку указане значення
		list = {1, 200, 3, 4, 4, 4, 5, 6, 100, 8, 9, 8, 10};
		ShowList(list);
		list.remove(4);
		list.remove(8);
		ShowList(list);

		// 18. remove_if - видаляє зі списку указане значення, якщо воно підходить указаній умові
		list.remove_if([](int value) { return value > 50; });
		ShowList(list);

		// 19. merge - об'єднює два ВІДСОРТОВАНИХ списки
		list1 = {1, 5, 7, 9, 10};
		list2 = {2, 3, 4, 6, 8};

		list1.merge(list2);

		ShowList(list1);
		ShowList(list2); // буде пустим!

		// 20. empty - повертає true якщо контейнер пустий.
		cout << "List is empty? " << (list.empty() ? "Yes" : "No") << endl;

		// 21. emplace_front - аналогічний до push_front, тілкьи не копіює готовий об'єкт, 
		//					   а конструює об'єкт зразу в контейнері. 
		list.emplace_front(8); // Якщо працюєте з класами використовуйте цей метод
		ShowList(list);

		// 22. max_size - повертає максимально можливу кількість елементів.
		cout << "List max_size: " << list.max_size() << endl;

		// 23. before_begin  - повертає ітератор перед початком діапазону елементів контейнера.
		// 24. cbefore_begin - повертає константний ітератор перед початком діапазону елементів контейнера.
		// 25. insert_after  - вставляє новий елемент після елемента, який указаний ітератором.
		// 26. emplace_after - конструює по параметрам новий елемент після елемента, який указаний ітератором.
		// 27. erase_after   - видаляє елемент контейнера після указаного ітератора.
		// 28. splice_after  - переміщує всі елементи іншого списку в указаний, з місця, яке указане ітератором.
	}

	/* 
		Вставка:   O(1)
		Доступ:	   O(1)/O(n)
		Видалення: O(1)
		Пошук:	   O(n)
	*/
	return 0;
}

void Show(const forward_list<int>& list)
{
	cout << endl << "--- FORWARD_LIST INFO ---\n" << endl;
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
	cout << endl << "\n-------------------------" << endl;
}

void ShowList(const forward_list<int>& list)
{
	cout << "Elements: ";
	for(auto iter = list.begin(); iter != list.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

}
