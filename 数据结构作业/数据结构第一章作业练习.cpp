#include "SequenceTableDemo.h"
#include <stdio.h>
#include <io.h>

constexpr auto error = 0;
//数据结构1.8
/*
1,2,3均为 n-1
4为n+(n-1)+(n-2)+...+1
5为1+(1+2)+(1+2+3)+...+(1+2+3+...+n)
6为n
7.......
8为1100
*/


//数据结构1.9
//log2n


//数据结构1.11
/*
2的n次方=10的12次方时  n=40
n的10次方=10的12次方时 n=16
故由循环次数n得第一种算法更合适
*/

//数据结构作业1.16
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

//数据结构作业1.17
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


//数据结构作业1.18




//数据结构作业1.19
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

//数据结构作业1.20
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
