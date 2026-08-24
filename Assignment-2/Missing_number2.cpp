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

    int low = 0;
    int high = n - 2;
    int missingNumber;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    missingNumber = low + 1;

    cout << "Missing number is: " << missingNumber;

    return 0;
}