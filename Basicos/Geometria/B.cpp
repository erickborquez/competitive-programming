#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;

#define lli long long

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, a;
  cin >> t;
  while (t--)
  {
    cin >> a;
    if (360 % (180 - a) == 0)
      cout << "YES" << ENDL;
    else
      cout << "NO" << ENDL;
  }

  return 0;
}