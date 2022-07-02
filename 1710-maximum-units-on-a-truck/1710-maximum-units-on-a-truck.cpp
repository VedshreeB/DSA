class Solution {
public:
    static bool comp(vector<int> a,vector<int> b){
        if(a[1] > b[1]) return true;
        return false;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
    
        int n = boxTypes.size();
        int i=0,ans = 0;
        while(i<n && truckSize>0){
            if(truckSize >= boxTypes[i][0]){
                truckSize -= boxTypes[i][0];
                ans += boxTypes[i][0] *boxTypes[i][1];
            }
            else{
                ans += truckSize*boxTypes[i][1];
                truckSize = 0;
            }
            i++;
        }
        return ans;
    }
};