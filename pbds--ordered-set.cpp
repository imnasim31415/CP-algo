#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
#define LL long long
using namespace __gnu_pbds;
using namespace std;
typedef tree<LL, null_type, less<LL>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

#define pb push_back
#define rep(i,n) for(i=0;i<n;i++)
#define Rep(i,n) for(i=1;i<=n;i++)
#define vi vector<long long>
string en="\n";
string sp=" ";
string t="hello";
string Y="YES\n";
string N="NO\n";
int main()
{
//    fast;
    LL i,j,k,n,m,l,s=0,x,y,tc=1,p,q,a,b,c=0,d;
    bool f=0,ff=0;string st,sa,sb,sc; char ch;


    ordered_set ans;
    
    ans.push(x);
    auto it=ans.find_by_key(p);
    
    p=ans.order_of_key(p);
}
