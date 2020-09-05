// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row = 0, col = 0, index = 41;
        while(index > 40) {
            row = 7*(rand7()-1);
            col = rand7();
            index = col + row;
        }
        return (index-1)%10+1;
    }
};
