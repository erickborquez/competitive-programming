#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u << " : " << u << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define pii pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)

using namespace std;

int main()
{
  IO;
  int m, n;
  cin >> m;
  vector<string> v(m);
  FOR(i, 0, m)
  {
    cin >> v[i];
  }
  cin >> n;
  lli ans = 1;
  lli ptr = 1;
  while (n > 0)
  {
    }
  cout << ans << ENDL;
  return 0;
}