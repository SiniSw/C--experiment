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
    int  *const  elems;	//申请内存用于存放栈的元素
    const  int   max;	//栈能存放的最大元素个数
    int   pos;			//栈实际已有元素个数，栈空时pos=0;
public:
STACK(int m):pos(0),max(m),elems(new int[m])  	//初始化栈：最多m个元素
{}
STACK(const STACK&s):pos(s.pos),max(s.max),elems(s.elems)    //用栈s拷贝初始化栈
{}
virtual int  size () const    	//返回栈的最大元素个数max
{
        return max;
} 
virtual operator int() const		//返回栈的实际元素个数pos
{
        return pos;
}
virtual int operator[ ] (int x) const	//取下标x处的栈元素
{
        return elems[x];
}
virtual STACK& operator<<(int e) 	//将e入栈,并返回栈
{
        if(pos!=max)
        {
                elems[pos]=e;
                pos++;
        }
        return *this;
}
virtual STACK& operator>>(int &e)	//出栈到e,并返回栈
{
        if(pos)
        {
                e=elems[pos-1];
                pos--;
        }
        return *this;
}
virtual STACK& operator=(const STACK&s) //赋s给栈,并返回被赋值的栈
{
		int **p = (int**)&elems;
		*p = s.elems;
		int *q = (int*)&max;
		*q = s.max;
		pos = s.pos;
		return *this;
}
virtual void print( ) const			//打印栈
{
                for(size_t i = 0;i<pos;i++)
                {
                        cout<<elems[i]<<"  ";
						outfile<< elems[i]<< "  ";
                }
}
virtual ~STACK( ){  delete []elems; } 	//销毁栈
};
class QUEUE:public STACK{
    STACK  s2;
public:
QUEUE(int m):STACK(m),s2(m){} //每个栈最多m个元素，要求实现的队列最多能入2m个元素

QUEUE(const QUEUE&s):STACK(s),s2(s.s2){} 			//用队列s拷贝初始化队列

virtual operator int ( ) const		//返回队列的实际元素个数
{
	return ((*this).STACK::operator int()+int(s2)); 
}
virtual int full ( ) const	       //返回队列是否已满，满返回1，否则返回0
{
	if((*this).STACK::operator int()!=0&&int(s2)==s2.size())
		return 1;
	return 0;
}
virtual int operator[ ](int x)const   //取下标为x的元素，第1个元素下标为0
{
    if(x<(*this).STACK::operator int()) return (*this).STACK::operator [ ] ((*this).STACK::operator int()-1-x);
	else return s2[x-(*this).STACK::operator int()];	
}
virtual QUEUE& operator<<(int e)	 //将e入队列,并返回队列
{
	if(int(s2)!=s2.size()) s2<<e;
	else if((*this).STACK::operator int()==0)
	{
		int loa;
		while(int(s2)!=0)
		{
		s2>>loa;
		(*this).STACK::operator <<(loa);		
		}
		s2<<e;		
	}
	return *this;
}
virtual QUEUE& operator>>(int &e)	//出队列到e,并返回队列
{
    if((*this).STACK::operator int())
    {
		(*this).STACK::operator >>(e);
    }
    else if(int(s2)) 
    {
    	int loa;
		while(int(s2)!=1)
		{
		s2>>loa;
		(*this).STACK::operator <<(loa);			
		}
		s2>>e;		
	} 
	return *this;
}
virtual QUEUE& operator=(const QUEUE&s) //赋s给队列,并返回被赋值的队列
{ 
	(*this).STACK::operator =(s); 
	s2=s.s2;
	return *this;		
} 
virtual void print( ) const			//打印队列
{
	for(int i = (*this).STACK::operator int()-1;i>=0;i--)
		{
            cout<<(*this).STACK::operator [ ] (i)<<"  ";
			outfile<<(*this).STACK::operator [ ] (i)<< "  ";
		}
	s2.print();
}
virtual ~QUEUE( ){};					//销毁队列
};
int main(int argc, char* argv[])
{
	int flag=0;
	int e;
	outfile.open("U201614754_4.txt", ios::out);
	QUEUE* p=NULL;
	QUEUE* s;
	
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
					e=int(*p);
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
					case 1: p=new QUEUE(e);;
							cout<<atoi(argv[i])<<"  ";
							outfile<<atoi(argv[i])<<"  ";
							break;
					case 2: if(p->full())
							{
								cout<<"E  ";
								outfile<<"E  ";
								i=argc;	
								flag=8;						
							}
							else
							{
								(*p)<<atoi(argv[i]);
							}
							break;
					case 3: if(int(*p)<atoi(argv[i]))
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
									(*p)>>e;
								}
							}
							break;
					case 4: s=new QUEUE(*p);
							p = s;
							break;
					case 5: s =new QUEUE(atoi(argv[i]));
							*s = *p;
							p = s;							
							break;
					case 6: 
							break;
					case 7: if(int(*p)<atoi(argv[i]))
							{
						
								cout<<"E  ";
								outfile<<"E  ";
								i=argc;	
								flag=8;					
							}
							else
							{
							e=(*p)[atoi(argv[i])];
							cout<<e<<"  ";
							outfile<<e<<"  ";							
							}
							break;					
					default:break;					
				}
			}
	}
	if(argc==1)
	{
		int F,M,f,m; 
		QUEUE* Men=NULL;
		QUEUE* Wom=NULL;
		cout<<"请输入F:";
		cin>>F;
		cout<<"请输入M:";
		cin>>M;
		cout<<"请输入f:";
		cin>>f;
		cout<<"请输入M:";
		cin>>m;
		Men = new QUEUE(F);
		Wom = new QUEUE(M);
		for(int i=0;i<F;i++)
		{
			(*Men)<<(i+1);
		}
		for(int i=0;i<M;i++)
		{
			(*Wom)<<(i+1);
		}
		int eF,eM;
		int count=1; 
		(*Men)>>eF;
		(*Wom)>>eM;
		while(eF!=f||eM!=m)
		{
			(*Men)<<eF;
			(*Wom)<<eM;
			(*Men)>>eF;
			(*Wom)>>eM;
			count++;
		}
		cout<<"男士"<<f<<"在第"<<count<<"支曲舞曲能和女士"<<m<<"跳舞"<< endl;
	} 
	else if(flag!=8&&flag!=6&&flag!=7)
	{
			p->print();		
	}
    return 0;
}
//---------------------------------------------------------------------------
