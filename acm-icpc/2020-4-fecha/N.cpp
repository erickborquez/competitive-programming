#include <bits/stdc++.h>
#define DEBUG true
#define ENDL '\n'
#define deb(u) \
  if (DEBUG)   \
    cout << #u " : " << (u) << ENDL;
#define deba(alias, u) \
  if (DEBUG)           \
    cout << alias << ": " << (u) << ENDL;
#define debp(u, v) \
  if (DEBUG)       \
    cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
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

int getBalance()
{
  string u;
  cin >> u;
  int pos = u.find('.');
  string left = "", right = "";
  left = u.substr(1, pos - 1);
  right = u.substr(pos + 1, u.size() - pos - 1);
  return stoi(left) * 100 + stoi(right);
}

int main()
{
  IO;
  int n, ans = 0, acc = 0;
  cin >> n;
  acc = getBalance();
  while (n--)
  {
    acc += getBalance();
    if (acc % 100 > 0)
      ans++;
  }
  cout << ans << ENDL;
  return 0;
}