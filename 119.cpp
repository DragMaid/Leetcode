class Solution {
public:
vector<int> getRow(int rowIndex) {
    vector<int> res(1,1);
    long long prev = 1;
    for (int k=1; k<=rowIndex; k++) {
        long long next = prev * (rowIndex - k + 1) / k;
        res.push_back(next);
        prev = next;
    }
    return res;
}
};

// Proof: math stuff
// Each row: C(r, 0), C(r, 1), ..., C(r, r)
// C is the function for binomial coefficient
// Its math - sketch it on notebook 
