#include<bits/stdc++.h>
using namespace std;


string solver(int arr1[],int arr2[])
{
    int s1= 0,s2 = 0;
    for(int i = 0;i<3;i++)
    {
        s1 = s1 + arr1[i];
        s2 = s2 + arr2[i];
    }
    if(s1>s2)
    {
        return "DRAGON";
    }
    else if(s1<s2)
    {
        return "SLOTH";
    }
    else
    {
        if(arr1[0]>arr2[0])
        {
            return "DRAGON";
        }
        else if(arr1[0]< arr2[0])
        {
            return "SLOTH";
        }
        else if(arr1[1]> arr2[1])
        {
            return "DRAGON";
        }
        else if(arr1[1]< arr2[1])
        {
            return "SLOTH";
        }
        else if(arr1[2]> arr2[2])
        {
            return "DRAGON";
        }
        else if(arr1[2]< arr2[2])
        {
            return "SLOTH";
        }
        else
        {
            return "TIE";
        }
    }
}

int main()
{
    int t;
    
    cin>>t;
    while(t--)
    {
        int a1[3],a2[3];
        string result;
        for(int i = 0; i<3;i++)
        {
            cin>>a1[i];
        }
        for(int i = 0; i<3;i++)
        {
            cin>>a2[i];
        }
        result = solver(a1,a2);
        cout<<result<<endl;
    }
}