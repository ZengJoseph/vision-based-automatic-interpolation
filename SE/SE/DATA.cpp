#include "stdafx.h"
#include "afxdialogex.h"
#include "DATA.h"

void DATA::order()
{
	for (int i = 0;i < A.size();i ++)
	{
		for (int j = i;j < A.size();j++)
		{
			if(A[i]> A[j])
			{
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				temp = B[i];
				B[i] = B[j];
				B[j] = temp;
			}
		}
	}
}

float DATA::insertvalue(int a)
{
	int i = 0;
	int flag = 1;
	for(i =  0;i < num;i ++)
	{
		if (a == A[i])
		{
			return B[i];
		}
		if (a > A[num-1])
		{
			flag = 2;
			break;
		}
		if(a < A[0])
		{
			flag = 0;
			break;
		}
		if(a < A[i])
		{
			break;
		}
		
	}
	float ans;
	if(flag == 1)
	{
		ans = double(B[i] - B[i-1])/(A[i] - A[i-1]) * (a - A[i-1]) + B[i-1];

	}
	else if (flag == 0)
	{
		ans = double(B[1] - B[0])/(A[1] - A[0]) * (a - A[0]) + B[0];
		
	}
	else
	{
		ans = double(B[num-1] - B[num-2])/(A[num-1] - A[num-2]) * (a - A[num-2]) + B[num-2];
	}



	return ans;
}