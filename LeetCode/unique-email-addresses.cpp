class Solution {
    public:
        int numUniqueEmails(vector<string>& emails) {
            set<string> res;
            for(int i = 0; i < emails.size(); i++){
                string s = "";
                bool flg1 = 0, flg2 = 0;
                for(int j = 0; j < emails[i].size(); j++){
                    if(flg1){ s.push_back(emails[i][j]); continue; }
                    else if(emails[i][j] == '@'){
                        s.push_back(emails[i][j]); 
                        flg1 = 1;
                        continue;
                    }
                    else if(emails[i][j] == '+') flg2 = 1;
                    if(flg2) continue;
                    else if(emails[i][j] == '.') continue;
                    else s.push_back(emails[i][j]);
                }
                res.insert(s);
            }
            return res.size();
        }
    };