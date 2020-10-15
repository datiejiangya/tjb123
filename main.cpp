#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,x,y;
int dis[100005],vis[100005];
struct node
{
    int to;
    int next;
}e[100005];
int head[100005];
int cnt=0;
void add(int a,int b)
{
    cnt++;
    e[cnt].to=b;
    e[cnt].next=head[a];
    head[a]=cnt;
}
queue<int>q;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        add(x,y);
        add(y,x);
    }
    memset(dis,0x3f,sizeof(dis));
    q.push(1);
    dis[1]=0;
    vis[1]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(dis[v]>dis[x]+1)
            {
                dis[v]=dis[x]+1;
                if(vis[v]==0)
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    int maxx=0,id=0,ans=0;
    for(int i=1;i<=n;i++)
        if(dis[i]>maxx)
        {
            maxx=dis[i];
            id=i;
        }
    printf("%d %d ",id,maxx);
    for(int i=1;i<=n;i++)
        if(maxx==dis[i])ans++;
    printf("%d",ans);
    return 0;
}
