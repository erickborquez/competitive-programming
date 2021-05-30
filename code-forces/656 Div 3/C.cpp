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

vector<int> v;
int n;

bool ok(int ptr)
{
  // deb(ptr);
  int left = ptr, right = n - 1;
  int val = -1;
  while (left <= right)
  {
    if (v[left] < val || v[right] < val)
      return false;
    // debp(v[left], v[right]);
    // deb(val);
    if (v[left] < v[right])
    {
      val = v[left];
      // cout << "left" << ENDL;
      left++;
    }
    else
    {
      // cout << "right" << ENDL;
      val = v[right];
      right--;
    }
  }
  // debp(left, right);
  return true;
}

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    v = vector<int>(n);
    FOR(i, 0, n)
    cin >> v[i];
    int ptr = n;
    for (int i = n; i > 0; i /= 2)
    {
      while (ptr - i >= 0 && ok(ptr - i))
      {
        ptr -= i;
      }
    }
    cout << ptr << ENDL;
  }
  return 0;
}