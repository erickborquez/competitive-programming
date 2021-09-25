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

const int TIME = 60 * 8 + 1;

int n, x;
int getOverlaps(int u, int s, int d)
{
  if (s + d < u)
    return 0;
  int start;
  bool hasOverlap = false;
  if (u >= s)
  {
    hasOverlap = true;
    start = u;
  }
  else
  {
    int left = s - u;
    if (left % x == 0)
      start = u + left;
    else
      start = u + (left - left % x) + x;
  }
  int extra = d - (start - s);
  int total = hasOverlap + extra / x;
  // deb(u);
  // debp(s, d);
  // deb(start);
  // deb(extra);
  // deb(hasOverlap);
  // deb(total);
  if (extra < 0)
    return 0;
  return extra / x + 1;
}

int main()
{
  IO;
  cin >> n >> x;
  vector<int> acc(TIME, 0);
  FOR(i, 0, n)
  {
    int s, d;
    cin >> s >> d;
    FOR(k, 0, TIME)
    acc[k] += getOverlaps(k, s, d);
  }
  int best = 0;
  FOR(i, 0, TIME)
  {
    // debp(i, acc[i]);
    if (acc[i] < acc[best])
      best = i;
  }
  cout << best << " " << acc[best] << ENDL;
  return 0;
}