#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int throw_dice();
 int round_1(int total);
int main()
{
	int total,round,target,result[99],flag=1,i;
	srand((unsigned)(time(0)));
	
	printf("�Q���X���O�H");
	scanf("%d",&round);
	//�Ĥ@����X7or11��Ĺ;2�B3�B12���;��l�]������ؼ� 
	
	for(i=0;i<round;i++)
	{
		printf("\n��%d��\n",i+1);
		target=round_1(throw_dice());
		if (target==1)
		{
			continue;//���U�@�� 
		}
		else
		{
			do
			{
				total=throw_dice();
			}while(total!=7 and total!=target);//�@�����ƪ����Y�X 7or target 
			
			if (total==7)
			{
				printf("�A��F\n");
				continue;//���� 
			}
			else
			{
				printf("�AĹ�F\n");
				continue;//���� 
			} 
		}
	}
	
	
	
 } 
 int throw_dice()//���Y��l���ʧ@ 
 {
 	printf("�Y��l");
	int dice1,dice2,total;
	dice1=rand()%6+1;dice2=rand()%6+1;
	total=dice1+dice2;
	system("pause");
	//printf("�Y�X�F%d%+d\n",dice1,dice2);//��x�����ΡA�S���D�`���n���D�C���Y�X���� 
	printf("�@�Y�X�F%d\n",total);
	return total;
 }
 int round_1(int total)
 {
 	int flag;
	if (total==7||total==11)
	{
		printf("�AĹ�F\n");
		flag=1;//���� 
		return flag;
	}
	else if(total==2||total==3||total==12)
	{
		printf("�A��F\n");
		flag=1;//���� 
		return flag;
	}
	else
	{
		flag=total;
		return flag;
	}
 }
