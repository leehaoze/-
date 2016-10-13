//NCC_31060 Majestic
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

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int n;
    input(n);
    int ans = -1;
    for (int i = n; i >= 0; --i) {
        for (int j = n; j >= 0; --j) {
            if((i + j) % 2 != 0) continue;//提前判断，如果已经枚举到的前两个数不满足条件就跳过第三层循环
            for (int k = n; k >= 0; --k) {
                if((j + k) % 3 == 0 && (i + j + k) % 5 == 0)
                    ans = max(ans,i + j+ k);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}