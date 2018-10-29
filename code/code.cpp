#include <bits/stdc++.h>
using namespace std;

void printit(int *cur,int size)
{
	for(int i=size-1;i>=0;i--)
	{
		cout<<cur[i]<<" ";
	}
	cout<<"\n";
}

//recusive function for printing all lis 
void printall(int beg,vector<int> p[],int *a,int n,int idx,int *cur,int size)
{
  //if parent is empty means lis is constructed
	if(!p[beg].size())
	{
		printit(cur,size);
		return;
	}
	for(int i=0;i<p[beg].size();i++)
	{
		cur[size]=a[p[beg][i]];
		printall(p[beg][i],p,a,n,idx,cur,size+1);
	}
}

void lis(int *a,int n)
{
//parent array of vectors to store all the parents that are part of lis
	vector<int> parent[n];
	int *store=new int[n];

	for(int i=0;i<n;i++)
	{
        	store[i]=1;
	}

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i])
			{
                		if(store[i]<(store[j]+1))
                		{
                			store[i]=store[j]+1;
                			while(parent[i].size())
                			{
                				parent[i].pop_back();
                			}
                			parent[i].push_back(j);
                		}
                		else if(store[i]==store[j]+1)
                		{
                			parent[i].push_back(j);
                		}
			}
		}
	}

    	for(int i=0;i<n;i++)
    	{
    		cout<<store[i]<<" ";
    	}
    	cout<<"\n";

	int *cur=new int[n];
	int mx=store[0],cnt=1;
	vector<int> midx;
	midx.push_back(0);
  	//finding all the candidate indexes for lis
	for(int i=1;i<n;i++)
	{
        	if(store[i]==mx)
        	{
        		midx.push_back(i);
            		cnt++;
        	}
        	else if(store[i]>mx)
        	{
        		mx=store[i];
        		while(midx.size())
        		{
        			midx.pop_back();
        		}
        		midx.push_back(i);
        		cnt=1;
        	}
	}

    	cout<<"count "<<cnt<<"\n";
    	for(int i=0;i<midx.size();i++)
    	{
    		cur[0]=a[midx[i]];
    		printall(midx[i],parent,a,n,0,cur,1);
    	}
}

int main()
{
	int *a,n;
	cout<<"n?"<<"\n";
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	lis(a,n);
	return 0;
}
