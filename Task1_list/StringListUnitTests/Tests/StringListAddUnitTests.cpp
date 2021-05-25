#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsNamespace
{
	TEST_CLASS(StringListAddUnitTests)
	{
	public:
		TEST_METHOD(String_List_Push_Back_One_Element)
		{
			//arrange
			const char* expectedString = "111";
			//act
			StringListInit(&list);
			StringListPushBack(&this->list, "111");
			//assert
			Assert::AreEqual(expectedString, (*&this->list)[1]);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Push_Back_Several_Elements)
		{
			//arrange
			int expectedIndex = 2;
			//act
			StringListInit(&list);
			StringListPushBack(&list, "222");
			StringListPushBack(&list, "333");
			StringListPushBack(&list, "111");
			int actualIndex = StringListIndexOf(&list, "111");
			//assert
			Assert::AreEqual(expectedIndex, actualIndex);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Push_Front_One_Element)
		{
			//arrange
			const char* expectedString = "111";
			//act
			StringListInit(&list);
			StringListPushFront(&list, "111");
			//assert
			Assert::AreEqual(expectedString, (*&list)[1]);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Push_Front_Several_Elements)
		{
			//arrange
			int expectedIndex = 0;
			//act
			StringListInit(&list);
			StringListPushFront(&list, "222");
			StringListPushFront(&list, "333");
			StringListPushFront(&list, "111");
			int actualIndex = StringListIndexOf(&list, "111");
			//assert
			Assert::AreEqual(expectedIndex, actualIndex);
			StringListDestroy(&list);
		}
	private:
		char** list;
	};
}