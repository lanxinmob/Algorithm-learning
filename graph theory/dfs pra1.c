//P1249最大乘积【高精度】
//DFS TLE超出时间限制了应该用贪心
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<ranges>
using namespace std;

string mul(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> res(a.size() + b.size(), 0);
    
    for (int i = 0; i < a.size(); i++) {
        int na = a[i] - '0';
        for (int j = 0; j < b.size(); j++) {
            int nb = b[j] - '0';
            res[i + j] += na * nb;
        }
    }
    
    for (int i = 0; i < res.size() - 1; i++) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
    
    int len = res.size();
    while (len > 1 && res[len - 1] == 0) {
        len--;
    }
    
    string c;
    for (int i = 0; i < len; i++) {
        c.push_back(res[i] + '0');
    }
    
    reverse(c.begin(), c.end());
    return c;
}

string f(int n) {
    if (n == 0) return "0";
    string s;
    while (n > 0) {
        s.push_back(n % 10 + '0');
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    int n;
    cin >> n;
    
    if (n < 5) {
        cout << n << endl;
        return 0;
    }
    
    vector<int> a;
    int current = 2;
    while (n >= current) {
        a.push_back(current);
        n -= current;
        current++;
    }
    
    int idx = a.size() - 1;
    while (n > 0 && idx >= 0) {
        a[idx--]++;
        n--;
    }
    if (n > 0) a.back()++;
    
    string m = "1";
    for (int num : a) {
        cout<<num<<" ";  
    }
    cout<<endl;
    for (int num : a) {
        m = mul(m, f(num));
    }
    
    cout << m << endl;
    return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX  10000

int a[1000];
int *best,n;

typedef struct {
    int digit[MAX];
    int size;
} Bigint;
Bigint ma;
void initbigint(Bigint*num){
    memset(num->digit, 0, sizeof(num->digit));
    num->size = 1;
}
void bigmutiply(Bigint*result,Bigint*ans,int b){
    int carry = 0;
    for(int i = 0; i<ans->size ; i++){
        int temp = ans->digit[i]*b +carry;
        result->digit[i] = temp%10;
        carry = temp/10;
        //result->size++;
    }result->size=ans->size;
    while(carry>0){
        result->digit[result->size++] = carry%10;
        carry/=10;
    }
}
int comparebigint(Bigint*a,Bigint*b){
    if(a->size>b->size)return 1;
    if(a->size<b->size)return -1;
    for (int i = a->size-1; i >=0; i--){
        if(a->digit[i]>b->digit[i])return 1;
        if(a->digit[i]<b->digit[i])return -1;
    }
    return 0; 
}
void copy_bigint(Bigint*a,Bigint*b){
    a->size=b->size;
    memcpy(a->digit,b->digit,sizeof(int)*b->size);
}
void dfs(int cur,Bigint* ans,int sum,int c){
    if(n==sum){
        if(comparebigint(ans,&ma)>0){
        copy_bigint(&ma,ans);
        for(int i=0;i<c;i++)best[i] =a[i];
        best[c] =0;
        }
        return;
    }    
    for(int i=cur;sum+i<=n;i++){
        a[c] = i; 
        Bigint new;
        initbigint(&new);
        bigmutiply(&new, ans,i);
        dfs(i+1,&new,sum+i,c+1);
    }
}
void print_bigint(Bigint*num){
    for(int i=num->size -1;i>=0;i--)
        printf("%d",num->digit[i]);
}
int main(){
    best = (int*)calloc(1000,sizeof(int));
    scanf("%d",&n);
    Bigint ans;
    ans.digit[0] = 1;
    ans.size = 1;
    initbigint(&ma);
    dfs(1,&ans,0,0);
    for (int i = 0;best[i]!=0; i++){
        printf("%d ",best[i]);
    }
    printf("\n");
    print_bigint(&ma);
    printf("\n");
    free(best);
    return 0;
}*/

