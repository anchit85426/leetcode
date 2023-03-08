class Solution {
    class ST{
public:	vector<int>seg,lazy;
public:
	ST(int n){
		seg.resize(4*n);
		lazy.resize(4*n);
	}
public:
	void build(int ind,int low,int high,vector<int>&arr){
		if(low==high){
			seg[ind]=arr[low];
			return ;
		}
		int mid=(low+high)>>1;
		build(2*ind+1,low,mid,arr);
		build(2*ind+2,mid+1,high,arr);
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];

	}
public:
	void update(int ind,int low,int high,int l,int r){
		//update the previous remaingn updates
		// and propagate downwards
		if(lazy[ind]!=0){
			seg[ind]=(high-low+1)-seg[ind];
			// propogate the lazy update downwards
			//for the reamingin nodes ot get updates
			if(low!=high){
				lazy[2*ind+1]=!lazy[2*ind+1];
				lazy[2*ind+2]=!lazy[2*ind+2];
			}
			lazy[ind]=0;
		}
		// no overlap
		// we dont do anything and return 
		if(high<l or r<low){
			return;
		}
		// complete overlap 
		if(low>=l and high<=r ){
			seg[ind]=(high-low+1)-seg[ind];
			if(low!=high){
				lazy[2*ind+1]=!lazy[2*ind+1];
				lazy[2*ind+2]=!lazy[2*ind+2];
			}
			return;
		}
		// patially overlap
		int mid=(low+high)>>1;
		update(2*ind+1,low,mid,l,r);
		update(2*ind+2,mid+1,high,l,r);
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}
public:
	int query(int ind,int low,int high,int l ,int r){
		// update of any updates are remaining
		// as the node will stay fresh and updated
		if(lazy[ind]!=0){
			seg[ind]=(high-low+1)*lazy[ind];
			// propogate the lazy update downwards
			//for the reamingin nodes ot get updates
			if(low!=high){
				lazy[2*ind+1]=lazy[ind];
				lazy[2*ind+2]=lazy[ind];
			}
			lazy[ind]=0;
		}


		// no overlap return 0
		if(high<l or r<low){
			return 0;
		}

		// complete overlap
		if(low>=l and high<=r) return seg[ind];
		int mid=(low+high)>>1;
		int left=query(2*ind+1,low,mid,l,r);
		int right=query(2*ind+1,mid+1,high,l,r);
		return left+right;
	}


};
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n=nums1.size();
        ST st(n);
        st.build(0,0,n-1,nums1);
        long long int sum=0;
        for(auto it:nums2){sum+=it;}
        vector<long long >ans;
       
        for(auto it:queries){
            if(it[0]==1){
                // update
                
                st.update(0,0,n-1,it[1],it[2]);
                
            }
            else if(it[0]==2){
               
                sum+=(long long )st.seg[0]*it[1];
            }
            else{
                ans.push_back(sum);
            }
        }
        return ans;
    }
};