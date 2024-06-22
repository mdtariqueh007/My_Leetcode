class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int z = x + y;

        if(z<target){
            return false;
        }
        if(z==target){
            return true;
        }

        if(x%2==0 && y%2==0 && z%2==1){
            return false;
        }

        queue<pair<int,int>> q;
        set<pair<int,int>> visited;

        q.push({0,0});
        // visited.insert({0,0});

        while(!q.empty()){
            int val1 = q.front().first;
            int val2 = q.front().second;
            
            q.pop();

            if(visited.find({val1,val2})!=visited.end()){
                continue;
            }

            if(val1+val2==target){
                return true;
            }

            visited.insert({val1,val2});

            q.push({x,val2});
            q.push({val1,y});
            q.push({0,val2});
            q.push({val1,0});
            q.push({val1 - min(val1,y-val2),val2 + min(val1,y-val2)});
            q.push({val1 + min(val2,x - val1),val2 - min(val2,x - val1)});
        }

        return false;


    }
};