#include<stdio.h>
char tictac[3][3];
int check()
{
	int count=0;
    int j,i;
    for(i=0;i<3;i++)
    {
        if( tictac[i][0]==tictac[i][1] && tictac[i][1]==tictac[i][2] && tictac[i][0]==tictac[i][2]&& tictac[i][2]!='2')
            return 1;
        if( tictac[0][i]==tictac[1][i] && tictac[1][i]==tictac[2][i] && tictac[0][i]==tictac[2][i] && tictac[2][i]!='2')
            return 1;
    }
    if(tictac[0][0]!= '2'&&tictac[0][0]==tictac[1][1]&&tictac[1][1]!='2'&&tictac[1][1]==tictac[2][2])
        return 1;
    if(tictac[0][2]!='2'&&tictac[0][2]==tictac[1][1]&&tictac[1][1]!='2'&&tictac[1][1]==tictac[2][0])
        return 1;
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    if(tictac[i][j]!='2')
    count++;
    if(count==9)
    return 4;
        return 0;
}
void print()
{
    int i,j;
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
        	if(tictac[i][j]=='2')
        	printf("   ");
        	else
            printf(" %c ",tictac[i][j]);
            if(j==2)
                break;
            printf(" | ");
        }
        printf("\n");
        if(i==2)
            break;
        printf("--------------");
        printf("\n");
    }
}
main()
{
	int k,chk=0;
	 int i,j;
	 for(i=0;i<3;i++)
	 for(j=0;j<3;j++)
	 tictac[i][j]='2';
    printf("Player 1 takes x\nPlayer 2 takes o\n");
    print();
    while(1){
    printf("Player 1 take chance\n");
    zo:
    scanf("%d %d",&i,&j);
    if(j<3 && i<3 && i>=0 && j>=0 && tictac[i][j]=='2')
        tictac[i][j]='x';
    else
    {
    	printf("\nWrong place. Enter again.\n");
    	goto zo;
	}
        print();
    chk=check();
    if(chk==1)
    {
        printf("Player 1 wins!");
        return 0;
    }
    if(chk==4)
    {
        printf("its a tie!");
        return 0;
    }
    printf("\nPlayer 2 take chance\n");
    lo:
    scanf("%d %d",&i,&j);
    if(j<3 && i<3 && i>=0 && j>=0 && tictac[i][j]=='2')
        tictac[i][j]='o';
    else
    {
    	printf("\nWrong place. Enter again.\n");
    	goto lo;
	}
	        print();
        chk=check();
    if(chk==1)
    {
        printf("Player 2 wins!");
        return 0;
    }
}
    return 0;
}