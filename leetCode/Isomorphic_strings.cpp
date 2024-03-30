class Solution {
public:
    bool isIsomorphic(string s, string t) {

        bool ret = true;
        map<char, char> mp;
        map<char, char> mp2;

        for(int i=0; i< s.size(); i++)
        {
            if(mp.find(s[i]) == mp.end())
            {
                mp[s[i]] = t[i];
            }
            else
            {
                int ch = mp[s[i]];
                if(ch != t[i]) 
                {
                    ret = false;
                    break;
                }
            }

            if(mp2.find(t[i]) == mp2.end())
            {
                mp2[t[i]] = s[i];
            }
            else
            {
                int ch = mp2[t[i]];
                if (ch != s[i])
                {
                    ret = false;
                    break;
                }
            }




        }
            return ret;
    }
};