#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void ChangeCols(int** a, int col1, int col2, int rowCount);
void Sort(int** a, int rowCount, int colCount);
void Calc(int** a, int rowCount, int colCount, int& S, int& k);

namespace UnitTestMatrix
{
	TEST_CLASS(UnitTestMatrix)
	{
	public:

		int** CreateMatrix(int rows, int cols, int data[])
		{
			int** a = new int* [rows];
			int index = 0;
			for (int i = 0; i < rows; i++)
			{
				a[i] = new int[cols];
				for (int j = 0; j < cols; j++)
					a[i][j] = data[index++];
			}
			return a;
		}

		void DeleteMatrix(int** a, int rows)
		{
			for (int i = 0; i < rows; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSortColumns)
		{
			const int rows = 3;
			const int cols = 3;

			int data[] = { 5, 2, 5, 1, 9, 3, 7, 4, 8 };
			int** a = CreateMatrix(rows, cols, data);

			Sort(a, rows, cols);

			Assert::IsTrue(a[0][0] <= a[0][1]);
			Assert::IsTrue(a[0][1] <= a[0][2]);

			DeleteMatrix(a, rows);
		}

		TEST_METHOD(TestCalcFunction)
		{
			const int rows = 2;
			const int cols = 3;

			int data[] = { 14, 9, 8, 21, 10, 5 };
			int** a = CreateMatrix(rows, cols, data);

			int S = 0;
			int k = 0;

			Calc(a, rows, cols, S, k);

			Assert::AreEqual(18, S);
			Assert::AreEqual(2, k);
			Assert::AreEqual(0, a[0][2]);
			Assert::AreEqual(0, a[1][1]);

			DeleteMatrix(a, rows);
		}

		TEST_METHOD(TestChangeCols)
		{
			const int rows = 2;
			const int cols = 2;

			int data[] = { 1, 2, 3, 4 };
			int** a = CreateMatrix(rows, cols, data);

			ChangeCols(a, 0, 1, rows);

			Assert::AreEqual(2, a[0][0]);
			Assert::AreEqual(1, a[0][1]);
			Assert::AreEqual(4, a[1][0]);
			Assert::AreEqual(3, a[1][1]);

			DeleteMatrix(a, rows);
		}
	};
}

