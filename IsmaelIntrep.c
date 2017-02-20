#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Ismael Melendez
 * Spring 2017
 * Phase 1
 * This application is phase 1 of a semester project. 
 * It is an intrepreter that uses loops (no standard routines) to
 * read in a line from user. Then it identifies and does corresponding procedures
 * in the following phases (2,3,4) more fuction will be implemented.
 */

/*function declarations*/
 void checkinput(char *input, int *flag);
 void loadfilename();
 void execute();
 void debug();
 void dumpse();
 void assemblefile();
 void loadfilename();
 void directory();
 void help();
 int kill(int flag);

int main()
{
	char input[80];
	printf("Welcome!\n "); 
	int continue_flag=1;// To check if exit is requested form user
	while(continue_flag==1){ // will continue to run commands until user inputs 'exit'
	printf("Please enter a command:\n ");
		printf(">>");
		fgets(input, 80, stdin);

	printf("Entered input is:%s\n", input);
	checkinput(input, &continue_flag);	
	}
}
/*
   This function takes a line and breaks it into words.
   The orginal line is in the char array str, the first word
   will go into the char array c, the second into p1, and the
   the third into p2.   
   At the end, n contains the number of
   words read.
*/
void breakUp(char a[3][20],char *str,int *n)
{
    int wordctr=0;
    int letterctrforstring=0;//int letterctrforwordinarray=0;
    char letternow;
	letternow = str[letterctrforstring];//set letter now to first letter in string
	while(letternow!='\0') //while have not reached end of line
	{
		//~ printf ("input sentence is: %s current letter is %c\n\n\n ", str,letternow);//for debugging
		//~ printf("before, currentletter from string and letterctrforstring is set to %c,%d\n",letternow,letterctrforstring);//for debuggin
		int letterctrforwordinarray=0;
		if(letterctrforstring!=0&&letternow==' ')//check if letterctr is not zero
		{
			letterctrforstring=letterctrforstring+1;
			letternow=str[letterctrforstring];
			printf(" AT THE IF AT THE IF AT THE IF IS %c\n", letternow);
		}
		
		while(letternow!=' ')
		{		
			//printf("letterctrforwordinarraycomingupCTR %d 2222 current lettercominupIS is %c\n",letterctrforwordinarray, letternow);
			//printf(" WORD COUNT AT START OF WORD IS%d\n", wordctr);
			//~ printf(" LETTER AT START OF WORD IS%c\n", letternow); //For debugging
			// Index for the word location and the letter
			a[wordctr][letterctrforwordinarray]=letternow;
			//~ printf("22222222**************** %s\n", a[wordctr]); //For debugging
			//OUTPUTS Current letter and its index
			//~ printf(" Character = %c %d\n", letternow,letterctrforstring);//For debugging
			letterctrforwordinarray=letterctrforwordinarray+1;			
			if(letternow=='\0')//check if we reached end of string
			{
				break;
			}
			letterctrforstring=letterctrforstring+1;
			letternow=str[letterctrforstring];
			//~ printf("*************************** %s\n", a[wordctr]); //For debugging
		}
		if(wordctr>3)//check if more than three paramaters; if so break
		{
			wordctr=-1;
			break;
		}
		if(letternow=='\0')//check if we reached end of string; break
		{
			break;
		}
		wordctr=wordctr+1;		
		letternow = str[letterctrforstring];
	}
	*n=wordctr;
	//~ printf(" WORD COUNT IN OUTER LOOP IS%d\n", wordctr); //For debuggin
	//~ printf("OUT SIDE I AM %s\n", a[0]);	 //For debuggin
}
void checkinput(char *inputhere, int *flag)
{
 char *loadcompare="load";
 char *execompare="execute";
 char *debugcompare="debug";
 char *dumpsecompare="dump";
 char *assemcompare="assemble";
 char *helpcompare="help";
 char *exitcompare="exit";
 char *dircompare="directory";
 char a[3][20]={{'\0'}};;// empty array to store tokes from strin as c,p1,p2
 char *c,*p1,*p2;
 int length, n;
 
 /* get rid of trailing newline character */
 length = strlen(inputhere) - 1;
 if (inputhere[length] == '\n')
	inputhere[length] = '\0';

 /* Break up the line */
 breakUp(a, inputhere, &n);
 //~ printf("check input function | 1 |%s test1\n", a[0]); //For debugging
 //~ printf("check input function | 2 |%s test2\n", a[1]); //For debugging
 //~ printf("check input function | 3 |%s test3\n", a[2]); //For debugging
 c=a[0];
 p1=a[1];
 p2=a[2];

    //~ printf ("%d things on this line\n", n);
    printf ("command: %s\n", c);
    printf ("parameter 1: %s\n", p1);
    printf ("parameter 2: %s\n\n", p2);
    int *temp=flag;
	if(n==0)
	{
		//~ printf("One it is\n");
		if (strcmp(execompare, c) == 0)
		{execute();}
		else if (strcmp(debugcompare, c) == 0)
		debug();
		else if (strcmp(helpcompare, c) == 0)
		help();
		else if (strcmp(dircompare, c) == 0)
		directory();
		else if (strcmp(exitcompare, c) == 0)
		{*flag=kill(*temp);}
		else
		{
		printf ("COMMAND NOT RECOGNIZED OR NO INPUT FROM USER (1)");
		}
	}
	else if(n==1)
	{
		//~ printf("Two it is");
		if(strcmp(loadcompare, c) == 0)//TODO: CHECK IF ONE PARAMTER
		loadfilename();
		else if (strcmp(assemcompare, c) == 0)//TODO: CHECK IF ONE PARAMTER
		assemblefile();
		else
		{
		printf ("COMMAND NOT RECOGNIZED (2)");
		}
	}
	else if(n==2)
	{
		//~ printf("Three it is\n");
		if (strcmp(dumpsecompare, c) == 0)
		dumpse();
		else
		{
		printf ("COMMAND NOT RECOGNIZED (3)");
		}
	}
	else
	{
	 printf("I don't understand your input, try again\n");
	 printf("Type help for more options\n");
	}

}
void loadfilename()
{
	printf("***loadfilename is empty***\n");
}
void execute()
{
	printf("***execute is empty***\n");
}
void debug()
{
	printf("***debug is empty***\n");
}
void dumpse()
{
	printf("***dumpse is empty***\n");
}
void assemblefile()
{
	printf("***assemblefile is empty***\n");
}
void help()
{
	printf("Available commands:\n");
	printf("load [filename]\n");
	printf("execute\n");
	printf("debug\n");
	printf("dump [start] [end]\n");
	printf("help\n");
	printf("assemble [file]\n");
	printf("directory\n");
	printf("exit\n");
}
void directory()
{
 system("ls");
}
int kill(int flag)
{
 printf("Good bye\n");
 return 0;
 
}

