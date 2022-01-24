#pragma once

template <typename T>
class TestClass
{
public:
	T add(T lhs, T rhs);
private:
	T value;
};

template<typename T>
T TestClass<T>::add(T lhs, T rhs)
{
	return lhs + rhs;
}

