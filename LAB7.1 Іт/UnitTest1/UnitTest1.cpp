#include "pch.h"
#include "CppUnitTest.h"
#include <ctime>
#include <iomanip>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "D:/LAB7.1 Іт/Project1/LAB7.1.cpp"

void ChangeCols(int** a, int col1, int col2, int rowCount);
void Sort(int** a, int rowCount, int colCount);
void Calc(int** a, int rowCount, int colCount, int& S, int& k);

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestChangeCols)
		{
			int rowCount = 3, colCount = 2;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 1; a[0][1] = 2;
			a[1][0] = 3; a[1][1] = 4;
			a[2][0] = 5; a[2][1] = 6;

			ChangeCols(a, 0, 1, rowCount);

			Assert::AreEqual(2, a[0][0]);
			Assert::AreEqual(1, a[0][1]);
			Assert::AreEqual(4, a[1][0]);
			Assert::AreEqual(3, a[1][1]);
			Assert::AreEqual(6, a[2][0]);
			Assert::AreEqual(5, a[2][1]);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSort)
		{
			int rowCount = 3, colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			// Стовпці:
			// [5, 1, 3]
			// [2, 9, 4]
			// [7, 8, 6]

			a[0][0] = 5; a[0][1] = 1; a[0][2] = 3;
			a[1][0] = 2; a[1][1] = 9; a[1][2] = 4;
			a[2][0] = 7; a[2][1] = 8; a[2][2] = 6;

			Sort(a, rowCount, colCount);

			// Після сортування по 1-му рядку за зростанням: 1,3,5
			Assert::AreEqual(1, a[0][0]);
			Assert::AreEqual(3, a[0][1]);
			Assert::AreEqual(5, a[0][2]);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestCalc)
		{
			int rowCount = 2, colCount = 3;
			int S = 0, k = 0;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 14; // кратне 7 → не підходить
			a[0][1] = 8;  // парне і не кратне 7 → підходить
			a[0][2] = 5;  // непарне → не підходить
			a[1][0] = 10; // парне і не кратне 7 → підходить
			a[1][1] = 21; // кратне 7 → не підходить
			a[1][2] = 4;  // парне і не кратне 7 → підходить

			Calc(a, rowCount, colCount, S, k);

			Assert::AreEqual(8 + 10 + 4, S);
			Assert::AreEqual(3, k);

			Assert::AreEqual(0, a[0][1]);
			Assert::AreEqual(0, a[1][0]);
			Assert::AreEqual(0, a[1][2]);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
