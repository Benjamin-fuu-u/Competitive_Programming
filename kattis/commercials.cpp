#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,c;
    int time_price[100000];
    cin>>n>>c;
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        time_price[i]=in-c;
    }

    int dp[100001];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=max(dp[i-1]+time_price[i-1],time_price[i-1]);
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        ans=max(dp[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}
