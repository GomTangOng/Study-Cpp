#pragma once
#include <cstring>

template <class T>
class NamedObject
{
public :
	NamedObject(string& name, const T& value) : nameValue(name), objectValue(value) {}
private :
	string& nameValue;
	const T objectValue;
};