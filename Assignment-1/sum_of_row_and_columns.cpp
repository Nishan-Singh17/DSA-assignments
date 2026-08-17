#include <iostream>
using namespace std;

int main()
{
    int a[10][10], r, c, sum;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix:\n";

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> a[i][j];

    cout << "Row sums:\n";

    for(int i = 0; i < r; i++)
    {
        sum = 0;

        for(int j = 0; j < c; j++)
            sum = sum + a[i][j];

        cout << "Row " << i + 1 << " = " << sum << endl;
    }

    cout << "Column sums:\n";

    for(int j = 0; j < c; j++)
    {
        sum = 0;

        for(int i = 0; i < r; i++)
            sum = sum + a[i][j];

        cout << "Column " << j + 1 << " = " << sum << endl;
    }

    return 0;
}