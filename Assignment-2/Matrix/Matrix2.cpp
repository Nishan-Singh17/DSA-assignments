#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the size of matrix: ";
    cin >> n;

    int m = (3 * n) - 2;

    int arr[m];

    cout << "Enter the elements of an array: ";

    for(int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    int k = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j || i - j == 1 || j - i == 1)
            {
                cout << arr[k++] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }

        cout << endl;
    }

    return 0;
}