#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> time;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        time.push_back(num);
    }

    int run[101001];
    fill(run+0,run+101001,0);

    for(int i=0;i<n;i++)
    {
        int start=time[i];
        for(int j=start;j<start+1000;j++)
        {
            run[j]++;
        }
    }

    int max_request=0;
    for(int i=0;i<101000;i++)
    {
        max_request=max(run[i],max_request);
    }
    int answer;
    if(max_request%k==0)
    {
        answer=max_request/k;
    }
    else
    {
        answer=max_request/k+1;
    }
    cout<<answer;
}
