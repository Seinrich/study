#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//int Fibonacci(int n)
//{
//    //int a = 1;
//    //int b = 1;
//    //// write code here
//    //if (n > 0 && n <= 2)
//    //    return 1;
//    //else
//    //{
//    //    int j = 0;
//    //    for (; j < n - 2; j++)
//    //    {
//    //        int c = a + b;
//    //        a = b;
//    //        b = c;
//    //        if (j == n - 3)
//    //            return c;
//    //    }
//    //}
//}

//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int a = Fibonacci(n);
//    printf("%d", a);
//}

//指针笔试/面试题目

//1.计算下式结果

//int main()
//{
//	/*char arr[] = { "abcde" };
//	printf("%d\n", sizeof(arr));             
//	printf("%d\n", sizeof(&arr));            
//	printf("%d\n", strlen(arr));             
//	printf("%d\n", strlen(&arr[0]));*/       
//
//	//二维数组与指针（难度偏高）
//
//	int arr[3][4] = { 0 };
//	//将此二维数组视为有三个元素的一维数组，每个数组有四个整形元素
//
//	//printf("%d", sizeof(arr[0]));               16
//    //arr[0]是第一行数组的首元素的地址
//    //数组名单独放入sizeof()内，代表的是整个数组
//
//	//printf("%d", sizeof(arr[0] + 1));           4or8
//	//arr[0]仍是第一行数组首元素地址
//    //但不单独放入,arr[0]+1代表的不是第二行数组首元素地址，而是第一行第二个元素地址
//
//	//printf("%d", sizeof(arr + 1));
//	//arr是二维数组的数组名，没有sizeof（arr），也没有&arr，所以arr是首元素地址
//	//故arr是第一行（首元素）的地址,故arr+1是第二行的地址
//
//	//printf("%d", sizeof(*(arr + 1)));                 
//	//第二行的数组大小，是16
//
//	//printf("%d", sizeof(&arr[0] + 1));
//	//第二行的地址：运算符优先级，&高于+，故先取地址
//
//	//printf("%d", sizeof(*arr));
//	//arr代表二维数组中首元素的地址
//
//	//printf("%d", sizeof(*(arr[3]));
//	//理论上，arr[3]不存在，但是
//	//sizeof内部不参与真实运算，仅仅根据数据类型计算大小
//	//值为16
//}


//2.笔试题

//int main()
//{
//	//int arr[3][2] = { (0,1),(2,3),(4,5) };
//	//int* p = arr[0];
//	//printf("%d", arr[0]);
//}