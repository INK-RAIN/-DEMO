#include "SequenceTableDemo.h"
#include <stdio.h>
#include <io.h>

constexpr auto error = 0;
//���ݽṹ1.8
//
//1,2,3��Ϊ n-1
//4Ϊn+(n-1)+(n-2)+...+1
//5Ϊ1+(1+2)+(1+2+3)+...+(1+2+3+...+n)
//6Ϊn
//7.......
//8Ϊ1100



//���ݽṹ1.9
//log2n


//���ݽṹ1.11
//2��n�η�=10��12�η�ʱ  n=40
//n��10�η�=10��12�η�ʱ n=16
//����ѭ������n�õ�һ���㷨������


//���ݽṹ��ҵ1.16
int WorkOne(int X,int Y,int Z) {
	Sqtable table;
	MSqt_Initial(table);
	MSqt_Add(table, X);
	MSqt_Add(table, Y);
	MSqt_Add(table, Z);
	MSqt_Sort(table, 1);
	for (int i = 0; i < table.Length - 1; i++) {
		printf("%d", table.elements[i]);
	}
	MSqt_Desdroy(table);
	return 1;
}

//���ݽṹ��ҵ1.17
int WorkTwo(int k,int n) {
	if (k < 1) return error;
	int x;
	Sqtable table;
	int i, j;
	for (i = 0; i < k + 1; i++) {
		if (i < k - 1) {
		    MSqt_Insert(table,0, i);
		}
		else {
		    MSqt_Insert(table,1, i);
		}
	}
	for (i = k + 1; i < n + 1; i++) {
		x = table.elements[0];
		for (j = 0; j < k; j++) {
			table.elements[j] = table.elements[j + 1];
		}
		table.elements[k] = 2 * table.elements[k-1] - x;
	}
	return table.elements[k];
}


//���ݽṹ��ҵ1.18




//���ݽṹ��ҵ1.19
int WorkFour(int n,int arrysize) {
	if (n > arrysize ) {
		return error;
	}
	int i;
	Sqtable table;
	MSqt_Initial(table);
	MSqt_ExtendedSpace(table, 100);
	for (i = 0; i <= n; i++) {
		if (i == 0) {
			table.elements[i] = 1;
		}
		else {
			if (2 * i * table.elements[i - 1] > 25565) {
				return error;
			}
			else table.elements[i] = 2 * i * table.elements[i-1];
		}
	}
	for (i = 0; i <= n; i++) {
		if (table.elements[i] > 25565) {
			return error;
		}
		else {
			printf("%d", table.elements[i]);
		}
	}
	return 0;
}

//���ݽṹ��ҵ1.20
int WorkFive(double x, int n,Sqtable table) {
	if (n > 9) {
		return error;
	}
	int result=InternalFunction(a, n, x, n);
	printf("%d", result)
		return 0;
}
int InternalFunction(Sqtable table, int i, double x, int n) {
	if (i > 0){
		return table.elements[n-1] + polynomail(a, i - 1, x, n) * x;
	}
	else {
		return table.elements[n];
	}
}