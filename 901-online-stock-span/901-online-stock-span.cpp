class StockSpanner {
    stack<pair<int,int>> stk;
public:
    StockSpanner() {
        while(!stk.empty()) stk.pop();
    }
    
    int next(int price) {
        int cnt=1;
        if(stk.empty()){
            stk.push({price,cnt});
        }
        else{
           while(!stk.empty() && stk.top().first <= price){
               cnt += stk.top().second;
               stk.pop();
           }
            
            stk.push({price,cnt});
        }
        return cnt;
    }
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */