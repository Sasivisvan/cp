class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        bool zero =false;
        long long min=1000000;
        bool even = true;

        for(int i=0; i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)zero = true;
                if(abs(matrix[i][j])<abs(min))min = matrix[i][j];
                if(matrix[i][j]<0)even=!even;
                sum = sum + abs(matrix[i][j]);
            }
        }
        if(even||zero)return sum;
        // cout<<sum<<" :sum";
        return sum - abs(2*min);
    }
};