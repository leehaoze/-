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

int R,C,N;

typedef struct Plant{
    int x,y;
}Plant;

Plant Dead_Plants[5001];

bool operator < (const Plant &a, const Plant &b){
    if(a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}


int Cac_Path_Length(Plant &start,int dx,int dy){
    int step = 0;//本来是考虑到先走了一步进到了田地里嘛，就设置的为1，但应该为0，为什么为0呐，我也不知道，有空再说吧、休息下 哈哈
    Plant move = start;//这里最开始忘了先加一次dx，dy让他进到田地里
    move.x += dx;
    move.y += dy;
    while(move.x >= 1 && move.x <= R && move.y >= 1 && move.y <= C){
        if(!binary_search(Dead_Plants,Dead_Plants + N,move)){
            step = 0;
            break;
        }
        move.x += dx;
        move.y += dy;
        step++;
        //如果计算出的踩到的水稻，不在踩到的水稻数组里，说明这个路径不可行
    }
    return step;
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    scanf("%d%d",&R,&C);
    scanf("%d",&N);
    //读入数据
    for (int i = 0; i < N; ++i) {
        scanf("%d%d",&Dead_Plants[i].x,&Dead_Plants[i].y);
    }
    //对数据进行排序，这就是在做一个剪枝的操作，可以减少枚举量
    sort(Dead_Plants,Dead_Plants + N);

    //开始枚举，两个点两个点的举
    int dx,dy;
    int max_step = 1;//最大步长
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            //计算步长
            dx = Dead_Plants[j].x - Dead_Plants[i].x;
            dy = Dead_Plants[j].y - Dead_Plants[i].y;

            //计算起点，看看是不是落到了田地里，落到田地里说明步长太短，换一个第二个点拉大步长
            Plant start;
            start.x = Dead_Plants[i].x - dx;
            start.y = Dead_Plants[i].y - dy;

            if( (start.x >= 1 && start.x <= R) && (start.y >= 1 && start.y <= C) ){//第一次写中间写成了｜｜
                continue;
            }
            //这边哦，为什么分开考虑呐，是因为排序的时候是按照x的升序排列的，所以y的大小变化不是规律的，所以如果x
            //不合适，就说明以后的点构成的dx更不合适，因为后边的生成的dx只会更大，但是dy就不一定了
            if(Dead_Plants[i].x + (max_step - 1) * dx > R){//这个步长太大了,就不要了，而且以后的第二个点会更大的，所以直接break出内层循环
                break;
            }
            if( (Dead_Plants[i].y + (max_step - 1) * dy > C) || (Dead_Plants[i].y + (max_step - 1) * dy < 1) ){//这里考虑的不全，dy可以是正的，也可以是负的
                continue;
            }

            //如果程序可以跑到这里，说明这个路径比之前的都要好，算一下最多可以压倒多少，即算一下max_step
            max_step = max(max_step,Cac_Path_Length(start,dx,dy));
        }
    }
    if(max_step < 3) max_step = 0;
    printf("%d\n",max_step);

    return 0;
}