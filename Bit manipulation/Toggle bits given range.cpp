Input:
N = 17 , L = 2 , R = 3
Output:
23
Explanation:
(17)10 = (10001)2.  After toggling all
the bits from 2nd to 3rd position we get
(10111)2 = (23)10
  
  
  int toggleBits(int N , int L , int R) {
        // code here
        
        for(int i=L-1;i<R;i++)
        {
            N=N^(1<<i);
        } 
        
        return N;
        
    }
