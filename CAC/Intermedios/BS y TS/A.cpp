#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

#define lli long long

using namespace std;

lli n;

bool ok(lli i)
{
  return (i * (i + 1) / 2) <= n;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    int p = 0;
    for (lli i(1000000); i > 0; i /= 2)
    {
      while (ok(p + i))
        p += i;
    }
    cout << p << ENDL;
    }

  return 0;
}