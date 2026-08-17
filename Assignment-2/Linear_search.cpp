#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, i, key;
    int pos = -1;

    cout << "enter the number of elements";
    cin >> n;

    cout << "enter the elements in ascending order";
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "enter the element to be searched by linear search";
    cin >> key;

    for(i = 0; i < n; i++)
    {
        if(key == arr[i])
        {
            pos = i;
            break;
        }
    }

    if(pos == -1)
    {
        cout << "element not found";
    }
    else
    {
        cout << "element found at index " << pos;
    }

    return 0;
}