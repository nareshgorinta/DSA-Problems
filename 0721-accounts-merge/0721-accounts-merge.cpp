class Solution {
public:
    unordered_map<string,string> parent;

    string find(string x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(string a, string b){
        string pa = find(a);
        string pb = find(b);
        if(pa != pb){
            parent[pb] = pa;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> emailToName;

        // Step 1: initialize parent and union emails inside same account
        for(auto &acc : accounts){
            string name = acc[0];

            for(int i=1;i<acc.size();i++){
                string email = acc[i];

                if(!parent.count(email)) parent[email] = email;
                emailToName[email] = name;

                if(i > 1){
                    unite(acc[1], email);   // union with first email
                }
            }
        }

        // Step 2: group emails by root
        unordered_map<string, vector<string>> groups;
        for(auto &it : parent){
            string email = it.first;
            string root = find(email);
            groups[root].push_back(email);
        }

        // Step 3: build answer
        vector<vector<string>> ans;
        for(auto &it : groups){
            auto &emails = it.second;
            sort(emails.begin(), emails.end());

            vector<string> temp;
            temp.push_back(emailToName[it.first]);  // name
            temp.insert(temp.end(), emails.begin(), emails.end());

            ans.push_back(temp);
        }

        return ans;
    }
};