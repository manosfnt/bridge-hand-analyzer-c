#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct hand 
{
    char HANDD[40];//26 XARAKTHRES KAI 12 KENA
};
//////////////////////////////////////////////////////////////
int readFromInput(struct hand A[])
{
    int n;
    scanf("%d",&n);
    //scanf(" ");
    for (int i=0;i<n;i++)
    {
        scanf(" ");
        fgets(A[i].HANDD,40,stdin);
        A[i].HANDD[strcspn(A[i].HANDD,"\n")]='\0';
        
        //scanf(" ");

    }
    
    return n;
}
//////////////////////////////////////////////////////////////
void printHand(struct hand A)
{
    printf("SPADES:   ");
    for (int j=1;j<40;j+=3)
    {
        if (A.HANDD[j]=='S')
        {
            printf("%c ",A.HANDD[j-1]);
        }
    }
    printf("\n");
    printf("HEARTS:   ");
    for (int j=1;j<40;j+=3)
    {
        if (A.HANDD[j]=='H')
        {
            printf("%c ",A.HANDD[j-1]);
        }
    }
    printf("\n");
    printf("DIAMONDS: ");
    for (int j=1;j<40;j+=3)
    {
        if (A.HANDD[j]=='D')
        {
            printf("%c ",A.HANDD[j-1]);
        }
    }
    printf("\n");
    printf("CLUBS:    ");
    for (int j=1;j<40;j+=3)
    {
        if (A.HANDD[j]=='C')
        {
            printf("%c ",A.HANDD[j-1]);
        }
    }
    printf("\n");
}
//////////////////////////////////////////////////////////////
bool balanced(struct hand A)
{
    int count[4]={0};
    int m2=0;
    for (int i=1;i<40;i+=3)
    {
        if (A.HANDD[i]=='S')
            count[0]+=1;
        if (A.HANDD[i]=='H')
            count[1]+=1;
        if (A.HANDD[i]=='D')
            count[2]+=1;
        if (A.HANDD[i]=='C')
            count[3]+=1;    
    }
    for(int i=0;i<4;i++)
    {
        if (count[i]<2)
         return 0;
        if (count[i]==2)
         m2+=1;
    }
    if (m2<2)
        return 1;
    else 
        return 0;
}
//////////////////////////////////////////////////////////////
int hcp(struct hand A)
{ 
    int i,points;
    points=0;
    for (i=0;i<40;i+=3)
    {
        if (A.HANDD[i]=='A')
            points+=4;
        if (A.HANDD[i]=='K')
            points+=3;
        if (A.HANDD[i]=='Q')
            points+=2;
        if (A.HANDD[i]=='J')
            points+=1;
    }
    return points;
}
//////////////////////////////////////////////////////////////
int declarer(struct hand A)
{
    int count[4]={0};
    int i,points;
    points=0;
     for (i=1;i<40;i+=3)
    {
        if (A.HANDD[i]=='S')
            count[0]+=1;
        if (A.HANDD[i]=='H')
            count[1]+=1;
        if (A.HANDD[i]=='D')
            count[2]+=1;
        if (A.HANDD[i]=='C')
            count[3]+=1;
    }
    for (i=0;i<4;i++)
    {
        if (count[i]>4)
        {
            points+=count[i]-4;
        }
    }
    return points;
}
//////////////////////////////////////////////////////////////
void response(struct hand A)
{
    int i;
    int count[4]={0};
    for (i=1;i<40;i+=3)
    {
        if (A.HANDD[i]=='S')
            count[0]+=1;
        if (A.HANDD[i]=='H')
            count[1]+=1;
        if (A.HANDD[i]=='D')
            count[2]+=1;
        if (A.HANDD[i]=='C')
            count[3]+=1;
    }

    if (hcp(A)+declarer(A)<13)
        printf("PASS");
    else if (balanced(A) && hcp(A)>=15 && hcp(A)<=17)
        printf("1NT");
    else if (balanced(A) && hcp(A)>=20 && hcp(A)<=21)
        printf("2NT");
    else if (hcp(A)>=22)
        printf("2 CLUBS");
    else if (hcp(A)<22 && (hcp(A)+declarer(A))>=13)
    {   
        if (count[0]>=5 && count[1]<=5)
            printf("1 SPADES");
        else if (count[1]>=5 && count[0]<count[1])
            printf("1 HEARTS");
        else if (count[2]>=4 && count[0]<5 && count[1]<5 && count[3]<5)
            printf("1 DIAMONDS");
        else if (count[0]<5 && count[1]<5 && count[2]<4)
            printf("1 CLUBS");
    }
    printf("\n");
}
//////////////////////////////////////////////////////////////