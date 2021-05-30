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
    int n, x, a;
    cin >> n >> x;
    set<int> places;
    while (n--)
    {
      cin >> a;
      places.insert(a);
    }
    for (int i(1);; i++)
    {
      if (places.count(i) == 0)
      {
        if (x == 0)
        {
          cout << i - 1 << ENDL;
          break;
        }
        x--;
      }
    }
  }
  return 0;
}