//Link: https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
public:
	string rearrangeString(string str)
	{
		int arr[26] = {0};
		string res = "";
		for (int i = 0; i < str.length(); i++)
		{
			arr[str[i] - 'a'] += 1;
		}
		priority_queue<pair<int, char>> q;
		char c = 'a';
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] > 0)
			{
				q.push(make_pair(arr[i], 'a'+i));
			}
		}
		pair<int, char> temp = {-1, '#'};
		pair<int, char> n;
		while (!q.empty())
		{
			n = q.top();
			if(temp.second != n.second )
			{
				res += n.second;
				n.first--;
				q.pop();
				if(n.first>0)
				{
					q.push(n);
				}
				temp = n;
			}
			else if(temp.second == n.second && q.size() >=2)
			{
				q.pop();
				n = q.top();
				q.pop();
				res += n.second;
				n.first--;
				if(temp.first > 0)
				{
					q.push(temp);
				}
				if(n.first > 0)
				{
					q.push(n);
				}
				temp = n;
			}
			else
			{
				return "-1";
			}
		}

		/* priority_queue<pair<int,char>>q2 = q;

		while(!q2.empty())
		{
			pair<int,char> topofthequeue = q2.top();
			cout<<topofthequeue.first<<" "<<topofthequeue.second<<"\n";
			q2.pop();
		} */

		return res;
		// code here
	}
};

// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		Solution ob;
		string str1 = ob.rearrangeString(str);
		int flag = 1;
		int c[26] = {0};
		for (int i = 0; i < str.length(); i++)
			c[str[i] - 'a'] += 1;
		int f = 0;
		int x = (str.length() + 1) / 2;
		for (int i = 0; i < 26; i++)
		{
			if (c[i] > x)
				f = 1;
		}
		if (f)
		{
			if (str1 == "-1")
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}
		else
		{
			int a[26] = {0};
			int b[26] = {0};
			for (int i = 0; i < str.length(); i++)
				a[str[i] - 'a'] += 1;
			for (int i = 0; i < str1.length(); i++)
				b[str1[i] - 'a'] += 1;

			for (int i = 0; i < 26; i++)
				if (a[i] != b[i])
					flag = 0;

			for (int i = 0; i < str1.length(); i++)
			{
				if (i > 0)
					if (str1[i - 1] == str1[i])
						flag = 0;
			}
			if (flag == 1)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
	return 0;
} // } Driver Code Ends