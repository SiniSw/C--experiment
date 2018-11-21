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
    int  *const  elems;	//�����ڴ����ڴ��ջ��Ԫ��
    const  int   max;	//ջ�ܴ�ŵ����Ԫ�ظ���
    int   pos;			//ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
public:
STACK(int m):pos(0),max(m),elems(new int[m])  	//��ʼ��ջ�����m��Ԫ��
{}
STACK(const STACK&s):pos(s.pos),max(s.max),elems(s.elems)    //��ջs������ʼ��ջ
{}
virtual int  size () const    	//����ջ�����Ԫ�ظ���max
{
        return max;
} 
virtual operator int() const		//����ջ��ʵ��Ԫ�ظ���pos
{
        return pos;
}
virtual int operator[ ] (int x) const	//ȡ�±�x����ջԪ��
{
        return elems[x];
}
virtual STACK& operator<<(int e) 	//��e��ջ,������ջ
{
        if(pos!=max)
        {
                elems[pos]=e;
                pos++;
        }
        return *this;
}
virtual STACK& operator>>(int &e)	//��ջ��e,������ջ
{
        if(pos)
        {
                e=elems[pos-1];
                pos--;
        }
        return *this;
}
virtual STACK& operator=(const STACK&s) //��s��ջ,�����ر���ֵ��ջ
{
		int **p = (int**)&elems;
		*p = s.elems;
		int *q = (int*)&max;
		*q = s.max;
		pos = s.pos;
		return *this;
}
virtual void print( ) const			//��ӡջ
{
                for(size_t i = 0;i<pos;i++)
                {
                        cout<<elems[i]<<"  ";
						outfile<< elems[i]<< "  ";
                }
}
virtual ~STACK( ){  delete []elems; } 	//����ջ
};
class QUEUE:public STACK{
    STACK  s2;
public:
QUEUE(int m):STACK(m),s2(m){} //ÿ��ջ���m��Ԫ�أ�Ҫ��ʵ�ֵĶ����������2m��Ԫ��

QUEUE(const QUEUE&s):STACK(s),s2(s.s2){} 			//�ö���s������ʼ������

virtual operator int ( ) const		//���ض��е�ʵ��Ԫ�ظ���
{
	return ((*this).STACK::operator int()+int(s2)); 
}
virtual int full ( ) const	       //���ض����Ƿ�������������1�����򷵻�0
{
	if((*this).STACK::operator int()!=0&&int(s2)==s2.size())
		return 1;
	return 0;
}
virtual int operator[ ](int x)const   //ȡ�±�Ϊx��Ԫ�أ���1��Ԫ���±�Ϊ0
{
    if(x<(*this).STACK::operator int()) return (*this).STACK::operator [ ] ((*this).STACK::operator int()-1-x);
	else return s2[x-(*this).STACK::operator int()];	
}
virtual QUEUE& operator<<(int e)	 //��e�����,�����ض���
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
virtual QUEUE& operator>>(int &e)	//�����е�e,�����ض���
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
virtual QUEUE& operator=(const QUEUE&s) //��s������,�����ر���ֵ�Ķ���
{ 
	(*this).STACK::operator =(s); 
	s2=s.s2;
	return *this;		
} 
virtual void print( ) const			//��ӡ����
{
	for(int i = (*this).STACK::operator int()-1;i>=0;i--)
		{
            cout<<(*this).STACK::operator [ ] (i)<<"  ";
			outfile<<(*this).STACK::operator [ ] (i)<< "  ";
		}
	s2.print();
}
virtual ~QUEUE( ){};					//���ٶ���
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
		cout<<"������F:";
		cin>>F;
		cout<<"������M:";
		cin>>M;
		cout<<"������f:";
		cin>>f;
		cout<<"������M:";
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
		cout<<"��ʿ"<<f<<"�ڵ�"<<count<<"֧�������ܺ�Ůʿ"<<m<<"����"<< endl;
	} 
	else if(flag!=8&&flag!=6&&flag!=7)
	{
			p->print();		
	}
    return 0;
}
//---------------------------------------------------------------------------
