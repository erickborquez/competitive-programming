#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

#define lli long long
using namespace std;

int n;
map<pair<int, int>, bool> visited;
vector<pair<int, int>> fromLand, toLand;
pair<int, int> from, to;

bool isValidPos(int y, int x)
{
  return (!(y <= 0 || y > n || x <= 0 || x > n));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string land[51];

  cin >> n;
  cin >> from.F >> from.S;
  cin >> to.F >> to.S;

  for (int i(0); i < n; i++)
    cin >> land[i];
  queue<pair<int, int>> q;
  pair<int, int> actual, aux;
  int y[4] = {-1, 0, 1, 0};
  int x[4] = {0, 1, 0, -1};

  visited[from] = true;
  q.push(from);

  while (!q.empty())
  {
    actual = q.front();
    if (actual == to)
    {
      cout << 0 << ENDL;
      return 0;
    }
    fromLand.pb(actual);
    q.pop();
    for (int i(0); i < 4; i++)
    {
      aux.F = actual.F + y[i];
      aux.S = actual.S + x[i];
      if (isValidPos(aux.F, aux.S))
      {
        if (land[aux.F - 1][aux.S - 1] == '0')
        {
          if (!visited[aux])
          {
            q.push(aux);
            visited[aux] = true;
          }
        }
      }
    }
  }
  q.push(to);
  visited[to] = true;

  while (!q.empty())
  {
    actual = q.front();
    toLand.pb(actual);
    q.pop();
    for (int i(0); i < 4; i++)
    {
      aux.F = actual.F + y[i];
      aux.S = actual.S + x[i];
      if (isValidPos(aux.F, aux.S))
      {
        if (land[aux.F - 1][aux.S - 1] == '0')
        {
          if (!visited[aux])
          {
            q.push(aux);
            visited[aux] = true;
          }
        }
      }
    }
  }

  int minDistance = 10000;
  for (auto f : fromLand)
  {
    for (auto t : toLand)
    {
      minDistance = min(minDistance, (f.F - t.F) * (f.F - t.F) + (f.S - t.S) * (f.S - t.S));
      if (minDistance == 1)
      {
        cout << 1 << ENDL;
        return 0;
      }
    }
  }
  cout << minDistance << ENDL;

  return 0;
}

