## Tiếng Việt



## English



## Chinese (简体中文)



---

## Số học

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int maxn=1000000+10;

int is_prime[maxn]={0};
int d[maxn];
int ntest;
int n;
int a[maxn],b[maxn];

void Sang(){
    for(int i=2;i<=1000;i++)
        if (is_prime[i]==0)
            for(int j=i*i;j<=1000000;j+=i)
                is_prime[j]=i;
    for(int i=1;i<=1000000;i++)
        if (is_prime[i]==0) is_prime[i]=i;
}

void PhanTich(int n,int val){
    while(n>1){
        d[is_prime[n]]+=val;
        n=n/is_prime[n];
    }
}

bool Checker(){
    for(int i=2;i<=1000000;i++)
        if (is_prime[i]==i && i!=2 && i!=5 && d[i]<0){
            // cout<<"Checker "<<i<<" success"<<endl;
            return true;
        }
    return false;
}

int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Sang();
    cin>>ntest;
    for(int nt=1;nt<=ntest;nt++){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=1000000;i++) d[i]=0;
        for(int i=1;i<=n;i++) PhanTich(a[i],1);
        for(int i=1;i<=n;i++) PhanTich(b[i],-1);
        // Số thập phân hữu hạn khi nào?
        // Số thập phân vô hạn khi nào? Mẫu số có số nguyên tố khác 2 hoặc 5
        if (Checker()) cout<<"repeating"<<endl;
        else cout<<"finite"<<endl;
    }
    return 0;
}

```
