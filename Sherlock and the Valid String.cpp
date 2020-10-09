#include <bits/stdc++.h>
using namespace std;

int main() {
  set<int> myset;
  string s;
  cin >> s;
  string ans = "NO";

  int cnt[26] = {}, n = s.length();

  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }

  for (int i = -1; i < 26; i++) {
    if (i >= 0 and cnt[i] == 0)
      continue;

    if (i >= 0)
      cnt[i]--;

    set<int> myset;

    for (int j = 0; j < 26; j++) {
      if (cnt[j])
        myset.insert(cnt[j]);
    }

    if (myset.size() == 1)
      ans = "YES";

    if (i >= 0)
      cnt[i]++;
  }
  cout << ans << endl;
  return 0;
}
