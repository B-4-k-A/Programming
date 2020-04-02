class Solution {
public:
    bool isHappy(int n) {
        int j;
        int sum = 0;
        while(n != 1 && n!= 4) {
            while(n > 0) {
               j = n % 10;
               sum += pow(j, 2);
               n /= 10;
            }
            n = sum;
            sum = 0;
        }
        if(n == 1)
            return true;
        else 
            return false;
    }
};