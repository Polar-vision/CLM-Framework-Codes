/**************************************************************************
Copyright:Peking University
Author: Zhengkang ZUO
Date:2021-05-7
Description:Constraint Law Method (CLM) Framework for nonlinear least square problems
**************************************************************************/
#define LD double
#define PI 3.141592654
#define Euler 2.71828182845904523536
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;

LD * a = NULL;
//return a random number inside the range [0,1]
LD Random()
{
	return (LD)rand() / RAND_MAX;
}
struct B
{
	LD * p;
	LD f;
};
LD aX[8] = { 1,2,3,4,5,6,7,8 };
//LD aY[8] = { 8.3, 11.0, 14.7, 19.7, 26.7, 35.2, 44.4, 55.9 };//f21
//LD aY[8] = { 0.2, 0.25, 0.4, 0.8, 2, 4, 9, 20 };//f22
//LD aY[8] = { 1.2, 2, 3, 4, 5, 6, 7, 8 };//f23
//LD aY[8] = { 0.12, 0.23, 1.2, 2, 2.5, 2, 1, 0.25 };//f24
//LD aY[8] = { 0.1, 0.2, 0.3, 0.5, 3, 5, 9, 12 };//f25
//LD aY[8] = { 0.1, 0.2, 0.3, 1, 3, 5, 9, 12 };//f26
//LD aY[8] = { 0.1, 0.25, 0.3, 1, 3, 5, 9, 10 };//f27
LD aY[8] = { 1.2, 3, 5, 5.6, 4.7, 3.6, 2.7, 1 };//f28
B * x = NULL, *new_x = NULL, *new_l_x = NULL;
//fitness function
void f(B & x, int n)//n present dimension
{
	LD A,B,C,D,E,F,r,s=0;
	A = x.p[0];
	B = x.p[1];
	C = x.p[2];
	D = x.p[3];
	E = x.p[4];
	F = x.p[5];
	for (int i = 0; i < 8; i++)
	{
		//f21
		//r = A*n + B*aX[i] * aX[i] - C*cos(D*aX[i]);
		//f22
		//r = A*exp(-B*aX[i]) + C*exp(-D*aX[i]);
		//f23
		//r = A + B*cos(D*aX[i]) + C*sin(D*aX[i]);
		//f24
		//r = A*exp(powf((aX[i] - B) / C,2));
		//f25
		//r = A*aX[i] * aX[i] + B*aX[i] + C;
		//f26
		//r = A*pow(aX[i], B) + C;
		//f27
		//r = (A*aX[i] + B) / (aX[i] * aX[i] + C*aX[i] + D);
		//f28
		r = A*sin(B*aX[i] + C) + D*sin(E*aX[i] + F);
		r = r - aY[i];
		r = r*r;
		s += r;
	}
	x.f = s / 8;
}
//返回一组适应值
void f_array(int N, int n, B *&x)
{
	for (int i = 0; i<N; i++)
	{
		f(x[i], n);
	}
}

//若满足约束条件，返回true，否则，返回false
int H(B & x, int n)
{
	int i, s = 0;
	for (i = 0; i<n; i++)
	{
		if (x.p[i] >= -6)
			s += 1;
		if (x.p[i] <= 6)
			s += 1;
	}
	return s;
}
bool better(B & x1, B & x2, int n)
{
	int h1, h2;
	LD f1, f2;
	h1 = H(x1, n);
	h2 = H(x2, n);
	f1 = x1.f;
	f2 = x2.f;
	if (h1<h2)
		return false;
	else if (h1>h2)
		return true;
	if (f1<f2)
		return true;
	return false;
}
//返回在搜索空间中随机产生满足约束条件的初始群体,t=0
void rand_init_population(int N, int n, B * _x)//N presents the population size, n peresents the dimension
{
	int i, j;
	for (i = 0; i<N; ++i)
	{
		for (j = 0; j<n; j++)
		{
			_x[i].p[j] = Random()*12-6;
		}
	}
}
void swap(B &a, B &b)
{
	B temp = a;
	a = b;
	b = temp;
}
void sort(int N, int n, B * x)
{
	for (int i = 0; i<N - 1; i++)
	{
		for (int j = 0; j<N - 1 - i; j++)
		{
			if (x[j].f>x[j + 1].f)
			{
				swap(x[j], x[j + 1]);
			}
		}
	}
}
void rd(int M)
{
	LD s, g = 4;
	while (g>1.5 || g<-0.5)
	{
		s = 0;
		for (int i = 0; i<M - 1; i++)
		{
			a[i] = Random() * 2 - 0.5;
			s += a[i];
		}
		g = 1 - s;
	}
	a[M - 1] = g;
}
//从[-0.5,1.5]中随机产生M个数,使得这M个数和为1
void mrd(int M)
{
	LD s1 = -0.8586*powf(M, -0.9424) + 0.6115;
	LD s2 = 0.5802*powf(M, -0.8598) + 0.3443;
	int i;
	LD s, g = 4, fld;
	while (g>1.5 || g<-0.5)
	{
		s = 0;
		for (i = 0; i<M - 1; i++)
		{
			fld = Random();
			if (fld <= s1)
				a[i] = Random()*0.5 - 0.5;
			else if (fld <= s1 + s2)
				a[i] = Random();
			else
				a[i] = Random()*0.5 + 1;
			s += a[i];
		}
		g = 1 - s;
	}
	a[M - 1] = g;
}
void ConstraintLaw(int M)
{
	LD s, S, Last_Coeffient = 2, num = 0, t_low, t_up, b_low, b_up;
	int r;
	a[0] = Random() * 2 - 0.5;

	while (Last_Coeffient <= -0.5 || Last_Coeffient >= 1.5)
	{
		num++;
		S = s = 0;
		for (int i = 1; i < M - 1; i++)
		{
			s += a[i - 1];
			t_low = -0.5 - s;
			t_up = 1.5 - s;
			b_low = t_low >= -0.5 ? t_low : -0.5;
			b_up = t_up <= 1.5 ? t_up : 1.5;
			a[i] = Random()*(b_up - b_low) + b_low;
		}
		S = s + a[M - 2];
		a[M - 1] = Last_Coeffient = 1 - S;
	}
}

