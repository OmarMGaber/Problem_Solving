https://leetcode.com/submissions/detail/1058656259/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> kidsCandies(len, 1); // all kids must have at least 1 candy.
        for(int i = 1; i < len; i++)
            if (ratings[i] > ratings[i - 1])
                kidsCandies[i] = kidsCandies[i - 1] + 1;
        
        for(int i = len - 1; i > 0; i--)
            if (ratings[i] < ratings[i - 1])
                kidsCandies[i - 1] = max(kidsCandies[i - 1], kidsCandies[i] + 1);
        
        return accumulate(kidsCandies.begin(), kidsCandies.end(), 0);
    }
};