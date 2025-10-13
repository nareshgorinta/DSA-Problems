class Solution {
public:
    bool areAnagrams(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    int count[26] = {0};

    for (char c : s1)
        count[c - 'a']++;

    for (char c : s2)
        count[c - 'a']--;

    for (int i = 0; i < 26; i++)
        if (count[i] != 0)
            return false;

    return true;
    }


    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        if(words.size() == 1){
            return words;
        }
        int i=0;
        int j=1;
        while(j != words.size()){
            if(areAnagrams(words[i],words[j])){
                j++;
            }else{
                ans.push_back(words[i]);
                i=j;
                j++;
            }
        }
        ans.push_back(words[i]);
        return ans;
        
    }
};