#pragma once
#include "stdafx.h"

class TextBlock
{
public :
	TextBlock(const char* _text)
	{
		text = _text;
		cout << "TextBlock 생성자입니다\n";
	}
	~TextBlock()
	{
		text.clear();	
		cout << "TextBlock 소멸자입니다\n";
	}

	const char& operator[](std::size_t position) const
	{
		cout << "TextBlock 상수 operator 입니다\n";
		return text[position];
	}

	//char& operator[] (std::size_t position)			// Old Version
	//{
	//	cout << "TextBlock 비상수 operator 입니다\n";
	//	return text[position];
	//}

	char operator[] (std::size_t position)				// New Version
	{
		return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
	}
private :
	std::string text;
};

class CTextBlock
{
public :
	CTextBlock(const char* _text)
	{
		memcpy(pText, _text, strlen(_text) + 1);
	}
	~CTextBlock()
	{
		delete[] pText;
	}

	char& operator[](size_t position) const	// 부적절한(그러나 비트수준
	{										// 상수성이 있어서 허용되는)
		return pText[position];				// operator[]의 선언
	}
	
	size_t CTextBlock::length() const
	{
		if (!lengthIsValid)
		{
			textlength = strlen(pText);
			lengthIsValid = true;
		}
		return textlength;
	}
private :
	char *pText;
	mutable size_t textlength;		// 비트수준 상수성(bitwise constness)을 제거하는 키워드인 mutable
	mutable bool lengthIsValid;
};

//TextBlock tb("Hello");
//cout << tb[0] << endl;

//const TextBlock ctb("World");
//cout << ctb[0] << endl;
//
//tb[0] = 'x';
//ctb[0] = 'x'; // 에러 --> 반환 타입이 다르다.

//const CTextBlock cctb("Hello");
//char *pc = &cctb[0];
//*pc = 'J';

//char ch[128];