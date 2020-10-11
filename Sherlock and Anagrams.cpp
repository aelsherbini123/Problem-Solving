#include <bits/stdc++.h>

using namespace std;
int check_anagram(string, string);
int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int count = 0;
        string s;
        cin >> s;
        for (int i = 1; i <= s.length(); i++) {
            vector <string> str;

            for (int j = 0; j + i <= s.length(); j++) {
                str.push_back(s.substr(j, i));
            }

            for (int p = 0; p < str.size(); p++) {
                for (int q = p + 1; q < str.size(); q++) {
                    if (check_anagram(str[p], str[q]))count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}

int check_anagram(string s1, string s2) {

    int a1[26] = { 0 }, a2[26] = { 0 };

    for (int i = 0; i < s1.length(); i++) {
        a1[s1[i] - 'a']++;
    }

    for (int i = 0; i < s2.length(); i++) {
        a2[s2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (a1[i] - a2[i] != 0) {
            return 0;
        }
    }
    return 1;
}
