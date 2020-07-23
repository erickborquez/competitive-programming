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
    cin >> s;
    vector<int> acc(s.size(), 0);
    acc[0] = s[0] == '1' ? 1 : 0;
    FOR(i, 1, s.size())
    {
      acc[i] = acc[i - 1] + (s[i] == '1' ? 1 : 0);
      // deb(acc[i]);
    }
    int best = 10000;
    FOR(i, 0, s.size())
    {
      int offLeft = acc[i];
      int onLeft = i + 1 - acc[i];

      int offRight = acc[s.size() - 1] - acc[i];
      int onRight = s.size() - i - 1 - offRight;

      int curr = min(onLeft + offRight, offLeft + onRight);
      // deb(i);
      // deb(curr);
      best = min(best, curr);
    }
    best = min(best, max(0, acc[s.size() - 1]));

    cout << best << ENDL;
  }
  return 0;
}