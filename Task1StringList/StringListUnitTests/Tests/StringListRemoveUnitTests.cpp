#include "pch.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringListUnitTests
{
	TEST_CLASS(StringListRemoveUnitTests)
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
		TEST_METHOD(String_List_Pop_Back_When_No_Elements)
		{
			StringListPopBack(list);
			int size = StringListSize(list);
			Assert::AreEqual(size, 0);
		}
		TEST_METHOD(String_List_Pop_Front_When_No_Elements)
		{
			StringListPopFront(&list);
			int size = StringListSize(list);
			Assert::AreEqual(size, 0);
		}
		TEST_METHOD(String_List_Pop_Back_One_Element)
		{
			int expectedSize2 = 2;
			StringListPushBack(list, "11");
			StringListPushBack(list, "33");
			StringListPushBack(list, "22");
			StringListPopBack(list);
			int actualSize2 = StringListSize(list);
			Assert::AreEqual(expectedSize2, actualSize2);
		}
		TEST_METHOD(String_List_Pop_Front_One_Element)
		{
			int  expectedSize2 = 2;
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListPopFront(&list);
			int actualSize2 = StringListSize(list);
			Assert::AreEqual(expectedSize2, actualSize2);
		}
		TEST_METHOD(String_List_Remove_Duplicates_When_No_Such)
		{
			int expectedSize = 3;
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListRemoveDuplicates(&list);
			int actualSize = StringListSize(list);
			Assert::AreEqual(expectedSize, actualSize);
		}
		TEST_METHOD(String_List_Remove_Duplicates)
		{
			int expectedSize = 3;
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListRemoveDuplicates(&list);
			int actualSize = StringListSize(list);
			Assert::AreEqual(expectedSize, actualSize);
		}
		TEST_METHOD(String_List_Remove_All_Occurrences_When_No_Such)
		{
			int expectedSize = 7;
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListRemove(&list, "55");
			int actualSize = StringListSize(list);
			Assert::AreEqual(expectedSize, actualSize);
		}
		TEST_METHOD(String_List_Remove_All_Occurrences)
		{
			int expectedSize = 4;
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListRemove(&list, "11");
			int actualSize = StringListSize(list);
			Assert::AreEqual(expectedSize, actualSize);
		}
	private:
		char** list = NULL;
	};
}