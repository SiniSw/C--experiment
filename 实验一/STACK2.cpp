//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
struct STACK{
    int  *elems;	//�����ڴ����ڴ��ջ��Ԫ��
    int   max;	//ջ�ܴ�ŵ����Ԫ�ظ���
    int   pos;	//ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
};
void initSTACK(STACK *const p, int m)	//��ʼ��pָ���ջ�����m��Ԫ��
{
        p->elems = (int*)malloc(sizeof(int)*m);
        p->max = m;
        p->pos = 0;
}
void initSTACK(STACK *const p, const STACK&s) //��ջs��ʼ��pָ���ջ
{
	p->elems = (int*)malloc(s.max*sizeof(int));
        for(int i=0;i<s.pos;i++)        
        p->elems[i] = s.elems[i];
        p->pos = s.pos;
        p->max = s.max;
}
int  size (const STACK *const p)		//����pָ���ջ�����Ԫ�ظ���max
{
        return p->max;
}
int  howMany (const STACK *const p)	//����pָ���ջ��ʵ��Ԫ�ظ���pos
{
        return p->pos;
}
int  getelem (const STACK *const p, int x)	//ȡ�±�x����ջԪ��
{
        return p->elems[x];
}
STACK *const push(STACK *const p, int e)	//��e��ջ��������p
{
		if (p->pos!=p->max)
		{
        p->elems[p->pos] = e;
        p->pos++;			
		}
        return p;
}
STACK *const pop(STACK *const p, int &e) 	//��ջ��e��������p
{		
		if(p->pos!=0)
		{
        e = p->elems[p->pos-1];
        p->pos--;			
    	}
        return p;
}
STACK *const assign(STACK *const p, const STACK&s) //��s��pָ��ջ,������p
{
		if(p->max!=s.max)
		p->elems = (int*)realloc(p->elems,s.max*sizeof(int));
        for(int i=0;i<s.pos;i++)        
        p->elems[i] = s.elems[i];
        p->pos = s.pos;
        p->max = s.max;
        return p;
}
void print(const STACK*const p)		        //��ӡpָ���ջ
{
        for(int i=0;i<p->pos;i++)
                printf("%d ",p->elems[i]);
}
void destroySTACK(STACK*const p)		//����pָ���ջ
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
