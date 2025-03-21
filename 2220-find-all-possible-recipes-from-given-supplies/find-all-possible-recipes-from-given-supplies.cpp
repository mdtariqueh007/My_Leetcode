class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> adjList;

        for(int i = 0;i<ingredients.size();i++){
            string recipe = recipes[i];
            for(auto it: ingredients[i]){
                adjList[it].push_back(recipe);
                indegree[recipe]++;
            }
        }

        queue<string> q(supplies.begin(), supplies.end());

        vector<string> ans;

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            for(auto it: adjList[curr]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }

        return ans;

    }
};