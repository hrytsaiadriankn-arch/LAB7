#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void CreateRow(int** a, int row, int col, int n, int Low, int High)
{
    a[row][col] = Low + rand() % (High - Low + 1);
    if (col < n - 1)
        CreateRow(a, row, col + 1, n, Low, High);
}

void CreateRows(int** a, int row, int k, int n, int Low, int High)
{
    if (row >= k) return;
    CreateRow(a, row, 0, n, Low, High);
    CreateRows(a, row + 1, k, n, Low, High);
}

void PrintRow(int** a, int row, int col, int n)
{
    cout << setw(4) << a[row][col];
    if (col < n - 1)
        PrintRow(a, row, col + 1, n);
    else
        cout << endl;
}

void PrintRows(int** a, int row, int k, int n)
{
    if (row >= k) return;
    PrintRow(a, row, 0, n);
    PrintRows(a, row + 1, k, n);
}

void FindMinIndexRec(int** a, int row, int col, int n, int& minI)
{
    if (col == n) return;

    if (a[row][col] < a[row][minI])
        minI = col;

    FindMinIndexRec(a, row, col + 1, n, minI);
}

void FindMaxIndexRec(int** a, int row, int col, int n, int& maxI)
{
    if (col == n) return;

    if (a[row][col] > a[row][maxI])
        maxI = col;

    FindMaxIndexRec(a, row, col + 1, n, maxI);
}

void SwapRowMinMax(int** a, int row, int minI, int maxI)
{
    int temp = a[row][minI];
    a[row][minI] = a[row][maxI];
    a[row][maxI] = temp;
}

void SwapMinMaxRowsRec(int** a, int row, int k, int n)
{
    if (row >= k) return;

    int minI = 0;
    int maxI = 0;

    FindMinIndexRec(a, row, 1, n, minI);
    FindMaxIndexRec(a, row, 1, n, maxI);
    SwapRowMinMax(a, row, minI, maxI);

    SwapMinMaxRowsRec(a, row + 1, k, n);
}

int main()
{
    srand((unsigned)time(NULL));

    int k, n;
    cout << "Rows k = "; cin >> k;
    cout << "Cols n = "; cin >> n;

    int Low = -10, High = 50;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    CreateRows(a, 0, k, n, Low, High);

    cout << "\nOriginal matrix:\n";
    PrintRows(a, 0, k, n);

    SwapMinMaxRowsRec(a, 0, k, n);

    cout << "\nModified matrix:\n";
    PrintRows(a, 0, k, n);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}