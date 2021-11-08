#include<bits/stdc++.h>
using namespace std;

int partition(int si,int en,int a[])
{
	int pivot=a[si];
	int countSmaller=0;
	
	for(int i=si+1;i<=en;i++)
	{
		if(a[i]<=pivot)
		{
			countSmaller++;
		}
	}
	
	int pivotIndex=countSmaller+si;
	a[si]=a[pivotIndex];
	a[pivotIndex]=pivot;
	
	int i=si;
	int j=en;
	
	while(i<pivotIndex and j>pivotIndex)
	{
		if(a[i]<=pivot)
		{
			i++;
		} 
		else if(a[j]>pivot)
		{
			j--;
		} 
		else
		{
			swap(a[i],a[j]);
			i++;
			j--; 
		}
	} 
	
	return pivotIndex;
}



void quick_sort(int si,int en,int a[])
{
	if(si>=en)
		return;
	int m=partition(si,en,a);
	quick_sort(si,m-1,a);
	quick_sort(m+1,en,a);
}
     

int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0);
	
	
	int n;
	cin >> n;
	
	int a[n];
	for(int  i=0 ; i<n; i++)	
	{
		cin >> a[i];
	} 
	
	quick_sort(0,n,a);
	
	for(int i=0 ;i<n; i++)
		cout << a[i] <<" ";
}    
