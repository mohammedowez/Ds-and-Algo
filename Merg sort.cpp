#include<bits/stdc++.h>
using namespace std;

void merg(int a[],int l,int r)
{ 
	int n=r+1;
	int m=((l+r)/2);
	int k=l,i=l,j=m+1;
	int t[1000];
	while(i<=m && j<=r)
	{
		if(a[i]<a[j])
			t[k++]=a[i++];
		else
			t[k++]=a[j++];
	} 
	
	while(i<=m)
	{
		t[k++]=a[i++];
	}
	
	while(j<=r)
	{
		t[k++]=a[j++];
	} 
	
	for(int i=0;i<n;i++)
	{
		a[i]=t[i];
	}
	
}

void mergsort(int a[],int l,int r)
{
	
	int m=((l+r)/2);
	if(l>=r)
	{
		return;
	}
	mergsort(a,l,m);
	mergsort(a,m+1,r);
	merg(a,l,r);
}

int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0);
	
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	mergsort(a,0,n-1); 
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
		
	} 
	return 0;
}
