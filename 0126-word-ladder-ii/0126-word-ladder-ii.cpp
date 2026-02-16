class Solution {
public:
    
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void backtrack(string word, string beginWord, vector<string>& path) {
        
        if(word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        
        for(auto &p : parent[word]) {
            path.push_back(p);
            backtrack(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return {};
        
        queue<string> q;
        q.push(beginWord);
        
        bool found = false;
        
        while(!q.empty() && !found) {
            
            int size = q.size();
            unordered_set<string> levelVisited;
            
            for(int i = 0; i < size; i++) {
                
                string word = q.front();
                q.pop();
                
                string originalWord = word;
                
                for(int j = 0; j < word.size(); j++) {
                    
                    char originalChar = word[j];
                    
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        
                        word[j] = ch;
                        
                        if(st.find(word) != st.end()) {
                            
                            if(word == endWord)
                                found = true;
                            
                            if(!levelVisited.count(word)) {
                                q.push(word);
                                levelVisited.insert(word);
                            }
                            
                            parent[word].push_back(originalWord);
                        }
                    }
                    
                    word[j] = originalChar;
                }
            }
            
            for(auto &w : levelVisited)
                st.erase(w);
        }
        
        if(!found) return {};
        
        vector<string> path;
        path.push_back(endWord);
        backtrack(endWord, beginWord, path);
        
        return ans;
    }
};
