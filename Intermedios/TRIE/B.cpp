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
  bool uniquePrefix;

  TrieNode()
  {
    isEnd = false;
    uniquePrefix = true;
    for (int i(0); i < SIZE; i++)
    {
      children[i] = nullptr;
    }
  }
};

struct Trie
{
  TrieNode *root = new TrieNode;

  Trie()
  {
    root->uniquePrefix = false;
  }

  void insert(string s)
  {
    bool uniquePrefix = false;
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
        node->children[key]->uniquePrefix = false;
      }
      node = node->children[key];
    }
  }

  int getAllChars()
  {
    return search(root, 0);
  }

  int search(TrieNode *r, int sz)
  {
    if (r->uniquePrefix)
    {
      return sz;
    }
    int c = 0;
    for (int i(0); i < SIZE; i++)
    {
      if (r->children[i] != nullptr)
      {
        c += search(r->children[i], sz + 1);
      }
    }
    return c;
  }
};

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, c;
  string s;
  cin >> c;
  while (c--)
  {
    Trie t;
    cin >> n;
    while (n--)
    {
      cin >> s;
      t.insert(s);
    }
    cout << t.getAllChars() << ENDL;
  }
  return 0;
}