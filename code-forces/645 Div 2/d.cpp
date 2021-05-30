#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ulli unsigned long long
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

lli sum(ulli n)
{
  if (n % 2)
    return ((n + 1) / 2) * n;
  return (n / 2) * (n + 1);
}

int main()
{
  IO;
  lli n, x;
  cin >> n >> x;
  vector<lli> v(n + 1), accDays(n + 1), acc(n + 1);
  lli best = 0;

  FOR(i, 0, n)
  {
    cin >> v[i];
    best = max(best, v[i]);
  }

  lli ans = 0;
  if (best >= x)
  {
    ans = sum(best) - sum(best - x);
  }
  else
  {
    v[n] = 0;
    acc[n] = 0;
    accDays[n] = 0;
    FORN(i, n, 0)
    {
      accDays[i] = accDays[i + 1] + v[i];
      acc[i] = acc[i + 1] + sum(v[i]);
    }
    if (accDays[0] == x)
    {
      cout << acc[0] << ENDL;
      return 0;
    }
    FOR(k, 0, n)
    {
      lli ptr = k;
      for (lli i = n - 1; i > 0; i /= 2)
      {
        while (true)
        {
          lli newPtr = (ptr - i + n) % n;
          lli days;
          if (newPtr > k)
            days = accDays[newPtr] + accDays[0] - accDays[k + 1];
          else
            days = accDays[newPtr] - accDays[k + 1];
          if (days > x)
            break;
          ptr = newPtr;
          // deb(days);
          // deb(newPtr);
        }
      }
      lli total, restDays;
      if (ptr > k)
      {
        total = acc[ptr] + acc[0] - acc[k + 1];
        restDays = x - (accDays[ptr] + accDays[0] - accDays[k + 1]);
      }
      else
      {
        total = acc[ptr] - acc[k + 1];
        restDays = x - (accDays[ptr] - accDays[k + 1]);
      }

      if (restDays > 0)
      {
        lli newPtr = (ptr - 1 + n) % n;
        if (ptr > k)
          total += sum(v[newPtr]) - sum(v[newPtr] - restDays);
        else
          total += sum(v[newPtr]) - sum(v[newPtr] - restDays);
      }

      // deb(acc[ptr]);
      // deb(k + 1);
      // deb(acc[k + 1]);

      // deb(k);
      // deb(ptr);
      // deb(restDays);
      // deb(total);
      ans = max(ans, total);
    }
  }
  cout << ans << ENDL;

  return 0;
}