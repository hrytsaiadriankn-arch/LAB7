#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
void SwapMinMaxRows(int** a, const int k, const int n);

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

    Create(a, k, n, Low, High);

    cout << "\nOriginal matrix:\n";
    Print(a, k, n);

    SwapMinMaxRows(a, k, n);

    cout << "\nModified matrix:\n";
    Print(a, k, n);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

void SwapMinMaxRows(int** a, const int k, const int n)
{
    for (int i = 0; i < k; i++)
    {
        int minIndex = 0;
        int maxIndex = 0;

        for (int j = 1; j < n; j++)
        {
            if (a[i][j] < a[i][minIndex]) minIndex = j;
            if (a[i][j] > a[i][maxIndex]) maxIndex = j;
        }

        int temp = a[i][minIndex];
        a[i][minIndex] = a[i][maxIndex];
        a[i][maxIndex] = temp;
    }
}