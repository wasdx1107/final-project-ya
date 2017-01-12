#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int DIGITS = 4;    //�ŧi�n�q���Ʀr����ơA�ѨϥΪ̩w�q�A��ȳ] 4 
int question[6];    //�ŧi���D�Ʀr�}�C
void generateQuestion();    //�H������ DIGITS �Ӥ��P���Ʀr int 
void guess(int your_answer[]);    //�q�Ʀr�A�ѨϥΪ̿�J�Ʀr 
int compare(int your_answer[]);    //����O�_���T  

int main(int argc, char *argv[])
{
	int your_answer[6];    //�ŧi�q���Ʀr�}�C
	int is_correct;    //��ƭȡG��O�Ҳq�Ʀr�O�_���T
	int count = 0;    //�p��q�F�X�� 
	do
	{
		printf( "�п�J�n�q�X��ơH(4 �� 5 �� 6)");
		scanf_s("%d",&DIGITS);
	} while (DIGITS < 4 || DIGITS > 6);
	generateQuestion();
	printf("�п�J%d�Ӥ��P���Ʀr�A�B�Ĥ@�ӼƦr�����s�C��J 0 �h��ܵ��� ^_^\n",DIGITS);

	do
	{
		guess(your_answer);    //�q�Ʀr
		count++;
		is_correct = compare(your_answer);    //����O�_���T
	} while (is_correct == 0);    //�����T�N�~��q

	printf("���ߡI�I\n�A�q��F�I�I\n");
	printf("�A�`�@�q�F %d���I\n",count);
	system("PAUSE");
	return EXIT_SUCCESS;
}

/* �H������ DIGITS �Ӥ��P���Ʀr int */
void generateQuestion()
{
	int is_repeat;    /* ���F�ˬd�O�_���ͭ��ƪ��Ʀr */
	int i, j;    //�ŧi index �ܼ� 
	srand(time(NULL));    //�H�ɶ������üƺؤl 

	question[0] = rand() % 9 + 1;    /* �Ĥ@�ӼƦr�|�O 1-9 */

	/* ���ͨ�l�Ʀr */
	for (i = 1; i < DIGITS; i++){
		/* ���ͷs���Ʀr����S�����ƪ����εo�� */
		do{
			is_repeat = 0;    /* �@�}�l���]�S�����ͭ��ƼƦr�����p */
			question[i] = rand() % 10;    /* ��L�Ʀr�|�O 0-9. */
			for (j = 0; j < i; j++)
			{
				if (question[i] == question[j])
				{
					is_repeat = 1;    /* ���Ƶo�� */
					break;
				}
			}
		} while (is_repeat == 1);    //���Ƶo�ʹN�~�� 
	}
}

/* ���o�ϥΪ̿�J���Ʀr�æs�b your_answer �}�C�� */
/* ��ϥΪ̿�J 0 �ɡA�h�q�X���� */
void guess(int your_answer[])
{
	int value, i;    //�ŧi����ܼ� 
	scanf_s("%d", &value);    //��J�Ʀr 
	if (value == 0)    //��Ʀr�� 0 �ɡA�L�X���� 
	{
		for (i = 0; i<DIGITS; i++)
		{
			printf("%d",question[i]);
			your_answer[i] = question[i];
		}
		printf(" endl");
	}
	else     /* ���o�Ʀr */
	{
		for (i = DIGITS - 1; i >= 0; i--)
		{
			your_answer[i] = value % 10;
			value = value / 10;
		}
	}
}
/* ��� question �P�ϥΪ̩ҿ�J���Ʀr
�p�G�ϥΪ̲q��F return 1;
�_�h return 0;
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
		printf("�ЦA�q�@�� ^_^\n");
		return 0;
	}
}