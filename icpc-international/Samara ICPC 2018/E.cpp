#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

int main()
{
  IO;
  string s, t;
  cin >> s >> t;
  if (s == t)
  {
    cout << "YES" << ENDL;
    return 0;
  }
  int n = s.size();
  vector<bool> e(n, true);
  map<char, int> ms, mt;
  int start = -1, end = -1;
  FOR(i, 0, n)
  {
    ms[s[i]]++;
    mt[t[i]]++;
    if (s[i] != t[i])
    {
      if (start == -1)
        start = i;
      end = i;
    }
  }
  if (ms != mt)
  {
    cout << "NO" << ENDL;
    return 0;
  }
  string left = s.substr(0, start), right = s.substr(end + 1, n - end);
  string mid = s.substr(start, end - start + 1);
  // deb(left);
  // deb(right);
  // deb(mid);
  reverse(ALL(mid));
  string newS = left + mid + right;
  // deb(newS);
  if (t == newS)
  {
    cout << "YES" << ENDL;
  }
  else
    cout << "NO" << ENDL;

  return 0;
}