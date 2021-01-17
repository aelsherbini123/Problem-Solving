// Write your code here
#include <cstring>
#include <iostream>
#include <cstdlib>
#define ll long long
#define mod 1000000007
using namespace std;
 
ll result[100006] = {0};
/* 
 * Find Factorial of a Number using Dynamic Programming 
 */

int main(){
	int tc, n;
	cin >> tc;
	result[0] = 1;
	for (int i = 1; i <= 100000; ++i) 
	{
		result[i] = (i * result[i - 1])%mod;
	}
	for(int i = 0; i < tc; i++){
		cin >> n;
		cout << result[n] << endl;
	}
	return 0;
}
