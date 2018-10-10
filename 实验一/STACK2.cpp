//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
struct STACK{
    int  *elems;	//申请内存用于存放栈的元素
    int   max;	//栈能存放的最大元素个数
    int   pos;	//栈实际已有元素个数，栈空时pos=0;
};
void initSTACK(STACK *const p, int m)	//初始化p指向的栈：最多m个元素
{
        p->elems = (int*)malloc(sizeof(int)*m);
        p->max = m;
        p->pos = 0;
}
void initSTACK(STACK *const p, const STACK&s) //用栈s初始化p指向的栈
{
	p->elems = (int*)malloc(s.max*sizeof(int));
        for(int i=0;i<s.pos;i++)        
        p->elems[i] = s.elems[i];
        p->pos = s.pos;
        p->max = s.max;
}
int  size (const STACK *const p)		//返回p指向的栈的最大元素个数max
{
        return p->max;
}
int  howMany (const STACK *const p)	//返回p指向的栈的实际元素个数pos
{
        return p->pos;
}
int  getelem (const STACK *const p, int x)	//取下标x处的栈元素
{
        return p->elems[x];
}
STACK *const push(STACK *const p, int e)	//将e入栈，并返回p
{
		if (p->pos!=p->max)
		{
        p->elems[p->pos] = e;
        p->pos++;			
		}
        return p;
}
STACK *const pop(STACK *const p, int &e) 	//出栈到e，并返回p
{		
		if(p->pos!=0)
		{
        e = p->elems[p->pos-1];
        p->pos--;			
    	}
        return p;
}
STACK *const assign(STACK *const p, const STACK&s) //赋s给p指的栈,并返回p
{
		if(p->max!=s.max)
		p->elems = (int*)realloc(p->elems,s.max*sizeof(int));
        for(int i=0;i<s.pos;i++)        
        p->elems[i] = s.elems[i];
        p->pos = s.pos;
        p->max = s.max;
        return p;
}
void print(const STACK*const p)		        //打印p指向的栈
{
        for(int i=0;i<p->pos;i++)
                printf("%d ",p->elems[i]);
}
void destroySTACK(STACK*const p)		//销毁p指向的栈
{
        for(int i=p->max-1;i>=0;i--)
                free((p->elems+i));
        free(p);
}
int main(int argc, char* argv[])
{
	int flag;
	int e;
	FILE *fp;
	STACK*const p=(STACK*)malloc(sizeof(STACK));;
		if(argc>=2)
		{
			fp=fopen(argv[0],"a+");
			for(int i=1;i<argc-1;i++)
			{
			if(argv[i][0]=='-')
			{
				if(argv[i][1]=='S')
				{
				fprintf(fp,"%c",argv[i][1]);
				fprintf(fp, " ");
				flag=0;			
				}
				if(argv[i][1]=='I')
				{
				fprintf(fp,"%c",argv[i][1]);
				fprintf(fp, " ");
				flag=1;
				}
				if(argv[i][1]=='O')
				{
				fprintf(fp,"%c",argv[i][1]);
				fprintf(fp, " ");
				flag=2;
				}
			}
			else{
				switch(flag)
				{
					case 0:initSTACK(p,atoi(argv[i]));break;
					case 1:push(p,atoi(argv[i]));break;
					case 2:for(int j=atoi(argv[i]);j<atoi(argv[2]);i++)
								pop(p,e);
							break;
					default:break;					
				}
				fprintf(fp,"%d",argv[i]);
			}
			}
			print(p);
		}
        return 0;
}
//---------------------------------------------------------------------------
