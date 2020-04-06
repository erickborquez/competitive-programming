#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> g(1000);
  int n, aux;
  cin >> n;
  for (int i(1); i <= n; i++)
  {
    cin>>aux;
    g[aux] = i;
  }
    for (int i(1); i <= n; i++)
  {
    cout<<g[i]<<" ";
  }
  return 0;
}