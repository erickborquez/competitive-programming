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
  lli k;
  cin >> k;
  string ans = "codeforces";
  vector<int> v(ans.size(), 1);
  lli total = 1;
  int ptr = 0;
  while (true)
  {
    total = 1;
    FOR(i, 0, ans.size())
    {
      total *= v[i];
    }
    if (total >= k)
      break;
    v[ptr]++;
    ptr = (ptr + 1) % ans.size();
  }
  // deb(total);
  FOR(i, 0, ans.size())
  {
    cout << string(v[i], ans[i]);
  }
  cout << ENDL;
  return 0;
}