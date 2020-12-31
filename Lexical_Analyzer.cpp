//#include<iostream>
//#include<cstring>
//#include<string>
//#include<fstream>
//using namespace std;
//
//int CS = 0;
//int iwlfst = -1;
//int ls = 0;
//int lfsv = -1;
//int fwd = 0;
//int Line_Number = 1;
//
//string states[7];
//bool Final_States[7];
//int F_A[7][72];
//char Input_characters[72];
//string input;
//ifstream inp, charset("charset.txt"),FA("FA.txt");
//ofstream of("output.txt"), err("errors.txt");
//
//void States()
//{
//	states[0] = "Start";
//	states[1] = "ID";
//	states[2] = "Int";
//	states[3] = ";";
//	states[4] = "int-to-real";
//	states[5] = "Real";
//	states[6] = "=";
//	Final_States[0] = false;
//	Final_States[1] = true;
//	Final_States[2] = true;
//	Final_States[3] = true;
//	Final_States[4] = false;
//	Final_States[5] = true;
//	Final_States[6] = true;
//}
//
//void Input_Char_Table()
//{
//	Input_characters[0] = '\b';
//	Input_characters[1] = '\r';
//	Input_characters[2] = '\t';
//	Input_characters[3] = '\n';
//	for (int i = 4; i < 72; i++)
//	{
//		charset >> Input_characters[i];
//	}
//	charset.close();
//}
//
//void FA_Table()
//{
//	for (int i = 0; i < 7; i++)
//	{
//		for (int j = 0; j < 72; j++)
//		{
//			FA >> F_A[i][j];
//		}
//	}
//	FA.close();
//}
//
//int Find_Char(char t)
//{
//	for (int i = 0; i < 72; i++)
//	{
//		if (Input_characters[i] == t)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//void Input_File()
//{
//	inp.open("input.txt");
//	string temp;
//	while (!inp.eof())
//	{
//		getline(inp, temp);
//		input.append(temp);
//	}
//	inp.close();
//}
//
//bool IsFinal(int st)
//{
//	return Final_States[st];
//}
//
//void ungetch()
//{
//	fwd--;
//}
//
//bool IsLexemeIdentified()
//{
//	if (lfsv != -1)
//	{
//		return true;
//	}
//	return false;
//}
//
//string PutLexeme()
//{
//	string lexeme;
//	for (int i = ls; i <= iwlfst; i++)
//	{
//		lexeme.push_back(input[i]);
//	}
//	return lexeme;
//}
//
//string PutToken()
//{
//	if (lfsv != 1)
//	{
//		return states[lfsv];
//	}
//	else
//	{
//		if (0)
//		{
//
//		}
//		else
//		{
//			return states[lfsv];
//		}
//	}
//}
//
//void Reset()
//{
//	CS = 0;
//	ls = iwlfst + 1;
//	iwlfst = -1;
//	lfsv = -1;
//}
//
//void Skip()
//{
//	Reset();
//}
//
//void Save(string lex, string tok)
//{
//	of << lex << " : " << tok << endl;
//}
//
//void Error(char ch)
//{
//	err << "Symobl Not defined : \"" << ch << "\" at line no : " << Line_Number << endl;
//}
//
//void Lexer()
//{
//	Input_File();
//	States();
//	Input_Char_Table();
//	FA_Table();
//	char temp = input[fwd];
//	while (temp != '\0')
//	{
//		temp = input[fwd];
//		//cout << "\n  " << temp;
//		fwd++;
//		if (Find_Char(temp) != -1 || temp == '\0')
//		{
//			int cs = F_A[CS][Find_Char(temp)];
//			if (cs != -1)
//			{
//				CS = cs;
//				if (IsFinal(CS))
//				{
//					iwlfst = fwd - 1;
//					lfsv = CS;
//				}
//			}
//			else
//			{
//				if (Input_characters[0] == temp || Input_characters[1] == temp || Input_characters[2] == temp || Input_characters[3] == temp)
//				{
//					Skip();
//				}
//				//if (IsFinal(CS))
//				{
//					ungetch();
//					if (IsLexemeIdentified())
//					{
//						string lexeme = PutLexeme();
//						string token = PutToken();
//						Save(lexeme, token);
//						Reset();
//					}
//
//				}
//			}
//		}
//		else
//		{
//			Error(temp);
//			CS = 0;
//			iwlfst = -1;
//			ls = fwd;
//			lfsv = -1;
//		}
//	}
//}
//
//int main()
//{
//	Lexer();
//	of.close();
//	err.close();
//	system("pause");
//	return 0;
//}