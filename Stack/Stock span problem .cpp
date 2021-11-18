Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span for 100 
will be 1, 80 is smaller than 100 so the 
span is 1, 60 is smaller than 80 so the 
span is 1, 70 is greater than 60 so the 
span is 2 and so on. Hence the output will 
be 1 1 1 2 1 4 6.



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
