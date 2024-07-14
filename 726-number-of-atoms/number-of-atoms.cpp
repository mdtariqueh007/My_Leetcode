class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();

        stack<unordered_map<string,int>> st;
        st.push(unordered_map<string,int>());

        int i = 0;

        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string,int>());
                i++;
            }
            else if(formula[i]==')'){
                unordered_map<string,int> curr = st.top();
                st.pop();
                i++;

                string multiplier;
                while(i<n && isdigit(formula[i])){
                    multiplier.push_back(formula[i]);
                    i++;
                }

                if(!multiplier.empty()){
                    int mul = stoi(multiplier);

                    for(auto &it : curr){
                        it.second *= mul;
                    }
                }

                for(auto &it  :curr){
                    st.top()[it.first] += it.second;
                }
            }
            else{
                string currAtom;

                currAtom += formula[i];
                i++;

                while(i<n && isalpha(formula[i]) && islower(formula[i])){
                    currAtom += formula[i];
                    i++;
                }

                string currCount;
                while(i<n && isdigit(formula[i])){
                    currCount += formula[i];
                    i++;
                }

                int count = currCount.empty()?1:stoi(currCount);

                st.top()[currAtom] += count;
            }
        }

        map<string,int> mp(st.top().begin(),st.top().end());

        string res;

        for(auto it : mp){
            res += it.first;

            if(it.second>1){
                res += to_string(it.second);
            }
        }

        return res;


    }
};