#include <bits/stdc++.h>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {
    string hacker_rank = "hackerrank";
    int pos = 0;
    string ans = "";
    for (int i = 0; i < (int)hacker_rank.length(); i++) {
        for(int j = pos; j < (int)s.length(); j++)
        {
            if(hacker_rank[i] == s[j])
            {
                pos = j+1;
                ans += s[j];
                break;
            }
        }
    }
    if(hacker_rank == ans) return "YES";
    return "NO" ;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);
        fout << result << "\n";
    }

    fout.close();

    return 0;
}
