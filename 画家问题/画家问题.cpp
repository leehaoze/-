#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

#define input(a) scanf("%d",&a);
#define print_one_blank printf(" ");

int wall[16][17], pait[16][17];
int n;

bool guess() {
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pait[i + 1][j] = (wall[i][j] + pait[i - 1][j] + pait[i][j - 1] + pait[i][j + 1] + 1 + pait[i][j]) % 2;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if ((pait[n][i] + pait[n][i - 1] + pait[n][i + 1] + pait[n - 1][i]) % 2 == wall[n][i])
            return false;
    }
    return true;
}

int cac_num() {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (pait[i][j] == 1)count++;
        }
    }
    return count;
}

int solve() {//枚举第一行的状态
    memset(pait, 0, sizeof pait);
    int ans = n * n + 1;
    while (1) {
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                pait[i][j] = 0;
            }
        }
        if (guess()) {
            ans = min(ans, cac_num());
        }
        bool is_quit = true;
        for (int k = 1; k <= n; ++k) {
            if (pait[1][k] != 1) {
                is_quit = false;
                break;
            }
        }
        if (is_quit)break;
        pait[1][1]++;
        int pos = 1;
        while (pait[1][pos] > 1 && pos <= n) {
            pait[1][pos] = 0;
            pos++;
            pait[1][pos]++;
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    //输入
    int T = 1;
    //input(T);
    while(T--) {
        input(n);
        memset(wall, 0, sizeof wall);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                char c;
                cin >> c;
                if (c == 'w') wall[i][j] = 0;
                else if (c == 'y') wall[i][j] = 1;
            }
        }
        int ans = solve();
        if (ans == n * n + 1)
            printf("inf\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}