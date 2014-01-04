#pragma once
#include "afxwin.h"
#include <fstream>
#include <vector>
#include <iostream>

class DATA
{
private:
	std::vector<int> A;
	std::vector<int> B;
	int num;

public :
	DATA()
	{
		num = 0;
	}
	int getnum()
	{
		return num;
	}
	int read(CString file = _T("Output/Tables.txt"))
	{
		
	std::ifstream myfile(file,std::ios::in);
	if(!myfile)		
	{
		std::cout<<"Unable to open myfile";
	    exit(0);
	}

	int i = 0;
	while(true)
	{
		int a,b;
		myfile>>a;

		if(myfile.fail())
		{
			break;
		}

		myfile>>b;
		if(myfile.fail())
		{
			break;
		}

		A.push_back(a);
		B.push_back(b);
		i++;
		this->num ++;
	}

	myfile.close();
}
	void order();

	float insertvalue(int a);
};