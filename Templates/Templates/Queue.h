#pragma once
#include <Iostream>
#include <vector>

namespace Custom {

	template<typename T>
	class Queue
	{
	public:

		T Get() const;
		double Size() const;
		void Put(const T& value);

	private:
		std::vector<T> data;
	};

	template<typename T>
	inline T Queue<T>::Get() const
	{
		if (data.size() >= 1)
		{
			T firstElement = data[0];
			return firstElement;
		}
		std::cout << "There are no elements stored in the Queue" << std::endl;
		return T();
	}

	template<typename T>
	inline double Queue<T>::Size() const
	{
		return data.size();
	}

	template<typename T>
	inline void Queue<T>::Put(const T& value)
	{
		data.push_back(value);
	}
}