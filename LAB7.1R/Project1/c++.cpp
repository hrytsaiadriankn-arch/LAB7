#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, int i, int j, int rowCount, int colCount, int Low, int High);
void Print(int** a, int i, int j, int rowCount, int colCount);
void ChangeCols(int** a, int col1, int col2, int rowCount, int i = 0);
void Sort(int** a, int rowCount, int colCount, int i0 = 0, int i1 = 0);
void Calc(int** a, int rowCount, int colCount, int i, int j, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 18, High = 74;
    int rowCount = 9, colCount = 6;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, 0, 0, rowCount, colCount, Low, High);
    Print(a, 0, 0, rowCount, colCount);

    Sort(a, rowCount, colCount);
    Print(a, 0, 0, rowCount, colCount);

    int S = 0, k = 0;
    Calc(a, rowCount, colCount, 0, 0, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    Print(a, 0, 0, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, int i, int j, int rowCount, int colCount, int Low, int High)
{
    if (i == rowCount) return;
    if (j == colCount)
    {
        Create(a, i + 1, 0, rowCount, colCount, Low, High);
        return;
    }

    a[i][j] = Low + rand() % (High - Low + 1);
    Create(a, i, j + 1, rowCount, colCount, Low, High);
}

void Print(int** a, int i, int j, int rowCount, int colCount)
{
    if (i == 0 && j == 0) cout << endl;
    if (i == rowCount)
    {
        cout << endl;
        return;
    }
    if (j == colCount)
    {
        cout << endl;
        Print(a, i + 1, 0, rowCount, colCount);
        return;
    }

    cout << setw(4) << a[i][j];
    Print(a, i, j + 1, rowCount, colCount);
}

void ChangeCols(int** a, int col1, int col2, int rowCount, int i)
{
    if (i == rowCount) return;

    int tmp = a[i][col1];
    a[i][col1] = a[i][col2];
    a[i][col2] = tmp;

    ChangeCols(a, col1, col2, rowCount, i + 1);
}

void Sort(int** a, int rowCount, int colCount, int i0, int i1)
{
    if (i0 == colCount - 1) return;

    if (i1 < colCount - i0 - 1)
    {
        if ((a[0][i1] > a[0][i1 + 1]) ||
            (a[0][i1] == a[0][i1 + 1] && a[1][i1] < a[1][i1 + 1]) ||
            (a[0][i1] == a[0][i1 + 1] && a[1][i1] == a[1][i1 + 1] && a[2][i1] < a[2][i1 + 1]))
            ChangeCols(a, i1, i1 + 1, rowCount);

        Sort(a, rowCount, colCount, i0, i1 + 1);
    }
    else
        Sort(a, rowCount, colCount, i0 + 1, 0);
}

void Calc(int** a, int rowCount, int colCount, int i, int j, int& S, int& k)
{
    if (i == rowCount) return;

    if (j == colCount)
    {
        Calc(a, rowCount, colCount, i + 1, 0, S, k);
        return;
    }

    if (!(a[i][j] % 2 != 0 || a[i][j] % 7 == 0))
    {
        S += a[i][j];
        k++;
        a[i][j] = 0;
    }

    Calc(a, rowCount, colCount, i, j + 1, S, k);
}