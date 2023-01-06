class Solution {
    private:
      static bool sortbysec(const vector<int> &a,
              const vector<int> &b)
    {
            return (a[1] < b[1]);
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),sortbysec);
        int ans=1;
        int max=points[0][1];
        for(auto it :points){
            if(it[0]>max){
                ans+=1;
                max=it[1];
                }
        }
        return ans;
    }
};