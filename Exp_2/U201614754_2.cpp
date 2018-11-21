//---------------------------------------------------------------------------

//#include <vcl.h>
#include<iostream>
#include<cstdlib>
#include <fstream> 
#pragma hdrstop
using namespace std;
//---------------------------------------------------------------------------

#pragma argsused
fstream outfile;
class STACK{
    int  *const  elems;	        //�����ڴ����ڴ��ջ��Ԫ��
    const  int   max;	        //ջ�ܴ�ŵ����Ԫ�ظ���
    int   pos;					//ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
public:
STACK(int m):pos(0),max(m),elems(new int[m])  	//��ʼ��ջ�����m��Ԫ��
{}
STACK(const STACK&s):pos(s.pos),max(s.max),elems(s.elems)    //��ջs������ʼ��ջ
{}
int  size ( ) const    	//����ջ�����Ԫ�ظ���max
{
        return max;
}
int  howMany ( ) const 	//����ջ��ʵ��Ԫ�ظ���pos
{
        return pos;
}
int  getelem (int x) const	//ȡ�±�x����ջԪ��
{
        return elems[x];
}
STACK& push(int e) 	        //��e��ջ,������ջ
{
        if(pos!=max)
        {
                elems[pos]=e;
                pos++;
        }
        return *this;
}
STACK& pop(int &e)      	//��ջ��e,������ջ
{
        if(pos)
        {
                elems[pos]=e;
                pos--;
        }
        return *this;
}
STACK& assign(const STACK&s)   //��s��ջ,�����ر���ֵ��ջ
{
		int **p = (int**)&elems;
		*p = s.elems;
		int *q = (int*)&max;
		*q = s.max;
		pos = s.pos;
		return *this;
}
void print( ) const		//��ӡջ
{
                for(size_t i = 0;i<pos;i++)
                {
                        cout<<elems[i]<<"  ";
						outfile<< elems[i]<< "  ";
                }
}
~STACK(){  delete []elems; }                      //����ջ
};
int main(int argc, char* argv[])
{
	int flag=0;
	int e;
	outfile.open("U201614754_2.txt", ios::out);
	STACK* p=NULL;
	STACK* s;
	
		for(int i=1;i<argc;i++)
	{
			if(argv[i][0]=='-')
			{	
				if(argv[i][1]=='S')
				{
					e = atoi(argv[i+1]);
					cout<<"S  ";
					outfile<<"S  ";
					if(flag!=0)
					{
						cout<<"E  ";
						outfile<<"E  ";
						i=argc;
						flag=8;
					}		
					flag=1;
                }
                else if(flag!=6&&flag!=7)
                {
					p->print();
				}
				if(argv[i][1]=='I')
				{
					cout<<"I  ";
					outfile<<"I  ";
                    if(flag==0)
					{
						cout<<"E  ";
						outfile<<"E  ";
						i=argc;
						flag=8;
					}
					flag=2;
				}
				if(argv[i][1]=='O')
				{
					cout<<"O  ";
					outfile<<"O  ";
                    if(flag==0)
					{
						cout<<"E  ";
						outfile<<"E  ";
						i=argc;
						flag=8;
					}
					flag=3;
				}
				if(argv[i][1]=='C')
				{
					cout<<"C  ";
					outfile<<"C  ";
                    if(flag==0)
					{
						cout<<"E  ";
						outfile<<"E  ";
						i=argc;
						flag=8;
					}
					flag=4;
				}
				if(argv[i][1]=='A')
				{
					cout<<"A  ";
					outfile<<"A  ";
                    if(flag==0)
					{
						cout<<"E  ";
						outfile<<"E  ";
						i=argc;
						flag=8;
					}
					flag=5;
				}
				if(argv[i][1]=='N')
				{
					cout<<"N  ";
					outfile<<"N  ";
                    if(flag==0)
					{
						cout<<"E  ";
						outfile<<"E  ";
						i=argc;
						flag=8;
					}
					e=p->howMany();
					cout<<e<<"  ";
					outfile<<e<<"  ";
					flag=6;
				}
				if(argv[i][1]=='G')
				{
					cout<<"G  ";
					outfile<<"G  ";
                    if(flag==0)
					{
						cout<<"E  ";
						outfile<<"E  ";
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
							cout<<atoi(argv[i])<<"  ";
							outfile<<atoi(argv[i])<<"  ";
							break;
					case 2: if(p->howMany()==p->size())
							{
								cout<<"E  ";
								outfile<<"E  ";
								i=argc;	
								flag=8;						
							}
							else
							{
								p->push(atoi(argv[i]));
							}
							break;
					case 3: if(p->howMany()<atoi(argv[i]))
							{
						
								cout<<"E  ";
								outfile<<"E  ";
								i=argc;	
								flag=8;					
							}
							else
							{
								for(int j=0;j<atoi(argv[i]);j++)
								{
									p->pop(e);
								}
							}
							break;
					case 4: s=new STACK(*p);
							p = s;
							break;
					case 5: s =new STACK(atoi(argv[i]));
							s = &(s->assign(*p));
							p = s;							
							break;
					case 6: 
							break;
					case 7: if(p->howMany()<atoi(argv[i]))
							{
						
								cout<<"E  ";
								outfile<<"E  ";
								i=argc;	
								flag=8;					
							}
							else
							{
							e=p->getelem(atoi(argv[i]));
							cout<<e<<"  ";
							outfile<<e<<"  ";							
							}
							break;					
					default:break;					
				}
			}
	}
	if(argc!=1&&flag!=8&&flag!=6&&flag!=7)
	{
			p->print();		
	}
    return 0;
}
//---------------------------------------------------------------------------
