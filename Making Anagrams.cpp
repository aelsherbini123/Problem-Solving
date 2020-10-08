#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {
    int mp1[26]={},mp2[26]={};
    for (int i = 0; i < s1.length(); i++) {
        mp1[s1[i]-97]++;
    }
    for (int i = 0; i < s2.length(); i++) {
        mp2[s2[i]-97]++;
    }
    int cnt = 0;
    for(int i = 0; i < 26; i++){
        cnt += abs(mp1[i] - mp2[i]);
    }
    return cnt;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
