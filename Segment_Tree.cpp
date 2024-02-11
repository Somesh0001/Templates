//This is the segment tree template code 
//It finds the minimum in a given range  
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vl vector<ll>
#define vpl vector<pair<ll, ll>>
#define vpi vector<pair<int, int>>
#define sort(A) sort(A.begin(), A.end())
#define rep(i, k, n) for (ll i = k; i < n; i++)
ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }

class SGTree
{
private:
    vector<ll> seg;

public:
    SGTree(ll n) : seg(4 * n) {}
    void build(vector<ll> &v, ll l, ll r, ll ind)
    {
        if (l == r)
        {
            seg[ind] = v[l];
            return;
        }
        ll mid = (l + r) / 2;
        ll left = (2 * ind) + 1;
        ll right = (2 * ind) + 2;
        build(v, l, mid, left);
        build(v, mid + 1, r, right);
        seg[ind] = min(seg[left], seg[right]);
    }
    ll query(ll l, ll r, ll ql, ll qr, ll ind, vector<ll> &v)
    {
        // case 1: no overlap  :
        if (r < ql || l > qr)
        {
            return LONG_MAX;
        }
        // complete overlap
        if (l >= ql && r <= qr)
        {
            return seg[ind];
        }
        int mid = l + (r - l) / 2;
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        ll ansl = query(l, mid, ql, qr, left, v);
        ll ansr = query(mid + 1, r, ql, qr, right, v);
        return min(ansl, ansr);
    }
    void update(ll l, ll r, ll i, ll val, ll ind)
    {
        if (l == r)
        {
            seg[ind] = val;
            return;
        }
        ll mid = l + (r - l) / 2;
        ll left = 2 * ind + 1;
        ll right = 2 * ind + 2;
        if (i <= mid)
        {
            update(l, mid, i, val, left);
        }
        else
        {
            update(mid + 1, r, i, val, right);
        }
    }
};

void solve()
{
    ll n;
    cin >> n;
    vl v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    SGTree st1(n);
    SGTree st2(n);
    st1.build(v, 0, n - 1, 0);
    ll q;
    cin >> q;
    while (q--)
    {
        ll type, a, b;
        cin >> type >> a >> b;
        a--;
        b--;
        if (type == 1)
        {
            cout << st1.query(0, n - 1, a, b, 0, v) << " ";
        }
        else
        {
            // here a is the index and b is the value to be updated
            st1.update(0, n - 1, a, b + 1, 0);
            v[a] = b;
        }
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}