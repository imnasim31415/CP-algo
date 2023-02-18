#include<bits/stdc++.h>
#define LL long long
using namespace std;
/*
Complexity: O( N logN )

ϕ(N)=N-1                 -> if N is prime
ϕ(ab)=ϕ(a)*ϕ(b)          -> if a and b are coprime
ϕ(ab)=ϕ(a)*ϕ(b)*{d/ϕ(d)} ->if a and b are not coprime

*/
const LL N=1000005;
LL phi[N+5];
void calc_Phi()
{
    phi[0]=0;
    phi[1]=1;
    for(int i=2;i<=N;i++) phi[i]=i-1;
    for(int i=2;i<=N;i++)
    {
        for(int j=i*2;j<=N;j+=i)
        {
            phi[j]-=phi[i];
        }
    }
}
int main()
{
    calc_Phi();
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        cout<<phi[n]<<endl;
    }
}
