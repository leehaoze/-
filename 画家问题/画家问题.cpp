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
            //根据第一行计算出最后一行的状态，这里是＋1再对2求余，和之前的不一样
        }
    }
    for (int i = 1; i <= n; ++i) {
        if ((pait[n][i] + pait[n][i - 1] + pait[n][i + 1] + pait[n - 1][i]) % 2 == wall[n][i])
            //如果最后一行的操作的结果等于wall[n][i]自身，比如wall[n][i]本来就是0，计算的结果也是0，那么他还是0，不符合条件嘛～ 返回false
        return false;
    }
    return true;
}

int cac_num() {//计算涂了几个砖块
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
    while (1) {//因为要枚举所有的情况找出最小值，所以先写了一个死循环
        for (int i = 2; i <= n; ++i) {//每次循环都清空一下第二行以后的pait数组，保证不会影响后续计算
            for (int j = 1; j <= n; ++j) {
                pait[i][j] = 0;
            }
        }
        if (guess()) {
            ans = min(ans, cac_num());
        }
        //判断是否要退出循环（全都为1，并且已经guess完了）
        bool is_quit = true;
        for (int k = 1; k <= n; ++k) {
            if (pait[1][k] != 1) {
                is_quit = false;
                break;
            }
        }
        if (is_quit)break;
        //模拟二进制运算枚举
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