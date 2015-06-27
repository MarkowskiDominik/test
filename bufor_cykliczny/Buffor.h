#pragma once
#include <memory>
#include <utility>

template<typename T, typename A = std::allocator<T>>
class Buffor
{
public:
	//declaration alias
	using value_type = T;
	using size_type = typename std::allocator<T>::size_type;
	using reference = value_type&;
	using allocator_type = A;
	using iterator = T*;
	using const_iterator = const T*;
	
	//constructors
	explicit Buffor(const A& a = A())
		: alloc(a), elem(nullptr), add(nullptr), get(nullptr), size(0), count(0)
	{}

	explicit Buffor(size_type size, const T& val = T(), const A& a = A())
		: alloc(a), elem(alloc.allocate(size)), add(elem), get(elem), size(size), count(0)
	{
		uninitialized_fill(begin(), end(), val);
	}

	Buffor(const Buffor& b)
		: alloc(b.alloc), elem(alloc.allocate(b.size)), add(elem + (b.add - b.elem)), get(elem + (b.get - b.elem)), size(b.size), count(b.count)
	{
		uninitialized_copy(b.cbegin(), b.cend(), begin());
	}

	Buffor(Buffor&& b) : alloc(b.alloc), elem(b.elem), add(b.add), get(b.get), size(b.size), count(b.count)
	{
		b.elem = b.add = b.get = nullptr;
		b.size = b.count = 0;
	}

	explicit Buffor(std::initializer_list<T> il, const A& a = A())
		: alloc(a), elem(alloc.allocate(il.size())), add(elem), get(elem), size(il.size()), count(il.size())
	{
		uninitialized_copy(il.begin(), il.end(), begin());
	}

	//destructor
	~Buffor()
	{
		for (size_type i = 0; i < get_size(); i++)
			alloc.destroy(elem + i);
		alloc.deallocate(elem, get_size());
	}

	//add delete operations
	void enqueue(const T& val)
	{
		if (!full())
		{

		}
		else
			throw exception;
	}

	void enqueue(T&& val)
	{
		if (!full())
		{

		}
		else
			throw exception;
	}

	reference dequeue() const
	{
		if (!empty())
		{

		}
		else
			throw exception;
	}

	//operator=
	Buffor& operator=(const Buffor& b)
	{
		if (v != this)
		{
			for (size_type i = 0; i < get_size(); i++)
				alloc.destroy(elem + i);
			alloc.deallocate(elem, get_size());

			alloc = b.alloc;
			size = b.get_size();
			count = b.get_count();
			elem(alloc.allocate(size));
			add(elem + (b.add - b.elem));
			get(elem + (b.get - b.elem))

			uninitialized_copy(b.cbegin(), b.cend(), begin());
			//uninitialized_copy_n(b.cbegin(), b.size(), begin());
		}
		return *this;
	}
	Buffor& operator=(Buffor&& b)
	{
		if (v != this)
		{
			for (size_type i = 0; i < get_size(); i++)
				alloc.destroy(elem + i);
			alloc.deallocate(elem, get_size());

			alloc = b.alloc;
			size = b.get_size();
			count = b.get_count();
			elem(b.elem);
			add(b.add);
			get(b.get);

			b.elem = b.add = b.get = nullptr;
			b.size = b.count = 0;
		}
		return *this;
	}
	Buffor& operator=(std::initializer_list<T> il)
	{
		for (size_type i = 0; i < get_size(); i++)
			alloc.destroy(elem + i);
		alloc.deallocate(elem, get_size());

		elem = alloc.allocate(il.size());
		size = count = il.size();
		add = get = elem;

		if (il.size() != 0) uninitialized_copy(il.begin(), il.end(), begin());
		//if (il.size() != 0) uninitialized_copy_n(il.begin(), il.size(), begin());
	}

	//extra function
	void swap(Buffor& b)
	{
		Buffor tmp(std::move(v));
		v = std::move(*this);
		*this = std::move(tmp);
	}

	bool empty() const { return (count == 0); }
	
	bool full() const { return (count == size); }
	
	size_type get_size() const { return size; }

	size_type get_count() const { return count; }

	void resize(size_type newSize, const T& = {})
	{

	}

	void clear()
	{
		for (size_type i = 0; i < size(); i++)
			alloc.destroy(elem + i);
		count = 0;
		add = get = elem;
	}

	//iterators
	iterator begin() { return elem; }
	iterator end() { return elem + get_size(); }
	const_iterator cbegin() const { return elem; }
	const_iterator cend() const { return elem + get_size(); }

private:
	T* elem;
	T* add;
	T* get;
	size_type size;
	size_type count;
	A alloc;
};