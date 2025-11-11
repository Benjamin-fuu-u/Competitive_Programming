#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> baloni;
    map<int,int>arrow;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int height;
        cin>>height;
        baloni.push_back(height);
    }
    int answer=0;
    for(int i=0;i<n;i++)
    {
        if(arrow[baloni[i]]==0)
        {
            arrow[baloni[i]-1]++;
            answer++;
        }
        else if(arrow[baloni[i]]!=0)
        {
            arrow[baloni[i]-1]++;
            arrow[baloni[i]]--;
        }
    }
    cout<<answer;
}
