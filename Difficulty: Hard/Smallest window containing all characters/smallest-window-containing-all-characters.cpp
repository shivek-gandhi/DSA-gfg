class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        vector<int> cnt(128, 0);
        int req = p.length();
        int left = -1;
        int minLen = s.length() + 1;

        for(char c : p) {
            cnt[c]++;
        }

        int l = 0;
        for(int r = 0; r < s.length(); r++) {
            if(--cnt[s[r]] >= 0)
                req--;

            while(req == 0) {
                if(r - l + 1 < minLen) {
                    left = l;
                    minLen = r - l + 1;
                }

                if(++cnt[s[l++]] > 0)
                    req++;
            }
        }

        if(left == -1) return "";
        return s.substr(left, minLen);
    }
};