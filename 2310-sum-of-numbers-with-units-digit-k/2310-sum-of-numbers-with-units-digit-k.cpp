class Solution {
public:
    int minimumNumbers(int num, int k) {
        //set cannot contain 0
        if(num == 0)return 0;
        
        //set doesn't exist
        if(num < k) return -1;
        
        int un = num%10;
        for(int x=1 ; x<=10 ; x++){
            int res = (x*k)%10;
            if(res == un){
                if(x*k > num)
                {
                    return -1;
                }
                return x;
            }
        }
        return -1;
    }
};