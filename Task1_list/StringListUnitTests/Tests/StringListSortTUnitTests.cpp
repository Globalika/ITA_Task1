#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsNamespace
{
	TEST_CLASS(StringListSortUnitTests)
	{
	public:
		TEST_METHOD(String_List_Bubble_Sort)
		{
			//arrange
			int expectedIndex1 = 0, expectedIndex2 = 3, expectedIndex3 = 4;
			//act
			StringListInit(&list);
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListPushFront(&list, "11");
			StringListSort(&list);
			int actualIndex1 = StringListIndexOf(&list, "11");
			int actualIndex2 = StringListIndexOf(&list, "22");
			int actualIndex3 = StringListIndexOf(&list, "33");
			//assert
			Assert::AreEqual(expectedIndex1, actualIndex1);
			Assert::AreEqual(expectedIndex2, actualIndex2);
			Assert::AreEqual(expectedIndex3, actualIndex3);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Bubble_Sort_When_Sorted)
		{
			//arrange
			int expectedIndex1 = 0, expectedIndex2 = 3, expectedIndex3 = 4;
			//act
			StringListInit(&list);
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "11");
			StringListPushFront(&list, "33");
			StringListPushFront(&list, "22");
			StringListPushFront(&list, "11");
			StringListSort(&list);
			//sort twise
			StringListSort(&list);
			int actualIndex1 = StringListIndexOf(&list, "11");
			int actualIndex2 = StringListIndexOf(&list, "22");
			int actualIndex3 = StringListIndexOf(&list, "33");
			//assert
			Assert::AreEqual(expectedIndex1, actualIndex1);
			Assert::AreEqual(expectedIndex2, actualIndex2);
			Assert::AreEqual(expectedIndex3, actualIndex3);
			StringListDestroy(&list);
		}
	private:
		char** list;
	};
}

//arrange
//act
//assert