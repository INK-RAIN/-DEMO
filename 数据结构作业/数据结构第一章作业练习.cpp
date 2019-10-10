#include "SequenceTableDemo.h"
#include <stdio.h>
#include <io.h>

constexpr auto error = 0;

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