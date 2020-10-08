#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    if (s.length() % 2 == 1)
        return -1;
    map<char, int> mp;
    string first = s.substr(0, (s.length() / 2));
    string second = s.substr((s.length() / 2), s.length());
    for (int i = 0; i < first.length(); i++) {
        mp[first[i]]++;
    }
    int cnt = 0;
    for (int i = 0; i < second.length(); i++) {

        if(mp[second[i]] > 0) mp[second[i]]--;
        else cnt++;
    }

    return cnt;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
        cout << result << "\n";
    }

    fout.close();

    return 0;
}
