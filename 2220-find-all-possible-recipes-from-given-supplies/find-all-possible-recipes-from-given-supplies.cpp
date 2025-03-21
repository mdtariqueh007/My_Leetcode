class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_set<string> has(supplies.begin(), supplies.end());

        unordered_set<string> ansSet;

        bool progress = true;

        while(progress){
            progress = false;
            for(int i = 0;i<recipes.size();i++){
                if(ansSet.find(recipes[i])!=ansSet.end()){
                    continue;
                }
                bool hasAll = true;
                for(int j = 0;j<ingredients[i].size();j++){
                    if(has.find(ingredients[i][j])==has.end()){
                        hasAll = false;
                        break;
                    }
                }

                if(hasAll){
                    has.insert(recipes[i]);
                    ansSet.insert(recipes[i]);
                    progress = true;
                }
            }
        }

        
        return vector<string>(ansSet.begin(), ansSet.end());



    }
};