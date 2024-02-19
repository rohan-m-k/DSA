//2nd lab program
#include<stdio.h>
int fact(int n)
{
if(n==0)
return 1;
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
printf("1 for Factorial\n2 for Natural Number\n3 for Fibonacci series\n4 for EXIT\n");
while(1)
{
printf("\nEnter the choice\n");
scanf("%d",&c);
switch(c)
{
case 1:
printf("Enter the number to get factioral\n");
scanf("%d",&n);
fact(n);
printf("factorial= %d\n",fact(n));
case 2:
printf("Enter the number\n");
scanf("%d",&n);
n_number(n);
printf("Sum of Natural number is %d\n",n_number(n));
break;
case 3:
printf("Enter the number\n");
scanf("%d",&n);
fib(n);
printf("Sum of %d Fibonacci Series is\n",n);
for(i=0;i<n;i++)
{
printf("%d\t",fib(i));
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
