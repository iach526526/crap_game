#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int throw_dice();
int round_1(int total);
double average(int a[],int n);
int total(int a[],int n);
int main()
{
	int total,round,target,i,play_count;
	srand((unsigned)(time(0)));//�]�w�üƺؤl 
	int win_count[99]={0},round_count[99]={0};
	printf("�Q���X���O�H");
	scanf("%d",&round);
	//�Ĥ@����X7or11��Ĺ;2�B3�B12���;��l�]������ؼ� 
	
	for(i=0;i<round;i++)
	{
		printf("\n��%d��\n",i+1);
		target=round_1(throw_dice());
		if (target==1||target==0)
		{
			if (target==1)
			{
				win_count[i]=1;
			}
			round_count[i]=1;
			round_count[i]=1;
			continue;//���U�@�� �A�O�I�_���A�g�F continue�j���i+1 
		}
		else
		{
			play_count=1;
			do
			{
				total=throw_dice();
				play_count++;
			}while(total!=7 and total!=target);//�@�����ƪ����Y�X 7or target 
			
			if (total==7)
			{
				printf("�A��F\n");
				round_count[i]=play_count;
			}
			else
			{
				printf("�AĹ�F\n");
				win_count[i]=1;
				round_count[i]=play_count;
			}
		}
	}
	
	
	int count=0;
	for(i=0;i<round;i++)
	{
		if(win_count[i]==1)
		{
			count++;
		}
	}
	
	printf("\n����:\n�`�p�@Ĺ%d��\n",count);
	printf("�����^�X��:%.2lf",average(round_count,round));
	
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
		flag=0;//���� 
		return flag;
	}
	else
	{
		flag=total;
		return flag;
	}
 }
int total(int a[],int n)
{  
	int i;
	int sum=0;
  for(i=0;i<n;i++)
     sum+=a[i];
  return sum;
}
double average(int a[],int n)//��}�C�`�M�A�⥭���^�M�� 
{ 
	double ans;
	ans=(double)(total(a,n))/n;
	return ans;
	
}
