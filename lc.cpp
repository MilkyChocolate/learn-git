#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*TreeNode root(3);
TreeNode a1 (5);
TreeNode a2 (1);
TreeNode b1 (6);
TreeNode b2 (2);
TreeNode b3 (0);
TreeNode b4 (8);
TreeNode c1(7);
TreeNode c2(4);
root.left = &a1;
root.right = &a2;
a1.left = &b1;
a1.right = &b2;
a2.left = &b3;
a2.right = &b4;
b2.left = &c1;
b2.right = &c2;*/

//int integerBreak(int n) {
//    if (n == 2)return 1;
//    if (n == 3)return 2;
//    vector<int> dp(n + 1);//拆或不拆的最大值
//    dp[2] = 2;
//    dp[3] = 3;
//    for (int i = 4; i <= n; i++) {
//        for (int j = 2; j <= i - 2; j++) {
//            dp[i] = (i - j) * dp[j];
//        }
//    }
//    return dp[n];
//}

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if (duration == 0)
        return 0;
    if (duration == 1)
        return timeSeries.size();
    int res = 0;
    
    for (auto it = timeSeries.begin(); it != timeSeries.end();) {
		
        if (*it==*it + 1) {
			it = it + 1;
			continue;
        }
        auto lower = lower_bound(it, timeSeries.end(), (*it + duration-1));
        if (lower != timeSeries.end()) {
            /*if (*(lower - 1) == (*it + duration - 1)) {
                it = lower-1;
                res += duration-1;
            }
            else {
                it = lower;
                res += duration;
            }*/
			res += duration;
			it = lower;
        }
        else {
            if (it == timeSeries.begin() + (timeSeries.size() - 1)) {
                res += duration;
                break;
            }
            else {
                res += timeSeries[timeSeries.size() - 1] - (*it) + duration;
                break;
            }
        }
    }
    return res;
}

//class Solution {
//    int res = -2147483647;
//    vector<int> track;
//    void dfs(vector<vector<int>>& dungeon, int r, int c) {
//        if (r == dungeon.size() - 1 && c == dungeon[0].size() - 1) {
//            track.push_back(dungeon[r][c]);
//            int sum = 0, temp = 2147483647;
//            for (auto num : track) {
//                sum += num;
//                temp = min(sum, temp);
//				cout << num << " ";
//            }
//			cout << "temp=" << temp <<" ";
//            res = max(res, temp);
//			cout << "res=" << res << endl;
//            track.pop_back();
//            return;
//        }
//        if (r >= dungeon.size() || c >= dungeon[0].size())return;
//        track.push_back(dungeon[r][c]);
//        dfs(dungeon, r + 1, c);
//        dfs(dungeon, r, c + 1);
//        track.pop_back();
//    }
//public:
//    int calculateMinimumHP(vector<vector<int>>& dungeon) {
//        if (1 == dungeon.size() && 1 == dungeon[0].size())
//            return max(1, -dungeon[0][0] + 1);
//        dfs(dungeon, 0, 0);
//        return max(1, -res);
//    }
//};
int main() {
    //Solution s;
	//vector<vector<int>> dungeon = { { -2,-3,3 },{ -5,-10,1 },{ 10,30,-5 } };
	//cout << s.calculateMinimumHP(dungeon) << endl;
	vector<int> a = { 1,2,3,5,7,9,14,14};
    int duration = 2;
	cout << findPoisonedDuration(a, 4) << endl;

    return 0;
}