#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

const static ll INF = 1e9;

using namespace std;

struct WaveletTree
{
    int low, high;
    WaveletTree *left, *right;
    vector<int> freq;

    WaveletTree(int *from, int *to, int x, int y)
    {
        low = x, high = y;
        if (low == high or from >= to)
            return;
        int mid = low + ((high - low) / 2);
        auto f = [mid](int x)
        {
            return x <= mid;
        };
        freq.reserve(to - from + 1);
        freq.push_back(0);
        for (auto it = from; it != to; it++)
            freq.push_back(freq.back() + f(*it));
        auto pivot = stable_partition(from, to, f);
        left = new WaveletTree(from, pivot, low, mid);
        right = new WaveletTree(pivot, to, mid + 1, high);
    }

    int GTE(int l, int r, int k)
    {
        if (l > r or k > high)
            return 0;
        if (low >= k)
            return r - l + 1;
        int lb = freq[l - 1], rb = freq[r];
        return this->left->GTE(lb + 1, rb, k) + this->right->GTE(l - lb, r - rb, k);
    }
};

const static int N = 300005;
const static int MAX_VALUE = 1e5;
int a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int Y, N;
    cin >> Y >> N;
    vector<int> icpcSlots(Y);
    for (int i = 0; i < Y; i++)
        cin >> a[i + 1];
    WaveletTree tree(a + 1, a + Y + 1, 0, MAX_VALUE);
    for (int i = 0; i < N; i++)
    {
        int retirement, lastRank, years;
        cin >> retirement >> lastRank >> years;
        if (a[retirement] >= lastRank)
            cout << "0" << endl;
        else
            cout << tree.GTE(retirement, retirement + years, lastRank) << endl;
    }
    return 0;
}