Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6


vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) 
{
            
  queue<long long > q;
      vector<long long> v;
      long long  j=0;
      
      for(long long  i=0;i<K;i++)
      {
          if(A[i]<0)
            q.push(A[i]);
      } 
      
     if(q.size()==0)
        v.push_back(0);
    else
        v.push_back(q.front());
        
        
        for(long long i=K;i<N;i++)
        {
            if(q.front()==A[j])
            {
                q.pop();
            } 
            
            j++;
            
            if(A[i]<0)
                q.push(A[i]);
            
            if(q.size()==0)
                v.push_back(0);
            else 
                v.push_back(q.front());
        }
        
                
        return v;    
            
        
    

 }
