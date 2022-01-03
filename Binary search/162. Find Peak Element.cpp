Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
  
  class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        
    
    
        int start=0;
        int end=arr.size()-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(arr[mid]>arr[mid+1]){
                //we are in the decimal part of the array,this may be the answer
                //but we have to look at left too this is why end!=mid-1
                end=mid;
                
            }
            else{
                //you are in the ascending part of the array
                start=mid+1;//because we know that mid+1 element is greater than mid
            }
        }
     //in the end,start==end and pointing to the largest number because of the 2 checks
        //start and end are always trying to find element in the above 2 checks
        //hence when they are just pointing to just one element,that is the max one becaus ethat is
        //what the check say
        //at every point of start and end,they have the best possible answer till  that time
        // and if we are saying that only item is remaining ,hence cuz of above line
        return end;
    }//or return as both are =
    

};
