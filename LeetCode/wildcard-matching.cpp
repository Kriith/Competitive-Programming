class Solution {
    public:
        bool isMatch(string s, string p) {
            if(s == p || (s.size() == 0 && p.size() == 0)) return true;
            else if(p.size() == 0) return false;
            else if(s.size() == 0){
                for(int i = 0; i < p.size(); i++)
                    if(p[i] != '*') return false;
                return true;
            }
            string ss = "", pp = "";
            if(p[0] == '?' || s[0] == p[0]){ ss = s.substr(1); pp = p.substr(1); }
            else if(p[0] == '*'){
                if(p.size() == 1) return true;
                else if(p[1] == s[0]){ ss = s.substr(1); pp = p.substr(2); }
                else{ ss = s.substr(1); pp = p; }
            }
            else if(s[0] != p[0]) return false;
            return isMatch(ss, pp);
        }
    };