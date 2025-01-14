class Solution {
public:
    string sortSentence(string s) {
        vector<string> positions(10);
        string temp;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                int pos = temp[temp.size() - 1] - '0';
                temp.pop_back();
                positions[pos] = temp;
                temp = "";
                count++;
            } else {
                temp += s[i];
            }
        }

        int pos = temp[temp.size() - 1] - '0';
        temp.pop_back();
        positions[pos] = temp;
        count++;
        temp.clear();

        for (int i = 1; i <= count; i++) {
            temp += positions[i];
            temp += " ";
        }
        temp.pop_back();
        return temp;
    }
};