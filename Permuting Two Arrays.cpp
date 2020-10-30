#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++)
    {
        int n,k;
        cin >> n >> k;
        vector<int>a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<int>());
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] + b[i] >= k) cnt++;
        }
        if(cnt == n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
