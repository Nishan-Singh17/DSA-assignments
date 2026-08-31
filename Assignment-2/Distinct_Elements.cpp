// Count Distinct Elements

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int duplicate = 0;

        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                duplicate = 1;
                break;
            }
        }

        if (duplicate == 0)
        {
            count++;
        }
    }

    cout << "Number of distinct elements = " << count;

    return 0;
}