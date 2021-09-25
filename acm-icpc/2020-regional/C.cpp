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

int n;
vector<lli> v;
lli total;
lli avg;

lli getClockWise(vector<lli> curr)
{
  lli cost = 0;
  lli actual = 0;
  FOR(i, 0, n)
  {
    // deb(actual);
    cost += actual;
    if (curr[i] == avg)
      continue;
    if (curr[i] > avg)
    {
      actual += curr[i] - avg;
      curr[i] = avg;
    }
    else
    {
      lli canGive = min(actual, avg - curr[i]);
      curr[i] += canGive;
      actual -= canGive;
    }
  }
  FOR(i, 0, n)
  {
    // deb(actual);
    cost += actual;
    if (curr[i] == avg)
      continue;
    lli canGive = min(actual, avg - curr[i]);
    curr[i] += canGive;
    actual -= canGive;
  }
  // deb(cost);
  return cost;
}

int main()
{
  IO;
  cin >> n;
  v = vector<lli>(n);
  total = 0;
  FOR(i, 0, n)
  {

    cin >> v[i];
    total += v[i];
  }
  avg = total / n;
  // debp(total, avg);

  vector<lli> reversed = v;
  reverse(ALL(reversed));

  lli clockWise = getClockWise(v);
  lli antiClockWise = getClockWise(reversed);
  // deb(clockWise);
  // deb(antiClockWise);
  // cout << min(getClockWise(v), getClockWise(reversed)) << ENDL;
  cout << min(clockWise, antiClockWise) << ENDL;
  return 0;
}