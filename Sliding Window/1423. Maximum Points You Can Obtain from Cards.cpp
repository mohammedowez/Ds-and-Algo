Another Name is = pick from both sides
Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score.
  The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

  
  
  
  class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        if(k<1 or cardPoints.size()<1)
            return 0;
        
        int total_sum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        
        if(k==cardPoints.size())
            return total_sum;
        
        int i=0,j=0;
        int maxi=0;
        int curr_sum=0;
        int n=cardPoints.size();
        while(i<n)
        {
            curr_sum=curr_sum+cardPoints[i];
            if(i-j+1==n-k)
            {
                maxi=max(total_sum-curr_sum,maxi);
                curr_sum-=cardPoints[j];
                j++;
            }
            i++;
            
        }
        return maxi;
        
    }
};
