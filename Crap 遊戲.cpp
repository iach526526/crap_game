#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int throw_dice();
int main()
{
	int total,round,target;
	srand((unsigned)(time(0)));
	total=throw_dice();
	
	//第一次投出7or11算贏;2、3、12算輸;其餘設為之後目標 
	if (total==7||total==11)
	{
		printf("你贏了");
		return 0;//結束 
	}
	else if(total==2||total==3||total==12)
	{
		printf("你輸了");
		return 0;//結束 
	}
	else
	{
		target=total;
	}
	
	do
	{
		total=throw_dice();
	}while(total!=7 and total!=target);//一直重複直到擲出 7or target 
	if (total==7)
	{
		printf("你輸了");
		return 0;//結束 
	}
	else
	{
		printf("你贏了");
		return 0;//結束 
	} 
	
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
