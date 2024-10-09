

//����ɢ�б�Ĺ����Ͳ���

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>		//����ʱ����Ҫ���� -lm

#include <unistd.h>


#define NUM_LEN 100
#define NUM_MAX_VALUE 1000
#define MAP_LEN 300


#define TIMES 1000
int test(double );
int test2(double a, double b);
int test2_average(int tims, double a, double b, int);
int main(int argn, void *argv[])
{
	int i, j;
	int ret;
	int totle;
	int max, tmpA, tmpB;
	
#if 0
	//srandom(time(NULL));	//���������
	totle = 0;
	for(i = 0; i < TIMES; i++)
	{
		ret = test(atof(argv[1]));
		totle += ret;
		//system("sleep 1");
		srandom(time(NULL) + i);	//���������
		//usleep(40 * 1000);
		printf("%d ", ret);
		if((i+1) % 20 == 0)printf("\n");
	}	
	printf("\n-->result: %d\n", totle / TIMES);*/
#endif	
	max = 0;
	
#define A_TIMES 10
#define B_TIMES	20
	for(i = 0; i < A_TIMES; i++)
	{
		for(j = 0; j < B_TIMES; j++)
		{
			ret = test2_average(TIMES, 0.9 + i * 0.05 , j * 22, (i - 1) * B_TIMES + j);
			printf("%d ", ret);
		
			if(((i - 1) * B_TIMES + j + 1) % 20 == 0)printf("\n");
			
			if(max < ret)
			{
				max = ret;
				tmpA = i;
				tmpB = j;
			}	
			
			system("sleep 1");
		}
	}
	
	printf("\n-->max:%d tmpA:%d tmpB=%d\n", max, tmpA, tmpB);
	return 0;
}


int test2_average(int tims, double a, double b, int randomNum)
{
	//srandom(time(NULL));	//���������
	int i;
	int ret;
	int totle = 0;
	for(i = 0; i < tims; i++)
	{
		ret = test2(a, b);
		totle += ret;
		//system("sleep 1");
		srandom(time(NULL) + i + randomNum);	//���������
		//usleep(10 * 1000);
		//printf("%d ", ret);
		//if((i+1) % 20 == 0)printf("\n");
	}	
	//printf("\n-->result: %d\n", totle / TIMES);
	return totle / tims;
}



int test2(double a, double b)
{
	//printf("OK\n");
	
	int i;
	int result;
	
		
	int cnt0,cnt1,cntOther;
	int num[NUM_LEN] = {0};
	int map[MAP_LEN] = {0};
	int stat[NUM_MAX_VALUE] = {0};
	
	for(i = 0; i < NUM_LEN; i++)
	{	
		while(1)//��ֹ�ظ�
		{
			num[i] = random() % NUM_MAX_VALUE;
			if(stat[num[i]] == 0)
			{
				stat[num[i]] = 1;
				break;
			}			
		}
		
		result = (int)(a * num[i] + b) % MAP_LEN;	//ӳ��Ľ��
		//result = num[i] % MAP_LEN;
		
		map[result]++;
		//printf("%d ", num[i]);
		//if((i+1) % 10 == 0)printf("\n");
	}
	//printf("\n----------------\n");
	
	cnt0 = cnt1 = cntOther = 0;
	for(i = 0; i < MAP_LEN; i++)
	{
		if(map[i] == 0)cnt0++;
		else if(map[i] == 1)cnt1++;
		else cntOther++;
		//printf("%d ", map[i]);
		//if((i+1) % 20 == 0)printf("\n");
	}
	//printf("cnt0:%d cnt1:%d cntOther:%d\n", cnt0, cnt1, cntOther);
	
	return cnt1;
	
}






#if 0
int test(double para)
{
	//printf("OK\n");
	
	int i;
	int result;
	
		
	int cnt0,cnt1,cntOther;
	int num[NUM_LEN] = {0};
	int map[MAP_LEN] = {0};
	int stat[NUM_MAX_VALUE] = {0};
	
	for(i = 0; i < NUM_LEN; i++)
	{	
		while(1)//��ֹ�ظ�
		{
			num[i] = random() % NUM_MAX_VALUE;
			if(stat[num[i]] == 0)
			{
				stat[num[i]] = 1;
				break;
			}			
		}
		
		//result = num[i] % MAP_LEN;
		//result = (int)(num[i]*atof(argv[1])) % MAP_LEN;
		result = (unsigned int)(pow(num[i], para)) % MAP_LEN;	//ӳ��Ľ��
		//result = (int)sqrt((double)num[i]) % MAP_LEN;
		//result = (num[i] * NUM_MAX_VALUE / MAP_LEN) % MAP_LEN;
		
		map[result]++;
		//printf("%d ", num[i]);
		//if((i+1) % 10 == 0)printf("\n");
	}
	//printf("\n----------------\n");
	
	cnt0 = cnt1 = cntOther = 0;
	for(i = 0; i < MAP_LEN; i++)
	{
		if(map[i] == 0)cnt0++;
		else if(map[i] == 1)cnt1++;
		else cntOther++;
		//printf("%d ", map[i]);
		//if((i+1) % 20 == 0)printf("\n");
	}
	//printf("cnt0:%d cnt1:%d cntOther:%d\n", cnt0, cnt1, cntOther);
	
	return cnt1;
}
#endif













