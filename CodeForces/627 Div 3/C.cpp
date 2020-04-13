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
    vector<int> jump;
    int last = -1;
    int mxDist = -1;
    FOR(i, 0, s.size())
    {
      if (s[i] == 'R')
      {
        int dist = i - last;
        mxDist = max(mxDist, dist);
        last = i;
      }
    }
    mxDist = max(mxDist, int(s.size() - last));
    cout << mxDist << ENDL;
  }
  return 0;
}