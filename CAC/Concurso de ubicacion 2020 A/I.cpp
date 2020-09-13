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
  lli total;
  int n, aux;
  vector<pair<int, int>> cans;
  cin >> n;
  total = n;
  for (int i(1); i <= n; i++)
  {
    cin >> aux;
    cans.pb(make_pair(aux, i));
  }
  sort(cans.rbegin(), cans.rend());
  for (int i(0); i < cans.size(); i++)
  {
    total += cans[i].F * i;
  }
  cout << total << ENDL;
  for (auto c : cans)
  {
    cout << c.S << " ";
  }

  return 0;
}