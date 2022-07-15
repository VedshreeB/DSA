class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int arr[1000]= {0};
        
        for(int i=0; i<trips.size(); i++){
            int passengers = trips[i][0];
            if(capacity<passengers)return false;
            
            for(int j=trips[i][1] ; j<trips[i][2]; j++){
                arr[j] += passengers;
                if(arr[j] > capacity) return false;
            }
        }
        return true;      
    }
};