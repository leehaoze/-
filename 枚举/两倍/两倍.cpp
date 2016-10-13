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
    int data[16];
    int num = 0;
    //读入数据
    while(scanf("%d",&data[num]) && data[num] != 0){
        ++num;
    }
    sort(data,data + num);
    int count = 0;
    for (int i = 0; i < num; ++i) {
        int Want_Num = data[i] * 2;
        for (int j = i; j < num; ++j) {
            if(data[j] == Want_Num) {
                count++;
                break;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}