#include<stdio.h>
#include<stdlib.h>
void* (*fn)(void*,void*);
typedef struct complex
{
int r,i;
}cplx;
void* int_sum(void* n1,void* n2)
{
int *s = (int*)malloc(sizeof(int));
*s=*(int*)n1 + *(int*)n2;
return s;
}
void* float_sum(void* n1,void* n2)
{
float* s=(float*)malloc(sizeof(float));
*s=*(float*)n1+*(float*)n2;
return s;
}
void* complex_sum(void* n1,void* n2)
{
cplx* s=(cplx*)malloc(sizeof(cplx));
s->r=((cplx*)n1)->r+((cplx*)n2)->r;
s->i=((cplx*)n1)->i+((cplx*)n2)->i;
return s;
}
void* sum_two_no(void* n1,void* n2,void* (*fn)())
{
return fn(n1,n2);
}
void* getfun(int c)
{
switch(c)
{
case 1:
return &int_sum;
break;
case 2:
return &float_sum;
break;
case 3:
return &complex_sum;
break;
default:
return NULL;
}
}
int main()
{
int c;
void* n1,*n2;
while(1)
{
printf("1 for Interger Sum\n2 for Floating point sum\n3 for Complexsum\n4 for exit\n");
printf("Enter the choice\n");
scanf("%d",&c);
switch(c)
{
case 1:
n1 = (int*)malloc(sizeof(int));
n2 = (int*)malloc(sizeof(int));
fn = getfun(c);
printf("Enter the 2 Integer numbers\n");
scanf("%d %d",(int*)n1,(int*)n2);
printf("Sum = %d\n", *(int*)sum_two_no(n1,n2,fn));
break;
case 2:
n1 = (float*)malloc(sizeof(float));
n2 = (float*)malloc(sizeof(float));
fn = getfun(c);
printf("Enter the 2 Floating numbers\n");
scanf("%f %f",(float*)n1,(float*)n2);
printf("Sum = %f\n", *(float*)sum_two_no(n1,n2,fn));
break;
case 3:
n1=(cplx*)malloc(sizeof(cplx));
n2=(cplx*)malloc(sizeof(cplx));
fn=getfun(c);
printf("Enter the First complex numbers\n");
printf("Real number: \n");
scanf("%d",&((cplx*)n1)->r);
printf("Imaginer Nmber: \n");
scanf("%d",&((cplx*)n1)->i);
printf("Enter the Second complex numbers\n");
printf("Real number: \n");
scanf("%d",&((cplx*)n2)->r);
printf("Imaginer Number: \n");
scanf("%d",&((cplx*)n2)->i);
cplx* s=(cplx*)sum_two_no(n1,n2,fn);
printf("Real Part=%d\n",s->r);
printf("Imaginer part=%d\n",s->i);
free(s);
break;
case 4:return 0;
default:
printf("Entered choice is invalid\n");
}
free(n1);
free(n2);
}
}
