Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        
        // time Complexity is O(N)
        // space Complexity is O(1)
        
        
        stack<int> st;
        for(int i=0;i<n;i++)
            st.push(i);
        
        
        while(st.size()>=2)
        {
            int i=st.top();
                st.pop();
            int j=st.top();
                st.pop();
            
            if(M[i][j]==1)
            {
                st.push(j);
            } 
            else 
                st.push(i);
        } 
        
        int pot=st.top();
        st.pop();
        
       
        for( int i=0;i<n;i++)
        {
            
            if(i!=pot and (M[i][pot]==0 or M[pot][i]==1))
                return -1;
        } 
        
        return pot;
        
        
    }
};
