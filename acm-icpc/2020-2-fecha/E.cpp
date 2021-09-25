#include <bits/stdc++.h>

using namespace std;

// IO
#define fastio                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
    }
#define endl '\n'
#define fix(prec)                            \
    {                                        \
        cout << setprecision(prec) << fixed; \
    }

// Pairs
#define mp make_pair
#define f first
#define s second

// Vectors
#define sz(x) int((x).size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define pf push_front
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define getunique(v)                      \
    {                                     \
        sort(all(v));                     \
        v.erase(unique(all(v)), v.end()); \
    }

// Types
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

// Debug
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p)
{
    return cout << "(" << p.f << ", " << p.s << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ", ";
        cout << v[i];
    }
    return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p)
{
    cin >> p.first;
    return cin >> p.second;
}

// RNG
// mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// Constants
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;

ll getCapacity(string s)
{

    ll size = s.size();
    ll capacity = stoll(s.substr(0, size - 1));
    ll mult = s[size - 1] == 'M' ? 1 : s[size - 1] == 'G' ? 1024
                                                          : 1048576;
    return capacity *= mult;
}

void solve(int tc)
{
    int n;
    string s;
    cin >> n >> s;
    ll capacity = getCapacity(s);

    vl videoSizes(n);
    vl prefixSum(n);

    for (ll i = 0; i < n; i++)
        cin >> videoSizes[i];

    ll currentSum = 0;
    ll minVideosToExceed = n;
    ll firstVideoToExceed = -1;

    for (ll left = 0, right = 0; right < n; right++)
    {
        if (right == 0)
            prefixSum[0] = videoSizes[0];
        else
            prefixSum[right] = prefixSum[right - 1] + videoSizes[right];

        currentSum += videoSizes[right];

        bool shouldUpdate = false;
        while (currentSum > capacity)
        {
            shouldUpdate = true;
            currentSum -= videoSizes[left];
            left++;
        }

        ll videos = right - left + 1LL;
        if (shouldUpdate && videos < minVideosToExceed)
        {
            minVideosToExceed = videos;
            firstVideoToExceed = left;
        }
    }

    cout << minVideosToExceed << " " << firstVideoToExceed << endl;
}

int main()
{
    fastio int T = 1;
    //cin >> T;
    for (int i = 0; i < T; i++)
        solve(i);
}