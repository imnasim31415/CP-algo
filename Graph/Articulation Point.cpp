// run a dfs and find if there is any back-edge

#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
vector<LL>adj[200],art_point;
bool vis[200];
LL dis[200],low[200],n,e,c=0;

void dfs(LL s,LL p)
{
    vis[s]=1;
    dis[s]=low[s]=++c;
    LL child=0;
    for(int i=0;i<adj[s].size();i++)
    {
        LL x=adj[s][i];
        if(x==p)continue;
        if(vis[x])
        {
            low[s]=min(low[s],dis[x]);
        }
        else
        {
            dfs(x,s);
            low[s]=min(low[s],low[x]);
            if(low[x]>=dis[s]&&p!=-1)art_point.pb(s);
            child++;
        }
    }
    if(p==-1&&child>1)art_point.pb(s);
}
void find_cutpoints()
{
    for(int i=1; i<n; i++)vis[i]=0,dis[i]=low[i]=-1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)dfs(i,-1);
    }
}
int main()
{
    cin>>n>>e;
    for(int i=1; i<=n; i++)adj[i].clear();
    while(e--)
    {
        LL a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    find_cutpoints();
    for(int i=1;i<=n;i++)cout<<i<<" "<<dis[i]<<" "<<low[i]<<endl;
    cout<<"Articulation Points are:\n";
    for(int i=0;i<art_point.size();i++)
        cout<<art_point[i]<<endl;
}
