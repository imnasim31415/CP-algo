/* first run a dfs from each non-visited node. After
processing the node put it in the stack. Then take
elements one by one from stack and run a dfs again on the
inverted graph. The visited components in the 2nd dfs are
in scc. */

#include<bits/stdc++.h>
using namespace std;
#define sz size()
#define cnt continue
#define pb push_back
string en="\n";
using LL=long long;
vector<LL> adj[200005], rev_adj[200005], vis(200005),topSort;

void dfs(int n)
{
    vis[n]=1;
    for(int i=0;i<adj[n].size();i++)
    {
        int x=adj[n][i];
        if(!vis[x])dfs(x);
    }
    topSort.pb(n);
}

void dfs2(int n)
{
    vis[n]=1;
    for(int i=0;i<rev_adj[n].sz;i++)
    {
        int x=rev_adj[n][i];
        if(vis[x])cnt;
        cout<<x<<" ";
        dfs2(x);
    }
}
int main()
{
    LL i,j,k,n,m,l,s=0,x,y,tc=1,p,q,a,b,c=0,d=0;
    bool f=0,ff=0;string st,sa,sb,sc; char ch;
    while(cin>>n>>m)
    {
        topSort.clear();
        for(i=0;i<=n+5;i++)
        {
            adj[i].clear(); vis[i]=0;
        }

        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            adj[a].pb(b);
            rev_adj[b].pb(a);  // reverse graph
        }
        for(i=0;i<n;i++)
        {
            if(!vis[i])dfs(i);
        }


        for(i=0;i<n;i++)vis[i]=0;
        cout<<"Strongly Connected Components:\n";
        for(i=topSort.sz-1;i>=0;i--)
        {
            x=topSort[i];
            if(!vis[x])
            {
                cout<<x<<" ";
                dfs2(x);
                cout<<endl;
            }
        }
    }
}
