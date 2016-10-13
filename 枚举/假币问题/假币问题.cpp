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

struct Weights{
    string a,b,c;
};

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int T;
    input(T);
    while(T--){
        Weights w[3];
        //读入数据
        int hash[26];
        memset(hash,0,sizeof hash);
        for (int i = 0; i < 3; ++i) {
            cin >> w[i].a >> w[i].b >> w[i].c;
            int len = w[i].a.length();
            for (int j = 0; j < len; ++j) {
                hash[w[i].a[j] - 'A'] = 1;
                hash[w[i].b[j] - 'A'] = 1;
            }
        }
        char ans;
        int h_l;
        //枚举每一枚硬币为假币，看看满不满足输入的条件
        for (int i = 0; i < 26; ++i) {
            if(hash[i] == 0)continue;//如果这个字符没有出现过，就不计算了
            char FCoin = i + 'A';
            int heavy_or_light = 0;//表示是轻还是重，－1为重，1为轻
            bool jump_out =false;
            for (int j = 0; j < 3; ++j) {
                bool show = false;//假币是否出现过
                int len = w[j].a.length();
                for (int k = 0; k < len; ++k) {
                    //如果在左侧找到了这枚硬币
                    if(FCoin == w[j].a[k]){
                        show = true;
                        if(w[j].c == "even"){//如果存在假币，还相等，说明这种情况不对，枚举下一枚硬币为假币
                            jump_out = true;
                            break;
                        }
                        else if(w[j].c == "up"){//左端略高，说明是轻了
                            //这个地方，原本的时候，忘记了加判断，都是统一的进来就赋值
                            //实际上，如果已经赋好了值，就需要判断和之前赋的值是不是冲突，是的话，就说明这个情况不对
                            if(heavy_or_light == 0)
                                heavy_or_light = -1;
                            else{
                                if(heavy_or_light == 1){
                                    jump_out = true;
                                    break;
                                }
                            }
                        }
                        else{
                            if(heavy_or_light == 0)
                                heavy_or_light = 1;
                            else{
                                if(heavy_or_light == -1){
                                    jump_out = true;
                                    break;
                                }
                            }
                        }
                    }
                    if(FCoin == w[j].b[k]){
                        show = true;
                        if(w[j].c == "even"){//如果存在假币，还相等，说明这种情况不对，枚举下一枚硬币为假币
                            jump_out = true;
                            break;
                        }
                        else if(w[j].c == "up"){//左端略高，说明是重了
                            if(heavy_or_light == 0)
                                heavy_or_light = 1;
                            else{
                                if(heavy_or_light == -1){
                                    jump_out = true;
                                    break;
                                }
                            }
                        }
                        else{
                            if(heavy_or_light == 0)
                                heavy_or_light = -1;
                            else{
                                if(heavy_or_light == 1){
                                    jump_out = true;
                                    break;
                                }
                            }
                        }
                    }
                }
                if(!show){//如果没有出现过假币，那么这次称量的结果必定是even，否则这种情况不对，枚举下一枚
                    if(w[j].c != "even")jump_out = true;
                }
                if(jump_out)break;
            }
            if(jump_out)continue;
            //如果程序可以跑到这一行，说明，枚举的这枚假币，可以满足三次测量，那么就是它了
            ans = FCoin;
            h_l = heavy_or_light;
            break;
        }
        if(h_l == -1){
            printf("%c is the counterfeit coin and it is heavy.\n",ans);
        }
        else
            printf("%c is the counterfeit coin and it is light.\n",ans);
    }

    return 0;
}