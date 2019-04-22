#include<stdio.h>
#include<semaphore.h>
sem_t s;
void introduction()
{
	printf("\t\t\t\t*******ONLINE MULTIPLAYER GAME*******\n");
	printf("Project for CSE316");
}
void game()
{
	sem_wait(&s);
	printf("Game is running\n");
	sem_post(&s);
}

int main()
{
	introduction();
	sem_init(&s,0,1);
	int a,i,k;
//To check if the last game is complete
n:
char answer;
printf("\n Is the last game finished Enter Y or N: \n", answer);
scanf("%c", &answer);
if(answer == 'Y')
{
goto m;
}
else
{
goto n;
}
	m:
	printf("Enter the number of players:- \n");
	scanf("%d",&a);
	int p1[a],p2,p3,f=0;
	if(a<3)
	{
		printf("\nThere must be a minimum of 3 players to start the game \n");
		goto m;
	}
	int b[a];
	for(i=0;i<a;i++)      
	{
		b[i]=i;
	}
	for(k=0;k<a;k++)
	{
		p1[k]=b[k];
		f++;
		if(f%3==0)
			game();
	}
	if(f%3!=0)
	{
		printf("\nNot sufficient players\n");
		printf("Waiting for more players to arrive\n");
	}
}
