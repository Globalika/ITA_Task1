#pragma once
#ifndef MY_ANY_TYPE_CLASS
#define MY_ANY_TYPE_CLASS
#include "string.h"
#include <string>
#include <typeinfo> 

class exceptionType
{
public:
	std::string whatStr = "", msg1 = "Bad cast from ", msg2 = " to ";
	exceptionType(const type_info& type1, const type_info& type2) noexcept
	{
		whatStr = msg1 + type1.name() + msg2 + type2.name() + "!";
	}
	const char* what() { return whatStr.c_str(); }
private:
};

class AnyType
{
public:
	AnyType() = delete;
	AnyType(bool b);
	AnyType(char ch);
	AnyType(short ch);
	AnyType(int i);
	AnyType(long i);
	AnyType(float f);
	AnyType(double d);
	AnyType(AnyType& other);
	AnyType(AnyType&& other) noexcept ;
	~AnyType();

	bool ToBool();
	char ToChar();
	short ToShort();
	int ToInt();
	long ToLong();
	float ToFloat();
	double ToDouble();

	AnyType& Swap(AnyType& otherValue);
	AnyType& operator=(bool value);
	AnyType& operator=(char value);
	AnyType& operator=(short value);
	AnyType& operator=(int value);
	AnyType& operator=(long value);
	AnyType& operator=(float value);
	AnyType& operator=(double value);
	const type_info& GetType();

private:
	enum class Types {
		BOOL,
		CHAR,
		SHORT,
		INT,
		LONG,
		FLOAT,
		DOUBLE,
	} *m_Type;
	union Value {
		bool b;
		char ch;
		short sh;
		int i;
		long l;
		float f;
		double d;
	} *m_Value;
};

#endif MY_ANY_TYPE_CLASS
