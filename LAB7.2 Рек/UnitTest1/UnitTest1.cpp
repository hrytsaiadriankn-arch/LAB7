#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "D:/LAB7.2 Рек/Project1/LAB7.2.cpp"

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestFindMinMaxIndex)
		{
			int n = 5;
			int** a = new int* [1];
			a[0] = new int[n] { 7, -2, 15, 0, 9 };

			int minI = 0;
			int maxI = 0;

			FindMinIndexRec(a, 0, 1, n, minI);
			FindMaxIndexRec(a, 0, 1, n, maxI);

			Assert::AreEqual(1, minI); 
			Assert::AreEqual(2, maxI);

			delete[] a[0];
			delete[] a;
		}

		TEST_METHOD(TestSwapRowMinMax)
		{
			int n = 4;
			int** a = new int* [1];
			a[0] = new int[n] { 3, 8, -1, 5 };

			int minI = 2; 
			int maxI = 1;

			SwapRowMinMax(a, 0, minI, maxI);

			Assert::AreEqual(3, a[0][0]);
			Assert::AreEqual(-1, a[0][1]);
			Assert::AreEqual(8, a[0][2]);
			Assert::AreEqual(5, a[0][3]);

			delete[] a[0];
			delete[] a;
		}

		TEST_METHOD(TestSwapMinMaxRowsRec)
		{
			int k = 2, n = 4;

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			a[0][0] = 4;  a[0][1] = -3; a[0][2] = 7;  a[0][3] = 10;

			a[1][0] = 1;  a[1][1] = 5;  a[1][2] = 9;  a[1][3] = 2;

			SwapMinMaxRowsRec(a, 0, k, n);

			Assert::AreEqual(4, a[0][0]);
			Assert::AreEqual(10, a[0][1]);
			Assert::AreEqual(7, a[0][2]);
			Assert::AreEqual(-3, a[0][3]); 

			Assert::AreEqual(9, a[1][0]); 
			Assert::AreEqual(5, a[1][1]);
			Assert::AreEqual(1, a[1][2]); 
			Assert::AreEqual(2, a[1][3]);

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
