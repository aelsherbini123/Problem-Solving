#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    long long cnt = 0, sum = k;
    for(int i = 0; i < n; i++)
    {
        sum = sum - a[i];
        if(sum >= 0)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
