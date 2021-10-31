#include <bits/stdc++.h>

#define optimize                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define S second
#define F first
#define ENDL '\n'
#define fori(i, n) for (int i = 0; i < n; ++i)
#define foreach(n) for (int i = 0; i < n; ++i)
#define read_v(v)                      \
    for (int i = 0; i < v.size(); ++i) \
    cin >> v[i]
#define all(v) v.begin(), v.end()
#define asc_sort(v) sort(v.begin(), v.end())
#define desc_sort(v) sort(v.rbegin(), v.rend())
#define print_all(v)                        \
    for (int i = 0; i < (int)v.size(); ++i) \
    cout << v[i] << (i < (int)v.size() - 1 ? ' ' : '\n')
#define pb push_back
#define sz(v) v.size()
#define ceil_div(a, b) (a + b - 1) / b
#define tcs(foo)     \
    {                \
        int tc;      \
        cin >> tc;   \
        while (tc--) \
            foo();   \
    }

using namespace std;

typedef string str;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vbool;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<string> vstr;
typedef vector<pair<int, int> > vpii;
typedef set<int> s_int;
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > min_heap;
typedef priority_queue<int> max_heap;

string to_string(string s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
            res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

/********************
    END TEMPLATE
*********************/
const int N = 2 * 1e5;

vector<vi> tree(N);
vi pos(N, 0), inverse(N, -1);
vbool isAlive(N, false);
int king;

void search(int x)
{
    if (x != king)
        return;

    int next, parent = x;
    while (inverse[parent] != -1 || pos[parent] < sz(tree[parent]))
    {
        while (pos[parent] < sz(tree[parent]))
        {
            next = tree[parent][pos[parent]];
            debug(parent, next);
            if (isAlive[next])
            {
                king = next;
                return;
            }
            parent = next;
        }

        parent = inverse[parent];
        ++pos[parent];
        debug(parent, pos[parent]);
    }
}

void solve()
{
    int q, cur = 1;
    cin >> q;
    isAlive[1] = true;
    pos[1] = 0;
    king = 1;

    while (q--)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1)
        {
            tree[x].pb(++cur);
            pos[x] = 0;
            isAlive[cur] = true;
            inverse[cur] = x;
        }
        else
        {
            isAlive[x] = false;
            search(x);
            cout << king << ENDL;
        }
    }
}

int main()
{
    solve();
    return 0;
}
