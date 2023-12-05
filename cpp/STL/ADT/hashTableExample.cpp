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
        unique_ptr<Node> next;
    };

    size_t m_size;
    Node** m_table;

    size_t HashFunction(const Key& key) const
    {
        return hash<Key>()(key) % m_size;
    };

public:
    HashTable(size_t size = 10)
        : m_size(size)
        , m_table(new Node* [size]{})
    { }

    HashTable(const HashTable& other) = delete;
    HashTable& operator=(const HashTable& other) = delete;

    ~HashTable()
    {
        Clear();
        delete[] m_table;   
    }

    void Insert(const Key& key, const Value& value)
    {
        size_t index = HashFunction(key);

        Node*& node = m_table[index];

        while(node != nullptr)
        {
            if(node->key == key)
            {
                node->value = value;
                return;
            }
            node = node->next.get();
        }
        node = new Node {key, value, unique_ptr<Node>(nullptr)};
    }
    const Value& Search(const Key& key) const
    {
        size_t index = HashFunction(key);

        Node* node = m_table[index];
        while(node != nullptr)
        {
            if(node->key == key)
            {
                return node->value;
            }
            node = node->next.get();
        }
        
        throw out_of_range("Key no found");
    }

    bool Remove(const Key& key)
    {
        size_t index = HashFunction(key);

        Node*& node = m_table[index];

        if(node == nullptr)
        {
            return false;
        }

        if(node->key == key)
        {
            unique_ptr<Node> temp(move(node->next));
            delete node;
            node = temp.release(); 

            return true;
        }

        Node* prev = node;
        Node* curr = node->next.get();

        while(curr != nullptr)
        {
            if(curr->key == key)
            {
                unique_ptr<Node> temp(move(curr->next));
                prev->next = move(temp);
                delete curr;

                return true;
            }
            prev = curr;
            curr = curr->next.get();
        }
        return false;
    }

    void Clear()
    {
        for(size_t i = 0; i < m_size; i++)
        {
            while(m_table[i] != nullptr)
            {
                unique_ptr<Node> temp(move(m_table[i]->next));
                delete m_table[i];
                m_table[i] = temp.release();
            }
        }
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

    HashTable<string, string> dictionary;

    dictionary.Insert("Frog", "Test one");
    dictionary.Insert("Dog", "Test two");
    dictionary.Insert("Cat", "Test three");

    ShowValue<string, string>(dictionary, "Frog");

    if(!dictionary.Remove("Dog"))
    {
        cout << "Key doesn't exist" << endl;
    }

    ShowValue<string, string>(dictionary, "Dog");
    ShowValue<string, string>(dictionary, "Frog");

    dictionary.Clear();

    ShowValue<string, string>(dictionary, "Frog");


    return 0;
}