class Solution {
    private:
    long long convertToPal(long long &num){
        string s = to_string(num);

        int n = s.length();

        int left = (n - 1)/2;
        int right = n/2;

        while(left>=0){
            s[right] = s[left];
            left--;
            right++;
        }

        return stoll(s);
    }
    long long findSmaller(long long num){
        long long low = 0;
        long long high = num;

        long long res = INT_MIN;

        while(low<=high){
            long long mid = low + (high - low)/2;
            long long pal = convertToPal(mid);

            if(pal<num){
                res = pal;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return res;
    }

    long long findGreater(long long num){
        long long low = num;
        long long high = 1e18;

        long long ans = INT_MIN;

        while(low<=high){
            long long mid = low + (high - low)/2;
            long long pal = convertToPal(mid);

            if(pal>num){
                ans = pal;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
public:
    string nearestPalindromic(string n) {
        int len = n.size();

        long long num = stoll(n);

        long long a = findSmaller(num);
        long long b = findGreater(num);

        if(abs(a - num)<=abs(b - num)){
            return to_string(a);
        }
        else{
            return to_string(b);
        }
    }
};