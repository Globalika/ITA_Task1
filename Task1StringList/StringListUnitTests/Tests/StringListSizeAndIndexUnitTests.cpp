#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringListUnitTests
{
	TEST_CLASS(StringListSizeAndIndexUnitTests)
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
		TEST_METHOD(String_List_Get_Size)
		{
			int expectedSize2 = 2;
			StringListPushBack(list, "2");
			StringListPushBack(list, "3");
			int actualSize2 = StringListSize(list);
			Assert::AreEqual(expectedSize2, actualSize2);
		}
		TEST_METHOD(String_List_Get_Size_When_No_Elements)
		{
			int actualSize = StringListSize(list);
			Assert::AreEqual(actualSize, 0);
		}
		TEST_METHOD(String_List_Get_Index)
		{
			int expectedIndex = 1;
			StringListPushBack(list, "1");
			StringListPushBack(list, "2");
			StringListPushBack(list, "3");
			int actualIndex = StringListIndexOf(list, "2");
			Assert::AreEqual(expectedIndex, actualIndex);
		}
		TEST_METHOD(String_List_Get_Index_When_No_Such_String)
		{
			int expectedIndex = -1;
			StringListPushBack(list, "1");
			StringListPushBack(list, "2");
			StringListPushBack(list, "3");
			int actualIndex = StringListIndexOf(list, "4");
			Assert::AreEqual(expectedIndex, actualIndex);
		}
		TEST_METHOD(String_List_Get_Index_When_No_Elements)
		{
			int expectedIndex = -1;
			int actualIndex = StringListIndexOf(list, "4");
			Assert::AreEqual(expectedIndex, actualIndex);
		}
	private:
		char** list = NULL;
	};
}