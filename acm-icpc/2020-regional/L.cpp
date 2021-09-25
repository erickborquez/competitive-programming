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

const int MX = 1e6;
const int TIME = 60 * 8;
const int SHIFT = 1000;

int main()
{
  IO;
  int n, x, s, d;
  cin >> n >> x;
  vector<int> acc(1e6 + 1, 0);
  FOR(i, 0, n)
  {
    cin >> s >> d;
    int start = s % x;
    while (start <= s)
    {
      int end = start + d + 1;
      acc[start]++;
      acc[end]--;
      // debp(start, end);
      int actual = start + x;
      while (actual < end)
      {

        acc[start]++;
        acc[end - actual + start]--;
        // debp(start, end - actual + start);

        actual += x;
      }
      start += x;
    }

    int nStart = s % x - x;
    int nEnd = min(start - 1, nStart + d + 1);
    int nActual = nStart + x;

    if (nEnd <= 0)
      continue;

    if (nEnd > 0)
    {
      acc[max(0, nStart)]++;
      acc[nEnd]--;
    }
    while (nActual < nEnd)
    {
      if (nEnd - nActual > 0)
      {

        acc[max(0, nStart)]++;
        acc[nEnd - nActual]--;
      }
      nActual += x;
    }
  }

  pair<int, int> best = make_pair(0, acc[0]);
  int curr = 0;
  FOR(i, 0, TIME + 1)
  {
    curr += acc[i];
    if (best.S > curr)
    {
      best = make_pair(i, curr);
    }
  }
  cout << best.F << " " << best.S << ENDL;

  return 0;
}