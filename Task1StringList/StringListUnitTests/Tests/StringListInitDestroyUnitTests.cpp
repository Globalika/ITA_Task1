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
			StringListInit(&list);
			Assert::IsNotNull(list);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Initialize_Already_Initialized_List_Test)
		{
			StringListInit(&list);
			StringListInit(&list);
			Assert::IsNotNull(list);
			StringListDestroy(&list);
		}
		TEST_METHOD(String_List_Destroy_List_With_No_Element_Test)
		{
			StringListInit(&list);
			StringListDestroy(&list);
			Assert::IsNull(list);
		}
	private:
		char** list = NULL;
	};
}