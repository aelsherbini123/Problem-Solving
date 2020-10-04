#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
	char alphabetics[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
			'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
			'x', 'y', 'z' };
	map<char, int> tab;
	int pos = 0;
	for (char i = 'a'; i <= 'z'; i++) {
		tab[i] = pos;
		pos++;
	}
	for (int i = 0; i < (int)s.length(); i++) {
		if (isalpha(s[i])) {
			if (isupper(s[i])) {
				s[i] = toupper(alphabetics[((tab[tolower(s[i])] + k) % 26)]);
			} else {
				s[i] = alphabetics[((tab[s[i]] + k) % 26)];
			}
		}
	}
	cout << s << endl;
	return s;
}

int main() {
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string s;
	getline(cin, s);

	int k;
	cin >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string result = caesarCipher(s, k);

	fout << result << "\n";

	fout.close();

	return 0;
}
