#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsNamespace
{
	TEST_CLASS(StringListSizeAndIndexUnitTests)
	{
	public:
		TEST_METHOD(String_List_Get_Size)
		{
			//arrange
			int expectedSize1 = 1, expectedSize2 = 3;
			//act
			StringListInit(&list);
			StringListPushBack(&list,"1");
			int actualSize1 = StringListSize(&list);
			StringListPushBack(&list, "2");
			StringListPushBack(&list, "3");
			int actualSize2 = StringListSize(&list);
			Assert::AreEqual(expectedSize1, actualSize1);
			Assert::AreEqual(expectedSize2, actualSize2);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Get_Size_When_No_Elements)
		{
			StringListInit(&list);
			int actualSize = StringListSize(&list);
			Assert::AreEqual(actualSize, 0);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Get_Index)
		{
			//arrange
			int expectedIndex = 1;
			//act
			StringListInit(&list);
			StringListPushBack(&list, "1");
			StringListPushBack(&list, "2");
			StringListPushBack(&list, "3");
			int actualIndex = StringListIndexOf(&list, "2");
			//assert
			Assert::AreEqual(expectedIndex, actualIndex);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Get_Index_When_No_Such_String)
		{
			//arrange
			int expectedIndex = -1;
			//act
			StringListInit(&list);
			StringListPushBack(&list, "1");
			StringListPushBack(&list, "2");
			StringListPushBack(&list, "3");
			int actualIndex = StringListIndexOf(&list, "4");
			//assert
			Assert::AreEqual(expectedIndex, actualIndex);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Get_Index_When_No_Elements)
		{
			//arrange
			int expectedIndex = -1;
			//act
			StringListInit(&list);
			int actualIndex = StringListIndexOf(&list, "4");
			//assert
			Assert::AreEqual(expectedIndex, actualIndex);
			StringListDestroy(&list);
		}
	private:
		char** list;
	};
}