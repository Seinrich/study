
public class game {
    public static final int ROW = 9;
    public static final int COL = 9;
    public static final int Easy_Count = 10;

    //初始化棋盘
    public static void InitBoard(char[][] board, int rows, int cols, char set) {
        int i;
        int j;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++)
                board[i][j] = set;
        }
    }

    public static void PutMine(char[][] mine, int ignoredRows) {
        int count = 0;
        int x;
        int y;
        while (count < Easy_Count) {
            x = (int) (Math.random() * ROW + 1);
            y = (int) (Math.random() * COL + 1);
            if (mine[x][y] == '0') {
                mine[x][y] = '1';
                count++;
            }
        }
    }

    public static void DisplayBoard(char[][] board, int row, int col) {
        int i;
        int j;
        for (i = 0; i <= row; i++)
            System.out.print(i + " ");
        System.out.println();
        for (i = 1; i <= row; i++) {
            System.out.print(i + " ");
            for (j = 1; j <= col; j++)
                System.out.print(board[i][j] + " ");
            System.out.println();
        }
    }

    //计算周围雷的个数
    public static int get_mine_count(char[][] mine, int x, int y) {
        return mine[x - 1][y] +
                mine[x - 1][y - 1] +
                mine[x][y - 1] +
                mine[x + 1][y - 1] +
                mine[x + 1][y] +
                mine[x + 1][y + 1] +
                mine[x][y + 1] +
                mine[x - 1][y + 1] - 8 * '0';
    }

    //递归空白展开
    public static void blank(char[][] mine, char[][] show, int x, int y) {
        int count = get_mine_count(mine, x, y);
        if (count == 0) {
            show[x][y] = ' ';
            if (x - 1 >= 1 && x <= ROW && y >= 1 && y <= COL && show[x - 1][y] == '*')
                blank(mine, show, x - 1, y);
            if (x >= 1 && x <= ROW && y - 1 >= 1 && y <= COL && show[x][y - 1] == '*')
                blank(mine, show, x, y - 1);
            if (x <= ROW && y >= 1 && y <= COL && show[x + 1][y] == '*')
                blank(mine, show, x + 1, y);
            if (x >= 1 && x <= ROW && y <= COL && show[x][y + 1] == '*')
                blank(mine, show, x, y + 1);
        } else
            show[x][y] = (char) (count + '0');
    }

    //判断未检查数量
    public static int Is_Win(char[][] show, int row, int col) {
        int i;
        int j;
        int count = 0;
        for (i = 1; i <= row; i++) {
            for (j = 1; j <= col; j++) {
                if (show[i][j] == '*')
                    count++;
            }
        }
        return count;
    }

    public static void FindMine(char[][] mine, char[][] show, int row, int col) {
        int x;
        int y;
        int count = Is_Win(show, row, col);
        while (count != Easy_Count) {
            System.out.println("请输入排查位置:>");
            x = new java.util.Scanner(System.in).nextInt();
            y = new java.util.Scanner(System.in).nextInt();
            if (x >= 1 && x <= row && y >= 1 && y <= col) {
                if (mine[x][y] == '1') {
                    System.out.println("很遗憾，你被炸死了,雷位置如下（1为雷）\n");
                    DisplayBoard(mine, ROW, COL);
                    break;
                } else if (show[x][y] != '*')
                    System.out.println("此位置已查，请重新输入!");
                else {
                    blank(mine, show, x, y);
                    System.out.println("\n");
                    DisplayBoard(show, ROW, COL);
                }
            } else
                System.out.println("此位置不正确，请重新输入!");
        }
        if (count == Easy_Count)
            System.out.println("恭喜你，排雷成功");
    }

    public static void main(String[] args) {
        char[][] board = new char[ROW + 2][COL + 2];
        char[][] mine = new char[ROW + 2][COL + 2];
        char[][] show = new char[ROW + 2][COL + 2];
        InitBoard(board, ROW + 2, COL + 2, '*');
        InitBoard(mine, ROW + 2, COL + 2, '0');
        InitBoard(show, ROW + 2, COL + 2, '*');
        DisplayBoard(board, ROW, COL);
        PutMine(mine, ROW);
        FindMine(mine, show, ROW, COL);
    }
}
