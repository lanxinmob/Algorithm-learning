//两个模板
#include<bits/stdc++.h>
using namespace std;

//大整数的存储：使用数组
//整数的高位存储在数组的高位，整数的低位存储在数组的低位
//将整数按字符串%s读入的时候实际上是逆位存储的，因此在读入之后需要在另存至d[]数组的时候反转一下
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
bign change(char str[]){ //将整数转换为bign
    bign a;
    a.len=strlen(str);
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

//高精度加法 必须都得是正数
bign add(bign a,bign b){
    bign c;
    int carry=0; //carry是进位
    for(int i=0;i<a.len||i<b.len;i++){ //以较长的为界限（想象竖式加法）
        int temp=a.d[i]+b.d[i]+carry; //两个对应位与进位相加
        c.d[c.len++]=temp%10; //个位数为该位的结果
        carry=temp/10; //十位数为新的进位
    }
    if(carry!=0) {
        c.d[c.len++]=carry; //如果最后进位不为0，那么直接赋给结果的最高位
    }
    return c;
}

//高精度减法
bign sub(bign a,bign b){
    bign c;
    for(int i=0;i<a.len||i<b.len;i++){
        if(a.d[i]<b.d[i]){ //如果不够减
            a.d[i+1]--;
            a.d[i]+=10;
        }
        c.d[c.len++]=a.d[i]-b.d[i]; //减法结果为当前位数结果
    }
    while(c.len-1>=1&&c.d[c.len-1]==0){ //最后一步需要注意减法后高位可能有多余的0，要忽视他们，但是也要保证结果（去掉可能存在的高位0之后）至少有1位数
        c.len--; //忽视高位0
    }
    return c;
}
//最后需要指出使用sub函数之前需要比较两个数的大小，如果被减数小于减数，则需要交换两个变量，然后输出负号，再使用sub函数

//高精度与低精度的乘法
bign multi(bign a,int b){
    bign c;
    int carry=0;
    for(int i=0;i<a.len;i++){
        int temp=a.d[i]*b+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    while(carry!=0){ //因为乘法的进位可能不止一位所以用while
        c.d[c.len++]=carry%10;
        carry/=10;
    }
    return c;
}

//高精度与低精度的除法
bign divide(bign a,int b,int& r){ //r 为余数
    bign c;
    c.len=a.len; //被除数的每一位和商的每一位是一一对应的，因此可以先令长度相等 
    for(int i=a.len-1;i>=0;i++){ //除法从高位开始
        r=r*10+a.d[i];
        if(r<b) c.d[i]=0; //不够除则这位为0
        else{
            c.d[i]=r/b;
            r=r%b;
        }
    }
    while(c.len-1>=1&&c.d[c.len-1]==0){
        c.len--;
    }
    return c;
}

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct Wint:vector<int>//用标准库vector做基类，完美解决位数问题，同时更易于实现
{
    //将低精度转高精度的初始化，可以自动被编译器调用
    //因此无需单独写高精度数和低精度数的运算函数，十分方便
    Wint(int n=0)//默认初始化为0，但0的保存形式为空
    {
        push_back(n);
        check();
    }
    Wint& check()//在各类运算中经常用到的进位小函数，不妨内置
    {
        while(!empty()&&!back())pop_back();//去除最高位可能存在的0
        if(empty())return *this;
        for(int i=1; i<size(); ++i)//处理进位 
        {
            (*this)[i]+=(*this)[i-1]/10;
            (*this)[i-1]%=10;
        }
        while(back()>=10)
        {
            push_back(back()/10);
            (*this)[size()-2]%=10;
        }
        return *this;//为使用方便，将进位后的自身返回引用
    }
};
//输入输出
istream& operator>>(istream &is,Wint &n)
{
    string s;
    is>>s;
    n.clear();
    for(int i=s.size()-1; i>=0; --i)n.push_back(s[i]-'0');
    return is;
}
ostream& operator<<(ostream &os,const Wint &n)
{
    if(n.empty())os<<0;
    for(int i=n.size()-1; i>=0; --i)os<<n[i];
    return os;
}
//比较，只需要写两个，其他的直接代入即可
//常量引用当参数，避免拷贝更高效
bool operator!=(const Wint &a,const Wint &b)
{
    if(a.size()!=b.size())return 1;
    for(int i=a.size()-1; i>=0; --i)
        if(a[i]!=b[i])return 1;
    return 0;
}
bool operator==(const Wint &a,const Wint &b)
{
    return !(a!=b);
}
bool operator<(const Wint &a,const Wint &b)
{
    if(a.size()!=b.size())return a.size()<b.size();
    for(int i=a.size()-1; i>=0; --i)
        if(a[i]!=b[i])return a[i]<b[i];
    return 0;
}
bool operator>(const Wint &a,const Wint &b)
{
    return b<a;
}
bool operator<=(const Wint &a,const Wint &b)
{
    return !(a>b);
}
bool operator>=(const Wint &a,const Wint &b)
{
    return !(a<b);
}
//加法，先实现+=，这样更简洁高效
Wint& operator+=(Wint &a,const Wint &b)
{
    if(a.size()<b.size())a.resize(b.size());
    for(int i=0; i!=b.size(); ++i)a[i]+=b[i];
    return a.check();
}
Wint operator+(Wint a,const Wint &b)
{
    return a+=b;
}
//减法，返回差的绝对值，由于后面有交换，故参数不用引用
Wint& operator-=(Wint &a,Wint b)
{
    if(a<b)swap(a,b);
    for(int i=0; i!=b.size(); a[i]-=b[i],++i)
        if(a[i]<b[i])//需要借位
        {
            int j=i+1;
            while(!a[j])++j;
            while(j>i)
            {
                --a[j];
                a[--j]+=10;
            }
        }
    return a.check();
}
Wint operator-(Wint a,const Wint &b)
{
    return a-=b;
}
//乘法不能先实现*=
Wint operator*(const Wint &a,const Wint &b)
{
    Wint n;
    n.assign(a.size()+b.size()-1,0);
    for(int i=0; i!=a.size(); ++i)
        for(int j=0; j!=b.size(); ++j)
            n[i+j]+=a[i]*b[j];
    return n.check();
}
Wint& operator*=(Wint &a,const Wint &b)
{
    return a=a*b;
}
//除法和取模先实现一个带余除法函数
Wint divmod(Wint &a,const Wint &b)
{
    Wint ans;
    for(int t=a.size()-b.size(); a>=b; --t)
    {
        Wint d;
        d.assign(t+1,0);
        d.back()=1;
        Wint c=b*d;
        while(a>=c)
        {
            a-=c;
            ans+=d;
        }
    }
    return ans;
}
Wint operator/(Wint a,const Wint &b)
{
    return divmod(a,b);
}
Wint& operator/=(Wint &a,const Wint &b)
{
    return a=a/b;
}
Wint& operator%=(Wint &a,const Wint &b)
{
    divmod(a,b);
    return a;
}
Wint operator%(Wint a,const Wint &b)
{
    return a%=b;
}
//顺手实现一个快速幂，可以看到和普通快速幂几乎无异
Wint pow(const Wint &n,const Wint &k)
{
    if(k.empty())return 1;
    if(k==2)return n*n;
    if(k.back()%2)return n*pow(n,k-1);
    return pow(pow(n,k/2),2);
}
int main()
{
	
}

