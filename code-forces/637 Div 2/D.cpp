#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
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

string sq[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int v[2001], dg[10];

int getChanges(int a, int b)
{
  // debp(a, b);
  int val = (a | b) ^ b;
  if (val)
    return -1;
  return __builtin_popcount((a | b) ^ a);
}

int convert(string s)
{
  return stoi(s, nullptr, 2);
}

int dp[2001][2001];
bool cal[2001][2001];
int n, k;

int solve(int u, int k)
{
  if (u >= n)
  {
    if (k == 0)
      return 1;
    else
      return -1;
  }

  if (cal[u][k])
    return dp[u][k];
  int ans = -1;
  FORN(i, 10, 0)
  {
    int changes = getChanges(v[u], dg[i]);
    if (changes != -1 && changes <= k && solve(u + 1, k - changes) != -1)
    {
      // deb(u);
      // debp(i, changes);
      // deb(solve(u + 1, k - changes));
      ans = i;
      break;
    }
  }
  cal[u][k] = true;
  dp[u][k] = ans;

  return ans;
}

int main()
{
  IO;
  cin >> n >> k;
  FOR(i, 0, 10)
  dg[i] = convert(sq[i]);
  FOR(i, 0, n)
  {
    string val;
    cin >> val;
    v[i] = convert(val);
  }
  FOR(i, 0, n)
  FOR(j, 0, k)
  {
    cal[i][j] = false;
    dp[i][j] = -1;
  }
  // FOR(i, 0, 10)
  // {
  //   int val = getChanges(dg[1], dg[i]);
  //   debp(i, val);
  // }
  int ptr = solve(0, k);
  // deb(ptr);
  if (ptr == -1)
    cout << -1 << ENDL;
  else
  {

    FOR(i, 0, n)
    {
      ptr = solve(i, k);
      k -= getChanges(v[i], dg[ptr]);
      cout << ptr;
    }
    cout << ENDL;
  }

  return 0;
}