#include <iostream>
using namespace std;

int main()
{
    int a[100], n, k;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter k: ";
    cin >> k;

    k = k % n;

    cout << "Left rotation: ";

    for(int i = k; i < n; i++)
        cout << a[i] << " ";

    for(int i = 0; i < k; i++)
        cout << a[i] << " ";

    cout << "\nRight rotation: ";

    for(int i = n-k; i < n; i++)
        cout << a[i] << " ";

    for(int i = 0; i < n-k; i++)
        cout << a[i] << " ";

    return 0;
}