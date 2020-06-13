#pragma once


template <class T>
class super_pair
{
public:
	int priority = 0;
	T value = 0;

public:

	super_pair()
	{
		this->priority = 0;
		this->value = 0;
	}

	super_pair(int priority, T value)
	{
		this->priority = priority;
		this->value = value;
	}

	super_pair& operator = (const super_pair& super_pair_c)
	{

		this->value = super_pair_c.value;
		this->priority = super_pair_c.priority;

		return *this;
	}

	bool operator > (super_pair& super_pair_c)
	{
		return (this->priority > super_pair_c.priority);
	}

	bool operator >= (super_pair& super_pair_c)
	{
		return (this->priority >= super_pair_c.priority);
	}

	bool operator < (super_pair& super_pair_c)
	{
		return (this->priority < super_pair_c.priority);
	}

	bool operator <= (super_pair& super_pair_c)
	{
		return (this->priority <= super_pair_c.priority);
	}

	bool operator == (super_pair& super_pair_c)
	{
		return (this->priority == super_pair_c.priority && this->value == super_pair_c.value);
	}

	~super_pair() = default;

};

template <class T>
class Priority_queue
{
private:


	Binary_heap<super_pair<T>>* queue;

public:

	Priority_queue(const int priority, const T value)
	{
		this->queue = new Binary_heap<super_pair<T>>(super_pair<T>(priority, value));
	}

	~Priority_queue() = default;
	void add(const int priority, const T value)
	{
		this->queue->add(super_pair<T>(priority, value));
	}

	T extract()
	{
		if (this->queue->get_size() == 0)
		{
			std::cout << "QUEUE IS EMPTY!";
			return T(0);
		}
		return this->queue->extract_min().value;
	}

	bool exist(const int priority, const T value)
	{
		return this->queue->exist(super_pair<T>(priority, value));
	}
	
};
