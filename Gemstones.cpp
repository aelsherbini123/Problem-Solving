#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    string res, pre = arr[0];
    for (int i = 1; i < (int) arr.size(); i++) {
        res = "";
        sort(pre.begin(), pre.end());
        sort(arr[i].begin(), arr[i].end());
        set_intersection(pre.begin(), pre.end(), arr[i].begin(), arr[i].end(), back_inserter(res));
        pre = res;
    }
    return res.size();
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
