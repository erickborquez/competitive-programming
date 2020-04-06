#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;
#define lli long long
using namespace std;
#define SIZE 27

map<string, int> amount;
vector<string> a;

struct TrieNode
{
  TrieNode *children[SIZE];
  bool isEnd;
  bool uniquePrefix;
  pair<int, string> biggest;

  TrieNode()
  {
    biggest = {0, ""};
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

  Trie()
  {
  }

  void insert(string s, int n)
  {
    TrieNode *node = root;
    for (int i(0); i < s.size(); i++)
    {
      int key = s[i] - 'a';
      if (node->children[key] == nullptr)
      {
        node->children[key] = new TrieNode;
      }

      node = node->children[key];
      if (node->biggest.F < n)
        node->biggest = {n, s};
    }
    node->isEnd = true;
  }

  // void dfs(TrieNode *node, string w, vector<string> &ls)
  // {
  //   if (node->isEnd)
  //   {
  //     ls.pb(w);
  //   }
  //   for (int i(0); i < SIZE; i++)
  //   {
  //     if (node->children[i] != nullptr)
  //     {
  //       dfs(node->children[i], w + (char)('a' + i), ls);
  //     }
  //   }
  // }

  // void search(string w, vector<string> &ls)
  // {
  //   TrieNode *node = root;
  //   for (int i(0); i < w.size(); i++)
  //   {
  //     node = node->children[w[i] - 'a'];
  //     if (node == nullptr)
  //       return;
  //   }
  //   dfs(node, w, ls);
  // }

  TrieNode *get(string w)
  {
    TrieNode *node = root;
    for (int i(0); i < w.size(); i++)
    {
      node = node->children[w[i] - 'a'];
      if (node == nullptr)
        return nullptr;
    }
    return node;
  }
};

struct SegmentTree
{
  vector<string> MAX;
  SegmentTree(int n)
  {
    MAX.resize(n * 4);
    build(1, 1, n);
  }

  void build(int u, int l, int r)
  {
    if (l == r)
    {
      MAX[u] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build(2 * u, l, m);
    build(2 * u + 1, m + 1, r);
    pull(u);
  }

  void pull(int u)
  {
    string left = MAX[2 * u];
    string right = MAX[2 * u + 1];
    if (amount[right] > amount[left])
    {
      MAX[u] = right;
    }
    else
      MAX[u] = left;
  }

  string query(int u, int l, int r, int ll, int rr)
  {
    if (rr < l || r < ll || r < l)
    {
      return "";
    }
    if (ll <= l && r <= rr)
    {
      return MAX[u];
    }
    int m = (l + r) / 2;
    string left = query(u * 2, l, m, ll, rr);
    string right = query(u * 2 + 1, m + 1, r, ll, rr);

    if (left == "")
      return right;
    if (right == "")
      return left;
    if (amount[left] < amount[right])
    {
      return right;
    }
    else
      return left;
  }
};

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  Trie t;
  string s;

  cin >> n;
  for (int i(0); i < n; i++)
  {
    cin >> s;
    amount[s]++;
  }

  for (auto p : amount)
  {
    t.insert(p.F, p.S);
  }
  cin >> q;

  // SegmentTree st(a.size() - 1);
  // int start, end;
  // string wrd;
  while (q--)
  {

    cin >> s;
    TrieNode *node = t.get(s);
    if (node == nullptr)
    {
      cout << -1 << ENDL;
    }
    else
    {
      cout << node->biggest.S << " " << node->biggest.F << ENDL;
    }
    // vector<string> v;
    // cin >> s;
    // t.search(s, v);
    // if (v.size() == 0)
    // {
    //   cout << -1 << ENDL;
    //   continue;
    // }

    // start = lower_bound(a.begin(), a.end(), v[0]) - a.begin();
    // end = lower_bound(a.begin(), a.end(), v[v.size() - 1]) - a.begin();
    // if (start != end)
    // {
    //   wrd = st.query(1, 1, a.size(), start, end);
    // }
    // else
    // {
    //   wrd = a[start];
    // }
    // cout << wrd << " " << amount[wrd] << ENDL;
  }

  return 0;
}