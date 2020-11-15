#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

// ABCA = [2,1,1,0,0,0....,0];
// AAAA = [4,0,0,0,0,0....,0];

int l, c, n;
int m[100][100];
vector<vector<int>> words;
vector<vector<set<int>>> dp;
vector<int> sizes;
vector<int> dict;

void searchHorizontal(int y, int k)
{
  if (sizes[k] > c)
    return;
  dict.assign(26, 0);
  FOR(i, 0, sizes[k])
  {
    dict[m[y][i]]++;
  }

  int left = 0, right = sizes[k];
  while (right < c)
  {
    if (dict == words[k])
    {
      FOR(i, left, right)
      {
        dp[y][i].insert(k);
      }
    }
    dict[m[y][left++]]--;
    dict[m[y][right++]]++;
  }
  if (dict == words[k])
  {
    FOR(i, left, right)
    dp[y][i].insert(k);
  }
}

void searchVertical(int x, int k)
{
  if (sizes[k] > l)
    return;
  dict.assign(26, 0);
  FOR(i, 0, sizes[k])
  {
    dict[m[i][x]]++;
  }
  int top = 0, bot = sizes[k];
  while (bot < l)
  {
    if (dict == words[k])
    {
      FOR(i, top, bot)
      {
        dp[i][x].insert(k);
      }
    }
    dict[m[top++][x]]--;
    dict[m[bot++][x]]++;
  }
  if (dict == words[k])
  {
    FOR(i, top, bot)
    {
      dp[i][x].insert(k);
    }
  }
}

void searchOther(int y, int x, int k)
{
  dict.assign(26, 0);
  if (x + sizes[k] > c)
    return;
  if (y + sizes[k] > l)
    return;

  FOR(i, 0, sizes[k])
  {
    dict[m[y + i][x + i]]++;
  }
  pii topLeft = {y, x}, botRight = {y + sizes[k], x + sizes[k]};
  while (botRight.first < l && botRight.second < c)
  {
    if (dict == words[k])
    {
      FOR(i, 0, sizes[k])
      {
        dp[topLeft.first + i][topLeft.second + i].insert(k);
      }
    }
    dict[m[topLeft.first++][topLeft.second++]]--;
    dict[m[botRight.first++][botRight.second++]]++;
  }
  if (dict == words[k])
  {
    FOR(i, 0, sizes[k])
    {
      dp[topLeft.first + i][topLeft.second + i].insert(k);
    }
  }
}

void searchOtherInversed(int y, int x, int k)
{
  dict.assign(26, 0);
  if (x - sizes[k] < 0)
    return;
  if (y + sizes[k] > l)
    return;

  FOR(i, 0, sizes[k])
  {
    dict[m[y + i][x - i]]++;
  }
  pii topRight = {y, x}, botLeft = {y + sizes[k], x - sizes[k]};
  while (botLeft.first < l && botLeft.second >= 0)
  {
    if (dict == words[k])
    {
      FOR(i, 0, sizes[k])
      {
        dp[topRight.first + i][topRight.second - i].insert(k);
      }
    }
    dict[m[topRight.first++][topRight.second--]]--;
    dict[m[botLeft.first++][botLeft.second--]]++;
  }
  if (dict == words[k])
  {
    FOR(i, 0, sizes[k])
    {
      dp[topRight.first + i][topRight.second - i].insert(k);
    }
  }
}

int main()
{
  IO;
  cin >> l >> c;
  string w;
  FOR(i, 0, l)
  {
    cin >> w;
    FOR(j, 0, c)
    {
      m[i][j] = w[j] - 'A';
    }
  }
  cin >> n;
  words.assign(n, vector<int>(26, 0));
  sizes.assign(n, 0);
  dp.assign(l, vector<set<int>>(c));
  FOR(i, 0, n)
  {
    FOR(j, 0, 26)
    words[i][j] = 0;
    cin >> w;
    sizes[i] = w.size();
    for (auto c : w)
    {
      words[i][c - 'A']++;
    }
  }
  FOR(i, 0, l)
  FOR(k, 0, n)
  searchHorizontal(i, k);

  FOR(i, 0, c)
  FOR(k, 0, n)
  searchVertical(i, k);

  FOR(i, 0, l)
  FOR(j, 0, c)
  FOR(k, 0, n)
  {
    searchOther(i, j, k);
    searchOtherInversed(i, j, k);
  }

  int ans = 0;
  FOR(i, 0, l)
  {
    FOR(j, 0, c)
    {
      cout << dp[i][j].size() << " ";
      if (dp[i][j].size() > 1)
        ans++;
    }
    cout << ENDL;
  }
  cout << ans << ENDL;

  return 0;
}