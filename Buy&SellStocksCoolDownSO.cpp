class Solution {
public:
    int maxProfit(vector<int>& Arr) {

    int n = Arr.size();
   
    vector<int> next(2,0); 
    vector<int> nnext(2,0); 
    vector<int> cur(2,0);

    for(int ind = n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            int profit;
            
            if(buy==0){// We can buy the stock
                profit = max(0+next[0], -Arr[ind] +next[1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+next[1], Arr[ind] + nnext[0]);
            }
            
            cur[buy] = profit;

            
        }
        nnext = next;
        next = cur;
    }
    
    return next[0];

    }
};
