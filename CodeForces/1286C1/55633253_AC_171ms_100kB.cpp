#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
multiset<string> s1, s2;
int cnt[N][26];
int main() {
   cin >> n;
   if (n == 1) {
      cout << "? 1 1" << endl;
      string s;
      cin >> s;
      cout << "! " << s << endl;
      return 0;
   }
   cout << "? " << 1 << ' ' << n << endl;
   for (int i = 1; i <= n * (n + 1) / 2; i++) {
      string s;
      cin >> s;
      sort(s.begin(), s.end());
      s1.insert(s);
   }
   cout << "? " << 2 << ' ' << n << endl;
   for (int i = 1; i <= n * (n - 1) / 2; i++) {
      string s;
      cin >> s;
      sort(s.begin(), s.end());
      s2.insert(s);
   }
   for (string S : s1) {
      if (s2.find(S) != s2.end())
         s2.erase(s2.find(S));
      else
         for (char c : S)
            cnt[S.size()][c - 'a']++;
   }
   cout << "! ";
   for (int i = 1; i <= n; i++)
      for (int j = 0; j < 26; j++)
         if (cnt[i - 1][j] + 1 == cnt[i][j])
            cout << (char)(j + 'a');
   cout << endl;
}

// aabc
