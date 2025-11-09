#include <iostream>

// Заголовкові файли контейнерів STL
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;

/* --- DEQUE --- */

class Person
{
public:
	Person() { cout << "Constructor" << endl; }
	~Person() { cout << "Destructor" << endl; }
};

void Show(const deque<int>& vector);
void ShowDeq(const deque<int>& vector);

int main()
{
	// Конструктори:
	{
		cout << "--- Constructor ---" << endl;
		// 1. Конструктор за замовчуванням.
		{
			deque<int> someList;
			Show(someList);
		}

		// 2. Коструктор, приймаючий std::initializer_list.
		{
			deque<int> someList {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			Show(someList);
		}

		// 3. Конструктор, який приймає діапазон значень по ітераторі колекції.
		{
			vector<int> someContainer {1, 2, 3, 4, 5};
			deque<int> someList(someContainer.cbegin(), someContainer.cend());
			Show(someList);
		}

		// 4. Конструктор копії
		{
			deque<int> otherList {1, 2, 3, 4, 5};
			deque<int> someList(otherList);
			Show(someList);
		}
		
		// 5. Параметри: Iterator begin, Iterator end
		{
			vector<int> vector {10, 20, 30, 40, 50};
			deque<int> deque(vector.begin(), vector.end());
			Show(deque);
		}

		// 6. Параметри: size_t кількість елментів.
		{
			deque<int> deque(4);
			Show(deque);
		}
		
		// 7. Параметри: size_t кількість елментів, const T& значення
		{
			deque<int> deque(4, 123);
			Show(deque);
		}
		
		// всі інші констуктори такі самі, тільки приймають ще й алокатор
	}

	// Деструктор:
	{
		cout << endl << "--- Destructor ----" << endl;
		forward_list<Person> container(2);
	}

	// Методи: 
	{
		cout << endl << "----- Methods -----" << endl;

		std::deque<int> deque {1, 2, 3};
		std::deque<int> otherDeque {-1, -2, -3};
		ShowDeq(deque);

		// 1. operator= - переписує вміст контейнера новим набором значень. 
		{
			deque = {100, 101, 102, 103};            // std::initializer_list
			ShowDeq(deque);

			deque = otherDeque;                      // copy
			ShowDeq(deque);

			deque = std::deque<int>(10, -1);         // move
			ShowDeq(deque);
		}

		// 2. assign - переписує вміст контейнера новим набором значень. Працює аналогічно з operator=,
		//	    	   тільки має інші варіанти присвоєння.
		{
			deque.assign(3, 10000);                               // assign(кількість_елементів, значення) 
			ShowDeq(deque);

			deque.assign({1, 2, 3, 4, 5});                        // assign(std::initializer_list)
			ShowDeq(deque);

			deque.assign(otherDeque.cbegin(), otherDeque.cend()); // assign(ітератор_на_початок, ітератор_на_кінець)
			ShowDeq(deque);

		}

		// 3. get_allocator - повертає алокатор, який прив'язаний до контейнера.
		{
			auto allocator = deque.get_allocator(); // auto -> std::allocator<int>
		}

		// 4. operator[] - повертає оператор на елоемент за заданим індексом.
		{
			cout << "deque[3] = " << deque[3] << endl;
		}

		// 5. at - повертає посилання на елемент за заданим індексом. Кидає виключення
		//		   типу std::out_of_range, якщо індекст виходить за границі масиву.
		{
			try
			{
				deque.at(100) = 1000;
			}
			catch(out_of_range& exc)
			{
				cout << exc.what() << endl;
			}
		}

		// 5. front - повертає посилання на перший елемент контейнера.
		{
			cout << "First element = " << deque.front() << endl;
			deque.front() = 100;
			cout << "First element = " << deque.front() << endl;
		}

		// 6. back - повертає посилання на останній елемент контейнера.
		{
			cout << "First element = " << deque.back() << endl;
			deque.back() = 20;
			cout << "First element = " << deque.back() << endl;
		}

		// Інтератори такі ж як і в вектора чи ліста

		// 5.  begin 
		// 6.  end    
		// 7.  cbegin
		// 8.  cend  
		// 9.  rbegin
		// 10. rend
		// 11. crbegin
		// 12. crend

		// 13. сlear - очищує вміст контейнеру.
		{
			deque.clear();
			ShowDeq(deque);
		}

		// 14. push_front - вставити новий елемент в початок контейнера.
		// 15. pop_front  - видалити пперший елемент контейнера.
		{
			deque.push_front(10);
			deque.push_front(20);
			deque.push_front(30);
			ShowDeq(deque);
			deque.pop_front();
			deque.pop_front();
			ShowDeq(deque);
		}

		// 16. push_back - вставити новий елемент в кінець контейнера.
		// 17. pop_back  - видалити останній елемент контейнера.
		{
			deque.push_back(10);
			deque.push_back(20);
			deque.push_back(30);
			ShowDeq(deque);
			deque.pop_back();
			deque.pop_back();
			ShowDeq(deque);
		}

		// 18. swap	- поміняти вміст двох списків.
		{
			std::deque<int> deque1 {1, 2, 3};
			std::deque<int> deque2 {4, 5, 6};
			cout << "list1: "; ShowDeq(deque1);
			cout << "list2: "; ShowDeq(deque2);
			deque1.swap(deque2); cout << "spaw()" << endl;
			cout << "list1: "; ShowDeq(deque1);
			cout << "list2: "; ShowDeq(deque2);
		}

		// 19. resize - змінює розмір контейнеру 
		//				Якщо розмір менший за попередні, то контейнер скоротчується до нового розміру.
		//				Якщо розмір більший за попередній, то у контейнер додаються нові елементи зі значенням за замовчуванням.
		{
			deque.resize(1);
			ShowDeq(deque);
			deque.resize(10);
			ShowDeq(deque);
		}

		// 20. empty - повертає true якщо контейнер пустий.
		{
			cout << "Deque is empty? " << (deque.empty() ? "Yes" : "No") << endl;
		}

		// 21. emplace_front - аналогічний до push_front, тілкьи не копіює готовий об'єкт, 
		//					   а конструює об'єкт зразу в контейнері. 
		{
			deque.emplace_front(8); // Якщо працюєте з класами використовуйте цей метод
			ShowDeq(deque);
		}

		// 22. emplace_back - аналогічний до push_back, тілкьи не копіює готовий об'єкт, 
		//					   а конструює об'єкт зразу в контейнері. 
		{
			deque.emplace_back(8); // Якщо працюєте з класами використовуйте цей метод
			ShowDeq(deque);
		}

		// 23. size - повертає розмір контейнера
		{
			std::deque<int> deque1 {1, 2, 3};
			std::deque<int> deque2;
			cout << "deque1 has " << deque1.size() << "elements" << endl;
			cout << "deque2 has " << deque2.size() << "elements" << endl;
		}

		// 24. max_size - повертає максимально можливу кількість елементів.
		{
			cout << "Deuq max_size: " << deque.max_size() << endl;
		}
		
		// 25. shrink_to_fit - зменшує (скоротчує) об'єм ємності контейнера до розміру.
		{
			std::deque<int> deq(50);  // виділить на кучі пам'ять під 50 елементів. Викликати конструктор кожного елементу. Ємність = 50
			deq.resize(30);           // викличе деструктори останніх 20 елементів. Пам'ять під них ВСЕ ЩЕ виділена. Ємність все ще = 50.
			deq.shrink_to_fit();      // переросприділить пам'ять так, щоб залишилося лише 30 елментів. Ємність уже = 30.
		}

		// 26. insert - вставляє нові значення у контейнер в задане місце.
		{
			deque = {1, 2, 3, 4, 5};
			deque.insert(deque.cbegin(), {100, 200});
			ShowDeq(deque);
		}

		// 27. emplace - кращий варіант методу insert. Для методу insert значення мають бути створені
		//				 в пам'яті ще до вставлення у вектор. А emplace значення можна будувати
		//				 прямо у векторі. Метод є варіантивним шаблоном.
		{
			deque.emplace(deque.cend(), 1000); // Кращий якщо ми використовуємо класи
			ShowDeq(deque);
		}

		// 28. erase - видалити елементі/діапазон значень із контейнеру.
		{
			deque = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			ShowDeq(deque);
			deque.erase(deque.cend() - 2, deque.cend());
			ShowDeq(deque);

			for(auto iter = deque.begin(); iter != deque.end(); iter++)
			{
				if(*iter % 2 != 0)
				{
					iter = deque.erase(iter);
				}
				else
				{
					iter++;
				}
			}
			ShowDeq(deque);
		}
	}

	/* 
		Вставка:   Back/Front Amortized O(1), other O(n)
		Доступ:	   O(1)
		Видалення: Back/Front O(1), other O(n)
		Пошук:	   O(n)
	*/
	return 0;
}

void Show(const deque<int>& list)
{
	cout << endl << "------ DEQUE ------\n" << endl;
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
	cout << endl << "\n-------------------" << endl;
}

void ShowDeq(const deque<int>& list)
{
	cout << "Elements: ";
	for(auto iter = list.begin(); iter != list.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

}
