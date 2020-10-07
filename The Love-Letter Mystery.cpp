#include <bits/stdc++.h>

using namespace std;

// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(string s) {
    int len = (int) s.length();
    if (len % 2 == 0) {
        int cnt = 0;
        for (int i = 0, j = len - 1; (i < len / 2 && j >= len / 2); i++, j--) {
//            cout << s[i] << " " << s[j] << endl;
            if (s[i] > s[j]) {
                cnt += s[i] - s[j];
            } else {
                cnt += s[j] - s[i];
            }
        }
        return cnt;
    } else {
        int cnt = 0;
        for (int i = 0, j = len - 1; (i < (len / 2) && j >= (len / 2) + 1); i++, j--) {
//            cout << s[i] << " " << s[j] << endl;
            if (s[i] > s[j]) {
                cnt += s[i] - s[j];
            } else {
                cnt += s[j] - s[i];
            }
        }
        return cnt;
    }
    return 0;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = theLoveLetterMystery(s);

        fout << result << "\n";
        cout << result << "\n";
    }

    fout.close();

    return 0;
}
