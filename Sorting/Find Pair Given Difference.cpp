Input:
L = 6, N = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.

bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    int i = 0;  
    int j = 1;
 
    while (i<size && j<size)
    {
        if (i != j && arr[j]-arr[i] == n)
        {
            return true;
        }
        else if (arr[j]-arr[i] < n)
            j++;
        else
            i++;
    }
 
    return false;
}
