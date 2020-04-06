#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;

#define lli long long
using namespace std;
lli k;

lli suma(lli n)
{
  lli sum = 0;
  if (n % 2 == 0)
  {
    sum = n / 2;
    sum *= n + 1;
  }
  else
  {
    sum = (n + 1) / 2;
    sum *= n;
  }
  return sum;
}

bool ok(lli pos)
{
  return suma(pos) < k;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lli t, n;
  cin >> t;
  while (t--)
  {
    cin >> n >> k;
    lli pos = 0;
    for (lli i(n); i > 0; i /= 2)
    {
      while (ok(pos + i))
      {
        pos += i;
      }
    }
    lli first = pos + 1;
    lli second = k - suma(pos) - 1;

    for (lli i(n - 1); i >= 0; i--)
    {
      if (i == first)
        cout << 'b';
      else if (i == second)
        cout << 'b';
      else
        cout << 'a';
    }
    cout << ENDL;
  }

  return 0;
}