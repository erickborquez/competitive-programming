#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;

#define lli long long

using namespace std;

int parent[1000000];
int ssize[1000000];

multiset<int> ms;

void makeSet(int v)
{
  parent[v] = v;
  ssize[v] = 1;
  ms.insert(1);
}

int findSet(int v)
{
  if (v == parent[v])
    return v;
  return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b)
{
  a = findSet(a);
  b = findSet(b);
  if (a != b)
  {
    ms.erase(ms.lower_bound(ssize[a]));
    ms.erase(ms.lower_bound(ssize[b]));
    if (ssize[a] < ssize[b])
      swap(a, b);
    parent[b] = a;
    ssize[a] += ssize[b];
    ms.insert(ssize[a]);
    cout << *(--ms.end()) - *ms.begin() << ENDL;
  }
  else
  {
    cout << 0;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q, a, b;
  cin >> n >> q;
  for (int i(1); i <= n; i++)
    makeSet(i);
  while (q--)
  {
    cin >> a >> b;
    unionSet(a, b);
  }

  return 0;
}