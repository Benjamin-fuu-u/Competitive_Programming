#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>num;
    for(int i=0;i<n;i++)
    {
        int number;
        cin>>number;
        num.push_back(number);
    }
        vector<int>gis;
        int now_number=0;
        for(int i=0;i<n;i++)
        {
            if(num[i]>now_number)
            {
                gis.push_back(num[i]);
                now_number=num[i];
            }
        }

        cout<<gis.size()<<endl;
        for(int i=0;i<gis.size();i++)
        {
            cout<<gis[i]<<" ";
        }
}
