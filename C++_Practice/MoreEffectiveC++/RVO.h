#pragma once

// RVO Example
class Rational
{
public :
	int m_numerator;
	int m_denominator;

	Rational(int numerator = 0, int denominator = 1)
	{
		m_numerator = numerator;
		m_denominator = denominator;
	}
	int numerator() const { return m_numerator;}
	int denominator() const { return m_denominator;}
};

// Rational c = *(a * b); <-- 이상...
// & *의 반환은 위험..

/*const Rational* operator*(const Rational& lhs, const Rational& rhs)
{
...
}*/

/*const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
...
}*/

// 컴파일러가 최적화하게 하는 방법
const Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

// 더 좋은 방법
inline const Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}