#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int throw_dice();
int main()
{
	int total,round,target;
	srand((unsigned)(time(0)));
	total=throw_dice();
	
	//�Ĥ@����X7or11��Ĺ;2�B3�B12���;��l�]������ؼ� 
	if (total==7||total==11)
	{
		printf("�AĹ�F");
		return 0;//���� 
	}
	else if(total==2||total==3||total==12)
	{
		printf("�A��F");
		return 0;//���� 
	}
	else
	{
		target=total;
	}
	
	do
	{
		total=throw_dice();
	}while(total!=7 and total!=target);//�@�����ƪ����Y�X 7or target 
	if (total==7)
	{
		printf("�A��F");
		return 0;//���� 
	}
	else
	{
		printf("�AĹ�F");
		return 0;//���� 
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
