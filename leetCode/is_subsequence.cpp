class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int s_idx = 0;
        int t_idx = 0;

        while(t_idx < t.size() )
        {
            if(s_idx >= s.size()) break;

            if(t[t_idx] == s[s_idx])
            {
                t_idx++;
                s_idx++;
            }
            else
            {
                t_idx++;
            }
        }

        if(s_idx == s.size()) return true;
        else return false;

    }
};