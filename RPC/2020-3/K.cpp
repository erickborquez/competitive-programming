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
  int n, m;
  string plain, cip;
  cin >> n >> m >> plain >> cip;
  vector<int> key(m);
  FOR(i, 1, n + 1)
  {
    char o = plain[n - i], c = cip[m - i];
    int posO = plain[n - i] - 'a', posC = cip[m - i] - 'a';
    int k;
    if (posO > posC)
    {
      k = 26 - posO + posC;
    }
    else
      k = posC - posO;
    key[m - i] = k;
  }
  string res = plain;
  FOR(i, 1, m - n + 1)
  {
    int pos = m - i;
    char gen = key[pos];
    res = (char(key[pos] + 'a')) + res;
    // deb(res);
    // debp(res[0], cip[m - n - i]);
    int posO = res[0] - 'a', posC = cip[m - n - i] - 'a';
    int k;
    if (posO > posC)
    {
      k = 26 - posO + posC;
    }
    else
      k = posC - posO;
    // deb(k);
    key[m - n - i] = k;
  }
  cout << res << ENDL;

  return 0;
}