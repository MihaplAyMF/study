#include <iostream>
#include <string>

using namespace std;

template <typename Key, typename Value>
class HashTable
{
private:
    struct Node
    {
        Key key;
        Value value;
        shared_ptr<Node> next;
    };

    size_t m_size;
    unique_ptr<shared_ptr<Node>[]> m_table;

    size_t HashFunction(const Key& key) const
    {
        return hash<Key>()(key) % m_size;
    };

public:
    HashTable(size_t size = 10)
        : m_size(size)
        , m_table(make_unique<shared_ptr<Node>[]>(size))
    {
    }

    HashTable(const HashTable& other) = delete;
    HashTable& operator=(const HashTable& other) = delete;

    ~HashTable() = default;

    void Insert(const Key& key, const Value& value)
    {
        // Мені не дуже подобається реалізація, але кращої я не придумав

        size_t index = HashFunction(key);
        // ШІ казав що треба & щоб не робити даремної копії, але з ним код не працює
        shared_ptr<Node> node = m_table[index];

        if(node == nullptr)
        {
            m_table[index] = make_shared<Node>(Node {key, value, shared_ptr<Node>(nullptr)});
            return;
        }

        while(node != nullptr)
        {
            if(node->key == key)
            {
                node->value = value;
                return;
            }
            if(node->next == nullptr) break;
            node = node->next;
        }

        // Ось тут я вставляю в наступний елемент, хоча хотів би вставляти в цей
        // node = element, це допомогло б забрати перевірку на if(node == nullptr)
        // але тоді в нас перезаписуватиметься перший елемент, а мені цього не треба
        node->next = make_shared<Node>(Node {key, value, shared_ptr<Node>(nullptr)});

    }

    const Value& Search(const Key& key) const
    {
        size_t index = HashFunction(key);
        shared_ptr<Node> node = m_table[index];

        while(node != nullptr)
        {
            if(node->key == key)
            {
                return node->value;
            }
            node = node->next;
        }

        throw out_of_range("Key no found");
    }

    bool Remove(const Key& key)
    {
        size_t index = HashFunction(key);
        shared_ptr<Node> prev = nullptr;
        shared_ptr<Node> curr = m_table[index];

        while(curr != nullptr && curr->key != key)
        {
            prev = curr;
            curr = curr->next;
        }

        if(curr == nullptr) return false;
        prev != nullptr ? prev->next = curr->next : m_table[index] = curr->next;

        return true; 
    }

};

template <typename Key, typename Value>
void ShowValue(const HashTable<Key, Value>& table, const Key& key)
{
    try
    {
        string findValue = table.Search(key);
        cout << key << ": [" << findValue << "]" << endl;
    }
    catch(const out_of_range& exc)
    {
        cout << exc.what() << endl;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    HashTable<string, string> dictionary;

    dictionary.Insert("Miha", "Studen 4 course. Also learn c++");
    ShowValue<string, string>(dictionary, "Miha");
    dictionary.Insert("Anuriy", "Studen 4 course. Also learn c++");
    ShowValue<string, string>(dictionary, "Anuriy");
    dictionary.Insert("Oleksiy", "Studen 4 course. Also learn c++");
    ShowValue<string, string>(dictionary, "Oleksiy");
    dictionary.Insert("Maks", "Studen 4 course. Also learn c++");
    ShowValue<string, string>(dictionary, "Maks");

    cout << endl;
    ShowValue<string, string>(dictionary, "Miha");
    ShowValue<string, string>(dictionary, "Anuriy");
    ShowValue<string, string>(dictionary, "Oleksiy");
    ShowValue<string, string>(dictionary, "Maks");

    dictionary.Remove("Maks");
    ShowValue<string, string>(dictionary, "Maks");

    return 0;
}

