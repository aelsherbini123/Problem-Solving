#include <bits/stdc++.h>

using namespace std;

// Complete the stringConstruction function below.
int stringConstruction(string s) {
    set<char> st(s.begin(), s.end());
    return st.size();
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = stringConstruction(s);

        fout << result << "\n";
        cout << result << "\n";
    }

    fout.close();

    return 0;
}
