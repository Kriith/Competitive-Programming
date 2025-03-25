class Solution {
    public: 
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            set<string> st(wordList.begin(), wordList.end());
            if(st.find(endWord) == st.end())
                return 0;
            queue<string> q;
            map<string, bool> marked;
            for(auto i : st) marked[i] = 0;
            q.push(beginWord);
            int d = 1;
            while(!q.empty()){
                int sz = q.size();
                while(sz--){
                    string s = q.front();
                    marked[s] = 1;
                    for(int i = 0; i < s.size(); i++){
                        char t = s[i];
                        for(char c = 'a'; c <= 'z'; c++){
                            s[i] = c;
                            if(s == endWord) return d + 1;
                            if(st.find(s) != st.end() && !marked[s]){
                                marked[s] = 1;
                                q.push(s);
                            }
                        }
                        s[i] = t;
                    }
                    q.pop();
                }
                d++;
            }
            return 0;
        }
    };