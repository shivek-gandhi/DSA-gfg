class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        vector<int> freq(26,0);
        
        int left = 0;
        int distinct = 0;
        int maxLen = -1;

        for(int right = 0; right < s.size(); right++){
            
            if(freq[s[right]-'a'] == 0)
                distinct++;
            
            freq[s[right]-'a']++;

            while(distinct > k){
                freq[s[left]-'a']--;
                
                if(freq[s[left]-'a'] == 0)
                    distinct--;
                    
                left++;
            }

            if(distinct == k)
                maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};