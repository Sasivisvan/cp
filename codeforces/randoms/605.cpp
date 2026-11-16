class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        if (1==flowerbed.size()){
            if(n==0 && flowerbed[0]==1)return true;
            if(n==1 && flowerbed[0]==0)return true;
            
        } 
        
        for (int i = 0; i < flowerbed.size(); i++) {
            if (count == n) {
                return true;
                
            }
            if (i == 0 && i!=flowerbed.size()-1 && flowerbed[i] == 0 && flowerbed[i + 1] == 0){
                flowerbed[i]=1;
                count++;
                
            }
            else if (i == flowerbed.size()-1 && flowerbed[i] == 0 && flowerbed[i - 1] == 0){
                flowerbed[i]=1;
                count++;
                
            }
            else if (i!=0 && i!=flowerbed.size()-1 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 &&
                flowerbed[i] == 0) {
                flowerbed[i] = 1;
                
                count++;
            }
            if (count == n) {
                return true;
                
            }
            
        }
        if (count == n) {
                return true;
                
            }
        
        return false;
    }
};