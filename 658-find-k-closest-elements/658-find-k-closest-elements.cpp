class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       //solution 1
           stable_sort(begin(arr),end(arr),[x](const auto a,const auto b){
               return (abs(x-a) < abs(x-b));
           });
            
            arr.resize(k);
            sort(begin(arr),end(arr));
            return arr;           
    }
};