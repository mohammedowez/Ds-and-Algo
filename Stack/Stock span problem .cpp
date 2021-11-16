
// Next Greater element to left 


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       // Your code here
       
      vector<int> v(n);
	    vector<int> v2(n);
	    stack<pair<int,int>> s;
	    
	    for(int i=0;i<n;i++)
	    {
	        while(!s.empty() and arr[i]>=s.top().first)
	            s.pop();
	           
	        if(s.empty())
	            v[i]=-1;
	       else 
	            v[i]=s.top().second;
	           
	       s.push({arr[i],i});
	    } 
	    
	    for(int i=0;i<n;i++)
	    {
	        v2[i]=abs(i-v[i]);
	    } 
	    return v2;
    }
};
