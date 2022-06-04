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
	srand((unsigned)(time(0)));//設定亂數種子 
	int win_count[99]={0},round_count[99]={0};
	printf("想玩幾次呢？");
	scanf("%d",&round);
	//第一次投出7or11算贏;2、3、12算輸;其餘設為之後目標 
	
	for(i=0;i<round;i++)
	{
		printf("\n第%d局\n",i+1);
		target=round_1(throw_dice());
		if (target==1||target==0)
		{
			if (target==1)
			{
				win_count[i]=1;
			}
			round_count[i]=1;
			round_count[i]=1;
			continue;//換下一局 ，保險起見，寫了 continue強制把i+1 
		}
		else
		{
			play_count=1;
			do
			{
				total=throw_dice();
				play_count++;
			}while(total!=7 and total!=target);//一直重複直到擲出 7or target 
			
			if (total==7)
			{
				printf("你輸了\n");
				round_count[i]=play_count;
			}
			else
			{
				printf("你贏了\n");
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
	
	printf("\n結算:\n總計共贏%d局\n",count);
	printf("平均回合數:%.2lf",average(round_count,round));
	
 }
 int throw_dice()//做擲骰子的動作 
 {
 	printf("擲骰子");
	int dice1,dice2,total;
	dice1=rand()%6+1;dice2=rand()%6+1;
	total=dice1+dice2;
	system("pause");
	//printf("擲出了%d%+d\n",dice1,dice2);//後台除錯用，沒有非常必要知道每次擲出什麼 
	printf("共擲出了%d\n",total);
	return total;
 }
 int round_1(int total)
 {
 	int flag;
	if (total==7||total==11)
	{
		printf("你贏了\n");
		flag=1;//結束 
		return flag;
	}
	else if(total==2||total==3||total==12)
	{
		printf("你輸了\n");
		flag=0;//結束 
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
double average(int a[],int n)//算陣列總和，算平均回和數 
{ 
	double ans;
	ans=(double)(total(a,n))/n;
	return ans;
	
}
