#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

bool validate(string s) {
    for (int k = 0; k < s.length() - 1; k++) {
        if (s[k] == s[k + 1]) {
            return false;
        }
    }
    return true;
}
int alternate(string s) {
    set<char> st(s.begin(), s.end());
    string res(st.begin(), st.end());
    int mx = 0;
    for (int i = 0; i < (int)res.length(); i++) {
        for (int j = i + 1; j < (int)res.length(); j++) {
            string ans = "";
            for (int k = 0; k < (int)s.length(); k++) {
                if (s[k] == res[i] || s[k] == res[j])
                    ans += s[k];
            }
            if(validate(ans))
                mx = max(mx, (int)ans.length());
        }
    }
//    cout << mx << endl;
    return mx;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end());

    return s;
}
