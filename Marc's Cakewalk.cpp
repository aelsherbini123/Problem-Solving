#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
long long getPower(long long a, long long b)
{
    long long res = 1;
    for(int i = 0; i < b; i++)
    {
        res *= 2;
    }
    return res;
}
int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<long long>());
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += getPower(2,i) * arr[i];
    }
    cout << sum << endl;
    return 0;
}
