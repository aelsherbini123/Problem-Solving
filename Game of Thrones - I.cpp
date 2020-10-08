#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    int count[256] = { 0 };
    for (int i = 0; s[i]; i++)
        count[s[i]]++;
    int odd = 0;
    for (int i = 0; i < 256; i++) {
        if (count[i] & 1)
            odd++;

        if (odd > 1)
            return "NO";
    }
    return "YES";

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";
    cout << result << "\n";
    fout.close();

    return 0;
}
