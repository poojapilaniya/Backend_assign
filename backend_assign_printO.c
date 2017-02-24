/* make a program which contains a bit string of length n without containing 2 zero adjacent*/

#include<stdio.h>
#include<stdlib.h>

void testcases_strLen();
void AllBitString(int,int *,int);
void MakeBitString(int , char *,int,int *,int);
 

int main()
{
	int action;
while(1)			// use of while(),so that user can run this program multiple times as user wants
{
        printf("choose an action which you want\n");
	printf("1.no. of test cases and bit string length for test cases\n 2.exit\n");
	scanf("%d",&action);
    
    switch(action){

	case 1:
	 testcases_strLen();	//  function call take inputs from user about no. of test cases and bit string length
		break;
	case 2:
           exit(1);		// exit program
 	   break;
	 default:
		printf("choose an right action\n");
}
}
	return(0);
}

void testcases_strLen()
{
	int t;		// no. of test cases
	 t1 : printf("Enter no. of test cases\n");
	printf("Enter string length for each test case\n");
	scanf("%d",&t);
	
	if(t <= 0 || t>= (10^3))			// check condition for test cases
	{
	 printf("you entered invalid test case no.\tdo you want re-enter no. of test cases \n");
	   /*char ans;
	scanf("%c",&ans);
            if(ans == 'y' || ans == 'Y')*/
		goto t1;
	    
           /* else
	       goto s1;*/
	}
	
	int strLen[t],i,counter[t];		// strLen[t]  to store bit string length of each test case
	  for(i=0;i<t;i++)			// counter[t] to store total no. of outputs for each test case
	{
	    t2: scanf("%d",&strLen[i]);
	      if(strLen[i] <= 0 || strLen[i] >= (10^15))	// check condition for bit string
		{
		 printf("Re-enter bit string length\n");
	    		goto t2;
		}
	counter[i]=0;				// initially output for each case is zero
	}
   
     for(i=0;i<t;i++)		//to generate bit string for each test case
      AllBitString(strLen[i],counter,i);   
      			    // pass three parameters string length of particular test case, address of output array,particular test case no. 									
	printf("output\n");
	for(i=0;i<t;i++)
	{
	   counter[i] = (counter[i]) % (10^9+7);			
	   printf("for test case %d output is %d\n",i+1,counter[i]); // print output
	}
}
 

void AllBitString(int n,int * counter,int i)	// generate all possible  bit string
{
	char BitStr[n];		//bit string of length n
	BitStr[0] = '0' ;	// bit string start with 0
	MakeBitString(n,BitStr,1,counter,i);
		
	BitStr[0] = '1' ;	// bit string start with 1
	MakeBitString(n,BitStr,1,counter,i);
}
	

void MakeBitString(int n,char string[],int k,int *counter,int tcn)	//create bit string to length l with given conditions
{
	int i;

	if(n == k)
	{
	   string[n]= '\0' ;				// to terminate string
	     *(counter+tcn) = *(counter+tcn)+1;		// when one string is created then increased the counterno.
	    for(i=0;string[i] != '\0'; i++)		// to print string
		printf("%c",string[i]);
		printf("\n");
		
	}
	else if(string[k-1]=='0'){  //no two should be adjacent so that if previous position contains 0 then current position holds 1
		string[k] = '1';
		MakeBitString(n,string,k+1,counter,tcn);
		
	}
	else if(string[k-1] == '1')//if previous position contains 1 then current position can have two options to fill position are 0 or 1
	{
		string[k] = '1';
		MakeBitString(n,string,k+1,counter,tcn);
		
		string[k] = '0';
		MakeBitString(n,string,k+1,counter,tcn);
	}
	
}

