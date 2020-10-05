#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<string> res;
    vector<bool> vis(10000000);
    char pre = '1';
    int cnt = 1;
    for(int i = 0; i < s.length(); i++)
    {
        int w = s[i] - 'a' + 1;
        if(s[i] == pre) {cnt++; w *= cnt;}
        else cnt = 1;
        pre = s[i];
        vis[w] = true;
    }
    for(int i = 0; i < queries.size(); i++)
    {
        if(vis[queries[i]]) res.push_back("Yes");
        else res.push_back("No");
    }
    return res;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
