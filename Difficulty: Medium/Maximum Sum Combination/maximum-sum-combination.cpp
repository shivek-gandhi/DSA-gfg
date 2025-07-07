class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size();
        vector <int> ans;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        priority_queue<pair<int,pair<int,int>>>pq;
        set <pair<int,int>> s;
        pq.push({a.back()+b.back(),{n-1,n-1}});
        s.insert({n-1,n-1});
        while(k--){
            auto p = pq.top();
            int sum = p.first;
            int i=p.second.first;
            int j = p.second.second;
            ans.push_back(sum);
            pq.pop();
            
            if(s.find({i-1,j})==s.end()){
                pq.push({a[i-1]+b[j],{i-1,j}});
                s.insert({i-1,j});
            }
            if(s.find({i,j-1})==s.end()){
                pq.push({a[i]+b[j-1],{i,j-1}});
                s.insert({i,j-1});
            }
        }
        return ans;
    }
};