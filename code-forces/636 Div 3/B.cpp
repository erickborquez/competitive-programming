#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb pus_back
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
    int n;
    cin >> n;
    if ((n / 2) % 2 == 1)
    {
      cout << "NO" << ENDL;
      continue;
    }
    vector<int> arr(n);
    bool flag = false;
    FOR(i, 0, n / 2)
    {
      arr[i] = i * 4 + 2;
      if (flag)
      {
        arr[n / 2 + i] = i * 4 - 1 + 2;
      }
      else
        arr[n / 2 + i] = i * 4 + 1 + 2;
      flag = !flag;
    }

    cout << "YES" << ENDL;
    for (auto e : arr)
      cout << e << " ";
    cout << ENDL;
  }
  return 0;
}