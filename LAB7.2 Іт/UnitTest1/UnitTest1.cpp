#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "D:/LAB7.2 Іт/Project1/LAB7.2.cpp"

void SwapMinMaxRows(int** a, const int k, const int n);

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestSwapMinMaxRows_Simple)
		{
			int k = 1, n = 5;

			int** a = new int* [k];
			a[0] = new int[n] { 4, 9, -2, 7, 3 };

			SwapMinMaxRows(a, k, n);

			Assert::AreEqual(4, a[0][0]);
			Assert::AreEqual(-2, a[0][1]);
			Assert::AreEqual(9, a[0][2]);  
			Assert::AreEqual(7, a[0][3]);
			Assert::AreEqual(3, a[0][4]);

			delete[] a[0];
			delete[] a;
		}

		TEST_METHOD(TestSwapMinMaxRows_MultipleRows)
		{
			int k = 2, n = 4;

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			a[0][0] = 5; a[0][1] = 1; a[0][2] = 8; a[0][3] = 3;

			a[1][0] = 2; a[1][1] = 6; a[1][2] = -4; a[1][3] = 0;

			SwapMinMaxRows(a, k, n);

			Assert::AreEqual(5, a[0][0]);
			Assert::AreEqual(8, a[0][1]);
			Assert::AreEqual(1, a[0][2]); 
			Assert::AreEqual(3, a[0][3]);

			Assert::AreEqual(2, a[1][0]);
			Assert::AreEqual(-4, a[1][1]); 
			Assert::AreEqual(6, a[1][2]);  
			Assert::AreEqual(0, a[1][3]);

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSwapMinMaxRows_AllEqual)
		{
			int k = 1, n = 3;

			int** a = new int* [k];
			a[0] = new int[n] { 5, 5, 5 }; 

			SwapMinMaxRows(a, k, n);

			Assert::AreEqual(5, a[0][0]);
			Assert::AreEqual(5, a[0][1]);
			Assert::AreEqual(5, a[0][2]);

			delete[] a[0];
			delete[] a;
		}
	};
}
