

/**************************************************************************
Copyright:Peking University
Author: Zhengkang ZUO
Date:2021-05-7
Description:Constraint Law Method (CLM) Framework
**************************************************************************/
#define LD double
#define PI 3.141592654
#define Euler 2.71828182845904523536
#include "stdafx.h"
#include <time.h>
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
B * x = NULL, *new_x = NULL, *new_l_x = NULL;
/*log以e为底x的函数*/
double loge(double x)
{
	return log(x) / log(exp(1));
}
//fitness function
void f(B & x, int n)//n present dimension
{
	//f1
	//double val1, s = 0;
	//for (int i = 0; i < n; i++)
	//{
	//	val1 = pow(x.p[i], 2);
	//	s += val1;
	//}
	//x.f = s;
	//f2
	//double val1, s = 0, S = 1;
	//for (int i = 0; i < n; i++)
	//{
	//	val1 = abs(x.p[i]);
	//	s += val1;
	//	S *= val1;
	//}
	//x.f = s + S;

	//f3
	//double val1, s = 0, S = 0;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < i; j++)
	//	{
	//		s += x.p[i];
	//	}
	//	val1 = s*s;
	//	S += val1;
	//}
	//x.f = S;

	//f4
	//double val, max = -200;
	//for (int i = 0;i < n;i++)
	//{
	//	val = abs(x.p[i]);
	//	max = val > max ? val : max;
	//}
	//x.f = max;

	//f5
	//double val1, val2, val3, s = 0;
	//for (int i = 0;i < n - 1;i++)
	//{
	//	val1 = 100 * (x.p[i + 1] - x.p[i] * x.p[i])*(x.p[i + 1] - x.p[i] * x.p[i]);
	//	val2 = (x.p[i] - 1)*(x.p[i] - 1);
	//	val3 = val1 + val2;
	//	s += val3;
	//}
	//x.f = s;

	//f6
	//double val1, val2, val3, s = 0;
	//for (int i = 0;i < n;i++)
	//{
	//	val1 = x.p[i] + 0.5;
	//	val2 = floor(val1);
	//	val3 = val2*val2;
	//	s += val3;
	//}
	//x.f = s;

	//f7
	//double val1, s = 0;
	//for (int i = 0;i < n;i++)
	//{
	//	val1 = (i + 1)*pow(x.p[i], 4);// + Random()
	//	s += val1;
	//}
	//x.f = s;

	//f8
	//double val1, val2, val3, s = 0;
	//for (int i = 0;i < n;i++)
	//{
	//	val1 = sqrt(abs(x.p[i]));
	//	val2 = sin(val1);
	//	val3 = -x.p[i] * val2;
	//	s += val3;
	//}
	//x.f = s;

	//f9
	//double val1, val2, val3, s = 0;
	//for (int i = 0;i < n;i++)
	//{
	//	val1 = x.p[i] * x.p[i];
	//	val2 = 10 * cos(2 * PI*x.p[i]);
	//	val3 = val1 - val2 + 10;
	//	s += val3;
	//}
	//x.f = s;

	//f10
	//double val1 = 0;
	//double val2 = 0;
	//for (int i = 0; i < n; i++) {
	//	val1 += x.p[i] * x.p[i];
	//	val2 += cos(2 * PI*x.p[i] / 180 * PI);
	//}
	//x.f = ((-20)*exp((-0.2)*sqrt(val1 / n)) - exp(val2 / n) + 20 + exp(1));

    //f11
//double val1, val2, s = 0, S = 1;
//for (int i = 0;i < n;i++)
//{
//	val1 = x.p[i] * x.p[i];
//	s += val1;
//	val2 = cos(x.p[i] / sqrt((i + 1)));
//	S *= val2;
//}
//x.f = s / 4000 - S + 1;

//f12
//double val1, val2, val3, val4, val5, s = 0, S = 0;
//double val6, val7, val8, val9, val10, val11, val12;
//val2 = 1 + (x.p[0] + 1) / 4;
//val3 = 10 * sin(PI*val2)*sin(PI*val2);
//val4 = 1 + (x.p[n - 1] + 1) / 4;
//val5 = (val4 - 1)*(val4 - 1);
//for (int i = 0;i < n - 1;i++)
//{
//	val1 = 1 + (x.p[i] + 1) / 4;
//
//	val6 = (val1 - 1)*(val1 - 1);
//	val7 = 1 + (x.p[i + 1] + 1) / 4;
//	val8 = PI*val7;
//	val9 = 10 * sin(val8)*sin(val8) + 1;
//	val10 = val6*val9;
//	s += val10;
//}
//for (int i = 0;i < n;i++)
//{
//	val11 = x.p[i];
//	if (val11 > 10)
//	{
//		val12 = 100 * pow(val11 - 10, 4);
//	}
//	if ((val11 > -10 || val11 == -10) && (val11 < 10 || val11 == 10))
//	{
//		val12 = 0;
//	}
//	if (val11 < -10)
//	{
//		val12 = 100 * pow(-val11 - 10, 4);
//	}
//	S += val12;
//}
//x.f = PI*(val3 + val5 + s) / n + S;

//f13
//double val1, val2, val3, val4, val5, val6, val7, val8, val9, val10, s = 0, S = 0;
//val1 = sin(3 * PI*x.p[0])*sin(3 * PI*x.p[0]);
//val2 = (x.p[n - 1] - 1)*(x.p[n - 1] - 1)*(1 + sin(2 * PI*x.p[n - 1])*sin(2 * PI*x.p[n - 1]));
//for (int i = 0;i < n - 1;i++)
//{
//	val3 = (x.p[i] - 1)*(x.p[i] - 1)*(1 + sin(3 * PI*x.p[i + 1])*sin(3 * PI*x.p[i + 1]));
//	s += val3;
//}
//for (int i = 0;i < n;i++)
//{
//	val4 = x.p[i];
//	if (val4 > 10)
//	{
//		val5 = 100 * pow(val4 - 10, 4);
//	}
//	if ((val4 > -10 || val4 == -10) && (val4 < 10 || val4 == 10))
//	{
//		val5 = 0;
//	}
//	if (val4 < -10)
//	{
//		val5 = 100 * pow(-val4 - 10, 4);
//	}
//	S += val5;
//}
//x.f = 0.1*(val1 + s + val2) + S;

//f14
//double aa[2][25] = { { -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32 },{ -32, -32, -32, -32, -32, -16, -16, -16, -16, -16, 0, 0, 0, 0, 0, 16, 16, 16, 16, 16, 32, 32, 32, 32, 32 } };
//double val1, val2, s = 0, S = 0;
//double val3, val4, val5;
//for (int i = 0;i < 10;i++)
//{
//	for (int j = 0;j < n;j++)
//	{
//		val1 = x.p[i] - aa[j][i];
//		val2 = pow(val1, 6);
//		s += val2;
//	}
//	val3 = 1 / ((i + 1) + s);
//	S += val3;
//}
//val4 = 1 / 500 + S;
//val5 = 1 / val4;
//x.f = val5;

//f15
//double a[11] = { 0.1957,0.1947,0.1735,0.1600,0.0844,0.0627,0.0456,0.0342,0.0323,0.0235,0.0246 };
//double b[11] = { 0.25,0.5,1,2,4,6,8,10,12,14,16 };
//double val1 = x.p[0];
//double val2 = x.p[1];
//double val3 = x.p[2];
//double val4 = x.p[3];
//double val5, val6, val7, val8, s = 0;
//for (int i = 0;i < 11;i++)
//{
//	val5 = val1*(b[i] * b[i] + b[i] * val2);
//	val6 = b[i] * b[i] + b[i] * val3 + val4;
//	val7 = val5 / val6;
//	val8 = (a[i] - val7)*(a[i] - val7);
//	s += val8;
//}
//x.f = s;

//f16
//double val1 = x.p[0];
//double val2 = x.p[1];
//double val3, val4, val5, val6, val7, val8, val9;
//val3 = 4 * val1*val1;
//val4 = 2.1*pow(val1, 4);
//val5 = pow(val1, 6) / 3;
//val6 = val1*val2;
//val7 = 4 * val2*val2;
//val8 = 4 * pow(val2, 4);
//val9 = val3 - val4 + val5 + val6 - val7 + val8;
//x.f = val9;

//f17
//double val1 = x.p[0];
//double val2 = x.p[1];
//double val3, val4, val5;
//val3 = val2 - 5.1*val1*val1 / (4 * PI*PI) + 5 * val1 / PI - 6;
//val4 = 10 * (1 - 1 / (8 * PI))*cos(val1);
//val5 = val3*val3 + val4 + 10;
//x.f = val5;

//f18
//double val1 = x.p[0];
//double val2 = x.p[1];
//double val3, val4, val5, val6, val7;
//val3 = pow(val1 + val2 + 1, 2);
//val4 = 19 - 14 * val1 + 3 * val1*val1 - 14 * val2 + 6 * val1*val2 + 3 * val2*val2;
//val5 = pow(2 * val1 - 3 * val2, 2);
//val6 = 18 - 32 * val1 + 12 * val1*val1 + 48 * val2 - 36 * val1*val2 + 27 * val2*val2;
//val7 = (1 + val3*val4)*(30 + val5*val6);
//x.f = val7;

//f19
double a[4][3] = { {3,10,30},{0.1,10,35},{3,10,30},{0.1,10,35} };
double c[4] = { 1,1.2,3,3.2 };
double p[4][3] = { {0.3689,0.117,0.2673},{0.4699,0.4387,0.747},{0.1091,0.8732,0.5547},{0.03815,0.5743,0.8828} };
double val1, val2, s = 0, S = 0;
for (int i = 0;i < 4;i++)
{
	for (int j = 0;j < n;j++)
	{
		val1 = a[i][j] * (x.p[j] - p[i][j])*(x.p[j] - p[i][j]);
		s += val1;
	}
	val2 = c[i] * exp(-s);
	S += val2;
}
x.f = -S;

//f20
//double a[4][6] = { { 10,3,17,3.5,1.7,8},{0.05,10,17,0.1,8,14},{3,3.5,1.7,10,17,8},{17,8,0.05,10,0.1,14} };
//double c[4] = { 1,1.2,3,3.2 };
//double p[4][6] = { { 0.1312,0.1696,0.5569,0.0124,0.8283,0.5886},{0.2329,0.4135,0.8307,0.3736,0.1004,0.9991},{0.2348,0.1415,0.3522,0.2883,0.3047,0.6650},{0.4047,0.8828,0.8732,0.5743,0.1091,0.0381} };
//double val1, val2, s = 0, S = 0;
//for (int i = 0;i < 4;i++)
//{
//	for (int j = 0;j < n;j++)
//	{
//		val1 = a[i][j] * (x.p[j] - p[i][j])*(x.p[j] - p[i][j]);
//		s += val1;
//	}
//	val2 = c[i] * exp(-s);
//	S += val2;
//}
//x.f = -S;
	/*f2*/
	//double val = 0;
	//for (int i = 0; i < n; i++)
	//	val += (x.p[i] * x.p[i]);
	//x.f=-exp(-0.5*val);
	/*f3*/
	//LD a, s = 0;
	//for (int i = 0; i<n; i++)
	//{
	//	a = x.p[i] * x.p[i] - 10 * cos(2 * PI*x.p[i]);
	//	s += a;
	//}
	//x.f = s + 10 * n;
	/*f4*/
	//double val = 0;
	//for (int i = 0; i < n; i++)
	//	val += x.p[i] * sin(sqrt(abs(x.p[i])));
	//x.f=-val;
	/*f5*/
	/*double val1 = 0, val2 = 1;
	for (int i = 0; i < n; i++)
		val1 += (loge(x.p[i] - 2)*loge(x.p[i] - 2) + loge(10 - x.p[i])*loge(10 - x.p[i]));
	for (int i = 0; i < 10; i++)
		val2 *= x.p[i];
	x.f=val1 - pow(val2, 0.2);*/
	/*f6*/
	//double val = 0;
	//for (int i = 0; i < n; i++) {
	//	val += x.p[i] * x.p[i];
	//}
	//x.f=val;
	/*f7*/
	/*double val = 0;
	for (int i = 0; i < n - 1; i++) {
		val += 100 * (x.p[i + 1] - x.p[i] * x.p[i])*(x.p[i + 1] - x.p[i] * x.p[i]) + (x.p[i] - 1)*(x.p[i] - 1);
	}
	x.f = val;*/
	/*f8*/
	//double val = 0;
	//for (int i = 0; i < n; i++)
	//	val += (x.p[i] - i - 1)*(x.p[i] - i - 1);
	//x.f = val;
	/*f9*/
	//double val1 = 0;
	//double val2 = 1;
	//for (int i = 0; i < n; i++) {
	//	val1 += abs(x.p[i]);
	//	val2 = val2*abs(x.p[i]);
	//}
	//x.f=(val1 + val2);
	/*f10*/
	//double val = 0;
	//for (int i = 0; i < n; i++)
	//	val += (i + 1)*x.p[i] * x.p[i];
	//x.f = val;
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
int H(B x, int n)
{
	int i, s = 0;
	for (i = 0; i<n; i++)
	{
		//if (i == 0)
		//{
		//	if (x.p[i] >= -5)
		//		s += 1;
		//	if (x.p[i] <= 10)
		//		s += 1;
		//}
		//if (i == 1)
		//{
		//	if (x.p[i] >= 0)
		//		s += 1;
		//	if (x.p[i] <= 15)
		//		s += 1;
		//}
		if (x.p[i] >= 0)
			s += 1;
		if (x.p[i] <= 1)
			s += 1;
	}
	return s;
}
bool better(B x1, B x2, int n)
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
			_x[i].p[j] = Random();
			//if(j==0)
			//	_x[i].p[j] = Random() * 15 - 5;
			//if (j == 1)
			//	_x[i].p[j] = Random() * 15;
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
		mrd(M);
		//ConstraintLaw(M);
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
void Write_to_excel(B * _x, int p, int n, ofstream & outfile)
{
	
	for (int i = 0; i<p; i++)
	{
		for (int j = 0; j<n; j++)
			outfile << setiosflags(ios::fixed) << setprecision(14) << _x[i].p[j] << ",";
		outfile << _x[i].f << endl;
	}
	
}
//int ccout=0;
int ct1=0;
void main()
{
	ofstream outfile;
	outfile.open("result.csv", ios::out);
	clock_t start, finish;
	LD duration, s = 0;
	int M = 15, n = 3, N = 100, K = 5, L = 1, i;
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
		for (int j = 0; j < 1; j++)
		{
			cout << j << endl;
			rand_init_population(N, n, x);
			f_array(N, n, x);
			sort(N, n, x);
			outfile << setiosflags(ios::fixed) << setprecision(14)  << x[0].f<<endl;
		//	Write_to_excel(x, N, n, outfile);
			i = 0;
			while (fabs(x[0].f - x[N - 1].f)>1E-14)//fabs(x[0].f-x[N-1].f)>1E-14
			{
				++i;
				
				H(n, N, M, K, L, x);
				//			if(i%1000==0)
				//outfile << setiosflags(ios::fixed) << setprecision(14) << i << "generation" << "," << endl;
				outfile << setiosflags(ios::fixed) << setprecision(14) << x[0].f << endl;
				//Write_to_excel(x, N, n, outfile);
				//	        cout<<"程序运行结果:"<<setiosflags(ios::fixed)<<setprecision(14)<<x[0].f<<endl;
			}
			if (fabs(x[0].f) < 1E-6)
				ct1++;
		}
		

		finish = clock();
		duration = (LD)(finish - start) / CLOCKS_PER_SEC;
		s += duration;
		cout << "程序执行代数:" << i << "代" << endl;//hj
		cout << "程序运行时间:" << setiosflags(ios::fixed) << setprecision(4) << duration << "s" << endl;
		cout << "程序运行结果:" << setiosflags(ios::fixed) << setprecision(18) << x[0].f << endl;
		cout << "程序运行结果:" << setw(17) << x[0].f << endl;
		cout << "ct1:" << ct1 << endl;
		delete[] a; a = NULL;
		delete[] x; x = NULL;
		delete[] new_x; new_x = NULL;
		delete[] new_l_x; new_l_x = NULL;
	}
	//	cout<<"程序执行代数:"<<i/30<<"代"<<endl;//hj
	//	cout<<s/30<<endl;
	outfile.close();
	system("pause");
}
