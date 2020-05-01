struct ComparByFirst{
  constexpr bool operator()(pair<int, int> const& a, pair<int, int> const& b) const noexcept{
      return a.second > b.second;
  }
};



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
        vector<int> result;
        unordered_map<int, int> feq;
        for(int num: nums ){
            if(feq.find(num) == feq.end())
                feq[num] = 0;
            feq[num] += 1;
        }
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparByFirst > pq;
        for(auto f: feq){
            //cout<< pq.top().first <<" "<< pq.top().second<<endl;
            if(pq.size() < k)
                pq.push(f);
            else if(pq.top().second < f.second){
                pq.pop();
                pq.push(f);
                
            }
        }
    
        while(!pq.empty()){
            cout<< pq.top().first <<" "<< pq.top().second<<endl;
            result.emplace_back(pq.top().first);
            pq.pop();
            
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
