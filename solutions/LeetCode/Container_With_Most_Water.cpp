// https://leetcode.com/problems/container-with-most-water/submissions/1049754129/

class Solution {
public:
    int calculateArea(int &length, int &height){
        return length * height;
    }

    int maxArea(vector<int>& height) {
        int len = height.size() - 1, left = 0, right = len;
        int maxArea = calculateArea(len, min(height[left], height[right]));

        while(left < right){
            if(height[left] <= height[right]) left++;
            else right--;
            maxArea = max(maxArea, calculateArea(--len, min(height[left], height[right])));
        }

        return maxArea;
    }
};