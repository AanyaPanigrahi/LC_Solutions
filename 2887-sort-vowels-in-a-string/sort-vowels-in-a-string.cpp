class Solution {
public:
    string sortVowels(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                lower[s[i] - 'a']++;
                s[i]='#';
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
                s[i] == 'U') {
                upper[s[i] - 'A']++;
                s[i]='#';
            }
        }

        string temp;
        for (int i = 0; i < 26; i++) {
            char c = i + 'A';
            while (upper[i]) {
                temp += c;
                upper[i]--;
            }
        }
        for (int i = 0; i < 26; i++) {
            char c = i + 'a';
            while (lower[i]) {
                temp += c;
                lower[i]--;
            }
        }
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                s[i]=temp[j];
                j++;
            }
        }

    return s;
}

}
;