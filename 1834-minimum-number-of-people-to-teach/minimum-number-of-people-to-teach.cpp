class Solution {
public:
    int minimumTeachings(int languageNumber, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<set<int>> languagesSets;
        for (auto& lang : languages) {
            set<int> s(lang.begin(), lang.end());
            languagesSets.push_back(s);
        }
        
        vector<pair<int, int>> notReachable;
        for (auto& friendship : friendships) {
            int from = friendship[0];
            int to = friendship[1];
            set<int> intersection;
            set_intersection(languagesSets[from - 1].begin(), languagesSets[from - 1].end(),
                           languagesSets[to - 1].begin(), languagesSets[to - 1].end(),
                           inserter(intersection, intersection.begin()));
            if (intersection.empty()) {
                notReachable.push_back({from - 1, to - 1});
            }
        }
        
        set<int> learnLanguage;
        int ans = INT_MAX;
        for (int language = 1; language <= languageNumber; language++) {
            learnLanguage.clear();
            int current = 0;
            for (auto& [from, to] : notReachable) {
                if (languagesSets[from].count(language) == 0 && learnLanguage.count(from) == 0) {
                    learnLanguage.insert(from);
                    current++;
                }
                if (languagesSets[to].count(language) == 0 && learnLanguage.count(to) == 0) {
                    learnLanguage.insert(to);
                    current++;
                }
            }
            ans = min(ans, current);
        }
        
        return ans;
    }
};