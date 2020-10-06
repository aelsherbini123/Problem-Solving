#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {
	for (int i = 1, j = s.length()-1; i < (int)s.length() && j >= 0; i++, j--){
		int x = abs(s[i - 1] - s[i]);
		int y = abs(s[j] - s[j-1]);
//		cout << x << " " << y << endl;
		if(x != y){
			return "Not Funny";
		}
	}
		return "Funny";
}

int main() {
	ofstream fout(getenv("OUTPUT_PATH"));

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string s;
		getline(cin, s);

		string result = funnyString(s);
//		cout << result << endl;
		fout << result << "\n";
	}

	fout.close();

	return 0;
}
