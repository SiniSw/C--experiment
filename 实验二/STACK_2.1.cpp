19:54:51
�Ĵ�-�ξ�ƽ 2018/11/7 19:54:51
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class STACK {
	int  *const  elems;	//�����ڴ����ڴ��ջ��Ԫ��
	const  int   max;	//ջ�ܴ�ŵ����Ԫ�ظ���
	int   pos;			//ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
public:
	STACK(int m);		//��ʼ��ջ�����m��Ԫ��
	STACK(const STACK&s); //��ջs������ʼ��ջ
	int  size() const;		//����ջ�����Ԫ�ظ���max
	int  howMany() const;	//����ջ��ʵ��Ԫ�ظ���pos
	int  getelem(int x) const;	//ȡ�±�x����ջԪ��
	STACK& push(int e); 	//��e��ջ,������ջ
	STACK& pop(int &e); 	//��ջ��e,������ջ
	STACK& assign(const STACK&s); //��s��ջ,�����ر���ֵ��ջ
	void print() const;		//��ӡջ
	~STACK();				//����ջ
}; 
STACK::STACK(int m):max(m),pos(0),elems(new int[m]){}
n
STACK::STACK(const STACK&s):elems(new int[s.pos]),pos(s.pos),max(s.max)
{
	//pos = s.pos;
	for (int i = 0; i < pos; i++)
		elems[i] = s.elems[i];
}

int STACK::size() const
{
	return max;
}

int STACK::howMany()const
{
	return pos;
}

int STACK::getelem(int x) const
{
	return elems[x];
}

STACK& STACK::push(int e)
{
	elems[pos] = e;
	pos++;
	return *this;
}

STACK& STACK::pop(int &e)
{
	e = elems[pos - 1];
	pos--;
	return *this;
}

STACK& STACK::assign(const STACK &s)
{
	for (int i = 0; i < s.pos; i++)
		elems[i] = s.elems[i];
	pos = s.pos;
	return *this;
}

void STACK::print() const
{
	for (int i = 0; i < pos; i++)
		cout << elems[i] << "  ";
}
STACK::~STACK()
{
	delete[]elems;
}

int main(int argc,char* argv[])
{
	string arg;
	int ch;
	STACK *p = NULL;
	for (int i = 1; i < argc; i++)
	{
         arg = argv[i];
	     if (arg == "-S")
	     {
		    ch = atoi(argv[i+1]);  //
			p = new STACK(ch);
			cout << "S  " << ch<<"  ";
	    }
		 else if (arg == "-I")
		 {
			 cout << "I  ";
			 int j = 1;
			 while ((i + j)<argc)
			 {
				 if (argv[i + j][0] != '-')
				 {
					 ch = atoi(argv[i + j]);
					 p->push(ch);
					 j++;
				 }
				 else break;	 
			 }
			 if (p->howMany() > p->size())
				 {
					 cout << "E  ";
					 break;
				 }
			 else p->print();
		 }
		 else if (arg == "-A")
		 {
			 cout << "A  ";
			 ch = atoi(argv[i+1]);
			 STACK *p1 = new STACK(ch);
			 p1->assign(*p);  //��ջ��ֵ
			 p = p1;   //�ص�ջp����
			 delete p1;
			 if (p->howMany())
				 p->print();
		 }
		 else if (arg == "-C")
		 {
			 cout << "C  ";

			 STACK *p2 = new STACK(*p);
			 p = p2;
			 delete p2;
			 if (p->howMany())
				 p->print();
		 }
		 else if (arg == "-N")
		 {
			 cout << "N  " << p->howMany() << "  ";
		 }
		 else if (arg == "-G")
		 {
			 ch = atoi(argv[i+1]);
			 if (ch < p->howMany())
				 cout << "G  " << p->getelem(ch) << "  ";
			 else {
				 cout << "G  E  ";
				 break;
			 }
		 }
		 else if (arg == "-O")
		 {
			 cout << "O  ";
			 ch = atoi(argv[i+1]);
			 int out;
			 for (int j = 0; j < ch; j++)
				 p->pop(out);
			 if (p->howMany())
				 p->print();
			 else {
				 cout << "E  ";
				 break;
			 }
		 }
	}
//	p->~STACK();
	p = NULL;
	return 0;
}

