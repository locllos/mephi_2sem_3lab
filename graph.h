#pragma once



template <class T>
class Graph
{
private:
	struct node
	{
		node* parent = nullptr;
		node* left = nullptr;
		node* right = nullptr;
		T key = T(0);

	};
	node* root = nullptr;
	int size = 0;

private:

	void dfs(node* node_ptr)
	{
		if (node_ptr == nullptr) return;
		
		if (node_ptr->left != nullptr)
		{
			dfs(node_ptr->left);
			std::cout << "\nLEFT " << node_ptr->left->key << " | PARENT " << node_ptr->left->parent->key;
		}
		if (node_ptr->right != nullptr)
		{
			dfs(node_ptr->right);
			std::cout << "\nRIGHT " << node_ptr->right->key << " | PARENT " << node_ptr->right->parent->key;;
		}
	}

	void destructor(node* node_ptr)
	{
		if (node_ptr == nullptr) return;
		
		if (node_ptr->left != nullptr)
		{
			destructor(node_ptr->left);
			delete node_ptr->left;
		}
		if (node_ptr->right != nullptr)
		{
			destructor(node_ptr->right);
			delete node_ptr->right;
		}
	}
	
	node* search(const T key)
	{
		node* node_ptr = this->root;

		while (node_ptr != nullptr)
		{
			if (key < node_ptr->key)
			{
				node_ptr = node_ptr->left;
			}
			else if (key > node_ptr->key)
			{
				node_ptr = node_ptr->right;
			}
			else return node_ptr;
		}
		return nullptr;
	}

	node* next(node* node_ptr)
	{
		if (node_ptr == nullptr) return nullptr;

		if (node_ptr->right != nullptr)
		{
			node_ptr = node_ptr->right;

			while (node_ptr->left != nullptr)
			{
				node_ptr = node_ptr->left;
			}

			return node_ptr;
		}
		else if (node_ptr->parent->left == node_ptr)
		{
			return node_ptr->parent;
		}
		else return nullptr;
	}

	void erase_(node* del_node_)
	{
		node* del_node = del_node_;

		if (del_node == nullptr) return;

		if (del_node->right == nullptr && del_node->left == nullptr)
		{
			if (del_node == this->root)
			{
				delete del_node;
				this->root = nullptr;
			}
			else
			{
				if (del_node->parent->right == del_node) del_node->parent->right = nullptr;
				else del_node->parent->left = nullptr;

				delete del_node;
			}
		}
		else if (del_node->right != nullptr && del_node->left == nullptr)
		{
			if (del_node == this->root)
			{
				del_node->right->parent = nullptr;
				this->root = del_node->right;

			}
			else
			{
				if (del_node->parent->left == del_node) del_node->parent->left = del_node->right;
				else del_node->parent->right = del_node->right;

				del_node->right->parent = del_node->parent;

			}

			delete del_node;
		}
		else if (del_node->right == nullptr && del_node->left != nullptr)
		{
			if (del_node == this->root)
			{
				del_node->left->parent = nullptr;
				this->root = del_node->left;
			}
			else
			{
				if (del_node->parent->left == del_node) del_node->parent->left = del_node->left;
				else del_node->parent->right = del_node->left;

				del_node->left->parent = del_node->parent;

			}

			delete del_node;
		}

		else if (del_node->right != nullptr && del_node->left != nullptr)
		{
			node* swap_node = next(del_node);

			T tmp_value = del_node->key;
			del_node->key = swap_node->key;
			swap_node->key = tmp_value;

			this->erase_(swap_node);
		}
	}

public:

	Graph() = default;
	
	Graph(const T root_key)
	{
		this->root = new node;
		this->root->key = root_key;
		size = 1;
	}
	void add(const T key)
	{
		node* node_ptr = this->root;

		++this->size;

		if (this->root == nullptr)
		{
			this->root = new node;
			this->root->key = key;
			
			return;
		}

		while (node_ptr != nullptr)
		{

			if (key < node_ptr->key)
			{
				if (node_ptr->left != nullptr)
				{
					node_ptr = node_ptr->left;
				}
				else
				{
					node_ptr->left = new node;
					node_ptr->left->key = key;
					node_ptr->left->parent = node_ptr;
					break;
				}
			}
			else
			{
				if (node_ptr->right != nullptr)
				{
					node_ptr = node_ptr->right;
				}
				else
				{
					node_ptr->right = new node;
					node_ptr->right->key = key;
					node_ptr->right->parent = node_ptr;
					break;
				}
			}
		}
	}

	void erase(T key)
	{
		node* del_node = search(key);
		if (del_node == nullptr) return;
		
		erase_(del_node);
		--this->size;
	}

	T next(const T key)
	{
		node* node_ptr = search(key);

		node_ptr = next(node_ptr);

		if (node_ptr == nullptr) return 0;

		return node_ptr->key;
	}

	T maximum()
	{
		node* node_ptr = this->root;

		if (this->root == nullptr) return T(0);

		while (node_ptr->right != nullptr)
		{
			node_ptr = node_ptr->right;
		}

		return node_ptr->key;
	}

	T minimum()
	{
		if (this->root == nullptr) return T(0);
		
		node* node_ptr = this->root;

		while (node_ptr->left != nullptr)
		{
			node_ptr = node_ptr->left;
		}

		return node_ptr->key;
	}

	bool exist(const T key)
	{
		if (search(key) != nullptr)
		{
			return true;
		}
		else return false;
	}

	void dfs()
	{
		if (this->root == nullptr) return;
		dfs(this->root);
		std::cout << "\nROOT " << this->root->key;
	}


	~Graph()
	{
		destructor(this->root);

		size = 0;
		delete this->root;
	}

};

