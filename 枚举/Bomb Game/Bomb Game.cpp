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

int map[101][101];
int A, B, K;

void Throw_Bomb(int x, int y, int power, int ko) {
    int start_x, start_y, end_x, end_y;
    start_x = x - (power - 1) / 2;
    start_y = y - (power - 1) / 2;
    if(start_x < 1)start_x = 1;
    if(start_y < 1)start_y = 1;
    end_x = x + (power - 1) / 2;
    end_y = y + (power - 1) / 2;
    if(end_x > A)end_x = A;
    if(end_y > B)end_y = B;

    if(ko == 1) {
        for (int i = start_x; i <= end_x; ++i) {
            for (int j = start_y; j <= end_y; ++j) {
                map[i][j]++;
            }
        }
    }
    else{
        for (int i = start_x; i <= end_x; ++i) {
            for (int j = start_y; j <= end_y; ++j) {
                map[i][j] = -100;
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    memset(map, 0, sizeof map);
    scanf("%d%d%d", &A, &B, &K);
    int count_of_bomb = 0;//计算堡垒被炸了几次，那么地图上的那个位置的值一定等于这个值；
    for (int i = 0; i < K; ++i) {
        int R, S, P, T;
        scanf("%d%d%d%d", &R, &S, &P, &T);
        Throw_Bomb(R,S,P,T);
        if(T == 1)count_of_bomb++;
    }
    int ans = 0;
    for (int i = 1; i <= A; ++i) {
        for (int j = 1; j <= B; ++j) {
            if(map[i][j] == count_of_bomb){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}