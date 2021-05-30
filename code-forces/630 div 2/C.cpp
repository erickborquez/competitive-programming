#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;
#define lli long long
#define pii pair<int, int>
#define INF -1000000
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    int subStrings = n / k;
    vector<vector<int>> word(k, vector<int>(28, 0));
    for (int i(0); i < n; i++)
    {
      int pos = i % k;
      word[pos][s[i] - 'a']++;
    }
    int total = 0;
    // int c = 0;
    // for (auto v : word)
    // {
    //   cout << c++ << ENDL;
    //   for (int i(0); i < 26; i++)
    //   {
    //     cout << i << ":" << v[i] << ENDL;
    //   }
    //   cout << ENDL << ENDL;
    // }
    for (int i(0); i < k / 2; i++)
    {
      int first = i;
      int last = k - i - 1;
      int mx = INF;
      int best = 0;

      for (int j(0); j < 26; j++)
      {

        int sum = word[first][j] + word[last][j];
        if (sum > mx)
          best = i;
        mx = max(mx, sum);
      }
      total += mx;
    }
    if (k % 2 == 1)
    {
      int mid = k / 2;
      int mx = INF;
      for (int i(0); i < 26; i++)
      {
        mx = max(mx, word[mid][i]);
      }
      total += mx;
    }
    cout << n - total << ENDL;
  }

  return 0;
}