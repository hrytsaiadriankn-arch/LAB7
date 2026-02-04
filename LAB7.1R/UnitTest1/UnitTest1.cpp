#include "pch.h"
#include "CppUnitTest.h"
#include <ctime>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void ChangeCols(int** a, int col1, int col2, int rowCount, int i = 0);
void Sort(int** a, int rowCount, int colCount, int i0 = 0, int i1 = 0);
void Calc(int** a, int rowCount, int colCount, int i, int j, int& S, int& k);

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Допоміжна функція створення матриці
        int** CreateMatrix(int rows, int cols)
        {
            int** a = new int* [rows];
            for (int i = 0; i < rows; i++)
                a[i] = new int[cols];
            return a;
        }

        void DeleteMatrix(int** a, int rows)
        {
            for (int i = 0; i < rows; i++)
                delete[] a[i];
            delete[] a;
        }

        TEST_METHOD(TestChangeCols)
        {
            int rows = 3, cols = 3;
            int** a = CreateMatrix(rows, cols);

            int val = 1;
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    a[i][j] = val++;

            ChangeCols(a, 0, 2, rows);

            Assert::AreEqual(3, a[0][0]);
            Assert::AreEqual(1, a[0][2]);
            Assert::AreEqual(6, a[1][0]);
            Assert::AreEqual(4, a[1][2]);

            DeleteMatrix(a, rows);
        }

        TEST_METHOD(TestSort)
        {
            int rows = 3, cols = 3;
            int** a = CreateMatrix(rows, cols);

            // Спеціально задаємо значення перших 3 рядків
            a[0][0] = 5; a[0][1] = 2; a[0][2] = 5;
            a[1][0] = 1; a[1][1] = 9; a[1][2] = 0;
            a[2][0] = 7; a[2][1] = 3; a[2][2] = 8;

            Sort(a, rows, cols);

            // Після сортування перший рядок має бути: 2,5,5
            Assert::AreEqual(2, a[0][0]);
            Assert::AreEqual(5, a[0][1]);
            Assert::AreEqual(5, a[0][2]);

            DeleteMatrix(a, rows);
        }

        TEST_METHOD(TestCalc)
        {
            int rows = 2, cols = 3;
            int** a = CreateMatrix(rows, cols);

            a[0][0] = 14; // кратне 7 -> не рахується
            a[0][1] = 20; // парне, не кратне 7 -> рахується
            a[0][2] = 9;  // непарне -> не рахується
            a[1][0] = 8;  // рахується
            a[1][1] = 21; // кратне 7 -> не рахується
            a[1][2] = 10; // рахується

            int S = 0, k = 0;
            Calc(a, rows, cols, 0, 0, S, k);

            Assert::AreEqual(38, S); // 20 + 8 + 10
            Assert::AreEqual(3, k);

            Assert::AreEqual(0, a[0][1]);
            Assert::AreEqual(0, a[1][0]);
            Assert::AreEqual(0, a[1][2]);

            DeleteMatrix(a, rows);
        }
    };
}
