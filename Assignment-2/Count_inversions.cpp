// Count Inversions

#include <iostream>
using namespace std;

int main()
{
    int n;
    int count = 0;

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of an array: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                count++;
            }
        }
    }

    cout << "Number of inversions: " << count << endl;

    return 0;
}