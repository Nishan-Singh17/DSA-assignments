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

void removeZero(int a[][3]) {
    int k = 1;

    for (int i = 1; i <= a[0][2]; i++) {
        if (a[i][2] != 0) {
            a[k][0] = a[i][0];
            a[k][1] = a[i][1];
            a[k][2] = a[i][2];
            k++;
        }
    }

    a[0][2] = k - 1;
}

int main() {
    int a[100][3], b[100][3], product[200][3];

    cout << "Enter rows, columns and non-zero elements of first matrix: ";
    cin >> a[0][0] >> a[0][1] >> a[0][2];

    cout << "Enter row column value:\n";
    for (int i = 1; i <= a[0][2]; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    cout << "Enter rows, columns and non-zero elements of second matrix: ";
    cin >> b[0][0] >> b[0][1] >> b[0][2];

    if (a[0][1] != b[0][0]) {
        cout << "Multiplication is not possible.";
        return 0;
    }

    cout << "Enter row column value:\n";
    for (int i = 1; i <= b[0][2]; i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];

    product[0][0] = a[0][0];
    product[0][1] = b[0][1];

    int k = 1;

    for (int i = 1; i <= a[0][2]; i++) {
        for (int j = 1; j <= b[0][2]; j++) {
            if (a[i][1] == b[j][0]) {
                bool found = false;

                for (int p = 1; p < k; p++) {
                    if (product[p][0] == a[i][0] &&
                        product[p][1] == b[j][1]) {

                        product[p][2] += a[i][2] * b[j][2];
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    product[k][0] = a[i][0];
                    product[k][1] = b[j][1];
                    product[k][2] = a[i][2] * b[j][2];
                    k++;
                }
            }
        }
    }

    product[0][2] = k - 1;

    removeZero(product);
    sortTriplet(product);

    cout << "\nProduct in sorted triplet form:\n";
    cout << "Row Col Value\n";

    for (int i = 0; i <= product[0][2]; i++)
        cout << product[i][0] << "   " << product[i][1]
             << "   " << product[i][2] << endl;

    return 0;
}