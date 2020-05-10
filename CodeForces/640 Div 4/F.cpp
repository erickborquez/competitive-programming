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
    int n0, n1, n2;
    bool last = false;
    cin >> n0 >> n1 >> n2;
    if (n2 > 0 && n0 > 0)
      n1--;
    if (n2 == 0 && n0 == 0)
    {
      last = false;
      cout << 0;
    }
    if (n2 > 0)
    {
      cout << "1";
      last = true;
    }
    while (n2--)
      cout << "1";
    if (n0 > 0)
    {
      cout << "0";
      last = false;
    }
    while (n0--)
      cout << "0";

    for (int i(0); i < n1; i++)
    {
      if (last)
        cout << 0;
      else
        cout << 1;
      last = !last;
    }
    cout << ENDL;
  }
  return 0;
}