Example 1:

Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
  
  
  class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int res=0;
        
        for(int i=0;i<32;i++)
        {
            bool a1=false,b1=false,c1=false;
            
            if(a & (1<<i))
                a1=true;
            if(b & (1<<i))
                b1=true;
            if(c & (1<<i))
                c1=true;
            
            if(c1==false)
            {
                if(a1==true and b1==true)
                   res=res+2;
                else if(a1==true or b1==true)
                    res++;
            } 
            else 
            {
                if(a1==false and b1==false)
                    res++;
            }
             
        } 
        
        return res;
    }
};
