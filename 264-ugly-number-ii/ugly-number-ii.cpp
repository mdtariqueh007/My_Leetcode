class Solution {
public:
    int nthUglyNumber(int n) {

        int i2, i3 ,i5;
        i2 = i3 = i5 = 1;

        vector<int> arr(n+1);

        arr[1] = 1;

        for(int i = 2;i<=n;i++){
            int i2UglyNum = arr[i2] * 2;
            int i3UglyNum = arr[i3] * 3;
            int i5UglyNum = arr[i5] * 5;

            int minUglyNum = min(i2UglyNum,min(i3UglyNum,i5UglyNum));

            arr[i] = minUglyNum;

            if(i2UglyNum==minUglyNum){
                i2++;
            }
            if(i3UglyNum==minUglyNum){
                i3++;
            }
            if(i5UglyNum==minUglyNum){
                i5++;
            }

        }

        return arr[n];
        
    }
};