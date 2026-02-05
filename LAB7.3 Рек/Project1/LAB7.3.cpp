#include <iostream>
#include <iomanip>
using namespace std;

void InputRow(int** a, int n, int i, int j)
{
    cin >> a[i][j];
    if (j < n - 1) InputRow(a, n, i, j + 1); 
}

void Input(int** a, int n, int i)
{
    InputRow(a, n, i, 0);
    if (i < n - 1) Input(a, n, i + 1);     
}

void PrintRow(int** a, int n, int i, int j)
{
    cout << setw(4) << a[i][j];
    if (j < n - 1) PrintRow(a, n, i, j + 1);
    else cout << endl;
}

void Print(int** a, int n, int i)
{
    PrintRow(a, n, i, 0);
    if (i < n - 1) Print(a, n, i + 1);
    else cout << endl;
}

void ShiftOnce(int** a, int n)
{
    int temp = a[0][0];

    for (int i = 0; i < n - 1; i++)
        a[i][0] = a[i + 1][0];

    for (int j = 0; j < n - 1; j++)
        a[n - 1][j] = a[n - 1][j + 1];

    for (int i = n - 1; i > 0; i--)
        a[i][n - 1] = a[i - 1][n - 1];

    for (int j = n - 1; j > 1; j--)
        a[0][j] = a[0][j - 1];

    a[0][1] = temp;
}

void ShiftRight(int** a, int n, int k)
{
    if (k == 0) return;
    ShiftOnce(a, n);
    ShiftRight(a, n, k - 1); 
}

void CountZerosCol(int** a, int n, int j, int i, int& count)
{
    if (a[i][j] == 0) count++;
    if (i < n - 1) CountZerosCol(a, n, j, i + 1, count);
}

void LastMaxZeroCol(int** a, int n, int j, int& maxZero, int& index)
{
    int count = 0;
    CountZerosCol(a, n, j, 0, count);

    if (count >= maxZero)
    {
        maxZero = count;
        index = j;
    }

    if (j < n - 1) LastMaxZeroCol(a, n, j + 1, maxZero, index); 
}

int main()
{
    int n, k;
    cin >> n >> k;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Input(a, n, 0); 

    int total = 4 * (n - 1);
    k %= total;
    ShiftRight(a, n, k); 

    Print(a, n, 0); 

    int maxZero = -1, index = -1;
    LastMaxZeroCol(a, n, 0, maxZero, index); 
    cout << index << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}