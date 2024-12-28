#include <bits/stdc++.h>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

const int N = 2005;
int t, n, a[N], cnt;
char c;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

char ask(int x) {
    cout << "? " << x << endl;
    cout.flush();
    cin >> c;
    return c;
}

void sol(vector<int>& q) {
    if (q.empty()) return;
    int x = rng() % q.size();
    vector<int> c1, c2;
    while (ask(q[x]) != '=');
    for (int i = 0; i < q.size(); ++i) {
        if (i != x) {
            if (ask(q[i]) == '<') c1.push_back(q[i]);
            else c2.push_back(q[i]);
            ask(q[x]);
        }
    }
    sol(c1);
    a[q[x]] = ++cnt;
    sol(c2);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> qwq;
        for (int i = 1; i <= n; ++i) qwq.push_back(i);
        cnt = 0;
        sol(qwq);
        cout << "! ";
        for (int i = 1; i <= n; ++i) cout << a[i] << " ";
        cout << endl;
        cout.flush();
    }
    return 0;
}