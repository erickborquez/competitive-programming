#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u << " : " << u << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define pii pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)

using namespace std;
#define INF 1000000
map<char, int> ch;
string s;
vector<vector<int>> acc;

pair<int, int> mm = {0, 100}, pos = {0, 0};
int lng = -1;
int diff = INF;

pii getDiff(int from, int to)
{
  int mx = -1, mn = INF;
  FOR(i, 0, 4)
  {
    mx = max(mx, acc[to][i] - acc[from - 1][i]);
    mn = min(mn, acc[to][i] - acc[from - 1][i]);
  }

  return {mn, mx};
}

int getBest(int ptr)
{
  int ans = 0;
  FOR(i, ptr, s.size() + 1)
  {
    pii d = getDiff(ptr, i);
    int df = d.S - d.F;
    int dist = i - ptr;
    if (df == diff)
    {
      if (dist > lng)
      {
        pos = {ptr, i};
        lng = dist;
        mm = d;
      }
    }

    if (df < diff)
    {
      lng = dist;
      diff = df;
      pos = {ptr, i};
      mm = d;
    }
  }
  return ans;
}

int main()
{
  IO;
  cin >> s;
  acc = vector<vector<int>>(s.size() + 1, vector<int>(4, 0));
  ch.emplace('R', 0);
  ch.emplace('G', 1);
  ch.emplace('B', 2);
  ch.emplace('Y', 3);
  FOR(i, 0, s.size())
  {
    acc[i + 1] = acc[i];
    acc[i + 1][ch[s[i]]]++;
  }
  // FOR(i, 1, s.size() + 1)
  // {
  //   FOR(j, 0, 4)
  //   {
  //     cout << acc[i][j] << " ";
  //   }
  //   cout << ENDL;
  // }

  FOR(i, 1, s.size() + 1)
  {
    getBest(i);
    // deb("??");
  }
  cout << diff << " " << lng + 1 << ENDL;
  cout << pos.F << " " << pos.S << ENDL;

  return 0;
}