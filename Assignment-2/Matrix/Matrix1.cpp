//Diagonal Matrix

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the size of matrix: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of an array: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
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