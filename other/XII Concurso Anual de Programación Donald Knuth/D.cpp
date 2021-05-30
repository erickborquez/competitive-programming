#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u << " : " << u << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ull unsigned long long
#define pii pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)

using namespace std;

#define MOD 1000000007ULL
#define INF 1000000000ULL
ull n;

ull sum(ull u)
{
  ull ans;
  if (u % 2 == 0)
  {
    ans = u / 2LL;
    ans = (ans * (u + 1LL));
  }
  else
  {
    ans = ((u + 1LL)) / 2LL;
    ans = (ans * u);
  }
  return ans;
}

ull sqrSum(ull u)
{
  ull ans;
  // u = u % MOD;
  ull a = u % MOD;
  ull b = (u + 1LL) % MOD;
  ull c = ((u * 2LL) % MOD + 1LL) % MOD;

  if (a % 2LL == 0)
    a /= 2LL;
  else
    b /= 2LL;

  if (a % 3LL == 0)
    a /= 3LL;
  else if (b % 3LL == 0)
    b /= 3LL;
  else
    c /= 3LL;

  ans = (a * b) % MOD;
  ans = (ans * c) % MOD;
  return ans;
}

bool ok(ull u)
{
  ull ans = 2ULL * sum(u);
  return ans <= n;
}

int main()
{
  IO;
  cin >> n;
  ull ptr = 0LL;
  for (ull i = INF; i > 0LL; i /= 2LL)
    while (ok(ptr + i))
      ptr += i;

  ull ans = ((sqrSum(ptr) % MOD) * 2LL) % MOD;
  ull res = n - 2LL * sum(ptr);
  ans = (ans + (((ptr + 1LL) * res) % MOD)) % MOD;

  cout << ans << ENDL;
  return 0;
}