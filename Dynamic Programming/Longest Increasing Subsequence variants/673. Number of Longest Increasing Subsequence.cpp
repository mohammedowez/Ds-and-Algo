Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
  
  class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
  
        int n=nums.size();   
        if(n == 0) return 0;       
        vector<int> length(n+1 ,1);
        vector<int> count(n +1,1);
        int maxlen = 1;
        
                
        for(int i= 1;i<n;i++)
        {
            for( int j = 0 ; j < i ; j++){
                
                if(nums[i] > nums[j]){   
                    
                    if(length[j]+1 > length[i]){ // adding one to j will improve the length    
                        length[i] = length[i]+1;  // length[i] = max (length[i],length[j]+1)  
                        count[i] = count[j];         
                    }
                    
                    //means we are ruuning a loop and some other value is also smaller than this i value 
                    // so just inc the count as they are having the same length 
                    // length is updated in the above once
                    // if same length appers again then we have to inc the count
                    else if(length[j]+1 == length[i]){ 
                         count[i] += count[j];
                    }
                }
            }       
           maxlen = max(maxlen,length[i]);
        }
       int ans = 0;
     

    for(int i = 0 ; i < n ; i++){
        if(length[i] == maxlen){
            ans+= count[i];     // How many have same max lengths
            
        }
    }
         return ans;
    }
};
