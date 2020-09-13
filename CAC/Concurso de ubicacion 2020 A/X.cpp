#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

#define lli long long

using namespace std;

void makePalindrome(string s)
{
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  map<char, int> m;
  for (auto c : s)
  {
    m[c]++;
  }

  int impar = 0;
  for (auto e : m)
    if (e.S % 2)
    {
      impar++;
    }

  impar /= 2;
  bool flag = s.size() & 1;
  if (impar > 0)
  {
    for (auto e : m)
    {
      if (e.S & 1)
      {
        if (impar > 0)
        {
          m[e.F]++;
          impar--;
        }
        else
        {
          if (flag)
          {
            flag = false;
          }
          else
          {
            m[e.F]--;
          }
        }
      }
    }
  }
  char saved;
  string palindrome;
  string left = "", right = "";
  for (auto e : m)
  {
    if (e.S & 1)
    {
      saved = e.F;
      m[e.F]--;
    }
    for (int i(0); i < e.S / 2; i++)
    {
      left += e.F;
    }
  }
  palindrome = left;
  if (s.size() & 1)
    palindrome += saved;

  for (int i(left.size() - 1); i >= 0; i--)
  {
    palindrome += left[i];
  }
  cout << palindrome << ENDL;
  return 0;
}