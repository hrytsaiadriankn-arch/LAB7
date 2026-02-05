#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "D:/LAB7.3 Рек/Project1/LAB7.3.cpp"

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestShiftRight_OneShift)
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

		TEST_METHOD(TestCountZerosCol)
		{
			int n = 3;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n] { 0, 1, 0 };

			int count = 0;
			CountZerosCol(a, n, 0, 0, count);

			Assert::AreEqual(3, count);

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestLastMaxZeroCol)
		{
			int n = 3;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];

			a[0][0] = 0; a[0][1] = 1; a[0][2] = 0;
			a[1][0] = 0; a[1][1] = 0; a[1][2] = 0;
			a[2][0] = 1; a[2][1] = 0; a[2][2] = 0;

			int maxZero = -1;
			int index = -1;

			LastMaxZeroCol(a, n, 0, maxZero, index);

			Assert::AreEqual(2, index);

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
