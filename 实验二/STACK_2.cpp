//---------------------------------------------------------------------------

#include <vcl.h>
#include<iostream>
#pragma hdrstop
using namespace std;
//---------------------------------------------------------------------------

#pragma argsused
class STACK{
    int  *const  elems;	        //申请内存用于存放栈的元素
    const  int   max;	        //栈能存放的最大元素个数
    int   pos;			//栈实际已有元素个数，栈空时pos=0;
public:
STACK(int m):pos(0),max(m),elems(new int[m])  	//初始化栈：最多m个元素
{}
STACK(const STACK&s):pos(s.pos),max(s.max),elems(new int[s.max])    //用栈s拷贝初始化栈
{
        for(size_t i = 0;i<pos;i++)
        {
                elems[i]=s.elems[i];
        }
}
int  size ( ) const    	//返回栈的最大元素个数max
{
        return max;
}
int  howMany ( ) const 	//返回栈的实际元素个数pos
{
        return pos;
}
int  getelem (int x) const	//取下标x处的栈元素
{
        return elems[x];
}
STACK& push(int e) 	        //将e入栈,并返回栈
{
        if(pos!=max)
        {
                elems[pos]=e;
                pos++;
        }
        return *this;
}
STACK& pop(int &e)      	//出栈到e,并返回栈
{
        if(pos)
        {
                elems[pos]=e;
                pos--;
        }
        return *this;
}
STACK& assign(const STACK&s)   //赋s给栈,并返回被赋值的栈
{
                pos=s.pos;
                for(size_t i = 0;i<pos;i++)
                {
                        elems[i]=s.elems[i];
                }
        return *this;
}
void print( ) const		//打印栈
{
                for(size_t i = 0;i<pos;i++)
                {
                        cout<<elem[i]<<" ";
                }
                cout<<endl;
}
~STACK(){  delete []elems; }                      //销毁栈
};
int main(int argc, char* argv[])
{
	int flag=0;
	int e;
	FILE *fp=fopen("U201614754_1.txt","w+");
	STACK* p=NULL;
	STACK s;
		for(int i=1;i<argc;i++)
	{
			if(argv[i][0]=='-')
			{	
				if(argv[i][1]=='S')
				{
					e = atoi(argv[i+1]);
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
					case 1: p=new STACK(e);;
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
					case 5: p =new STACK()
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
	if(flag!=8&&flag!=6&&flag!=7)
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
