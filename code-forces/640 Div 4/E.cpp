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
    cin >> n;
    vector<int> a(n), acc(n, 0);
    FOR(i, 0, n)
    {
      cin >> a[i];
      acc[i] = a[i];
      acc[i] += i == 0 ? 0 : acc[i - 1];
    }
    // for (auto e : acc)
    //   deb(e);
    int total = 0;
    for (auto special : a)
    {
      for (int i(0); i < n; i++)
      {
        if (a[i] >= special)
          continue;
        int search = acc[i] + (special - a[i]);
        // debp(special, search);
        bool ok = binary_search(acc.begin() + i, acc.end(), search);
        if (ok)
        {
          total++;
          break;
        }
      }
    }
    cout << total << ENDL;
  }
  return 0;
}