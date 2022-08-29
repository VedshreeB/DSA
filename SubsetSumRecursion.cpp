
class Solution{   
public:
    bool solve(int idx,int target,vector<int>a){
        if(target == 0)return true;
        if(idx == 0)return(a[0] == target);
        
        bool nottake = solve(idx-1,target,a);
        bool take = solve(idx-1,target-a[idx],a);
        return (take || nottake);
    }
    bool isSubsetSum(vector<int>arr, int sum){
       int n = arr.size();
       return solve(n-1,sum,arr);
    }
};
//T.C = O(2^n)
//S.C = O(n)
