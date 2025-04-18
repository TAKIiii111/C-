#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>




//编写一个函数，求三个数的最大值
void Max()
{
	int a, b, c;
	printf("请输入三个数：\n");
	scanf("%d %d %d", &a, &b, &c);
	int max = a;
	if (a >= b && a >= c) {
		max = a;
	}
	else if(b >=a&&b>=c) {
			max = b;
	}
	else if (c >= a && c >= b)
	{
		max = c;
	}
	printf("最大值为：%d", max);
}


/*要将"China"译成密码，译码规律是：用原来字母后面的第4个字母代替原来的字母．
例如，字母"A"后面第4个字母是"E"．"E"代替"A"。因此，"China"应译为"Glmre"。
请编一程序，用赋初值的方法使cl、c2、c3、c4、c5五个变量的值分别为，
’C’、’h’、’i’、’n’、’a’，
经过运算，使c1、c2、c3、c4、c5分别变为’G’、’l’、’m’、’r’、’e’，
并输出。*/
//未完成
void Key()
{
	char s1[] = { 'C', 'h', 'i', 'n', 'a' };
	char s2[5] = {'\0'};

	for (int i = 0; i < sizeof(s1); i++)
	{
		int n = (int)s1[i] + 4;
		s2[i] = (char) n;
	}
	printf("China译码后为：\n");
	for (int i = 0; i < sizeof(s2); i++)
	{
		printf("%c", s2[i]);
	}

}


/*有一头母牛，
它每年年初生一头小母牛。
每头小母牛从第四个年头开始，
每年年初也生一头小母牛。
请编程实现在第n年的时候，
共有多少头母牛？*/
void Niu()
{
	//定义年份
	int n = 0;
	printf("请输入年份:");
	scanf("%d", &n);
	//定义母牛数量
	int mn = 1;

	//定义小母牛数量
	int xmn = 0;
	//每当小母牛出生四年后，成为母牛
	for (int i = 1; i <= n; i++)
	{
		if (i >= 4)
		{
			mn += xmn;
			xmn = mn;
		}
		else
		{
			xmn++;
		}
	}
}


/*输入一个华氏温度，要求输出摄氏温度。
公式为 c=5(F-32)/9，取位2小数*/
void Tchange()
{
	double c =0.0;
	double F=0.0;
	scanf("%lf", &F);
	c = 5 * (F - 32) / 9;
	printf("c=%.2f", c);
}

/*有一个函数
y={  x      x<1
    |  2x-1   1<=x<10
    { 3x-11  x>=10

写一段程序，输入x，输出y*/
void hanshu()
{
	int x = 0;
	int y = 0;
	scanf("%d",&x);
	if (x<1)
	{
		y = x;
		printf("y=%d", y);
	}
	else if(1 <= x < 10)
	{
		y = 2*x-1;
		printf("y=%d", y);
	}
	else
	{
		y = 3*x - 11;
		printf("y=%d", y);
	}
}

//给出一百分制成绩，
// 要求输出成绩等级‘A’、‘B’、‘C’、‘D’、‘E’。
// 90分以及90分以上为A，
// 80-89分为B，
// 70-79分为C，
// 60-69分为D，
// 60分以下为E。
void cj()
{
	//定义成绩变量
	int score = 0;
	//用循环语句输入五个成绩检验代码
	for (size_t i = 0; i < 5; i++)
	{
		scanf("%d", &score);

		//判断分数是否在0-100之间
		if (score > 100||score<0)
		{
			printf("分数错误，请重新输入！\n");
			cj();
		}

		//判断分数等级
		if (score >= 90)
		{
			printf("成绩等级为：A\n");
		}
		else if (score >= 80 && score <= 89)
		{
			printf("成绩等级为：B\n");
		}
		else if (score >= 70 && score <= 79)
		{
			printf("成绩等级为：C\n");
		}
		else if (score >= 60 && score <= 69)
		{
			printf("成绩等级为：D\n");
		}
		else if (score < 60)
		{
			printf("成绩等级为：E\n");
		}
	}
}


