#include "..\..\Task2_AnyType\src\AnyType.h"
#include <iostream>

using namespace std;

int main()
{
	AnyType anyType = 1, anyType2 = '2';
	//anyType.Swap(anyType2);
	//AnyType anyType3 = anyType2;
	//AnyType anyType4 = std::move(anyType2);
	//anyType = true;
	//anyType = 1.7;
	//double storedValue2 = anyType.ToDouble();
	int value = anyType.ToInt();
	try
	{
		char storedValue = anyType.ToChar();
	}
	catch (exceptionType& ex)
	{
		cout << ex.what();
	}

	return 0;
}