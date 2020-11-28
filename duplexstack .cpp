#include <stdio.h>
#include <stdlib.h>


typedef struct
{
	int s[10];
	int top1;
	int top2;
} sqstack;

void push(sqstack *stack, int x, int flag)  //void push(sqstack &stack , int x,int flag)//ע�⣺cpp��ʽ
{
	if (stack->top1+1==stack->top2)
		printf("stack is full\n");
	else 
	{
		if (flag==1)
		{
			stack->top1++;
			stack->s[stack->top1]=x;
		}
		else if(flag==2)
		{
			stack->top2--;
			stack->s[stack->top2]=x;
		}
		else
			printf("input error\n");
	}
}
void pop(sqstack *stack, int flag) //(sqstack &stack , int &y, int flag) //ע�⣺cpp��ʽ 
{
	if (flag==1) 
		if(stack->top1<0)
			printf("empty\n");
		else
		{
			stack->s[stack->top1];
			stack->top1--;
		}
	else if(flag==2)
		if(stack->top2>=10)
			printf("empty\n");
		else
		{
			stack->s[stack->top2];
			stack->top2--;
		}
		else
			printf("input error\n");
}

void main()
{
	int flag, x, want, i1, i2, i;
	sqstack stack;
	stack.top1=-1;
	stack.top2=10;
	
	while(1)
	{
		
		printf("������Ҫ��ʲô,1-��ջ��2-��ջ������-�˳���");
		scanf("%d",&want);
		if(want == 1) 
		{
			printf("������Ҫ��ջ�����֣�");
			scanf("%d",&x);
			printf("������Ҫ��ջ�ķ��Ŵ���1-S1��2-S2��");
			scanf("%d",&flag);
			if(flag !=1 && flag != 2)
			{
				printf("�������\n");
				continue;
			} 
			push(&stack, x, flag);
		}	
		else if(want == 2) 
		{
			printf("������Ҫ��ջ�ķ��Ŵ���1-S1��2-S2��");
			scanf("%d",&flag);
			if(flag !=1 && flag != 2)
			{
				printf("�������\n");
				continue;
			}
			pop(&stack, flag);
		}
		else
			break; 
	}
	i1=stack.top1;
	printf("S1:"); 
	while(i1>=0)
	{
		printf("%d",stack.s[i1]);
		i1--;
	}
	printf("\n"); 
	i2=stack.top2;
	printf("S2:");
	while(i2<=9)
	{
		printf("%d ",stack.s[i2]);
		i2++;
	}
	printf("\n"); 
	printf("S1+S2:");
	i1=0; 
	while(i1<=stack.top1)
	{
		printf("%d ",stack.s[i1]);
		i1++;
	}
	i=i1;
	while(i<stack.top2)
	{
		printf("_ ");
		i++;
	}
	i2=stack.top2;
	while(i2<=9)
	{
		printf("%d ",stack.s[i2]);
		i2++;
	}
}

