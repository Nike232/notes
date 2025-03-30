#include<bits/stdc++.h>
using namespace std;
//用数组实现高精度加法
char a[1000],b[1000];//注意一定要定义为全局静态数组 用char而不用int可以节约空间但是注意后面字符和数字的转化
string add(string s1,string s2)
{
    int len1=s1.size(),len2=s2.size();
    for(int i=0;i<len1;i++){
       a[len1-i-1]=s1[i]-'0';
    }
    for(int i=0;i<len2;i++)
    {
        b[len2-1-i]=s2[i]-'0';
    }
    //将字符串倒序并且转化为数字的值存储到数组当中
    int mlen=len1>len2?len1:len2;
    for(int i=0;i<mlen;i++)
    {
        a[i]+=b[i];//因为全局变量默认初始化为0所以不影响结果
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[mlen])
    {
        mlen++;        
    }
    string res;
    for(int i=mlen-1;i>=0;i--)
    {
        res+=a[i]+'0';//注意将数字转化为字符形式
    }
    return res;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<add(s1,s2);
}