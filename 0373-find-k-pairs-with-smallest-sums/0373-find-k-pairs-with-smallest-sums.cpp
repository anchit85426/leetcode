class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto comp=[&nums1,&nums2](pair<int,int>a,pair<int,int>b){
            return nums1[a.first]+nums2[a.second]>nums1[b.first]+nums2[b.second];
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>pq(comp);
        int n=nums1.size();
        pq.push({0,0});
        vector<vector<int>>res;
        while(k-- and !pq.empty()){
            int i=pq.top().first;
            int j=pq.top().second;
            pq.pop();
            vector<int>v={nums1[i],nums2[j]};
            res.push_back(v);
            if(i+1<nums1.size()){
                pq.push({i+1,j});
            }
            if(i==0 and j+1<nums2.size()){
                pq.push({i,j+1});
            }
        }
        return res;
    }
};