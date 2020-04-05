#include <iostream>
#include<queue>
#include<algorithm>
#include<stack>
#include<iomanip>
using std::queue;
using std::stack;
using namespace std;

struct  element
{
	int value;
	char a;
	int i, j;
};

char maze1[10][10]=
	{{'S','X',' ',' ',' ',' ',' ',' ',' ',' '},
	 {' ','X',' ',' ',' ',' ',' ',' ',' ',' '},
	 {' ','X','X','X',' ','X',' ',' ','X',' '},
	 {' ',' ',' ',' ',' ','X',' ',' ','X',' '},
	 {'X','X','X','X','X','X',' ',' ','X',' '},
	 {' ',' ',' ',' ',' ',' ',' ',' ','X',' '},
	 {' ','X',' ',' ',' ',' ',' ',' ','X',' '},
	 {' ','X',' ',' ','X','X','X','X','X','X'},
	 {' ','X',' ',' ',' ',' ',' ',' ',' ',' '},
	 {' ','X',' ',' ',' ',' ',' ',' ',' ','F'}};
char maze2[10][10]=
	{{'S','X',' ',' ',' ',' ',' ',' ',' ',' '},
	 {' ','X',' ',' ',' ',' ',' ',' ',' ',' '},
	 {' ','X','X','X',' ','X',' ',' ','X',' '},
	 {' ',' ',' ',' ',' ','X',' ',' ','X',' '},
	 {'X','X','X','X','X','X',' ',' ','X',' '},
	 {' ',' ',' ',' ',' ',' ',' ',' ','X',' '},
	 {' ','X',' ',' ',' ',' ',' ',' ','X',' '},
	 {' ','X',' ',' ','X','X','X','X','X',' '},
	 {' ','X',' ',' ',' ',' ',' ',' ',' ',' '},
	 {' ','X',' ',' ',' ',' ',' ',' ',' ','F'}};
char maze3[10][10]=
	{{'S','X',' ',' ',' ',' ',' ',' ',' ',' '},
	 {' ','X',' ',' ',' ',' ',' ',' ',' ',' '},
	 {' ','X','X','X',' ','X',' ',' ','X',' '},
	 {' ',' ',' ',' ',' ','X',' ',' ','X',' '},
	 {'X','X','X','X','X','X',' ',' ','X',' '},
	 {' ',' ',' ',' ',' ',' ',' ',' ','X',' '},
	 {' ','X',' ',' ',' ',' ',' ',' ','X',' '},
	 {' ','X',' ',' ','X','X','X','X','X',' '},
	 {' ','X',' ',' ',' ',' ',' ',' ',' ',' '},
	 {'F','X',' ',' ',' ',' ',' ',' ',' ',' '}};
char maze4[10][10]=
	{{'S','X',' ',' ',' ',' ',' ',' ',' ',' '},
	 {' ','X',' ',' ',' ',' ',' ',' ',' ',' '},
	 {' ','X','X','X',' ','X',' ',' ','X',' '},
	 {' ',' ',' ',' ',' ','X',' ',' ','X',' '},
	 {'X','X','X','X','X','X',' ',' ','X',' '},
	 {' ',' ',' ',' ',' ',' ',' ',' ','X',' '},
	 {'X','X',' ',' ',' ',' ',' ',' ','X',' '},
	 {' ','X',' ',' ','X','X','X','X','X',' '},
	 {' ','X',' ',' ',' ',' ',' ',' ',' ',' '},
	 {'F','X',' ',' ',' ',' ',' ',' ',' ',' '}};
void print(element** s);
element** mark1(char m[][10]);
element** solve(element** s);
int main()
{
	cout << "marked maze 1  : " << endl;
	print(mark1(maze1));
	cout << "Solved maze 1 :  " << endl;
	print(solve(mark1(maze1)));
	system("pause");
	cout << "marked maze 2  : " << endl;
	print(mark1(maze2));
	cout << "Solved maze 2 :  " << endl;
	print(solve(mark1(maze2)));
	system("pause");
	cout << "marked maze 3  : " << endl;
	print(mark1(maze3));
	cout << "Solved maze 3  :  " << endl;
	print(solve(mark1(maze3)));
	system("pause");
	cout << "marked maze 4  : " << endl;
	print(mark1(maze4));
	cout << "Solved maze 4 :  " ;
	print(solve(mark1(maze4)));
	system("pause");
	return 0;
}


