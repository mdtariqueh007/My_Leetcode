class Solution {
public:

    string reverse(string&s){
        string ans = s;
        int low = 0,high = s.length()-1;
        while(low<high){
            swap(ans[low],ans[high]);
            low++;
            high--;
        }

        return ans;
    }
    string invert(string&s){
        string ans = s;
        for(int i = 0;i<s.length();i++){
            if(ans[i]=='1') ans[i] = '0';
            else ans[i] = '1';
        }
        return ans;
    }

    char findKthBit(int n, int k) {
        string prev = "";
        string curr = "0";
        for(int i = 1;i<n;i++){
            string prev = curr;
            string temp = reverse(prev);
            string temp2 = invert(temp);
            curr = prev + "1" + temp2;
        }

        return curr[k-1];
    }
};