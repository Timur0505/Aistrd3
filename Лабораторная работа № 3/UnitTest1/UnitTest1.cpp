#include "pch.h"
#include "CppUnitTest.h"
#include "..\Лабораторная работа № 3\BinaryHeap.cpp"
#include "..\Лабораторная работа № 3\Stack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Insert_Test)
		{
			BinaryHeap BH;
			BH.insert(0);
			Assert::AreEqual(BH.contains(0), true);
		}

		TEST_METHOD(Contains_Test1)
		{
			BinaryHeap BH;
			BH.insert(0);
			BH.insert(1);
			BH.insert(2);
			Assert::AreEqual(BH.contains(0), true);
		}

		TEST_METHOD(Contains_Test2)
		{
			BinaryHeap BH;
			BH.insert(0);
			Assert::AreEqual(BH.contains(100), false);
		}

		TEST_METHOD(Remove_Test1)
		{
			BinaryHeap BH;
			BH.insert(0);
			BH.insert(1);
			BH.remove(0);
			Assert::AreEqual(BH.contains(0), false);
		}

		TEST_METHOD(Remove_Test2)
		{
			BinaryHeap BH;
			try
			{
				BH.remove(0);
			}
			catch (const char* exception)
			{
				Assert::AreEqual(exception, "There is no such element");
			}
		}

		TEST_METHOD(bft_iterator_Test1)
		{
			BinaryHeap BH;
			BH.insert(15);
			BH.insert(3);
			BH.insert(29);
			BH.insert(13);
			Iterator* it = BH.create_bft_iterator();
			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(it->next(), BH.h[i]);
			}
		}

		TEST_METHOD(bft_iterator_Test2)
		{
			BinaryHeap BH;
			Iterator* it = BH.create_bft_iterator();
			try
			{
				it->has_next();
			}
			catch (const char* exception)
			{
				Assert::AreEqual(exception, "No more elements");
			}
		}

		TEST_METHOD(dft_iterator_Test1)
		{
			BinaryHeap BH;
			BH.insert(15);
			BH.insert(3);
			BH.insert(29);
			BH.insert(13);
			int check[4] = { 3, 13, 15, 29 };
			Iterator* it = BH.create_dft_iterator();
			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(it->next(), check[i]);
			}
		}

		TEST_METHOD(dft_iterator_Test2)
		{
			BinaryHeap BH;
			Iterator* it = BH.create_dft_iterator();
			try
			{
				it->has_next();
			}
			catch (const char* exception)
			{
				Assert::AreEqual(exception, "No more elements");
			}
		}
	};
}
