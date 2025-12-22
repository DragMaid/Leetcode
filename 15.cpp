class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());
    if (nums.size() < 3) return {};
    if (nums[0] > 0) return {};
    
    unordered_map<int, int> hm;
    for (int i=0; i<nums.size(); i++)
        hm[nums[i]] = i;

    for (int i=0; i<nums.size()-2; i++) {
        if (nums[i] > 0) break;
        for (int j=i+1; j<nums.size()-1; j++) {
            int required = -1 * (nums[i] + nums[j]);
            auto search = hm.find(required);
            // Only valid if the index is > j (not equals to j)
            if (search != hm.end() &&  search->second > j)
                ans.push_back({nums[i], nums[j], required});
            // Move j to last occurence of its value;
            j = hm.find(nums[j])->second;
        }
        i = hm.find(nums[i])->second;
    }
    return ans;
}
};

// Duplicants are adjacent
//vector<vector<int>> threeSum(vector<int>& nums) {
    //vector<vector<int>> ans;
    //sort(nums.begin(), nums.end());

    //if (nums.size() < 3) return {};
    //if (nums[0] > 0) return {};

    //for (int i=0; i<nums.size(); i++) {
        //// If the first number is positive -> not finding neg
        //if (nums[i] > 0) break;
        //// If number is getting repeated -> ignore lower loop
        //// The answer that involves itself (if exists) will
        //// already be covered at position i-1
        //// Doing this for i would only lead to duplicates
        //if (i > 0 && nums[i] == nums[i-1]) continue;
        //int sum = 0;
        //int low = i+1;
        //int high = nums.size()-1;
        //while (low < high) { 
            //sum = nums[i] + nums[low] + nums[high];
            //if (sum > 0) high--;
            //else if (sum < 0) low++;
            //else {
                //ans.push_back({nums[i], nums[low], nums[high]});
                //int last_l = nums[low];
                //int last_h = nums[high];

                //// To avoid duplicates
                //// If they are already covered then move the pointers
                //// so they point to a different value
                //while (low < high && nums[low] == last_l) low++;
                //while (low < high && nums[high] == last_h) high--;
            //}
        //}
    //}
    //return ans;
//}
