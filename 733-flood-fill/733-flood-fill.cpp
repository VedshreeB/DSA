class Solution {
public:
    bool isValid(vector<vector<int>>& image, int i, int j, int n,int m,int color,int val){
        if(i<0 || j<0 || i>=n|| j>=m|| image[i][j] != val)
            return false;
        return true;
    }
    void floodFillRec(vector<vector<int>>& image, int i, int j,int n,int m, int color,int val){                
        image[i][j] = color;
        
        if(isValid(image,i-1,j,n,m,color,val))
            floodFillRec(image,i-1,j,n,m,color,val);
        
        if(isValid(image,i+1,j,n,m,color,val))
            floodFillRec(image,i+1,j,n,m,color,val);
        if(isValid(image,i,j-1,n,m,color,val))
            floodFillRec(image,i,j-1,n,m,color,val);
        if(isValid(image,i,j+1,n,m,color,val))
            floodFillRec(image,i,j+1,n,m,color,val);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int val = image[sr][sc];
        
        if(val == color) return image;
        
        floodFillRec(image,sr,sc,n,m,color,val);
        
        return image;
    }
};