#include <stdio.h>
#include <math.h>

// n = number of stick to play
// pp = print pile
// uturn = You pick/Player pick
// cturn = CPU pick

int checkinput(char *);
void pp(int );
int checkupick (char *);
int checkifzero (int );
int cturn(int);

int main (int argc, char **argv)
{       char str[10], pile, uturn[10], temp[10];
    int n, i, r=1;
    int upick, cpick, returnvalue;
    if (argc==1)
    {
        printf ("\nWelcome to match stick game!\n");
        printf("How many stick would you like to start with?: ");
        fgets(str, 10, stdin);
        n=checkinput(str);
//      printf ("%d", n);
        if(n==-1)
        {       printf("You need to start with at least 10 sticks. Goodbye.\n");
            return (0);
        }

        printf ("We will be playing with %d sticks\n", n);
        printf ("Each turn, a player can take 1, 2 or 3 sticks. \nWhoever takes the last stick wins the game! Goodluck!!\n");

        i=n;
        printf( "Initial Pile: ");

        pp(n);

        while(n>0)
        {       printf("How many stick do you want to take?(1-3): ");
            fgets(uturn, 10, stdin);
            upick=checkupick(uturn);
//              printf("%d", upick);
            while (upick==-1)
            {       printf("You must enter between 1-3 : ");
                fgets(uturn, 10, stdin);
                upick=checkupick(uturn);
            }

            if (upick!=-1)
            {       n=n-upick;
                printf("You pick %d stick(s)\n", upick);
                printf("Remaining Pile: ");
                pp(n);
                if (r==checkifzero(n))
                {       printf("You won!! Goodbye!\n");
                    return 0;
                }
            }

            cpick=cturn(n);
//              printf("cpick= %d\n", cpick);
            n=n-cpick;
            printf("I pick %d stick(s)\n", cpick);
            printf("Remaining Pile: ");
            pp(n);
            if (r==checkifzero(n))
            {       printf("I won!! Goodbye!\n");
                return 0;
            }
        }
    }

    if (argc==2)
    {
        returnvalue=sscanf(argv[1], "%s", temp);
        n=checkinput(temp);
//      printf ("returnvalue =%d and n= %d", returnvalue, n);
        if(n==-1)
        {       printf("You need to start with at least 10 sticks. Goodbye.\n");
            return (0);
        }

        printf ("We will be playing with %d sticks\n", n);
        printf ("Each turn, a player can take 1, 2 or 3 sticks. \nWhoever takes the last stick wins the game! Goodluck!!\n");
        printf( "Initial Pile: ");
        pp(n);

        while(n>0)
        {       printf("How many stick do you want to take?(1-3): ");
            fgets(uturn, 10, stdin);
            upick=checkupick(uturn);
//              printf("%d", upick);
            while (upick==-1)
            {       printf("You must enter between 1-3 : ");
                fgets(uturn, 10, stdin);
                upick=checkupick(uturn);
            }

            if (upick!=-1)
            {       n=n-upick;
                printf("You pick %d stick(s)\n", upick);
                printf("Remaining Pile: ");
                pp(n);
                if (r==checkifzero(n))
                {       printf("You won!! Goodbye!\n");
                    return 0;
                }
            }

            cpick=cturn(n);
//              printf("cpick= %d\n", cpick);
            n=n-cpick;
            printf("I pick %d stick(s)\n", cpick);
            printf("Remaining Pile: ");
            pp(n);
            if (r==checkifzero(n))
            {       printf("I won!! Goodbye!\n");
                return 0;
            }
        }
    }

    else
    {       printf ("Invalid input. Goodbye.\n");
        return 0;
    }

    return 0;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int checkinput (char *n)
{       int result, str;
    char temp [10];
    result =sscanf(n, "%d%s", &str, temp);
    if (result==1)
    {       if(str<10)
        {return(-1);}
        else
        {return (str);}
    }
    else
    {       return (-1);}
}

void pp (int n)
{       char stick;
    int i=n;
    while(i>0)
    {       printf("|");
        i=i-1;
    }
    printf (" (%d)\n", n);
}

int checkupick (char *n)
{       int result, str;
    char temp [10];
    result =sscanf(n, "%d%s", &str , temp);
    if (result==1)
    {       if(str>=1 && str<=3)
            return (str);
        else
            return (-1);
    }
    else
        return (-1);
}

int checkifzero (int n)
{       if (n==0)
        return (1);
    return (-1);
}

int cturn (int n)
{       int r;
    r=n%4;
    if (r==0)
        return (1);
    return (r);
}
