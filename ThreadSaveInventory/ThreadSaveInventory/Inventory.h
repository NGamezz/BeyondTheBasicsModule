#pragma once

#include <vector>
#include <mutex>

template<typename T>
class Inventory
{
public:
	void Put(T& object);
	T Get(int index);
	std::vector<T> GetContents();

private:
	std::vector<T> data;
	std::mutex mutex;
};

template<typename T>
inline void Inventory<T>::Put(T& object)
{
	std::lock_guard<std::mutex> lock(mutex);
	data.push_back(object);
}

template<typename T>
inline T Inventory<T>::Get(int index)
{
	if (index > data.size() - 1)
	{
		return T();
	}

	std::lock_guard<std::mutex> lock(mutex);
	auto& currentObject = data[index];
	data.erase(currentObject);
	return currentObject;
}

template<typename T>
inline std::vector<T> Inventory<T>::GetContents()
{
	std::lock_guard<std::mutex> lock(mutex);
	return data;
}