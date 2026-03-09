class Solution {
  public:
    
    string largestSwap(string &s) {
        // code here
        vector<int> freq(10);
        for(int i=0; i<s.length();i++){
            freq[s[i]-'0'] = i;
        }
        
        for(int i=0;i< s.length();i++){
            for(int j = 9;(int)(s[i]-'0') < j;j--){
                if(freq[j]> i){
                    swap(s[i],s[freq[j]]);
                    return s;
                }
            }
        }
        return s;
    }
};