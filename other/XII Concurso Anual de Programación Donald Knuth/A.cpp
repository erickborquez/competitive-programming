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

int main()
{
  IO;
  string s;
  cin >> s;
  FOR(i, 0, s.size())
  {
    if (s[i] == 'O' || s[i] == 'o')
      s[i] = '0';
    if (s[i] == 'I' || s[i] == 'i')
      s[i] = '1';
    if (s[i] == 'Z' || s[i] == 'z')
      s[i] = '2';
    if (s[i] == 'E' || s[i] == 'e')
      s[i] = '3';
    if (s[i] == 'A' || s[i] == 'a')
      s[i] = '4';
    if (s[i] == 'S' || s[i] == 's')
      s[i] = '5';
    if (s[i] == 'G' || s[i] == 'g')
      s[i] = '6';
    if (s[i] == 'T' || s[i] == 't')
      s[i] = '7';
    if (s[i] == 'B' || s[i] == 'b')
      s[i] = '8';
  }
  cout << s << ENDL;
  return 0;
}