/*给出一个不多于5位的整数，
要求 1、求出它是几位数 
2、分别输出每一位数字 
3、按逆序输出各位数字，
例如原数为321,应输出123*/
void nsc()
{
	int num = 0;
	printf("请输入一个不多于5位的整数：\n");
	scanf("%d", &num);

	//处理输入错误的情况
	if (num > 99999 || num < 0)
	{
		printf("输入错误，请重新输入！");
	}

	//定义一个数组存储每一位数字
	int arr[5] = { 0 };

	//定义一个变量存储位数
	int count = 0;

	if (num==0)
	{
		arr[0] = 0;
		count = 1;
	}
	else
	{
		for (count = 0; count < sizeof(arr) / sizeof(arr[0]); count++)
		{
			if (num == 0)
			{
				break;
			}
				arr[count] = num % 10;
				num /= 10;			
		}
	}

	//输出位数
	printf("位数为：%d\n", count);

	//输出每一位数字
	printf("每一位数字为：\n");
	for (int i = 0; i < count; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");

	//逆序输出
	printf("逆序输出为：\n");
	for (; count - 1 >= 0; count--)
	{
		printf("%d", arr[count - 1]);
	}

}

/*企业发放的奖金根据利润I提成。

利润I低于或等于1000元的，奖金可提10%;
利润1000<I≤2000时，低于等于1000元部分按10％提成，高于1000元的部分，可提成 7.5%;
2000<I≤4000时，低于2000元部分仍按上述办法提成（下同），高于2000元的部分按5％提成；
4000<I≤6000元时，高于4000元的部分按3％提成；

6000<I≤10000时，高于6000元的部分按1.5%提成；
I>10000时，超过10000元的部分按1%提成。

从键盘输入当月利润I,求应发奖金总数。*/

void Lr()
{
	//定义利润变量
	int I = 0;
	printf("请输入利润：\n");
	scanf("%d", &I);

	//判断利润是否在合理范围内
	if (I < 0)
	{
		printf("利润输入错误，请重新输入！\n");
		Lr();
	}

	//定义奖金变量
	int P = 0;

	if (I > 0 && I <= 1000)
	{
		P = I * 0.1;
		printf("奖金为：%d\n", P);
	}
	else if (1000 < I && I <= 2000)
	{
		P = 1000 * 0.1 + (I - 1000) * 0.075;
		printf("奖金为：%d\n", P);
	}
	else if (2000 < I && I <= 4000) {
		P = 1000 * 0.1 + (2000 - 1000) * 0.075 + (I - 2000) * 0.05;
		printf("奖金为：%d\n", P);
	}
	else if (4000 < I && I <= 6000){
		P = 1000 * 0.1 + (2000 - 1000) * 0.075 + (4000 - 2000) * 0.05 + (I - 4000) * 0.03;
		printf("奖金为：%d\n", P);
	}
	else if (6000 < I && I <= 10000) {
		P = 1000 * 0.1 + (2000 - 1000) * 0.075 + (4000 - 2000) * 0.05 + (6000 - 4000) * 0.03 + (I - 6000) * 0.015;
		printf("奖金为：%d\n", P);
	}
	else if (I > 10000) {
		P = 1000 * 0.1 + (2000 - 1000) * 0.075 + (4000 - 2000) * 0.05 + (6000 - 4000) * 0.03 + (10000 - 6000) * 0.015 + (I - 10000) * 0.01;
		printf("奖金为：%d\n", P);
	}
}

/*输入两个正整数m和n，求其最大公约数和最小公倍数*/
void Test()
{
	int m = 0;
	int n = 0;
	printf("请输入第一个正整数：\n");
	scanf("%d", &m);

	printf("请输入第二个正整数：\n");
	scanf("%d", &n);

	//判断输入的数是否为正整数
	if (m <= 0 || n <= 0)
	{
		printf("输入错误，请重新输入！\n");
		Test();
	}
	
	printf("%d",m*n);
	int min = 0;
	//求最小公倍数
	for (int j = 0; j <= m*n; j++)
	{
		if (j%m==0 && j%n==0)
		{
			min = j;
		}
	}
	printf("最小公倍数为：%d\n", min);

	int max = 0;
	//求最大公约数
	for (int i = 1; i <= (m < n?m:n); i++)
	{
		if (m % i == 0 && n % i == 0)
		{
			max = i;
		}
	}
	printf("最大公约数为：%d\n", max);
}


/*输入一行字符，分别统计出其中英文字母、数字、空格和其他字符的个数;
一行字符,长度不超过200*/
void Test2() {

}

int main() {
	int i = 1;
	for (; i < 10; i++)
	{
		for (int j = 1; j < i; j++) {
			printf("%d",i);
			printf("X");
			printf("%d", j);
			printf("=%d", i * j);
			printf("\t");
		};
		printf("\n");
	}

	return 0;
}
