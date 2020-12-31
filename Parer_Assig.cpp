#include<iostream>
using namespace std;

class parser
{
public:
	string Token_Buffer;
	int fwd;
	char C_T;
	parser(string inp)
	{
		Token_Buffer=inp;
		fwd = 0;
		C_T = Token_Buffer[fwd];
	}
	void E()//E->TE'
	{
		T();
		E_();
	}
	void E_()
	{
		switch (C_T)
		{
		case '+':
			GetNxtToken();
			T();
			E_();
			break;
		case '-':
			GetNxtToken();
			T();
			E_();
			break;
		default:
			//ErrorHandler();
			;
		}
	}
	void T()//T->FT'
	{
		F();
		T_();
	}
	void T_()//T'->*FT && T'->emptystring
	{
		switch (C_T)
		{
		case '*':
			GetNxtToken();
			F();
			T_();
			break;
		default:
			//ErrorHandler();
			;
		}
	}
	void F()//F->n && F->(E)
	{
		switch (C_T)
		{
		case 'n':
			GetNxtToken();
			break;
		case '(':
			GetNxtToken();
			E();
			if (C_T == ')')
			{
				GetNxtToken();
			}
			else
			{
				ErrorHandler();
			}
			break;
		default:
			ErrorHandler();
		}
	}
	void GetNxtToken()
	{
		fwd++;
		C_T = Token_Buffer[fwd];
	}
	void ErrorHandler()
	{
		cout << "Syntax Error Found!!\n";
		system("pause");
		exit(0);
	}
};

int main()
{
	parser obj("n+n-n*n(n)");
	obj.E();
	cout << "Syntax is Correct.\n";
	system("pause");
	return 0;
}