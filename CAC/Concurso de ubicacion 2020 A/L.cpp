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
  set<int> s;
  int n, aux;
  cin >> n;
  cin >> aux;
  s.insert(aux);
  cin >> aux;
  s.insert(aux);
  cin >> aux;
  s.insert(aux);
  for (auto e : s)
    cout << e << ENDL;
  return 0;
}