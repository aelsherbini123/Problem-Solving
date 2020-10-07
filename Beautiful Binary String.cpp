#include <bits/stdc++.h>

using namespace std;

// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string b) {
    int cnt = 0;
    for (int i = 0; i < b.length();) {
        if ((i + 1 < b.length() && i + 2 < b.length()) && b[i] == '0'
                && b[i + 1] == '1' && b[i + 2] == '0') {
            cnt++;
            i += 3;
        } else {
            i++;
        }
    }
    return cnt;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";
//    cout << result << "\n";
    fout.close();

    return 0;
}
