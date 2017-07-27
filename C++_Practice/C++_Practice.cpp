// C++_Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "clause_3.h"
#include "clause_6.h"

int main()
{
	string newDog("Persephone");
	string oldDog("Satch");
	NamedObject<int> p(newDog, 2);
	NamedObject<int> s(oldDog, 36);

	p = s;
    return 0;
}

