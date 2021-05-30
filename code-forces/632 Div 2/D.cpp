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
  lli n;
  cin >> n;
  vector<lli> v(n + 1, 0), acc(n + 1, 0);
  FOR(i, 1, n + 1)
  {
    cin >> v[i];
  }
  set<lli> st;
  lli u = 1;
  lli ans = 0;
  st.emplace(0);
  FOR(i, 1, n + 1)
  {
    acc[i] = acc[i - 1] + v[i];
    while (st.find(acc[i]) != st.end())
    {
      lli lg = i - u;
      ans += lg;
      st.erase(acc[i]);
      u++;
    }
    st.emplace(acc[i]);
  }
  FOR(i, u, n + 1)
  {
    ans += n - i + 1;
  }
  cout << ans << ENDL;
  return 0;
}