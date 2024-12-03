#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll xor_n(ll n)
{
    ll t = n & 3;
    if (t & 1)
        return t / 2 ^ 1;
    return t / 2 ^ n;
}
ll query(ll l, ll r)
{
    cout << "xor " << l << ' ' << r << '\n';
    ll x;
    cin >> x;
    return x;
}
void solve()
{
    ll n;
    cin >> n;
    ll axbxc = query(1, n);
    if (axbxc == 0)
    {
        for (int i = 60; i >= 0; i--)
        {
            if ((1LL << i) - 1 > n)
                continue;
            ll t = query(1, (1LL << i) - 1);
            if (t)
            {
                ll a = t;
                ll L = a + 1, R = n;
                ll c = 1;
                while (L <= R)
                {
                    ll mid = L + R >> 1;
                    if (query(mid, n))
                        L = (c = mid) + 1;
                    else
                        R = mid - 1;
                }
                cout << "ans " << a << ' ' << (axbxc ^ a ^ c) << ' ' << c << endl;
                return;
            }
        }
    }
    else
    {
        ll L = 1, R = n, a = n;
        while (L <= R)
        {
            ll mid = L + R >> 1;
            if (query(1, mid))
                R = (a = mid) - 1;
            else
                L = mid + 1;
        }
        L = 1, R = n;
        ll c = 1;
        while (L <= R)
        {
            ll mid = L + R >> 1;
            if (query(mid, n))
                L = (c = mid) + 1;
            else
                R = mid - 1;
        }
        cout << "ans " << a << ' ' << (axbxc ^ a ^ c) << ' ' << c << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}