#include <iostream>
#include <iomanip>
using namespace std;

void Input(int** a, int n)
{
    for (int i = 0; i < n; i++)          
        for (int j = 0; j < n; j++)       
            cin >> a[i][j];
}

void Print(int** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void ShiftRight(int** a, int n, int k)
{
    int total = 4 * (n - 1);
    k %= total;

    while (k--)   
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
}

int LastMaxZeroCol(int** a, int n)
{
    int maxZero = -1, index = -1;

    for (int j = 0; j < n; j++)   
    {
        int count = 0;
        for (int i = 0; i < n; i++)  
            if (a[i][j] == 0)
                count++;

        if (count >= maxZero)
        {
            maxZero = count;
            index = j;
        }
    }
    return index;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Input(a, n);        
    ShiftRight(a, n, k); 
    Print(a, n);         

    cout << LastMaxZeroCol(a, n) << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}