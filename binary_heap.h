#pragma once


template<class T>
class Binary_heap
{
private:

	T* data = new T[1];

	int size = 0;

private:

	void like_a_rock(const int index)
	{
		int left, right, i = index;
		T tmp;
		int min_child;

		while (2 * i + 1 < this->size)
		{
			left = 2 * i + 1;
			right = 2 * i + 2;
			min_child = left;

			if (right < this->size && this->data[right] < this->data[left]) min_child = right;
			if (this->data[i] <= this->data[min_child]) break;

			tmp = this->data[i];
			this->data[i] = this->data[min_child];
			this->data[min_child] = tmp;
			i = min_child;
		}
	}

	void like_a_bubble(const int index)
	{
		T tmp;
		int i = index;

		while (i > 0)
		{
			int parent = (i - 1) / 2;

			if (this->data[parent] > this->data[i])
			{
				tmp = this->data[parent];
				this->data[parent] = this->data[i];
				this->data[i] = tmp;
			}
			else break;

			i = parent;
		}
	}
public:

	Binary_heap(T key)
	{
		data[0] = key;
		this->size = 1;
	}


	T get_min()
	{
		if (!this->size) { std::cout << "EMPTY QUEUE!"; exit(1); }
		return this->data[0];
	}

	T extract_min()
	{
		if (this->size == 0)
		{
			std::cout << "EMPTY HEAP!";
			exit(1);
		}
		T* new_data = new T[this->size - 1];
		
		const T min_key = this->data[0];
		this->data[0] = this->data[this->size - 1];
		
		for (int i = 0; i < this->size - 1; ++i) new_data[i] = this->data[i];
		
		delete[] this->data;
		--this->size;

		this->data = new_data;
		
		this->like_a_rock(0);

		return min_key;
	}

	void add(T key)
	{
		T* new_data = new T[this->size + 1];
		for (int i = 0; i < this->size; ++i) new_data[i] = this->data[i];
		new_data[this->size] = key;
		++this->size;
		
		delete[] this->data;
		
		this->data = new_data;

		this->like_a_bubble(this->size - 1);
	}


	void change_key(T old_key, T new_key)
	{
		int index = -1;
		for (int i = 0; i < this->size; ++i) if (this->data[i] == old_key) index = i;

		if (index < 0)
		{
			std::cout << "\nKEY DOES NOT EXIST!\n";
			return;
		}

		this->data[index] = new_key;


		if (new_key > old_key) { this->like_a_rock(index); }
		else this->like_a_bubble(index);
	}

	void show()
	{
		int tabulation_indicator = 2;
		int two_in_power = 2;

		if (this->size < 1) return;

		std::cout << "\nROOT " << this->data[0] << "\n";
		for (int i = 1; i < this->size; ++i)
		{

			if ((i - 1) % 2 == 0) { std::cout << "(LEFT " << this->data[i] << " | PARENT " << this->data[(i - 1) / 2] << ") "; }
			else std::cout << "(RIGHT " << this->data[i] << " | PARENT " << this->data[(i - 1) / 2] << ") ";

			if (tabulation_indicator == i)
			{
				two_in_power *= 2;
				tabulation_indicator += two_in_power;
				std::cout << "\n";
			}
		}
	}

	bool exist(T key)
	{
		for (int i = 0; i < this->size; ++i) if (this->data[i] == key) return true;

		return false;
	}

	int get_size()
	{
		return this->size;
	}

	~Binary_heap()
	{
		delete[] data;
		this->size = 0;
	}

};