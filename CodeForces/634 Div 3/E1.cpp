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
    int n, aux;
    cin >> n;

    map<int, vector<int>> mp;
    FOR(i, 0, n)
    {
      cin >> aux;
      mp[aux].pb(i);
    }
    int best = 0;
    int btw = 0;
    pii ptr = {-1, -1};
    int c = -1;
    if (n == 1)
    {
      cout << n << ENDL;
      continue;
    }
    if (n == 2)
    {
      if (mp.size() == 1)
        cout << 2 << ENDL;
      else
        cout << 1 << ENDL;
      continue;
    }
    for (auto e : mp)
    {
      // debp(e.F, e.S.size());
      FOR(i, 0, e.S.size() - 1)
      {
        int start = e.S[i];
        FOR(j, i + 1, e.S.size())
        {
          // cout << "---" << ENDL;
          int end = e.S[j];
          // deb(start);
          // deb(end);

          int mxInside = 0;
          for (auto f : mp)
          {
            auto MN = lower_bound(ALL(f.S), start);
            if (*MN >= end)
              continue;
            auto MX = lower_bound(ALL(f.S), end);
            if (MX != f.S.end() && *MX == end)
            {
              MX--;
            }
            // deb(*MX);

            int dist = MX - MN;
            // deb(dist);
            mxInside = max(mxInside, dist);
          }
          if (mxInside > best)
          {
            best = mxInside;
            ptr = {start, end};
            btw = end - start;
            c = e.F;
          }
          else if (mxInside == best && (end - start) < btw)
          {
            ptr = {start, end};
            btw = end - start;
            c = e.F;
          }
        }
      }
    }
    // deb(best);
    // deb(btw);
    // debp(ptr.F, ptr.S);
    // deb(c);
    int left = 0, right = 0;
    FOR(i, 0, mp[c].size())
    {
      if (mp[c][i] < ptr.F)
        left++;
      if (mp[c][i] > ptr.S)
        right++;
    }
    // debp(left, right);
    cout << best + 2 + max(left, right) * 2 << ENDL;
  }
  return 0;
}