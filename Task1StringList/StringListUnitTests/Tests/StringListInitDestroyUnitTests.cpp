#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringListUnitTests
{
	TEST_CLASS(StringListInitDestroyUnitTests)
	{
	public:
		TEST_METHOD(String_List_Initialize_Test)
		{
			Assert::IsNull(list);
			StringListInit(&list);
			Assert::IsNotNull(list);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Initialize_Already_Initialized_List_Test)
		{
			Assert::IsNull(list);
			StringListInit(&list);
			StringListInit(&list);
			Assert::IsNotNull(list);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Destroy_List_With_No_Element_Test)
		{
			Assert::IsNull(list);
			StringListInit(&list);
			StringListDestroy(&list);
			Assert::IsNull(list);
		}
		TEST_METHOD(String_List_Destroy_Already_Destroyed_List)
		{
			Assert::IsNull(list);
			StringListInit(&list);
			StringListDestroy(&list);
			Assert::IsNull(list);
			StringListDestroy(&list);
			Assert::IsNull(list);
		}
		TEST_METHOD(String_List_Destroy_List_With_One_Element_Test)
		{
			Assert::IsNull(list);
			StringListInit(&list);
			StringListPushBack(list, "element1");
			StringListDestroy(&list);
			Assert::IsNull(list);
		}
		TEST_METHOD(String_List_Destroy_List_With_Several_Elements_Test)
		{
			Assert::IsNull(list);
			StringListInit(&list);
			StringListPushBack(list, "element1");
			StringListPushFront(&list, "element2");
			StringListDestroy(&list);
			Assert::IsNull(list);
		}
	private:
		char** list = NULL;
	};
}