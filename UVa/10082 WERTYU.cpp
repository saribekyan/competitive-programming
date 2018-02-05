#include <iostream>
using namespace std;
int main()
{
	char c,ans;
	while (cin.get(c))
	{
		switch (c){
			case '1':ans='`';break;
			case '2':ans='1';break;
			case '3':ans='2';break;
			case '4':ans='3';break;
			case '5':ans='4';break;
			case '6':ans='5';break;
			case '7':ans='6';break;
			case '8':ans='7';break;
			case '9':ans='8';break;
			case '0':ans='9';break;
			case '-':ans='0';break;
			case '=':ans='-';break;
			case '\\':ans='=';break;
			case 'W':ans='Q';break;
			case 'E':ans='W';break;
			case 'R':ans='E';break;
			case 'T':ans='R';break;
			case 'Y':ans='T';break;
			case 'U':ans='Y';break;
			case 'I':ans='U';break;
			case 'O':ans='I';break;
			case 'P':ans='O';break;
			case '[':ans='P';break;
			case ']':ans='[';break;
			case '\n':ans='\n';break;
			case 'S':ans='A';break;
			case 'D':ans='S';break;
			case 'F':ans='D';break;
			case 'G':ans='F';break;
			case 'H':ans='G';break;
			case 'J':ans='H';break;
			case 'K':ans='J';break;
			case 'L':ans='K';break;
			case ';':ans='L';break;
			case 39:ans=';';break;
			case 'X':ans='Z';break;
			case 'C':ans='X';break;
			case 'V':ans='C';break;
			case 'B':ans='V';break;
			case 'N':ans='B';break;
			case 'M':ans='N';break;
			case ',':ans='M';break;
			case '.':ans=',';break;
			case '/':ans='.';break;
			case ' ':ans=' ';break;
		}
		cout<<ans;
	}
	return 0;
}