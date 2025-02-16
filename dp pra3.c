//P1018 dp+高精度
//ac代码
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct bign{
    int d[1000];
    int len;
    bign(){ //构造函数
        memset(d,0,sizeof(d));
        len=0;
    }
};
//这样在每次定义结构体变量的时候都会自动对此变量进行初始化
//而在读入大整数时一般都是先用字符串读入然后再把字符串另存到bign结构体 由于使用char数组进行读入时，与我们想要的顺序是相反的，因此为了让整数在bign中是顺位存储，需要让字符串倒着赋给d[]数组
bign change(string str){ //将string转换为bign
    bign a;
    a.len=str.length();
    for(int i=0;i<a.len;i++){
        a.d[i]=str[a.len-i-1]-'0';
    }
    return a;
}
//比较两个bign变量的大小：先比len再从高位到低位比较
int compare(bign a,bign b){
    if(a.len>b.len) return 1; //a大
    else if(a.len<b.len) return -1; //b大
    else{
        for(int i=a.len-1;i>=0;i--){
            if(a.d[i]>b.d[i]) return 1;
            else if(a.d[i]<b.d[i]) return -1;
        }
        return 0; //两数相等
    }
}

bign max_bign(bign a, bign b) {
    if (compare(a, b) >= 0) return a;
    else return b;
}
//高精度与低精度的乘法
bign multi(bign a, int b_int){
    bign c;
    int carry=0;
    for(int i=0;i<a.len;i++){
        int temp=a.d[i]*b_int+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    while(carry!=0){ //因为乘法的进位可能不止一位所以用while
        c.d[c.len++]=carry%10;
        carry/=10;
    }
    return c;
}

//高精度与高精度的乘法 (需要实现)
bign multiply(bign a, bign b) {
    bign c;
    vector<int> res(a.len + b.len, 0); 
    for (int i = 0; i < a.len; i++) {
        for (int j = 0; j < b.len; j++) {
            res[i + j] += a.d[i] * b.d[j];
        }
    }
    for (int i = 0; i < res.size() - 1; i++) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
    c.len = res.size();
    while (c.len > 1 && res[c.len - 1] == 0) {
        c.len--;
    }
    for (int i = 0; i < c.len; i++) {
        c.d[i] = res[i];
    }
    return c;
}

void print_bign(bign a){
    for(int i=a.len-1;i>=0;i--){
        cout<<a.d[i];
    }
}
bign dp[100][20]; 
bign num[100][100];

int main(){
    int n,k;
    string s;
    cin>>n>>k>>s;

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            num[i][j] = change(s.substr(i-1, j - i + 1));
        }
    }

    for(int i=1; i<=n; ++i) {
        dp[i][0] = num[1][i];
    }

    for(int j=1;j<=k;j++){//j个乘号
        for(int i=j+1;i<=n;i++){//前i个数
            //dp[i][j] = change("0");
            for(int m=j; m<=i-1;m++){//最后一个乘号在m和m+1个数之间
                dp[i][j] = max_bign(dp[i][j], multiply(dp[m][j-1], num[m+1][i]));
            }
        }
    }
    print_bign(dp[n][k]);
    cout << endl;

    return 0;
}
//80分
#include<iostream>
#include<cstring>
using namespace std;
__int128 dp[100][20];
__int128 num[100][100];
inline void output(__int128 a){
    if(a>9)output(a/10);
    putchar(a%10+'0');
}
int main(){
int n,k;
string s;
cin>>n>>k>>s;
memset(dp,0,sizeof(dp));
memset(num,0,sizeof(num));
//准备工作 dp的初始化
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
    num[i][j]=num[i][j-1]*10+s[j-1]-'0';
}
for(int i=1; i<=n; ++i) {
        dp[i][0] = num[1][i];
    }
    for(int j=1;j<=k;j++){//j个乘号
        for(int i=j+1;i<=n;i++){//前i个数
            for(int m=j; m<=i-1;m++){//最后一个乘号在m和m+1个数之间
                dp[i][j] = max(dp[i][j],dp[k][j-1]*num[k+1][i]);
            }
        }
    }
output(dp[n][k]);
}