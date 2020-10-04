#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {
    int len = s.length()/3;
    string res = "";
    for(int i = 0; i < len ; i++)
    {
        res += "SOS";
    }
    int diff = 0;
    for(int i = 0; i < s.length() ; i++)
    {
        if(s[i] != res[i]) diff++;
    }
    return diff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
