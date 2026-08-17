#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, i, key;
    int low, mid, high, found = false;
    int pos = -1;

    cout << "Enter the number of elements :";
    cin >> n;

    cout << "Enter the elements in ascending order :";
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to be searched by Binary search : ";
    cin >> key;

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(key == arr[mid])
        {
            cout << "Element found at " << mid + 1;
            found = true;
            break;
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (found == false){
        cout<<"Element not found";
    }
}