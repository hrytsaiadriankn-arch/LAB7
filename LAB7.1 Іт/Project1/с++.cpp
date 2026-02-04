#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, int rowCount, int colCount, int Low, int High);
void Print(int** a, int rowCount, int colCount);
void ChangeCols(int** a, int col1, int col2, int rowCount);
void Sort(int** a, int rowCount, int colCount);
void Calc(int** a, int rowCount, int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 18, High = 74;
    int rowCount = 9, colCount = 6;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    Sort(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int S = 0, k = 0;
    Calc(a, rowCount, colCount, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, int rowCount, int colCount, int Low, int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, int rowCount, int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void ChangeCols(int** a, int col1, int col2, int rowCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        int tmp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = tmp;
    }
}

void Sort(int** a, int rowCount, int colCount)
{
    for (int i0 = 0; i0 < colCount - 1; i0++)
        for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
            if ((a[0][i1] > a[0][i1 + 1]) ||
                (a[0][i1] == a[0][i1 + 1] && a[1][i1] < a[1][i1 + 1]) ||
                (a[0][i1] == a[0][i1 + 1] && a[1][i1] == a[1][i1 + 1] && a[2][i1] < a[2][i1 + 1]))
                ChangeCols(a, i1, i1 + 1, rowCount);
}

void Calc(int** a, int rowCount, int colCount, int& S, int& k)
{
    S = 0;
    k = 0;

    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (!(a[i][j] % 2 != 0 || a[i][j] % 7 == 0))
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
}