//精英多父体杂交
void e_m_p_c(int M, int K, int L, int n, int N, B * _x)
{
	int i, j, l;
	LD S;

	//从种群中选择K个最好的个体
	for (i = 0; i<K; i++)
	{
		new_x[i] = _x[i];
	}
	//另外M-K个个体从种群中随机选取
	for (i = 0; i<M - K; i++)
	{
		int t = rand() % N;
		while (t<K)
		{
			t = rand() % N;
		}
		new_x[i + K] = _x[t];
	}
	//由这M个个体张成子空间
	for (l = 0; l<L; l++)
	{
		//rd(M);
		//mrd(M);
		ConstraintLaw(M);
		for (i = 0; i<n; i++)
		{
			S = 0;
			for (j = 0; j<M; j++)
			{
				S += new_x[j].p[i] * a[j];
			}
			new_l_x[l].p[i] = S;
		}
	}
	//返回L个个体中最好的个体
	f_array(L, n, new_l_x);
	sort(L, n, new_l_x);
}
//每执行一次H函数，就为一代
void H(int n, int N, int M, int K, int L, B * _x)
{
	B best, worst;
	worst = _x[N - 1];
	e_m_p_c(M, K, L, n, N, _x);
	best = new_l_x[0];
	if (better(best, worst, n))
	{
		for (int i = 0; i<n; i++)
		{
			_x[N - 1].p[i] = best.p[i];
		}
		_x[N - 1].f = best.f;
	}
	sort(N, n, _x);
}
void Write_to_excel(B _x, int p, int n, ofstream & outfile)
{
	for (int j = 0; j<n; j++)
		outfile << setiosflags(ios::fixed) << setprecision(14) << _x.p[j] << ",";
	outfile << _x.f << endl;
}
int ct1 = 0;
int ct2 = 0;
int ct3 = 0;
int ct4 = 0;
int ct5 = 0;
int ct6 = 0;
void main()
{
	ofstream outfile;
	outfile.open("Original.csv", ios::out);
	clock_t start, finish;
	LD duration, s = 0;
	int M = 14, n = 6, N = 100, K = 5, L = 1, i;
	srand((unsigned)time(NULL));
	for (int kk = 0; kk<1; kk++)
	{
		start = clock();
		try
		{
			a = new LD[M];
			x = new B[N];
			new_x = new B[M];
			new_l_x = new B[L];
		}
		catch (bad_alloc&memExp)
		{
			cerr << memExp.what() << endl;
		}
		try
		{
			for (i = 0; i<N; i++)
			{
				x[i].p = new LD[n];
			}
			for (i = 0; i<M; i++)
			{
				new_x[i].p = new LD[n];
			}
			for (i = 0; i<L; i++)
			{
				new_l_x[i].p = new LD[n];
			}
		}
		catch (bad_alloc&memExp)
		{
			cerr << memExp.what() << endl;
		}
		for (int j = 0; j < 100; j++)
		{
			rand_init_population(N, n, x);
			f_array(N, n, x);
			sort(N, n, x);
			Write_to_excel(x[0], N, n, outfile);
			i = 0;
			while (fabs(x[0].f - x[N - 1].f)>1E-14)
			{
				++i;
				H(n, N, M, K, L, x);
				if (i > 100000)
				{
					ct6++;
					break;
				}
					
				Write_to_excel(x[0], N, n, outfile);
			}
			Write_to_excel(x[0], N, n, outfile);
			
			cout << "程序执行代数:" << i << "代" << endl;//hj
			cout << "程序运行结果:" << setiosflags(ios::fixed) << setprecision(14) << x[0].f << endl;
			if (fabs(x[0].f - 0.000063) < 1e-6)
				ct1++;
			if (fabs(x[0].f - 0.221370) < 1e-6)
				ct2++;
			if (fabs(x[0].f - 0.115718) < 1e-6)
				ct3++;
			if (fabs(x[0].f - 0.047646) < 1e-6)
				ct4++;
			if (fabs(x[0].f - 0.110355) < 1e-6)
				ct5++;
			//if (fabs(x[0].f - 0.003943) < 1e-6)
			//	ct1++;
		}
		std::cout << "0.000063=" << ct1 << std::endl;
		std::cout << "0.221370=" << ct2 << std::endl;
		std::cout << "0.115718=" << ct3 << std::endl;
		std::cout << "0.047646=" << ct4 << std::endl;
		std::cout << "0.110355=" << ct5 << std::endl;
		std::cout << "fail=" << ct6 << std::endl;

		finish = clock();
		duration = (LD)(finish - start) / CLOCKS_PER_SEC;
		s += duration;
		cout << "程序运行时间:" << setiosflags(ios::fixed) << setprecision(4) << duration/100 << "s" << endl;
		outfile.close();
		delete[] a; a = NULL;
		delete[] x; x = NULL;
		delete[] new_x; new_x = NULL;
		delete[] new_l_x; new_l_x = NULL;
	}
	//	cout<<"程序执行代数:"<<i/30<<"代"<<endl;//hj
	//	cout<<s/30<<endl;
	system("pause");
}
