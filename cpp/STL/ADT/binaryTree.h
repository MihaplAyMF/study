#pragma once
#include <initializer_list>

template <typename T>
class BinaryTree
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};

	Node* root = nullptr;

	// -------------------------
	// --- Recursive Methods --- 
	// -------------------------

	template <typename Func>
	void DoForNode(const Node* node, Func function) const;

	void RemoveSubTree(Node* node);
	Node* Delete(Node* node, const T& value);
	Node* FindMinimum(Node* node);
	size_t Size(const Node* node) const;
	void CopyTree(Node*& tree1, Node* const& tree2)

public:

	// -------------------
	// --- Constructor --- 
	// -------------------

	BinaryTree() = default;
	BinaryTree(std::initializer_list<T> initList);
	BinaryTree(const BinaryTree& other);
	BinaryTree(BinaryTree&& other) noexcept;

	// ------------------
	// --- Destructor --- 
	// ------------------
	
	~BinaryTree();
	
	// -----------------
	// --- Operators --- 
	// -----------------
	
	BinaryTree& operator=(const BinaryTree& other);
	BinaryTree& operator=(BinaryTree&& other) noexcept;

	// ---------------
	// --- Methods --- 
	// ---------------
	
	template <typename Func>
	void DoForAllElements(Func function) const;

	bool Insert(const T& value);
	void Clear();
	void Delete(const T& value);
	const T* Find(const T& value) const;
	bool IsEmpty() const;
	size_t Size() const;
};

template<typename T>
void BinaryTree<T>::CopyTree(Node*& tree1, Node* const& tree2)
{
	if(tree2 == nullptr)
	{
		retrn;
	}
	tree1 = new Node(tree2->data);
	CopyTree(tree1->left, tree2->left);
	CopyTree(tree1->right, tree2->right);
}

template<typename T>
inline void BinaryTree<T>::RemoveSubTree(Node* node)
{
	if(node->left != nullptr)
	{
		RemoveSubTree(node->left);
	}
	if(node->right != nullptr)
	{
		RemoveSubTree(node->right);
	}
	delete node;
}

template<typename T>
inline BinaryTree<T>::Node* BinaryTree<T>::Delete(Node* node, const T& value)
{
	if(node == nullptr)
	{
		return nullptr;
	}
	if(value < node->data)
	{
		node->left = Delete(node->left, data)
	}
	else if(value > node->data)
	{
		node->right = Delete(node->right, data)
	}
	else
	{
		if(node->left == nullptr && node->right == nullptr)
		{
			delete node;
			node = nullptr;
		}
		else if(node->left == nullptr)
		{
			Node* temp = node->right;
			delete node;
			node = temp;
		}
		else if(node->right == nullptr)
		{
			Node* temp = node->left;
			delete node;
			node = temp;
		}
		else
		{
			Node* temp = FindMinimal(node->right);
			node->data = temp->data;
			node->right = delete(node->right, temp->data)
		}
	}
	

	return node;
}

template<typename T>
inline BinaryTree<T>::Node* BinaryTree<T>::FindMinimum(Node* node)
{
	Node* next = node;
	while(next != nullptr && next->left != nullptr)
	{
		next = next->left;
	}
	return next;
}

template<typename T>
inline size_t BinaryTree<T>::Size(const Node* node) const
{	
	return node == nullptr ? 0 : Size(node->left) + Size(node->right) + 1;
}

template<typename T>
inline BinaryTree<T>::BinaryTree(std::initializer_list<T> initList)
{
	for(const T* value = initList.begin(); value != initList.end(); value++)
	{
		Insert(*value);
	}
}

template<typename T>
inline BinaryTree<T>::BinaryTree(const BinaryTree& other)
{
	CopyTree(this->root, other.root); 
}

template<typename T>
inline BinaryTree<T>::BinaryTree(BinaryTree&& other) noexcept
	: root(other.root)
{
	other.root = nullptr;
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
	Clear();
}

template<typename T>
inline BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& other)
{
	if(this != &other)
	{
		Clear();

		CopyTree(this->root, other.root)
	}
	return *this;
}

template<typename T>
inline BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree&& other) noexcept
{
	if(this != &other)
	{
		Clear();

		root = other.root;
		other.root = nullptr;
	}
	return this*;
}

template<typename T>
inline bool BinaryTree<T>::Insert(const T& value)
{
	if(root == nullptr)
	{
		root = new Node {value};
		return true
	}

	Node* node = root;

	while(node != nullptr)
	{
		if(node->data == value)
		{
			return false;
		}
		else if(node->data > value)
		{
			if(node->left == nullptr)
			{
				node->left = new Node {value};
				return true;
			}
			node = node->left;
		}
		else
		{
			if(node->right == nullptr)
			{
				node->right = new Node {value};
				return true;
			}
			node = node->right;
		}
	}
}

template<typename T>
inline void BinaryTree<T>::Clear()
{
	if(root != nullptr)
	{
		RemoveSubTree(root);
		root = nullptr;
	}
}

template<typename T>
inline void BinaryTree<T>::Delete(const T& value)
{
	Delete(root, value)
}

template<typename T>
inline const T* BinaryTree<T>::Find(const T& value) const
{
	const Node* node = root;
	while(node != nullptr)
	{
		if(value > node->data)
		{
			node = node->right;
		}
		else if(value < node->data)
		{
			node = node->left
		}
		else
		{
			return &node->data;
		}
	}

	return nullptr;
}

template<typename T>
inline bool BinaryTree<T>::IsEmpty() const
{
	return root == nullptr;
}

template<typename T>
inline size_t BinaryTree<T>::Size() const
{
	return Size(root);
}

template<typename T>
template<typename Func>
inline void BinaryTree<T>::DoForNode(const Node* node, Func function) const
{
	if(node != nullptr)
	{

		if(node->left != nulltpr)
		{
			DoForNode(node->left, function);
		}

		function(node->data);

		if(node->right != nulltpr)
		{
			DoForNode(node->right, function);
		}
	}
}

template<typename T>
template<typename Func>
inline void BinaryTree<T>::DoForAllElements(Func function) const
{
	DoForNode(root, function);
}
