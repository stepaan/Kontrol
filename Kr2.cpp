#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int fuu2(string &s, int j, char b,int x,int y,int z)
{
	int k;
	j++;
	for(;j<s.length();j++)
	{
		char a=s[j];
		if (b=='('||a==')')
		{
			x++;
			return 1;
		}
		else if  (b=='['||a==']')
		{
			y++;
			return 1;
		}
		else if(b=='"'||a=='"')
		{
			z++;
			return 1;
		}
		else if(a=='('||a=='['||a=='"')
		k=fuu2(s,j,a,x,y,z);
		else if(a==')'||a==']'||k==0)
		return 0;
	}
	return 0;
}
int fuu(string &s,int j,int x,int y,int z)
{
	int k;
	for(;j<s.length();j++)
	{
		char a=s[j];
		if (a=='('||a=='['||a=='"')
		{
		k=fuu2(s,j,a,x,y,z);
		}
		else if(a==')'||a==']'||k==0)
		return 0;
	}
	return 1;
}

int main ()
{
	int x=0;
	int y=0;
	int z=0;
	int k;
	ifstream input("D:\\Dev-Cpp\\progect\\King\\have.txt");
	string line;
	getline (input,line);
    cout << line << std::endl;
    k=fuu(line, 0, x,y,z);
    ofstream output("results.txt");
    if (k==0)
    {
    output << "no balansed\n";
    }
	else
	{
		output << "():" << x << "\n";
		output << "[]:" << y << "\n";	
		output << """:" << z << "\n";	
	} 
}
