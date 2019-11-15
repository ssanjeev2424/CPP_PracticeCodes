#include <bits/stdc++.h>
using namespace std;

class HouseRobber {
private:
    int dp[1001][2][2], len;
public:
    int rob(vector<int>& nums) { 
        len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        
        for(int i=0; i<len; i++)
            dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -1;
        
        int ans = max(solve(nums,1,0,0), nums[0] + solve(nums,1,1,1));
        return ans;
    }
    
    int solve(vector<int>& nums, int idx, int prev, int first) {
        if(idx == len-1) {
            if(!prev && !first) return nums[idx];
            return 0;
        }
        
        if(dp[idx][prev][first] != -1) 
return dp[idx][prev][first];
        
        if(prev) 
return dp[idx][prev][first] = solve(nums, idx+1, 0, first);
        
        int ans1 = nums[idx] + solve(nums, idx+1, 1, first);
        int ans2 = solve(nums, idx+1, 0, first);
        return dp[idx][prev][first] = max(ans1, ans2);
    }
};

int main() {
	int n, x; vector<int> vec;
	cout<<"Enter size of vector: "; cin>>n; cout<<"Enter elememts:\n";
	for(int i=0; i<n; i++) {
		cin>>x; vec.push_back(x);
	}
	HouseRobber *obj = new HouseRobber();
	int ans = (*obj).rob(vec);
	cout<<"Maximum money robbed: "<<ans<<endl;
	return 0;
}
