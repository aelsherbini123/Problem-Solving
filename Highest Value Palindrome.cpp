#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the highestValuePalindrome function below.
bool checkPalindrome(string s) {
    string x = s;
    reverse(x.begin(), x.end());
    if (s == x)
        return true;
    return false;
}
string highestValuePalindrome(string s, int n, int k) {
    string first, second;
    if (n % 2 == 0) {
        first = s.substr(0, n / 2);
        second = s.substr(n / 2, n);
    } else {
        first = s.substr(0, n / 2);
        second = s.substr((n / 2) + 1, n);
    }
    cout << first << " : " << second << endl;
    reverse(second.begin(), second.end());
    int diff = 0;
    for (int i = 0; i < (int) first.size(); i++) {
        if (first[i] != second[i]) {
            diff++;
        }
    }
    for (int i = 0; i < (int) first.size(); i++) {
        if (first[i] != second[i]) {
            if (first[i] == '9') {
                if (k - 1 >= diff - 1) {
                    second[i] = '9';
                    k--;
                    diff--;
                } else {
                    return "-1";
                }
            } else if (second[i] == '9') {
                if (k - 1 >= diff - 1) {
                    first[i] = '9';
                    k--;
                    diff--;
                } else {
                    return "-1";
                }
            } else {
                if (k - 2 >= diff - 1) {
                    first[i] = '9';
                    second[i] = '9';
                    k -= 2;
                    diff--;
                } else if (k - 1 >= diff - 1) {
                    if (first[i] > second[i]) {
                        second[i] = first[i];
                    } else {
                        first[i] = second[i];
                    }
                    k--;
                    diff--;
                } else {
                    return "-1";
                }
            }
        } else if (first[i] == second[i]) {
            if (first[i] == '9')
                continue;
            if (k - 2 >= diff) {
                first[i] = '9';
                second[i] = '9';
                k -= 2;
            }
        }
    }
    reverse(second.begin(), second.end());
    string res = "-1";
    if (n % 2 == 0) {
        res = "";
        res = first + second;
    } else {
        res = "";
        res += first;
        res += (k > 0) ? '9' : s[n / 2];
        res += second;
    }
    return res;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";
    cout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(),
            [](const char &x, const char &y) {
                return x == y and x == ' ';
            });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(
            input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
