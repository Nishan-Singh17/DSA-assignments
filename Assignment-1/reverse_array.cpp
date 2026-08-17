#include <iostream>
using namespace std;

int main()
{
    int a[100], n, temp;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n/2; i++)
    {
        temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }

    cout << "Reverse array: ";

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}