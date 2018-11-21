//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
/*#include <malloc.h>*/
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
		if(p->max<s.max)
		{
			p->elems = (int*)realloc(p->elems,s.max*sizeof(int));
        	p->max = s.max;
		}
        for(int i=0;i<s.pos;i++)        
        p->elems[i] = s.elems[i];
        p->pos = s.pos;
        return p;
}
void print(const STACK*const p)		        //打印p指向的栈
{
        for(int i=0;i<p->pos;i++)
                printf("%d  ",p->elems[i]);
}
void destroySTACK(STACK*const p)		//销毁p指向的栈
{
        for(int i=p->max-1;i>=0;i--)
                free((p->elems+i));
        p->elems = NULL;
        p->max = 0;
        p->pos = 0;
}
int main(int argc, char* argv[])
{
	int flag=0;
	int e;
	FILE *fp=fopen("U201614754_1.txt","w+");
	STACK* p=(STACK*)malloc(sizeof(STACK));
	STACK s;
		for(int i=1;i<argc;i++)
	{
			if(argv[i][0]=='-')
			{	
				if(argv[i][1]=='S')
				{
					printf("S  ");
					fprintf(fp,"%c  ",argv[i][1]);
					if(flag!=0)
					{
						printf("E  ");
						fprintf(fp,"E  ");
						i=argc;
						flag=8;
					}		
					flag=1;
                }
                else if(flag!=6&&flag!=7)
                {
                	for(int j=0;j<p->pos;j++)
			    {
	 					printf("%d  ", p->elems[j]);
	  					fprintf(fp,"%d  ", p->elems[j]);
				}	
				}
				if(argv[i][1]=='I')
				{
					printf("I  ");
					fprintf(fp,"%c  ",argv[i][1]);
                    if(flag==0)
					{
						printf("E  ");
						fprintf(fp,"E  ");
						i=argc;
						flag=8;
					}
					flag=2;
				}
				if(argv[i][1]=='O')
				{
					printf("O  ");
					fprintf(fp,"%c  ",argv[i][1]);
                    if(flag==0)
					{
						printf("E  ");
						fprintf(fp,"E  ");
						i=argc;
						flag=8;
					}
					flag=3;
				}
				if(argv[i][1]=='C')
				{
					printf("C  ");
					fprintf(fp,"%c  ",argv[i][1]);
                    if(flag==0)
					{
						printf("E  ");
						fprintf(fp,"E  ");
						i=argc;
						flag=8;
					}
					flag=4;
				}
				if(argv[i][1]=='A')
				{
					printf("A  ");
					fprintf(fp,"%c  ",argv[i][1]);
                    if(flag==0)
					{
						printf("E  ");
						fprintf(fp,"E  ");
						i=argc;
						flag=8;
					}
					flag=5;
				}
				if(argv[i][1]=='N')
				{
					printf("N  ");
					fprintf(fp,"%c  ",argv[i][1]);
                    if(flag==0)
					{
						printf("E  ");
						fprintf(fp,"E  ");
						i=argc;
						flag=8;
					}
					e=howMany(p);
					printf("%d  ", e);
					fprintf(fp,"%d  ", e);
					flag=6;
				}
				if(argv[i][1]=='G')
				{
					printf("G  ");
					fprintf(fp,"%c  ",argv[i][1]);
                    if(flag==0)
					{
						printf("E  ");
						fprintf(fp,"E  ");
						i=argc;
						flag=8;
					}
					flag=7;
				}
			}
			else{
				switch(flag)
				{
					case 1: initSTACK(p,atoi(argv[i]));
                            printf("%d  ",atoi(argv[i]));
							fprintf(fp,"%d  ",atoi(argv[i]));
							break;
					case 2: if(p->pos==p->max)
							{
								printf("E  ");
								fprintf(fp,"E  ");
								i=argc;	
								flag=8;						
							}
							else
							{
								push(p,atoi(argv[i]));
							}
							break;
					case 3: if(p->pos<atoi(argv[i]))
							{
						
								printf("E  ");
								fprintf(fp,"E  ");
								i=argc;	
								flag=8;					
							}
							else
							{
								for(int j=0;j<atoi(argv[i]);j++)
								{
									pop(p,e);
								}
							}
							break;
					case 4: s.pos = atoi(argv[i]);
							initSTACK(&s, *p);
							p = assign(p, s);
							break;
					case 5: initSTACK(&s, *p);
							p = assign(p, s);					
							break;
					case 6: 
							break;
					case 7: if(p->pos<atoi(argv[i]))
							{
						
								printf("E  ");
								fprintf(fp,"E  ");
								i=argc;	
								flag=8;					
							}
							else
							{
							e=getelem(p,atoi(argv[i]));
							printf("%d  ", e);
							fprintf(fp,"%d  ", e);								
							}
							break;					
					default:break;					
				}
			}
	}
	if(argc!=1&&flag!=8&&flag!=6&&flag!=7)
	{
                for(int j=0;j<p->pos;j++)
			    {
	 					printf("%d  ", p->elems[j]);
	  					fprintf(fp,"%d  ", p->elems[j]);
				}			
	}
    return 0;
}
//---------------------------------------------------------------------------
