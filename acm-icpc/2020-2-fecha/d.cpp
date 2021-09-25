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
#define ceil_div(a, b) (a + b - 1LL) / b
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
ll c, r, s;

ll getBestCase()
{
    int pasasRestantes = r % s;
    int cerealRestante = c % s;
    int bestCase = c / s;

    if (cerealRestante > 0 && pasasRestantes == 0 || cerealRestante + pasasRestantes > s)
        bestCase++;
    return bestCase;
}

ll getWorstCase()
{

    ll cerealConPasas = (s - 1) * r;
    ll cerealRestante = max(0LL, c - cerealConPasas);
    return ceil_div(cerealRestante, s);
}

void solve()
{
    cin >> c >> r >> s;
    cout << getBestCase() << " " << getWorstCase() << ENDL;
}

int main()
{
    tcs(solve) return 0;
}

/*
Probe con estos casos
4
20 10 5 -> 4 0
20 11 5 -> 4 0
6 2 3 -> 2 1
4 1 4 -> 1 1
10 10 3 -> 3 0
0 0 (x>=1) -> 0 0 
*/