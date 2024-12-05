#include <bits/stdc++.h>
using namespace std;

#define pair pair<int, int>
#define x first
#define y second
const int MAX = 1e2 + 10;
map<string, pair> mp; // 记录位置
string a[MAX][MAX];
int rs = 0, bs = 0; // 记录两队分数

bool check(string id) {
    if (a[mp[id].x][mp[id].y][1] != 'G' && mp[id] == mp[".B"]) {
        mp.erase(id);
        return true;
    }
    return false;
}

int main() {
    int n, m, t;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] != "..") mp[a[i][j]] = { i, j };
        }
    }
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string id;
        char op;
        cin >> id >> op;
        if (op == 'U')
            --mp[id].x;
        else if (op == 'D')
            ++mp[id].x;
        else if (op == 'L')
            --mp[id].y;
        else if (op == 'R')
            ++mp[id].y;
        else if (op == 'C') {
            string s;
            cin >> s;
            if (s == ".S") {
                if (id[0] == 'B') {
                    bs += 10;
                    cout << i << " "
                         << "BLUE "
                         << "CATCH GOLDEN SNITCH\n";
                } else {
                    rs += 10;
                    cout << i << " "
                         << "RED "
                         << "CATCH GOLDEN SNITCH\n";
                }
                break;
            }
            // 判断一下抓的是不是金色飞贼，如果是就加10分，结束比赛
        } else if (op == 'T') {
            // 进球加分
            if (a[mp[id].x][mp[id].y] == "BG") {
                ++rs;
                cout << i << " RED GOAL\n";
            } else if (a[mp[id].x][mp[id].y] == "RG") {
                ++bs;
                cout << i << " BLUE GOAL\n";
            }
        }
        // 检测淘汰
        for (int j = 0; j < 10; ++j) {
            string str = "B";
            str += ('0' + j);
            if (mp.find(str) != mp.end())
                if (check(str)) cout << i << " " << str << " ELIMINATED\n";
        }
        for (int j = 0; j < 10; ++j) {
            string str = "R";
            str += ('0' + j);
            if (mp.find(str) != mp.end())
                if (check(str)) cout << i << " " << str << " ELIMINATED\n";
        }
    }
    printf("FINAL SCORE: %d %d", rs, bs);
    return 0;
}