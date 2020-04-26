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
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;
vector<int> res(3000, -1);
int print(int n)
{
  if (res[n] != -1)
    return res[n];
  res[n] = res[n] = 3 * n - 1 + print(n - 1);
  return res[n];
}

int main()
{
  IO;
  string h, n;
  res[0] = 0;
  cin >> h;
  n = h;
  if (h.size() > 3)
    n = n.substr(h.size() - 3, 3);
  int pos = stoi(n);
  int t = 0;
  while (!(print(pos + t) % 4 == 0))
    t++;

  string res = "";
  FORN(i, h.size(), 0)
  {
    int num = h[i] - '0';
    res = to_string((num + t) % 10) + res;
    if (num + t < 10)
      t = 0;
    else
      t = 1;
  }
  if (t == 1)
    cout << 1;
  cout << res << ENDL;
}