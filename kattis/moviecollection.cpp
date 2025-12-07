#include<bits/stdc++.h>

using namespace std;

int n,m;
int b[200002];
int movie_now[200002];

void update(int x,int d)
{
    while(x<=n+m)
    {
        b[x]+=d;
        //cout<<x<<endl;
        x+=x&(-x);
    }
}

int query(int x)
{
    int ret = 0;
    while(x > 0)
    {
        ret+=b[x];
        //cout<<x<<"       "<<b[x]<<endl;
        x-=x&(-x);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<200002;j++)
        {
            movie_now[j] = 0;
            b[j] = 0;
        }

        cin>>n>>m;

        int top = m+1;
        for(int i=1;i<=n;i++)
        {
            update(m+i,1);
            movie_now[i] = m + i;
        }

         /*for(int j=0;j<10;j++)
        {
            cout<<movie_now[j]<<" ";
        }

        cout<<endl;*/
        for(int i=0;i<m;i++)
        {
            top--;
            int num;
            cin>>num;

            int ans=query(movie_now[num]-1);
            update(movie_now[num],-1);
            update(top,1);

            movie_now[num] = top;

            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
