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
    int a[100][3], b[100][3], sum[200][3];

    cout << "Enter rows, columns and non-zero elements of first matrix: ";
    cin >> a[0][0] >> a[0][1] >> a[0][2];

    cout << "Enter row column value:\n";
    for (int i = 1; i <= a[0][2]; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    cout << "Enter rows, columns and non-zero elements of second matrix: ";
    cin >> b[0][0] >> b[0][1] >> b[0][2];

    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition is not possible.";
        return 0;
    }

    cout << "Enter row column value:\n";
    for (int i = 1; i <= b[0][2]; i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];

    sum[0][0] = a[0][0];
    sum[0][1] = a[0][1];

    int k = 1;

    for (int i = 1; i <= a[0][2]; i++) {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        k++;
    }

    for (int i = 1; i <= b[0][2]; i++) {
        bool found = false;

        for (int j = 1; j < k; j++) {
            if (sum[j][0] == b[i][0] && sum[j][1] == b[i][1]) {
                sum[j][2] += b[i][2];
                found = true;
                break;
            }
        }

        if (!found) {
            sum[k][0] = b[i][0];
            sum[k][1] = b[i][1];
            sum[k][2] = b[i][2];
            k++;
        }
    }

    sum[0][2] = k - 1;

    removeZero(sum);
    sortTriplet(sum);

    cout << "\nSum in sorted triplet form:\n";
    cout << "Row Col Value\n";

    for (int i = 0; i <= sum[0][2]; i++)
        cout << sum[i][0] << "   " << sum[i][1] << "   " << sum[i][2] << endl;

    return 0;
}