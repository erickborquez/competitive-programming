#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

#define lli long long

using namespace std;

lli k, n, a, b;

bool ok(lli i)
{
  if (i > n)
    return false;
  lli j = n - i;
  return (k - a * i - b * j) > 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--)
  {
    cin >> k >> n >> a >> b;
    lli p = 0;
    if (b * n >= k)
    {
      cout << -1 << ENDL;
      continue;
    }
    for (lli i(n); i > 0; i /= 2)
    {
      while (ok(p + i))
      {
        p += i;
      }
    }
    cout << p << ENDL;
  }
  return 0;
}