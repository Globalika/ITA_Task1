#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsNamespace
{
	TEST_CLASS(StringListRemoveUnitTests)
	{
	public:
		TEST_METHOD(String_List_Pop_Back_When_No_Elements)
		{
			//act
			StringListInit(&list);
			StringListPopBack(&list);
			//assert
			int size = StringListSize(&list);
			Assert::AreEqual(size, 0);
			Assert::IsNull(list);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Pop_Front_When_No_Elements)
		{
			//act
			StringListInit(&list);
			StringListPopFront(&list);
			//assert
			int size = StringListSize(&list);
			Assert::AreEqual(size, 0);
			Assert::IsNull(list);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Pop_Back_One_Element)
		{
			//arrange
			int expectedSize1 = 3, expectedSize2 = 2, expectedSize3 = 0;
			//act
			StringListInit(&list);
			StringListPushBack(&list, "11");
			StringListPushBack(&list, "33");
			StringListPushBack(&list, "22");
			int actualSize1 = StringListSize(&list);
			StringListPopBack(&list);
			int actualSize2 = StringListSize(&list);
			StringListPopBack(&list);
			StringListPopBack(&list);
			int actualSize3 = StringListSize(&list);
			//assert
			Assert::AreEqual(expectedSize1, actualSize1);
			Assert::AreEqual(expectedSize2, actualSize2);
			Assert::AreEqual(expectedSize3, actualSize3);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Pop_Front_One_Element)
		{
			//arrange
			int expectedSize1 = 3, expectedSize2 = 2, expectedSize3 = 0;
			//act
			StringListInit(&list);
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			int actualSize1 = StringListSize(&list);
			StringListPopFront(&list);
			int actualSize2 = StringListSize(&list);
			StringListPopFront(&list);
			StringListPopFront(&list);
			int actualSize3 = StringListSize(&list);
			//assert
			Assert::AreEqual(expectedSize1, actualSize1);
			Assert::AreEqual(expectedSize2, actualSize2);
			Assert::AreEqual(expectedSize3, actualSize3);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Remove_Duplicates_When_No_Such)
		{
			//arrange
			int expectedSize = 3;
			//act
			StringListInit(&list);
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListRemoveDuplicates(&list);
			//assert
			int actualSize = StringListSize(&list);
			Assert::AreEqual(expectedSize, actualSize);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Remove_Duplicates)
		{
			//arrange
			int expectedSize = 3;
			//act
			StringListInit(&list);
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListRemoveDuplicates(&list);
			//assert
			int actualSize = StringListSize(&list);
			Assert::AreEqual(expectedSize, actualSize);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Remove_All_Occurrences_When_No_Such)
		{
			//arrange
			int expectedSize = 7;
			//act
			StringListInit(&list);
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListRemove(&list, "55");
			//assert
			int actualSize = StringListSize(&list);
			Assert::AreEqual(expectedSize, actualSize);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Remove_All_Occurrences)
		{
			//arrange
			int expectedSize = 4;
			//act
			StringListInit(&list);
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListRemove(&list, "11");
			//assert
			int actualSize = StringListSize(&list);
			Assert::AreEqual(expectedSize, actualSize);
			StringListDestroy(&list);
		}
	private:
		char** list;
	};
}

//arrange
//act
//assert