package ��̬�滮;

public class dynamic {

    //62.һ��������λ��һ�� m x n?��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����

//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish�� ����

//���ܹ��ж�������ͬ��·����
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

//103.������ͬ����Ӳ�� coins ��һ���ܽ�� amount����дһ��������������Դճ��ܽ����������ٵ�Ӳ�Ҹ��������û���κ�һ��Ӳ�����������ܽ�����? - 1��

//�������Ϊÿ��Ӳ�ҵ����������޵�

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


//����һ���Ǹ��������� nums �������λ������� ��һ���±� ��

//�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

//�ж����Ƿ��ܹ��������һ���±ꡣ
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
