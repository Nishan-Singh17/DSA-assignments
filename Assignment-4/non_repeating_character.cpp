#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    queue<char> q;
    int freq[256] = {0};

    for (char c : s) {
        freq[(unsigned char)c]++;
        q.push(c);

        while (!q.empty() &&
               freq[(unsigned char)q.front()] > 1)
            q.pop();

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }

    return 0;
}