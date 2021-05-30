#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;
#define lli long long
using namespace std;
#define SIZE 27

struct TrieNode
{
  TrieNode *children[SIZE];
  bool isEnd;

  TrieNode()
  {
    isEnd = false;
    for (int i(0); i < SIZE; i++)
    {
      children[i] = nullptr;
    }
  }
};

struct Trie
{
  TrieNode *root = new TrieNode;
  bool insert(string s)
  {

    bool sharesPrefix = false;
    TrieNode *node = root;
    for (int i(0); i < s.size(); i++)
    {
      int key = s[i] - 'a';
      if (node->children[key] == nullptr)
      {
        node->children[key] = new TrieNode;
      }
      else
      {
        if (node->children[key]->isEnd)
          sharesPrefix = true;
      }
      node = node->children[key];
    }
    node->isEnd = true;
    for (int i(0); i < SIZE; i++)
    {
      if (node->children[i] != nullptr)
        sharesPrefix = true;
    }
    return sharesPrefix;
  }
};

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  string s;
  Trie t;
  cin >> n;
  while (n--)
  {
    cin >> s;
    if (t.insert(s))
    {
      cout << "vulnerable" << ENDL;
      return 0;
    }
  }
  cout << "non vulnerable" << ENDL;
  return 0;
}