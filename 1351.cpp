class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int cr = grid[0].size();
        for(auto row: grid){
            for (; cr>0 && row[cr-1]<0;cr--);
            count=count+grid[0].size()-cr;
        }
        return count;
    }
};