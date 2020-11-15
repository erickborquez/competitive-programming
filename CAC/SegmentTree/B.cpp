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
#define vi vector<int>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

const int MAXN = 2 * 1e5;
const int SIZE = 1e6 + 1;
const int INF = 1e9;

struct SegmentTree
{
    int tam;
    vector<int> mx, sum;

    void pull(int nodo)
    {
        mx[nodo] = max(mx[(nodo * 2) + 1], mx[(nodo * 2) + 2]);
        sum[nodo] = sum[(nodo * 2) + 1] + sum[(nodo * 2) + 2];
    }

    void build(vi &vec, lli nodo, lli l, lli r)
    {
        if (r - l == 1)
        {
            if (l < vec.size())
            {
                mx[nodo] = vec[l];
                if (vec[l] != 0)
                {
                    sum[nodo] = 1;
                }
            }
            return;
        }
        lli m = (l + r) / 2;
        build(vec, (nodo * 2) + 1, l, m);
        build(vec, (nodo * 2) + 2, m, r);
        pull(nodo);
    }

    void build(vi &vec)
    {
        build(vec, 0, 0, tam);
    }

    SegmentTree(int n, vi &vec)
    {
        tam = 1;
        while (tam < n)
            tam *= 2;
        mx.assign(2 * tam, 0);
        sum.assign(2 * tam, 0);
        build(vec);
    }

    /// Queries (l, r) l hasta r - 1 querie(0, 1);
    void update(int pos, lli val, lli nodo, lli l, lli r)
    {
        if (r - l == 1)
        {
            mx[nodo] = val;
            sum[nodo] = 0;
            return;
        }
        lli m = (l + r) / 2;
        if (pos < m)
            update(pos, val, (nodo * 2) + 1, l, m);
        else
            update(pos, val, (nodo * 2) + 2, m, r);
        pull(nodo);
        // mx[nodo] = max(mx[(nodo * 2) + 1], mx[(nodo * 2) + 2]);
        // sum[nodo] = sum[(nodo * 2) + 1] + sum[(nodo * 2) + 2];
    }

    void update(int pos, lli val)
    {
        update(pos, val, 0, 0, tam);
    }

    int queryMx(lli nodo, lli l, lli r, lli ll, lli rr)
    {
        if (rr <= l or ll >= r)
            return 0;

        if (l <= ll and rr <= r)
            return mx[nodo];

        lli m = (ll + rr) / 2;
        int left = queryMx((nodo * 2) + 1, l, r, ll, m);
        int right = queryMx((nodo * 2) + 2, l, r, m, rr);
        return max(left, right);
    }

    int queryMx(lli l, lli r)
    {
        return queryMx(0, l, r, 0, tam);
    }

    int querySum(lli nodo, lli l, lli r, lli ll, lli rr)
    {
        if (rr <= l or ll >= r)
            return 0;

        if (l <= ll and rr <= r)
            return sum[nodo];

        lli m = (ll + rr) / 2;
        int left = querySum((nodo * 2) + 1, l, r, ll, m);
        int right = querySum((nodo * 2) + 2, l, r, m, rr);
        return left + right;
    }

    int querySum(lli l, lli r)
    {
        return querySum(0, l, r, 0, tam);
    }
};

int main()
{
    IO;
    lli n, m, k, l, r;
    cin >> n >> m >> k;
    vi v(SIZE, 0);
    FOR(i, 0, n)
    {
        int pos;
        cin >> pos;
        v[pos] = pos;
    }
    SegmentTree segtree(SIZE, v);
    int ans = 0;
    FOR(i, 0, SIZE - m)
    {
        if (v[i] != 0)
        {
            while (v[i] != 0 && segtree.querySum(i, i + m) >= k)
            {
                int ptr = 1;
                // cout << sum << ENDL;
                for (int j = m; j > 0; j /= 2)
                {
                    while (segtree.querySum(i, i + ptr + j) <= k)
                    {
                        ptr += j;
                    }
                }
                auto last = segtree.queryMx(i, i + ptr);
                debp(i, last);
                ans++;
                deb(segtree.querySum(i, i + m));
                deb(segtree.queryMx(i, i + ptr));

                segtree.update(last, 0);
                v[last] = 0;
                deb(segtree.querySum(i, i + m));
                deb(segtree.queryMx(i, i + ptr));

                // break;
            }
        }
    }
    cout << ans << ENDL;
    return 0;
}
/// 1 2 3 4 6 5 7
