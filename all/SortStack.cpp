#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert(stack<int> &s,int a)
{
    if(s.empty() || a > s.top())
    {
        s.push(a);
        //return;
    }
    else
    {
        int x = s.top();
        s.pop();
        insert(s,a);
        s.push(x);
        //return;
    }    

}
void SortedStack :: sort()
{
    int temp;
    if(s.empty())
    {
        return;
    }
    if(!s.empty())
    {
        temp = s.top();
        s.pop();
        sort();
        insert(s,temp);
        //return;
    }
   //Your code here
}