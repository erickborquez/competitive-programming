#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

#define lli long long

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a, b, mn;
  cin >> a >> b;
  mn = min(a, b);
  lli fact = 1;
  for (int i(1); i <= mn; i++)
  {
    fact *= i;
  }
  cout << fact << ENDL;

  return 0;
}