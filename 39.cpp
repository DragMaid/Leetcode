class Solution {
public:
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    unordered_map<int, vector<vector<int>>> cache;
    findCombinations(cache, candidates, target);
    return cache[target];
}
private:
void findCombinations(unordered_map<int, vector<vector<int>>>& cache, vector<int>& candidates, int target) {
    unordered_set<int> used;
    for (int c : candidates) {
        if (c > target) break;

        if (auto it=used.find(c); it != used.end()) continue;

        if (target - c == 0) cache[target].push_back({c});

        if (auto search = cache.find(c); search == cache.end())
            findCombinations(cache, candidates, c);
        if (auto search = cache.find(target-c); search == cache.end())
            findCombinations(cache, candidates, target-c);

        // Fix it so it doesn't find 0, since target and cis never 0
        auto search = cache.find(target-c); // This is the only thing that can possibly be 0
        auto search2 = cache.find(c);
        if (target-c != 0 && search != cache.end() && search2 != cache.end()) {
            for (vector<int> v : search->second) {
                for (vector<int> v2 : search2->second) {
                    v.insert(v.end(), v2.begin(), v2.end());
                    sort(v.begin(), v.end());
                    auto& vecs = cache[target];
                    if (find(vecs.begin(), vecs.end(), v) == vecs.end()) {
                        vecs.push_back(v);
                    }
                }
            }
            used.insert(c);
            used.insert(target-c);
        }
    }
}  
};

// The solution would be to save a cache how to do smaller components
