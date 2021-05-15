#include "AnyType.h"
using namespace std;


AnyType::AnyType(bool b)
{
	m_Type = new Types();
	*m_Type = Types::BOOL;
	m_Value = new Value();
	(*m_Value).b = b;
}

AnyType::AnyType(char ch)
{
	m_Type = new Types();
	*m_Type = Types::CHAR;
	m_Value = new Value();
	(*m_Value).ch = ch;
}

AnyType::AnyType(short sh)
{
	m_Type = new Types();
	*m_Type = Types::SHORT;
	m_Value = new Value();
	(*m_Value).sh = sh;
}

AnyType::AnyType(int i)
{
	m_Type = new Types();
	*m_Type = Types::INT;
	m_Value = new Value();
	(*m_Value).i = i;
}

AnyType::AnyType(long l)
{
	m_Type = new Types();
	*m_Type = Types::LONG;
	m_Value = new Value();
	(*m_Value).l = l;
}

AnyType::AnyType(float f)
{
	m_Type = new Types();
	*m_Type = Types::FLOAT;
	m_Value = new Value();
	(*m_Value).f = f;
}

AnyType::AnyType(double d)
{
	m_Type = new Types();
	*m_Type = Types::DOUBLE;
	m_Value = new Value();
	(*m_Value).d = d;
}

AnyType::AnyType(AnyType& other)
{
	m_Type = new Types();
	*m_Type = *other.m_Type;
	m_Value = new Value();
	*m_Value = *other.m_Value;
}

AnyType::AnyType(AnyType&& other) noexcept
{
	m_Type = other.m_Type;
	m_Value = other.m_Value;
	other.m_Type = nullptr;
	other.m_Value = nullptr;
}

AnyType::~AnyType()
{
	delete this->m_Type;
	delete this->m_Value;
}

bool AnyType::ToBool()
{
	if (typeid(bool) == GetType())
		return (*m_Value).b;
	else
		throw exceptionType(GetType(), typeid(bool));
}

char AnyType::ToChar()
{
	if (typeid(char) == GetType())
		return (*m_Value).ch;
	else
		throw exceptionType(GetType(), typeid(char));
}

short AnyType::ToShort()
{
	if (typeid(short) == GetType())
		return (*m_Value).sh;
	else
		throw exceptionType(GetType(), typeid(short));
}

int AnyType::ToInt()
{
	if (typeid(int) == GetType())
		return (*m_Value).i;
	else
		throw exceptionType(GetType(), typeid(int));
}

long AnyType::ToLong()
{
	if (typeid(long) == GetType())
		return (*m_Value).l;
	else
		throw exceptionType(GetType(), typeid(long));
}

float AnyType::ToFloat()
{
	if (typeid(float) == GetType())
		return (*m_Value).f;
	else
		throw exceptionType(GetType(), typeid(float));
}

double AnyType::ToDouble()
{
	if (typeid(double) == GetType())
		return (*m_Value).d;
	else
		throw exceptionType(GetType(), typeid(double));
}

AnyType& AnyType::operator=(bool value)
{
	(*m_Value).b = value;
	*m_Type = Types::BOOL;
	return *this;
}

AnyType& AnyType::operator=(char value)
{
	(*m_Value).ch = value;
	*m_Type = Types::CHAR;
	return *this;
}

AnyType& AnyType::operator=(short value)
{
	(*m_Value).sh = value;
	*m_Type = Types::SHORT;
	return *this;
}

AnyType& AnyType::operator=(int value)
{
	(*m_Value).i = value;
	*m_Type = Types::INT;
	return *this;
}

AnyType& AnyType::operator=(long value)
{
	(*m_Value).l = value;
	*m_Type = Types::LONG;
	return *this;
}

AnyType& AnyType::operator=(float value)
{
	(*m_Value).f = value;
	*m_Type = Types::FLOAT;
	return *this;
}

AnyType& AnyType::operator=(double value)
{
	(*m_Value).d = value;
	*m_Type = Types::DOUBLE;
	return *this;
}

AnyType& AnyType::Swap(AnyType& other)
{
	Types buffType = *m_Type;
	Value buffValue = *m_Value;
	*m_Type = *other.m_Type;
	*m_Value = *other.m_Value;
	*other.m_Type = buffType;
	*other.m_Value = buffValue;
	return *this;
}

const type_info& AnyType::GetType()
{
	switch (*m_Type)
	{
	case Types::BOOL:
	{
		return typeid((*m_Value).b);
	}
	case Types::CHAR:
	{
		return typeid((*m_Value).ch);
	}
	case Types::SHORT:
	{
		return typeid((*m_Value).sh);
	}
	case Types::INT:
	{
		return typeid((*m_Value).i);
	}
	case Types::LONG:
	{
		return typeid((*m_Value).l);
	}
	case Types::FLOAT:
	{
		return typeid((*m_Value).f);
	}
	case Types::DOUBLE:
	{
		return typeid((*m_Value).d);
	}
	}
}


