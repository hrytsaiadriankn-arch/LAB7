#include "pch.h"
#include "CppUnitTest.h"
#include "../YourProjectName/Matrix.h"   // 🔁 Заміни на назву свого проєкту

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

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

        // 🔹 Тест обміну стовпців
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
            Assert::AreEqual(9, a[2][0]);
            Assert::AreEqual(7, a[2][2]);

            DeleteMatrix(a, rows);
        }

        // 🔹 Тест сортування стовпців
        TEST_METHOD(TestSort)
        {
            int rows = 3, cols = 4;
            int** a = CreateMatrix(rows, cols);

            // стовпці: (5,2,1) (3,9,4) (5,1,7) (1,8,2)
            a[0][0] = 5; a[1][0] = 2; a[2][0] = 1;
            a[0][1] = 3; a[1][1] = 9; a[2][1] = 4;
            a[0][2] = 5; a[1][2] = 1; a[2][2] = 7;
            a[0][3] = 1; a[1][3] = 8; a[2][3] = 2;

            Sort(a, rows, cols);

            // Очікуваний порядок по 1 рядку ↑: (1,8,2) (3,9,4) (5,2,1) (5,1,7)
            Assert::AreEqual(1, a[0][0]);
            Assert::AreEqual(3, a[0][1]);
            Assert::AreEqual(5, a[0][2]);
            Assert::AreEqual(5, a[0][3]);

            // Перевіримо ще другий рядок (бо при рівності сортує за спаданням)
            Assert::AreEqual(8, a[1][0]);
            Assert::AreEqual(9, a[1][1]);

            DeleteMatrix(a, rows);
        }

        // 🔹 Тест обчислення суми та занулення
        TEST_METHOD(TestCalc)
        {
            int rows = 2, cols = 4;
            int** a = CreateMatrix(rows, cols);

            a[0][0] = 14; // кратне 7 → ні
            a[0][1] = 20; // парне і не кратне 7 → так
            a[0][2] = 9;  // непарне → ні
            a[0][3] = 8;  // так

            a[1][0] = 21; // кратне 7 → ні
            a[1][1] = 10; // так
            a[1][2] = 5;  // ні
            a[1][3] = 6;  // так

            int S = -1, k = -1;
            Calc(a, rows, cols, S, k);

            Assert::AreEqual(44, S); // 20 + 8 + 10 + 6
            Assert::AreEqual(4, k);

            Assert::AreEqual(0, a[0][1]);
            Assert::AreEqual(0, a[0][3]);
            Assert::AreEqual(0, a[1][1]);
            Assert::AreEqual(0, a[1][3]);

            DeleteMatrix(a, rows);
        }
    };
}

