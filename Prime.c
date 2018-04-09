/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
#include<stdio.h>


int sum_bit(int num) 
{
	int sumbit,b1,a1;
	b1=0;
	while(1)
    {
		a1=num%10;
        num=num/10;
        if ((num!=0)||(num==0&&a1!=0))
		    b1=b1+a1;
		else
			break;

	}
	sumbit=b1;
    return sumbit;
}



int multi_bit(int num) 
{
    int b2,a2;
	b2=1;
	while(1)
    {
		a2=num%10;
        num=num/10;
        if ((num!=0)||(num==0&&a2!=0))
		    b2=b2*a2;
		else
			break;

	}

    return b2;
}



int square_sum_bit(int num) 
{
    int b3,a3;
    b3=0;
	while(1)
    {
		a3=num%10;
        num=num/10;
        if ((num!=0)||(num==0&&a3!=0))
		    b3=b3+a3*a3;
		else
			break;

	}
    return b3;
}



int isprime(int num)
{
  int i,t;
  for(i=2;i<num;i++)
  {
	  t=num%i;
	  if(t==0)
		  break;
  }



  if (i==num)
  {return 1;}
  else
  {return 0;}

}



int main() 
{
   int a,c=0,sum=0,x;
   int b[10000];
   for(a=100;a<10000;a++)
   {
      if(isprime(a)&&isprime(sum_bit(a))&&isprime(multi_bit(a))&&isprime(square_sum_bit(a)))
	  {
	    b[c]=a;
	    c++;
	  }
   }
   for(x=0;x<c;x++)
	   sum=sum+b[x];

   printf("超级素数个数：%d",c);
   printf("超级素数之和：%d",sum);
   printf("最大的超级素数：%d",b[c-1]);




    return 0;

}
