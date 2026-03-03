class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        
        int curXor = 0;
        for(int i=0;i<k;i++){
            curXor^=arr[i];
        }
        
        int maxXor = curXor;
        
        for(int i=k;i<n;i++){
            curXor = curXor ^ arr[i-k] ^ arr[i];
            maxXor = max(curXor,maxXor);
        }
        return maxXor;
    }    
};