#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "D:/LAB7.3 Іт/Project1/LAB7.3.cpp"

void ShiftRight(int** a, int n, int k);
int LastMaxZeroCol(int** a, int n);

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestShiftRight_OneStep)
		{
			int n = 3;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];

			int val = 1;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					a[i][j] = val++;

			ShiftRight(a, n, 1);

			Assert::AreEqual(4, a[0][0]);
			Assert::AreEqual(1, a[0][1]);
			Assert::AreEqual(2, a[0][2]);
			Assert::AreEqual(7, a[1][0]);
			Assert::AreEqual(5, a[1][1]); 
			Assert::AreEqual(3, a[1][2]);
			Assert::AreEqual(8, a[2][0]);
			Assert::AreEqual(9, a[2][1]);
			Assert::AreEqual(6, a[2][2]);

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestShiftRight_FullCycle)
		{
			int n = 3;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];

			int original[3][3] = { {1,2,3},{4,5,6},{7,8,9} };

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					a[i][j] = original[i][j];

			int total = 4 * (n - 1);
			ShiftRight(a, n, total); 

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					Assert::AreEqual(original[i][j], a[i][j]);

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestLastMaxZeroCol_Basic)
		{
			int n = 3;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];

			a[0][0] = 0; a[0][1] = 1; a[0][2] = 0;
			a[1][0] = 0; a[1][1] = 0; a[1][2] = 0;
			a[2][0] = 1; a[2][1] = 0; a[2][2] = 0;

			int result = LastMaxZeroCol(a, n);

			Assert::AreEqual(2, result);

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestLastMaxZeroCol_LastIfTie)
		{
			int n = 3;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];

			a[0][0] = 0; a[0][1] = 1; a[0][2] = 0;
			a[1][0] = 0; a[1][1] = 5; a[1][2] = 0;
			a[2][0] = 7; a[2][1] = 3; a[2][2] = 9;

			int result = LastMaxZeroCol(a, n);

			Assert::AreEqual(2, result);

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
