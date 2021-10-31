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
#define ll long long
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

const ll TIME = 1e5 + 10;
const ll INF = 1e8 + 10;

int main()
{
  IO;
  ll n;
  vector<ll> vLeft, vRight;
  cin >> n;
  FOR(i, 0, n)
  {
    int t, d;
    cin >> t >> d;
    if (d == 1)
      vRight.pb(t);
    else
      vLeft.pb(t);
  }
  ll nextStop = 0;
  ll pLeft = 0, pRight = 0;
  bool isLeft = false, isStopped = true;

  while (pLeft < vLeft.size() || pRight < vRight.size())
  {
    if (isStopped)
    {

      if (pLeft >= vLeft.size())
        isLeft = false;
      else if (pRight >= vRight.size())
        isLeft = true;
      else
        isLeft = vLeft[pLeft] < vRight[pRight];
      isStopped = false;
    }
    else if (isLeft)
    {
      if (pLeft < vLeft.size())
      {
        nextStop = max(nextStop, vLeft[pLeft]) + 10;
        pLeft++;
        while (pLeft < vLeft.size() && vLeft[pLeft] < nextStop)
        {
          nextStop = max(nextStop, vLeft[pLeft] + 10);
          pLeft++;
        }
      }
      isStopped = true;
    }
    else
    {
      if (pRight < vRight.size())
      {
        nextStop = max(nextStop, vRight[pRight]) + 10;
        pRight++;
        while (pRight < vRight.size() && vRight[pRight] < nextStop)
        {

          nextStop = max(nextStop, vRight[pRight] + 10);
          pRight++;
        }
      }
      isStopped = true;
    }
  }

  cout << nextStop << ENDL;
  return 0;
}