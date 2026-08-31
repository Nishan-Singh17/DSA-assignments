// Symmetric Matrix

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    int size = n * (n + 1) / 2;

    int a[size];

    cout << "Enter lower triangular elements:\n";

    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    int k;

    cout << "Symmetric Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                k = i * (i + 1) / 2 + j;
            }
            else
            {
                k = j * (j + 1) / 2 + i;
            }

            cout << a[k] << " ";
        }

        cout << endl;
    }

    return 0;
}