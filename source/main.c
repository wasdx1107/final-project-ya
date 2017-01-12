#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int DIGITS = 4;    //宣告要猜的數字的位數，由使用者定義，初值設 4 
int question[6];    //宣告問題數字陣列
void generateQuestion();    //隨機產生 DIGITS 個不同的數字 int 
void guess(int your_answer[]);    //猜數字，由使用者輸入數字 
int compare(int your_answer[]);    //比較是否正確  

int main(int argc, char *argv[])
{
	int your_answer[6];    //宣告猜測數字陣列
	int is_correct;    //整數值：辨別所猜數字是否正確
	int count = 0;    //計算猜了幾次 
	do
	{
		printf( "請輸入要猜幾位數？(4 或 5 或 6)");
		scanf_s("%d",&DIGITS);
	} while (DIGITS < 4 || DIGITS > 6);
	generateQuestion();
	printf("請輸入%d個不同的數字，且第一個數字不為零。輸入 0 則顯示答案 ^_^\n",DIGITS);

	do
	{
		guess(your_answer);    //猜數字
		count++;
		is_correct = compare(your_answer);    //比較是否正確
	} while (is_correct == 0);    //不正確就繼續猜

	printf("恭喜！！\n你猜對了！！\n");
	printf("你總共猜了 %d次！\n",count);
	system("PAUSE");
	return EXIT_SUCCESS;
}

/* 隨機產生 DIGITS 個不同的數字 int */
void generateQuestion()
{
	int is_repeat;    /* 為了檢查是否產生重複的數字 */
	int i, j;    //宣告 index 變數 
	srand(time(NULL));    //以時間做為亂數種子 

	question[0] = rand() % 9 + 1;    /* 第一個數字會是 1-9 */

	/* 產生其餘數字 */
	for (i = 1; i < DIGITS; i++){
		/* 產生新的數字直到沒有重複的情形發生 */
		do{
			is_repeat = 0;    /* 一開始假設沒有產生重複數字的情況 */
			question[i] = rand() % 10;    /* 其他數字會是 0-9. */
			for (j = 0; j < i; j++)
			{
				if (question[i] == question[j])
				{
					is_repeat = 1;    /* 重複發生 */
					break;
				}
			}
		} while (is_repeat == 1);    //重複發生就繼續做 
	}
}

/* 取得使用者輸入的數字並存在 your_answer 陣列裡 */
/* 當使用者輸入 0 時，則秀出答案 */
void guess(int your_answer[])
{
	int value, i;    //宣告整數變數 
	scanf_s("%d", &value);    //輸入數字 
	if (value == 0)    //當數字為 0 時，印出答案 
	{
		for (i = 0; i<DIGITS; i++)
		{
			printf("%d",question[i]);
			your_answer[i] = question[i];
		}
		printf(" endl");
	}
	else     /* 取得數字 */
	{
		for (i = DIGITS - 1; i >= 0; i--)
		{
			your_answer[i] = value % 10;
			value = value / 10;
		}
	}
}
/* 比較 question 與使用者所輸入的數字
如果使用者猜對了 return 1;
否則 return 0;
*/
int compare(int your_answer[])
{
	int a_count = 0, b_count = 0, i, j;

	for (i = 0; i < DIGITS; i++)
	{
		if (your_answer[i] == question[i])
		{
			a_count++;
		}
		else
		{
			for (j = 0; j < DIGITS; j++)
			{
				if (your_answer[i] == question[j] && j != i)
				{
					b_count++;
					break;
				}
			}
		}
	}

	printf("%dA%dB\n",a_count,b_count);
	if (a_count == DIGITS)
		return 1;
	else
	{
		printf("請再猜一次 ^_^\n");
		return 0;
	}
}