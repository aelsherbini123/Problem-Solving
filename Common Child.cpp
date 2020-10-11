#include <bits/stdc++.h>

using namespace std;
int LCSLength(string x, string y) {
    int m = x.length();
    int n = y.length();
    vector< vector<int> > c(m+1, vector<int>(n+1));
    for (int i = 0; i < m; i++)
        c[i][0] = 0;
    for (int i = 0; i < n; i++)
        c[0][i] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
        }
    }
    return c[m][n];
}
int main() {
    string x, y;
    cin >> x;
    cin >> y;
    cout << LCSLength(x, y) << endl;
}

