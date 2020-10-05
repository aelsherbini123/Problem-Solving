#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    set<char> ans(s.begin(),s.end());
    if(ans.size() <= 26) return "not pangram";
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
