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

int puzzle[6][8],press[6][8];

bool guess(){
    for (int i = 1; i < 5; ++i) {//光想着第一行的状态是枚举的时候确定好的，其实是通过第一行来算第二行的啦～所以不用循环到5的呀
        for (int j = 1; j < 7; ++j) {
            press[i + 1][j] = (puzzle[i][j] + press[i][j] + press[i-1][j] + press[i][j-1] + press[i][j+1]) % 2;//这边漏掉了press[i][j]，按下自己的状态
        }
    }
    for (int i = 1; i < 7; ++i) {
        if((press[5][i] + press[5][i-1] + press[5][i+1] + press[4][i]) % 2 != puzzle[5][i])//这边之前也漏掉了press[5][i]这个
            return false;
    }
    return true;
}

void solve(){
    memset(press,0,sizeof(press));

    while(guess() != true){//自己在这里没分清楚，应该枚举的是如何按下开关，而不是灯的状态怎样，所以第一次写的时候直接写成了枚举puzzle数组，然后错的啊。。
        press[1][1]++;
        int pos = 1;
        while(press[1][pos] > 1){//这个模拟二进制的遍历真的是十分的巧妙啊
            press[1][pos] = 0;
            press[1][pos+1]++;
            pos++;
        }
    }
    return ;
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int n;
    input(n);
    for (int cases = 1; cases <= n; ++cases) {
        memset(puzzle,0,sizeof puzzle);
        for (int i = 1; i < 6; ++i) {
            for (int j = 1; j < 7; ++j) {
                input(puzzle[i][j]);
            }
        }

        solve();
        printf("PUZZLE#%d\n",cases);
        for (int i = 1; i < 6; ++i) {
            for (int j = 1; j < 7; ++j) {
                printf("%d ",press[i][j]);
            }
            printf("\n");
        }
    }
}