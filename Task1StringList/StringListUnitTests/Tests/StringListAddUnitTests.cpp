#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringListUnitTests
{

	TEST_CLASS(StringListAddUnitTests)
	{
	public:
		TEST_METHOD_INITIALIZE(Init)
		{
			StringListInit(&list);
		}
		TEST_METHOD_CLEANUP(Clear)
		{
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Push_Back_One_Element)
		{
			const char* expectedString = "111";
			StringListPushBack(list, "111");
			Assert::AreEqual(expectedString, list[1]);
		}
		TEST_METHOD(String_List_Push_Back_Several_Elements)
		{
			int expectedIndex = 2;
			StringListPushBack(list, "222");
			StringListPushBack(list, "333");
			StringListPushBack(list, "111");
			int actualIndex = StringListIndexOf(list, "111");
			Assert::AreEqual(expectedIndex, actualIndex);
		}
		TEST_METHOD(String_List_Push_Front_One_Element)
		{
			const char* expectedString = "111";
			StringListPushFront(&list, "111");
			Assert::AreEqual(expectedString, list[1]);
		}
		TEST_METHOD(String_List_Push_Front_Several_Elements)
		{
			int expectedIndex = 0;
			StringListPushFront(&list, "222");
			StringListPushFront(&list, "333");
			StringListPushFront(&list, "111");
			int actualIndex = StringListIndexOf(list, "111");
			Assert::AreEqual(expectedIndex, actualIndex);
			Assert::AreEqual(1, 1);
			Assert::AreNotEqual(1, 2);
			int a = 0, b = 0;
			int* p = NULL;
			Assert::AreSame(a, a);
			Assert::AreNotSame(a, b);
			Assert::IsNull(p);
			Assert::IsTrue(true);
		}
	private:
		char** list = NULL;
	};
}