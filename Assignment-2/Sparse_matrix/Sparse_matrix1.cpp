// Transpose of a sparse matrix using triplet representation

#include <iostream>
using namespace std;

void sortTriplet(int a[][3]) {
    for (int i = 1; i < a[0][2]; i++) {
        for (int j = 1; j <= a[0][2] - i; j++) {
            if (a[j][0] > a[j + 1][0] ||
                (a[j][0] == a[j + 1][0] && a[j][1] > a[j + 1][1])) {

                for (int k = 0; k < 3; k++) {
                    int temp = a[j][k];
                    a[j][k] = a[j + 1][k];
                    a[j + 1][k] = temp;
                }
            }
        }
    }
}

int main() {
    int a[100][3], t[100][3];

    cout << "Enter rows, columns and number of non-zero elements: ";
    cin >> a[0][0] >> a[0][1] >> a[0][2];

    cout << "Enter row column value:\n";
    for (int i = 1; i <= a[0][2]; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    t[0][0] = a[0][1];
    t[0][1] = a[0][0];
    t[0][2] = a[0][2];

    for (int i = 1; i <= a[0][2]; i++) {
        t[i][0] = a[i][1];
        t[i][1] = a[i][0];
        t[i][2] = a[i][2];
    }

    sortTriplet(t);

    cout << "\nTranspose in sorted triplet form:\n";
    cout << "Row Col Value\n";

    for (int i = 0; i <= t[0][2]; i++)
        cout << t[i][0] << "   " << t[i][1] << "   " << t[i][2] << endl;

    return 0;
}