void print(element** s)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << s[i][j].a;
		}
		cout << "\t\t";
		for (int j = 0; j < 10; j++)
		{
			if (s[i][j].a == ' ')
				cout << setw(3) << s[i][j].value;
			else
				cout << setw(3) << s[i][j].a;
		}
		cout << endl;
	}
	cout << endl;
}

element** mark1(char m[][10])
{
	queue<element> temp;
	element** o = new element*[10];
	element s;
	for (int i = 0; i < 10; i++)
	{
		o[i] = new element[10];
		for (int j = 0; j < 10; j++)
		{
			if (m[i][j] == 'S')
			{
				o[i][j].value = 0;
				o[i][j].a = m[i][j];
				o[i][j].i = i;
				o[i][j].j = j;
				temp.push(o[i][j]);
			}
			else
				o[i][j].value = -1;

			o[i][j].a = m[i][j];
			o[i][j].i = i;
			o[i][j].j = j;
		}
	}

	while (temp.size())
	{
		s = temp.front();
		if (s.i - 1 >= 0 && ((m[s.i - 1][s.j] == ' ') || (m[s.i - 1][s.j] == 'F')) && o[s.i - 1][s.j].value == -1)
		{
			element x = { s.value + 1 ,m[s.i - 1][s.j],s.i - 1,s.j };
			o[s.i - 1][s.j].value = s.value + 1;
			temp.push(x);
		}
		if (s.i + 1 < 10 && (m[s.i + 1][s.j] == ' ' || m[s.i + 1][s.j] == 'F') && o[s.i + 1][s.j].value == -1)
		{
			element x = { s.value + 1 ,m[s.i + 1][s.j],s.i + 1,s.j };
			o[s.i + 1][s.j].value = s.value + 1;
			temp.push(x);
		}
		if (s.j - 1 >= 0 && (m[s.i][s.j - 1] == ' ' || m[s.i][s.j - 1] == 'F') && o[s.i][s.j - 1].value == -1)
		{
			element x = { s.value + 1 ,m[s.i][s.j - 1],s.i ,s.j - 1 };
			o[s.i][s.j - 1].value = s.value + 1;
			temp.push(x);
		}
		if (s.j + 1<10 && ((m[s.i][s.j + 1] == ' ') || (m[s.i][s.j + 1] == 'F')) && o[s.i][s.j + 1].value == -1)
		{
			element x = { s.value + 1 ,m[s.i][s.j + 1],s.i ,s.j + 1 };
			o[s.i][s.j + 1].value = s.value + 1;
			temp.push(x);
		}
		temp.pop();

	}
	return o;

}

element** solve(element** s) {
	stack<element> temp;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (s[i][j].a == 'F')
			{
				temp.push(s[i][j]);
				break;

			}
		}
	}
	while (temp.top().a != 'S')
	{
		element n = temp.top();
		if (n.i - 1 >= 0 && n.value - 1 == s[n.i - 1][n.j].value)
		{
			temp.push(s[n.i - 1][n.j]);
		}
		else if (n.i + 1 < 10 && n.value - 1 == s[n.i + 1][n.j].value)
		{
			temp.push(s[n.i + 1][n.j]);
		}
		else if (n.j - 1 >= 0 && n.value - 1 == s[n.i][n.j - 1].value)
		{
			temp.push(s[n.i][n.j - 1]);
		}
		else if (n.j + 1< 10 && n.value - 1 == s[n.i][n.j + 1].value)
		{
			temp.push(s[n.i][n.j + 1]);
		}
		else
		{
			cout << "no road found" << endl;
			break;

		}
	}
	if (temp.top().a == 'S')
		while (temp.size())
		{
			element n = temp.top();
			if (n.a != 'S'&&n.a != 'F')
				s[n.i][n.j].a = '-';
			temp.pop();

		}
	return s;

}
