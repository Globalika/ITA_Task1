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
			Assert::IsNotNull(list);
		}
		TEST_METHOD(String_List_Pop_Front_When_No_Elements)
		{
			StringListPopFront(&list);
			int size = StringListSize(list);
			Assert::AreEqual(size, 0);
			Assert::IsNotNull(list);
		}
		TEST_METHOD(String_List_Pop_Back_One_Element)
		{
			int expectedSize1 = 3, expectedSize2 = 2, expectedSize3 = 0;
			StringListPushBack(list, "11");
			StringListPushBack(list, "33");
			StringListPushBack(list, "22");
			int actualSize1 = StringListSize(list);
			StringListPopBack(list);
			int actualSize2 = StringListSize(list);
			StringListPopBack(list);
			StringListPopBack(list);
			int actualSize3 = StringListSize(list);
			Assert::AreEqual(expectedSize1, actualSize1);
			Assert::AreEqual(expectedSize2, actualSize2);
			Assert::AreEqual(expectedSize3, actualSize3);
		}
		TEST_METHOD(String_List_Pop_Front_One_Element)
		{
			int expectedSize1 = 3, expectedSize2 = 2, expectedSize3 = 0;
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			int actualSize1 = StringListSize(list);
			StringListPopFront(&list);
			int actualSize2 = StringListSize(list);
			StringListPopFront(&list);
			StringListPopFront(&list);
			int actualSize3 = StringListSize(list);
			Assert::AreEqual(expectedSize1, actualSize1);
			Assert::AreEqual(expectedSize2, actualSize2);
			Assert::AreEqual(expectedSize3, actualSize3);
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