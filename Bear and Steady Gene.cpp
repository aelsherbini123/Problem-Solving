#include <bits/stdc++.h>

using namespace std;
bool isVlaid(map<char, int> mp, int x) {
    if (mp['A'] <= x && mp['C'] <= x && mp['G'] <= x && mp['T'] <= x)
        return true;
    return false;
}

int main() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    map<char, int> dict;
    for (int i = 0; i < n; i++) {
        dict[s[i]]++;
    }
    int mn = INT_MAX;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (!isVlaid(dict, n / 4)) {
            dict[s[j]]--;
            j++;
        }
        else {
            mn = min(mn, j - i);
            dict[s[i]]++;
            i++;
        }
    }
    cout << mn << endl;
}

