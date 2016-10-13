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
    int a;
    input(a);
    int MAX = -1, MIN = 40000;
    bool Find_Ans = false;
    for (int i = 0; i <= a / 2; ++i) {
        for (int j = 0; j <= a / 4; ++j) {
            if (i * 2 + j * 4 == a) {
                Find_Ans = true;
                MAX = max(MAX, i + j);
                MIN = min(MIN, i + j);
            }
        }
    }
    if(Find_Ans)
        printf("%d %d\n",MIN,MAX);
    else
        printf("0 0\n");

    return 0;
}