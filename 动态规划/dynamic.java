package 动态规划;

public class dynamic {

    //62.一个机器人位于一个 m x n?网格的左上角 （起始点在下图中标记为 “Start” ）。

//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

//问总共有多少条不同的路径？
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for (int i = 0; i < n; i++) dp[0][i] = 1;
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
}

//103.给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回? - 1。

//你可以认为每种硬币的数量是无限的

    public int coinChange(int[] coins, int amount) {
        int[] p = new int[amount + 1];
        Arrays.fill(p, amount + 1);
        p[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (i - coins[j] >= 0) {
                    p[i] = Math.min(p[i - coins[j]] + 1, p[i]);
                }
            }
        }
        return p[amount] > amount ? -1 : p[amount];
    }


//给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

//数组中的每个元素代表你在该位置可以跳跃的最大长度。

//判断你是否能够到达最后一个下标。
    public boolean canJump(int[] nums) {
        int[] p = new int[nums.length];
        p[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            p[i] = 0;
            for (int j = 0; j < i; j++) {
                if (p[j] == 1 && nums[j] + j >= i) {
                    p[i] = 1;
                    break;
                }
            }
        }
        return p[nums.length - 1] == 1;
    }

}
