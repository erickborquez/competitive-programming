#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
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
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    vector<string> nums;
    cin >> s;
    FOR(i, 0, s.size())
    {
      int pos = s.size() - i - 1;
      if (s[pos] == '0')
        continue;
      string aux(1, s[pos]);
      FOR(j, 0, i)
      aux += "0";
      nums.pb(aux);
    }
    cout << nums.size() << ENDL;
    for (auto k : nums)
      cout << k << " ";
    cout << ENDL;
  }
  return 0;
}