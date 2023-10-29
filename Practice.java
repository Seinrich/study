import java.util.Scanner;
import java.util.Random;

public class Practice {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        int ret;
        int choose;

        do {
            choose = menu(scanner);
            if (choose == 1) {
                ret = random.nextInt(100) + 1;
                game(ret, scanner);
                System.out.print("游戏结束，1.重新开始  0.退出游戏\n请选择哦:");
                choose = scanner.nextInt();
            }
        } while (choose != 0);

        scanner.close();
    }

    public static int menu(Scanner scanner) {
        int choose;
        do {
            System.out.println("欢迎来到猜数字游戏");
            System.out.println("1. play      0. exit");
            System.out.print("请您选择:");
            choose = scanner.nextInt();
            if (choose != 0 && choose != 1) {
                System.out.print("重新输入:");
            }
        } while (choose != 0 && choose != 1);

        return choose;
    }

    public static void game(int ret, Scanner scanner) {
        System.out.println("请猜数字");
        int guess;

        do {
            guess = scanner.nextInt();
            if (guess > ret) {
                System.out.print("猜大咯！再试试:");
            } else if (guess < ret) {
                System.out.print("猜小咯！再试试:");
            } else {
                System.out.println("猜对啦！");
            }
        } while (guess != ret);
    }

    public static void bubbleSort(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
    }

    public static void printArray(int[] arr) {
        for (int j : arr) {
            System.out.print(j + " ");
        }
    }

    public static void initArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = 0;
        }
    }

    public static void reverseArray(int[] arr) {
        int left = 0;
        int right = arr.length - 1;

        while (left < right) {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    }

    public static void swapArrays(int[] arr1, int[] arr2) {
        int n = arr1.length;

        for (int i = 0; i < n; i++) {
            int tmp = arr1[i];
            arr1[i] = arr2[i];
            arr2[i] = tmp;
        }
    }

    public static int countOnesInBinary(int a) {
        int count = 0;

        for (int i = 0; i < 32; i++) {
            int c = a & 1;
            if (c == 1) {
                count++;
            }
            a = a >> 1;
        }

        return count;
    }

    public static int countBitsDifference(int a, int b) {
        int c = a ^ b;
        int count = 0;

        while (c != 0) {
            count++;
            c = c & (c - 1);
        }

        return count;
    }

    public static void swapWithoutTemp(int a, int b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        System.out.println("a=" + a + ", b=" + b);
    }

    public static void printArrayWithPointer(int[] arr) {
        for (int j : arr) {
            System.out.print(j + " ");
        }
    }

    public static void printMultiplicationTable(int row) {
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.printf("%d*%d=%-3d ", j, i, i * j);
            }
            System.out.println();
        }
    }

    public static void printDigitsRecursively(int a) {
        if (a != 0) {
            printDigitsRecursively(a / 10);
            System.out.print(a % 10 + " ");
        }
    }

    public static int factorial(int n) {
        int tmp = 1;

        if (n != 0) {
            tmp = n * factorial(n - 1);
        }

        return tmp;
    }

    public static int factorialNonRecursive(int n) {
        int tmp = 1;

        for (int i = 1; i <= n; i++) {
            tmp = tmp * i;
        }

        return tmp;
    }

    public static int sumDigits(int a) {
        int sum = 0;

        if (a != 0) {
            sum = a % 10 + sumDigits(a / 10);
            System.out.print(a % 10 + " ");
        }

        return sum;
    }
}
