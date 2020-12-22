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

map<char, vector<int>> ht;

vector<int> pos;

void resolve()
{
  bool ok = false;
  if (pos.size() == 1)
    ok = true;
  else if (pos[pos.size() - 1] != -1)
    ok = true;
  if (ok)
    cout << "YES" << ENDL;
  else
    cout << "NO" << ENDL;
}

int main()
{
  IO;
  string s, t, q;
  char c;
  int n;
  cin >> s >> n;
  FOR(i, 0, s.size())
  {
    ht[s[i]].pb(i);
  }
  pos.pb(-1);
  FOR(i, 0, n)
  {
    cin >> q;
    if (q == "pop")
      pos.pop_back();
    else
    {
      cin >> c;
      int last = pos.size() - 1;
      if (last == 0 || pos[last] != -1)
      {
        int ptr = upper_bound(ALL(ht[c]), pos[last]) - ht[c].begin();
        if (ptr < ht[c].size())
          pos.pb(ht[c][ptr]);
        else
          pos.pb(-1);
      }
      else
        pos.pb(-1);
    }
    resolve();
  }

  return 0;
}