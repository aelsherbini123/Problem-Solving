#include <bits/stdc++.h>

using namespace std;

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    string res, min_num;
    for (int len = 1; len <= (s.length() / 2) && s != res; len++)
    {
        res = min_num = s.substr(0, len);
        for (int i = 1; res.length() < s.length(); i++)
        {
            res += to_string(stoll(min_num) + i);
        }
    }
    if (res == s) cout << "YES " << min_num << endl;
    else cout << "NO" << endl;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}
