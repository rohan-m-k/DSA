//2nd lab program
#include<stdio.h>
int fact(int n)
{
if(n==0||n==1)
{
return 1;
}
else
return n*fact(n-1);
}
int n_number(int n)
{
if(n==0)
return 0;
else
return n+n_number(n-1);
}
int fib(int n)
{
if(n==0)
return 0;
else if(n==1)
return 1;
else
return (fib(n-1)+fib(n-2));
}
int main()
{
int n,c,i;
while(1)
{
printf("1 for Factorial\n2 for Natural Number\n3 for Fibonacci series\n4 for EXIT\n");
printf("\nEnter the choice\n");
scanf("%d",&c);
switch(c)
{
case 1:
printf("Enter the number to get factioral\n");
scanf("%d",&n);
if(n<0)
{
	printf("no factotial possible of negative numbers \n");
}
else
{
printf("factorial= %d\n",fact(n));
}
break;
case 2:
printf("Enter the number\n");
scanf("%d",&n);
if(n<0)
{
	printf("negative numbers are not natural numbers so sum is is not possible \n");
}
else
{
printf("Sum of Natural number is %d\n",n_number(n));
}
break;
case 3:
printf("Enter the numberr\n");
scanf("%d",&n);
if(n<0)
{
	printf("no fibonacci series  possible for negative numbers \n");
}
else
{
printf(" Fibonacci Series for %d numbers is\n",n);
for(i=0;i<n;i++)
{
printf("%d\t",fib(i));
}
}
printf("\n");
break;
case 4:return 0;
break;
default:printf("Entered choice is Invalid\n\n");
}
}
return 0;
}
