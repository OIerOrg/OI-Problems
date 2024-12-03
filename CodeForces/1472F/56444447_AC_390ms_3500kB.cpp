#include <iostream>
#include <map>
using namespace std;

const int SPECIAL_CONDITION = 3;

bool isValid(const map<int, int>& changes) {
    int previousSum = -1;
    for (const auto& entry : changes) {
        int position = entry.first;
        int value = entry.second;

        if (previousSum == -1) {
            if (value != SPECIAL_CONDITION)
                previousSum = position + value;
        } else {
            if (value == SPECIAL_CONDITION || (previousSum + position + value) % 2 == 0)
                return false;
            previousSum = -1;
        }
    }
    return previousSum == -1;
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n, m;
        cin >> n >> m;

        map<int, int> positionChanges;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            positionChanges[y] += x;
        }

        cout << (isValid(positionChanges) ? "YES" : "NO") << endl;
    }

    return 0;
}