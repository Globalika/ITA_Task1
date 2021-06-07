#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringListUnitTests
{
	TEST_CLASS(StringListSortUnitTests)
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
		TEST_METHOD(String_List_Bubble_Sort)
		{
			int expectedIndex1 = 0, expectedIndex2 = 3, expectedIndex3 = 4;
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListPushFront(&list, "11");
			StringListBubbleSort(list);
			int actualIndex1 = StringListIndexOf(list, "11");
			int actualIndex2 = StringListIndexOf(list, "22");
			int actualIndex3 = StringListIndexOf(list, "33");
			Assert::AreEqual(expectedIndex1, actualIndex1);
			Assert::AreEqual(expectedIndex2, actualIndex2);
			Assert::AreEqual(expectedIndex3, actualIndex3);
		}
		TEST_METHOD(String_List_Bubble_Sort_When_Sorted)
		{
			int expectedIndex1 = 0, expectedIndex2 = 3, expectedIndex3 = 4;
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListPushFront(&list, "11");
			StringListBubbleSort(list);
			StringListBubbleSort(list);
			int actualIndex1 = StringListIndexOf(list, "11");
			int actualIndex2 = StringListIndexOf(list, "22");
			int actualIndex3 = StringListIndexOf(list, "33");
			Assert::AreEqual(expectedIndex1, actualIndex1);
			Assert::AreEqual(expectedIndex2, actualIndex2);
			Assert::AreEqual(expectedIndex3, actualIndex3);
		}
		TEST_METHOD(String_List_Quick_Sort)
		{
			int expectedIndex1 = 0, expectedIndex2 = 3, expectedIndex3 = 4;
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListPushFront(&list, "11");
			StringListQuickSort(&list);
			int actualIndex1 = StringListIndexOf(list, "11");
			int actualIndex2 = StringListIndexOf(list, "22");
			int actualIndex3 = StringListIndexOf(list, "33");
			Assert::AreEqual(expectedIndex1, actualIndex1);
			Assert::AreEqual(expectedIndex2, actualIndex2);
			Assert::AreEqual(expectedIndex3, actualIndex3);
		}
		TEST_METHOD(String_List_Quick_Sort_When_Sorted)
		{
			int expectedIndex1 = 0, expectedIndex2 = 3, expectedIndex3 = 4;
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListPushFront(&list, "11");
			StringListQuickSort(&list);
			StringListQuickSort(&list);
			int actualIndex1 = StringListIndexOf(list, "11");
			int actualIndex2 = StringListIndexOf(list, "22");
			int actualIndex3 = StringListIndexOf(list, "33");
			Assert::AreEqual(expectedIndex1, actualIndex1);
			Assert::AreEqual(expectedIndex2, actualIndex2);
			Assert::AreEqual(expectedIndex3, actualIndex3);
		}
	private:
		char** list = NULL;
	};
}
