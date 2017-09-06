class Solution {
public:
    //v1
    void rotate(vector<vector<int>>& matrix) {
        if(matrix .size() == 0) return;
        int n = matrix.size();
        vector<vector<int>>res(n,vector<int>(n,0));
        for(int i=0,j2=n-1; i< n&&j2>-1; ++i,--j2){
            for(int j=0,i2=0; j<n && i2<n; ++j,++i2){
                res[i2][j2] = matrix[i][j];
            }
        }
        matrix = res;
    }
    // v2
    void rotate(vector<vector<int>>& matrix) {
        if(matrix .size() == 0) return;
        int n = matrix.size();
        reverse(matrix.begin(),matrix.end());
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }

};