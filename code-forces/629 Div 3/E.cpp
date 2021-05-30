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
  int n, m;
  int from, to;
  cin >> n >> m;
  vector<vector<int>> tree;
  vector<pair<int, int>> nodes;
  vector<vector<int>> paths;
  for (int i(0); i < n - 1; i++)
  {
    cin >> from >> to;
    nodes.pb({from, to});
    tree[from].pb(to);
    tree[to].pb(from);
  }
  while (m--)
  {
  }

  return 0;
}