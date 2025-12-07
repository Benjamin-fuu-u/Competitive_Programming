#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n ,m;
    cin>>n>>m;
    vector<int> mission;
    multiset<int> quiet;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        mission.push_back(num);
    }

    for(int i=0;i<m;i++)
    {
        int num;
        cin>>num;
        quiet.insert(num);
    }

    sort(mission.begin() , mission.end());

    int ans = 0;

    for(int i=0;i<n;i++)
    {
        auto it = quiet.lower_bound(mission[i]);
        //cout<<mission[i]<<" "<<*it<<endl;

        if(it != quiet.end())
        {
            ans++;
            quiet.erase(it);

        }

    }

    cout<<ans;
    return 0;
}
