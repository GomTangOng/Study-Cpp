// C++_Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "clause_3.h"

int main()
{
	TextBlock tb("Hello");
	cout << tb[0] << endl;

	const TextBlock ctb("World");
	cout << ctb[0] << endl;

	tb[0] = 'x';
	//ctb[0] = 'x'; // ¿¡·¯

    return 0;
}

