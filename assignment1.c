//assignment 1
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
int rpart,ipart;
}cplx;
typedef void*(*fun)(void*,void*);
void* cplx_sum(void*,void*);
void* int_sum(void*,void*);
void* float_sum(void*,void*);
void* sum_two_nos(void*,void*,fun);
fun getfun(int);
void* cplx_sum(void*p1,void*p2)
{
cplx*pc1=(cplx*)p1;
cplx*pc2=(cplx*)p2;
 cplx*pc3=(cplx*)malloc(sizeof(cplx));
 pc3->rpart=pc1->rpart+pc2->rpart;
 pc3->ipart=pc1->ipart+pc2->ipart;
 return pc3;
}
void* int_sum(void*p1,void*p2)
{
int *pi1=(int*)p1;
int *pi2=(int*)p2;
int *pi3=(int*)malloc(sizeof(int));
*pi3=*pi1+*pi2;
return pi3;
}
void* float_sum(void*p1,void*p2)
{
float*pf1=(float*)p1;
float*pf2=(float*)p2;
float*pf3=(float*)malloc(sizeof(float));
*pf3=*pf1+*pf2;
return pf3;
}
fun getfun(int choice)
{
switch(choice)
{
case 1:return(&cplx_sum);
 break;
case 2:return(&int_sum);
 break;
case 3:return(&float_sum);
 break;
default:printf("fp=NULL");
}
return NULL;
}
void* sum_two_nos(void*op1,void*op2,fun fp)
{
return (fp(op1,op2));
}
int main()
{
fun fp;
cplx*pc1;
cplx*pc2;
cplx*pcresult;
int *pi1,*pi2,*piresult;
float *pf1,*pf2,*pfresult;
int choice;
printf("enter your choice\n");
printf("enter 1.complex number addition\t 2.integer addition 3.float addition ");
scanf("%d",&choice);
fp=getfun(choice);
 switch(choice)
 {
case 1:printf("enter real and imaginary part of complex number 1\n");
 pc1=(cplx*)malloc(sizeof(cplx));
 scanf("%d%d",&(pc1->rpart),&(pc1->ipart));
 printf("enter real and imaginary part of complex number 2\n");
 pc2=(cplx*)malloc(sizeof(cplx));
 scanf("%d%d",&(pc2->rpart),&(pc2->ipart)); 
 pcresult=(cplx*)sum_two_nos(pc1,pc2,fp);
 printf("real part =%d\t imaginary part=%d\n",pcresult->rpart,pcresult->ipart);
 break;
 case 2:printf("enter two integers \n");
 pi1=(int*)malloc(sizeof(int));
 scanf("%d",pi1);
 pi2=(int*)malloc(sizeof(int));
 scanf("%d",pi2);
 piresult=(int*)sum_two_nos(pi1,pi2,fp);
 printf("sum of %d and %d is %d\n",*pi1,*pi2,*piresult);
 break;
 case 3:printf("enter two numbers\n");
 pf1=(float*)malloc(sizeof(float));
 scanf("%f",pf1);
 pf2=(float*)malloc(sizeof(float));
 scanf("%f",pf2);
 pfresult=(float*)sum_two_nos(pf1,pf2,fp);
 printf("sum = %f\n",*pfresult);
 break;
 }
 
 return 0;
}
