#pragma once

template<typename T>
class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(const T* array, int size);
	DynamicArray(const DynamicArray<T>& other);
	~DynamicArray();

	DynamicArray<T>& operator=(const DynamicArray<T>& other);
	T& operator[](int index);
	const T& operator[](int index) const;

	int Length() const;
	void Resize(int newSize);

	T* begin();
	const T* begin() const;
	T* end();
	const T* end() const;

	void Add(const T& value);
	void Add(const T* array, int size);
	void Add(const DynamicArray<T>& other);
	void AddUnique(const T& value);
	void Insert(int index, const T& value);
	void Insert(int index, const T* array, int size);
	void Insert(int index, const DynamicArray<T>& other);
	void Remove(int index);
	void Remove(const T& value);
	void Remove(const T* array, int size);
	void Remove(const DynamicArray<T>& other);
	void RemoveAll(const T& value);
	void Clear();

private:
	T* m_array;
	int m_length;
};