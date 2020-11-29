#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

vector<string> shiftNames(vector<string> &s, int n)
{
    vector<string> ans;
    FOR(i, n, s.size())
    {
        ans.pb(s[i]);
    }
    FOR(i, 0, n)
    {
        ans.pb(s[i]);
    }
    return ans;
}

int main()
{
    IO;
    int n;
    cin >> n;
    string s;
    vector<string> st;
    int sz = 0;
    FOR(i, 0, n)
    {
        cin >> s;
        sz += s.size();
        st.pb(s);
    }
    int k;
    cin >> k;
    k--;
    int shifts = (k / sz) % n;
    vector<string> shifted = shiftNames(st, shifts);

    // debp(sz, shifts);
    string conc = "";
    for (auto e : shifted)
        conc += e;
    // cout << conc << ENDL;
    int ptr = k % sz;

    cout << conc[ptr] << ENDL;
    return 0;
}