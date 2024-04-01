class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        int s_arr[26] = {0,};
        int p_arr[26] = {0,};

        for(int i=0; i<p.size(); i++)
        {
            p_arr[p[i] - 'a'] +=1;
        }

        for(int i=0; i<= static_cast<int>(s.size() - p.size()); i++)
        {
            if(i == 0 )
            {
                for(int j=0; j<p.size(); j++)
                {
                    s_arr[s[j] -'a'] +=1;
                }
            }
            else
            {
                s_arr[s[i-1] - 'a'] -=1;
                s_arr[s[i + p.size() - 1] -'a'] +=1;
            }

            bool ret = true;
            for(int k=0; k<26; k++)
            {
                if(s_arr[k] != p_arr[k])
                {
                    ret = false;
                }
            }

            if(ret == true) 
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};