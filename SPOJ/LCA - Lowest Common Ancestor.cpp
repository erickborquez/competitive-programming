#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define lli long long
#define deb(u) cout << #u ": " << (u) << endl;

using namespace std;

vector<int> euler;
vector<vector<int>> t(1001);
bool vis[1001];
int first[1001];
int height[1001];

void addNode(int u, int h)
{
  vis[u] = true;
  euler.pb(u);
  first[u] = euler.size();
  height[u] = h;
  for (auto v : t[u])
  {
    if (!vis[v])
    {
      addNode(v, h + 1);
      euler.pb(u);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, aux;
  cin >> n;
  for (int i(1); i <= n; i++)
  {
    cin >> m;
    while (m--)
    {
      cin >> aux;
      t[i].pb(aux);
    }
  }

  addNode(1, 1);
  for (auto u : euler)
  {
    cout << u << ":" << height[u] << " ";
  }
  cout << ENDL;
  for (int i(1); i <= n; i++)
  {
    cout << i << ": " << first[i] << ENDL;
  }

  return 0;
}