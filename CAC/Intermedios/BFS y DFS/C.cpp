#include <bits/stdc++.h>
#define ENDL '\n'
#define F first
#define S second
#define pb push_back

using namespace std;

int nodes[10001];
bool roots[10001];
bool paths[10001][10001];
bool visited[10001];
queue<int> q;
set<int> av;

vector<int> tasks;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, from, to;
  cin >> n >> m;
  for (int i(0); i <= n; i++)
    roots[i] = true;
  while (m--)
  {
    cin >> from >> to;
    paths[from][to] = true;
    roots[to] = false;
    nodes[to]++;
  }

  for (int i(1); i <= n; i++)
  {
    if (roots[i])
    {
      av.emplace(i);
    }
  }

  if (av.empty())
  {
    cout << "Sandro fails." << ENDL;
    return 0;
  }
  int f;
  q.push(*av.begin());

  while (!q.empty())
  {
    f = q.front();
    if (visited[f])
    {
      cout << "Sandro fails." << ENDL;
      return 0;
    }
    visited[f] = true;
    tasks.pb(f);
    av.erase(f);
    q.pop();
    for (int i(1); i < n; i++)
    {
      if (paths[f][i])
      {
        if (--nodes[i] == 0)
        {
          av.emplace(i);
        }
      }
    }
    if (!av.empty())
    {
      q.push(*av.begin());
    }
  }
  if (tasks.size() != n)
  {
    cout << "Sandro fails." << ENDL;
    return 0;
  }
  for (int e : tasks)
  {
    cout << e << ENDL;
  }
  return 0;
}