#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define INF 1000000

#define lli long long

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> fib;
  fib.pb(0);
  fib.pb(1);
  fib.pb(1);
  for (int i(3);; i++)
  {
    fib.pb(fib[i - 1] + fib[i - 2]);
    if (fib[i] >= n)
      break;
  }
  if (n == 1)
  {
    cout << 1 << " " << 0 << " " << 0 << ENDL;
    return 0;
  }
  if (n == 0)
  {
    cout << 0 << " " << 0 << " " << 0 << ENDL;
    return 0;
  }
  cout << fib[fib.size() - 2] << " " << fib[fib.size() - 3] << " " << 0 << ENDL;
  return 0;
}