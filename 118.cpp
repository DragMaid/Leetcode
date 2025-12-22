class Solution {
public:
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> v;     // Full vector container
    for (int i=0; i<numRows; i++) {
        vector<int> vm{1}; // Mini vector to insert
        for (int j=0; j<i-1; j++) {
          vm.push_back(v[i-1][j]+v[i-1][j+1]);
        }
        if (i > 0) vm.push_back(1);
        v.push_back(vm);
    }
    return v;
}
};
