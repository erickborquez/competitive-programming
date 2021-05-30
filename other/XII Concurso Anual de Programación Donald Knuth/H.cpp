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
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, p;
    cin >> n >> p;
    vector<int> v(n + 1, 0);
    FOR(i, 1, n + 1)
    {
      int pos;
      cin >> pos;
      v[i] = pos;
    }
    bool ok = true;
    FOR(i, 1, n + 1)
    {
      while (v[i] != i)
      {
        if (p <= 0)
        {
          ok = false;
          break;
        }
        p--;
        swap(v[i], v[v[i]]);
      }
    }
    if (ok && p % 2 == 0)
      cout << "Yes" << ENDL;
    else
      cout << "No" << ENDL;
  }
  return 0;
}