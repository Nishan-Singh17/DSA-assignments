#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n - 1];

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    int missingNumber = n;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            missingNumber = i + 1;
            break;
        }
    }

    cout << "Missing number is: " << missingNumber;

    return 0;
}