class Solution {
public:
    int lengthOfLastWord(string str) {
     
        int count = 0;
        bool flag = false;
        for (int i = str.length() - 1; i >= 0; i--) {
            
            if ((str[i] >= 'a' && str[i] <= 'z')
                || (str[i] >= 'A' && str[i] <= 'Z')) {
                flag = true;
                count++;
            }
            
            else {
                if (flag == true)
                    return count;
            }
        }
        return count;

    }
};