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

int main()
{
  IO;
  int n;
  cin >> n;
  vector<lli> a(n), b(n);
  vector<lli> interest(n);
  FOR(i, 0, n)
  {
    cin >> a[i];
  }
  FOR(i, 0, n)
  {
    cin >> b[i];
    interest[i] = a[i] - b[i];
  }
  sort(ALL(interest));
  lli total = 0;
  // FOR(i, 0, n)
  // cout << interest[i] << " ";
  // cout << ENDL;
  FOR(i, 0, n)
  {
    lli actual = interest[i];
    auto begin = interest.begin() + i;

    int amount = int(interest.end() - upper_bound(begin, interest.end(), -actual));
    if (actual > 0)
      amount--;
    total += amount;
    // deb(amount);
  }
  cout << total << ENDL;

  return 0;
}