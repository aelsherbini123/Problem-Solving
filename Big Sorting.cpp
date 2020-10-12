#include <bits/stdc++.h>

using namespace std;
bool comp(string s1, string s2)
{
    int x = s1.length();
    int y = s2.length();
    if(x == y)
        return (s1 < s2);
    return x < y;
}
int main() {
    int n;
    cin >> n;
    vector<string> st;
    string s;
    for(int i = 0; i < n ; i++){
        cin >> s;
        st.push_back(s);
    }
    sort(st.begin(),st.end(), comp);
    for(int i = 0; i < (int)st.size(); i++)
    {
        cout << st[i] << endl;
    }
    return 0;
}

