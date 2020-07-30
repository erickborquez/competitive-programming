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
    int n;
    string str;
    cin >> n >> str;
    vector<int> vr(n + 1), vp(n + 1), vs(n + 1);
    FOR(i, 0, n)
    {
      int r = 0, p = 0, s = 0;
      if (str[i] == 'R')
      {
        r = 0;
        p = 1;
        s = -1;
      }
      else if (str[i] == 'P')
      {
        r = -1;
        p = 0;
        s = 1;
      }
      else if (str[i] == 'S')
      {
        r = 1;
        p = -1;
        s = 0;
      }
      vr[i + 1] = r + vr[i];
      vp[i + 1] = p + vp[i];
      vs[i + 1] = s + vs[i];
    }
    // cout << ENDL << "rock" << ENDL;
    // for (auto v : vr)
    //   cout << v << " ";
    // cout << ENDL << "paper" << ENDL;
    // for (auto v : vp)
    //   cout << v << " ";
    // cout << ENDL << "scisor" << ENDL;
    // for (auto v : vs)
    //   cout << v << " ";
    // cout << ENDL;

    int total = 0;
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    FOR(i, 0, n + 1)
    {
      // deb(i);
      int rock = 0;
      rock = vr[i];
      if (i == n && vr[i] > 0)
      {
        total++;
        break;
      }
      FOR(j, i, n + 1)
      {
        int paper = vp[j] - vp[i];
        int scisor = vs[n] - vs[j];
        int res = rock + paper + scisor;
        // deb(dp[i][j]);
        if (res > 0)
        {
          // debp(i, j);
          total++;
        }
      }
    }
    cout << total << ENDL;
  }
  return 0;
}

/*
4
3
RPS
1
R
5
PPRSR
5
RPSPR
*/