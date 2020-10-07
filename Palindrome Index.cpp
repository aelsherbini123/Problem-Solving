#include <bits/stdc++.h>

using namespace std;

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {
    int len = s.length();
    int i, j, x, y;
    for (i = 0, j = len - 1; i < len; i++, j--) {
        if (s[i] != s[j]) {
            break;
        }
    }
    if (i > j)
        return -1;
    for(x = i+1, y = j; x < j && y > i+1; x++,y--) {
        if (s[x] != s[y]) {
            return j;
        }
    }
    return i;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
        cout << result << "\n";
    }

    fout.close();

    return 0;
}
