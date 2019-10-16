#pragma once
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <ctime>
#include <cmath>
typedef int status;

constexpr auto Increased_Memory_Space = 10;
constexpr auto SafeSpace = 3;
constexpr auto InitialSpace = 1;
constexpr auto False = 0;
constexpr auto True = 1;
constexpr auto RedundantSpace = 10;

typedef struct {
	int *elements;
	int Length;
	int LastSize;
}Sqtable,*sqtable;

int MSqt_FillWithZero(Sqtable& L);
//��null����
int MSqt_FillWithNULL(Sqtable& L) {
	for (int i = 0; i <= L.Length - 1; i++) {
		L.elements[i] = NULL;
	}
	return True;
}
//��ʼ��˳���
int MSqt_Initial(Sqtable& L) {
	//����ַ
	L.elements = (int*)malloc(InitialSpace * sizeof(int));
	//�������ʧ�ܣ�����false
	if (L.elements == NULL) {
		return 1001;
	}
	//����
	L.Length = 0;
	//ʵ�ʿռ�
	L.LastSize = InitialSpace;
	return True;
}


//˳�����Ԫ��λ��
int MSqt_SwapElems(Sqtable& L, int location_a, int location_b) {
	int a = L.elements[location_a];
	L.elements[location_a] = L.elements[location_b];
	L.elements[location_b] = a;
	return True;
}


//˳�������
int MSqt_Clear(Sqtable& L) {
	MSqt_Initial(L);
	MSqt_FillWithNULL(L);
	return True;
}


//�ж��Ƿ�Ϊ�ձ�
int MSqt_IsEmpty(Sqtable L) {
	if (L.Length == 0) {
		return True;
	}
	else
	{
		return False;
	}
	return True;
}


//��0����
int MSqt_FillWithZero(Sqtable& L) {
	for (int i = 0; i <= L.Length - 1; i++) {
		L.elements[i] = 0;
	}
	return True;
}


//�ֶ�����
int MSqt_ExtendedSpace(Sqtable& L, int Size) {
	//�Ϸ��Լ��
	if (Size <= 0) {
		return  10001;
	}
	int* NewPoint = (int*)realloc(L.elements, (L.LastSize + Size) * sizeof(int));
	//���realloc�����Ƿ����ʧ�ܣ�ʹ���м�������Ӱ��˳���
	if (NewPoint != NULL) {
		//ָ�����
		//printf("�ֶ�����ָ�����\n");
		L.elements = NewPoint;
		//printf("%d\n", L.elements);
		//�����ͳ��ȸ���
		L.LastSize = L.LastSize + Size;
		L.Length = L.Length + Size;
		//printf("�ֶ�������������");
		//printf("%d\n", L.LastSize);
	}
	else {
		//�������ʧ�ܣ��ܾ���ֵ��L.elements,����Ұָ�����
		printf("����ʧ��");
		return 10002;
	}
	return True;
}




//˳���ĩβ��Ӳ���
int MSqt_Add(Sqtable& L, int elem) {
	//��鰲ȫ�ռ��Ƿ��㹻������Ļ����ӿռ�
	if (L.LastSize - L.Length <= SafeSpace) {
		int* NewPoint = (int*)realloc(L.elements, (L.LastSize + Increased_Memory_Space) * sizeof(int));
		//���realloc�����Ƿ����ʧ�ܣ�ʹ���м�������Ӱ��˳���
		if (NewPoint != NULL) {
			//ָ�����
			//printf("ָ�����\n");
			L.elements = NewPoint;
			//��������
			L.LastSize = L.LastSize + Increased_Memory_Space;
		}
		else {
			//�������ʧ�ܣ��ܾ���ֵ��L.elements,����Ұָ�����
			printf("ָ�����ʧ��\n");
			return 1004;
		}
	}
	//���Ϸ���(Do Something)


	//��Ӳ���
		//���ӳ��ȼ���
	L.Length++;
	L.elements[L.Length - 1] = elem;
	//printf("ִ��add����");
	//printf("%d\n",L.elements[L.Length - 1]);
	//printf("L.Length=");
	//printf("%d\n",L.Length);
	//���ӳ��ȼ���
	//printf("THEN L.Length=");
	//printf("%d\n", L.Length);
	//printf("%d\n", L.elements[L.Length - 1]);
	return True;
}


//˳���Ĳ������
int MSqt_Insert(Sqtable &L,int elem,int location) {
	//��鰲ȫ�ռ��Ƿ��㹻������Ļ����ӿռ�
	if (L.LastSize - L.Length <= SafeSpace) {
		int* NewPoint = (int*)realloc(L.elements, (L.LastSize+Increased_Memory_Space)*sizeof(int));
		//���realloc�����Ƿ����ʧ�ܣ�ʹ���м�������Ӱ��˳���
		if (NewPoint != NULL) {
			//ָ�����
			L.elements = NewPoint;
			//��������
			L.LastSize = L.LastSize + Increased_Memory_Space;
		}
		else {
			//�������ʧ�ܣ��ܾ���ֵ��L.elements,����Ұָ�����
			return 1002;
		}
	}
	//���Ϸ���(Do Something)
	if (location < 0 || location >= L.Length) {
		return 1003;
	}
	//�������
	int *q = &L.elements[location];
	MSqt_Add(L, L.elements[L.Length - 1]);
	for (int* p = &L.elements[L.Length - 2];  p >= q; p--) {
		*(p + 1) = *p;
	}
	*q = elem;
	//������ɣ���������
	L.Length++;
	return True;
}





//˳������ٲ���
int MSqt_Desdroy(Sqtable& L) {
	//ֱ���ͷ��ڴ�,�򵥴ֱ���Ч
	free(L.elements);
	return True;
}


//˳���ɾ������
int MSqt_Drop(Sqtable &L,int location) {
	//�жϲ����Ϸ���
	if (location <0 || location >L.Length - 1) {
		return 1005;
	}
	//ɾ������
	for (int* p = &L.elements[location + 1]; p <= &L.elements[L.Length - 1]; p++) {
		*(p - 1) = *p;
	}
	//������ɣ����ȼ���
	L.Length--;
	//���Լ죬ɾ�����లȫ�ռ�
	if (L.LastSize - L.Length >= RedundantSpace) {
		int* NewPoint = (int*)realloc(L.elements, (L.LastSize - SafeSpace) * sizeof(int));
		//���realloc�����Ƿ����ʧ�ܣ�ʹ���м�������Ӱ��˳���
		if (NewPoint != NULL) {
			//ָ�����
			L.elements = NewPoint;
			//��������
			L.LastSize = L.LastSize - SafeSpace;
		}
		else {
			//�������ʧ�ܣ��ܾ���ֵ��L.elements,����Ұָ�����
			return 1006;
		}
	}
	return True;
}


int FinalResultOfNumCoreP(Sqtable& PositiveNumberCount, int SortType, Sqtable& L) {
	if (SortType == 0) {
		//�������ֵַ
		int location = 0;
		//ֱ�ӱ����������
		printf("����Ϊ:");
		for (int i = 0; i < PositiveNumberCount.Length; i++) {
			printf("%d", PositiveNumberCount.elements[i]);
		}
		printf("\n");
		for (int i = 0; i <= PositiveNumberCount.Length - 1; i++) {
			while (PositiveNumberCount.elements[i] != 0)
			{
				L.elements[location] = i;
				PositiveNumberCount.elements[i]--;
				location++;
			}
		}
		printf("1�����������L��Ϊ:");
		for (int i = 0; i < L.Length;i++) {
			printf(",");
			printf("%d",L.elements[i]);
		}
		printf("\n");
	}
	//����
	//������򣬾͵��ű�������
	else {
		//�������ֵַ
		int location = 0;
		for (int i = PositiveNumberCount.Length - 1; i >= 0; i--) {
			while (PositiveNumberCount.elements[i] != 0)
			{
				L.elements[location] = i;
				PositiveNumberCount.elements[i]--;
				location++;
			}
		}
		printf("2�����������L��Ϊ:");
		for (int i = 0; i < L.Length; i++) {
			printf("%d", L.elements[i]);
		}
		printf("\n");
	}
	return True;

}
int FinalResultOfNumCore(Sqtable& PositiveNumberCount, Sqtable& NegativeNumberCount, int SortType, Sqtable& L) {
	//��������
	if (SortType == 0) {
		//�������ֵַ
		int location = 0;
		//���ȵ��ű��������ø�ֵ���
		for (int i = NegativeNumberCount.Length - 1; i >= 0; i--) {
			while (NegativeNumberCount.elements[i] != 0)
			{
				L.elements[location] = -i;
				NegativeNumberCount.elements[i]--;
				location++;
			}
		}
		//Ȼ�����ű����������Ÿ���ĩβ���
		for (int i = 0; i <= PositiveNumberCount.Length - 1; i++) {
			while (PositiveNumberCount.elements[i] != 0)
			{
				L.elements[location] = i;
				PositiveNumberCount.elements[i]--;
				location++;
			}
		}
		printf("3�����������L��Ϊ:");
		for (int i = 0; i < L.Length; i++) {
			printf("%d", L.elements[i]);
		}
		printf("\n");
	}
	//���������������
	//�������Ϊ��������
	else {
		//�������ֵַ
		int location = 0;
		//���ȵ��ű�������
		for (int i = PositiveNumberCount.Length - 1; i >= 0; i--) {
			while (PositiveNumberCount.elements[i] != 0)
			{
				L.elements[location] = i;
				PositiveNumberCount.elements[i]--;
				location++;
			}
		}
		//Ȼ����������ø�ֵ���
		for (int i = 0; i <= NegativeNumberCount.Length - 1; i++) {
			while (NegativeNumberCount.elements[i] != 0)
			{
				L.elements[location] = -i;
				NegativeNumberCount.elements[i]--;
				location++;
			}
		}
		printf("4�����������L��Ϊ:");
		for (int i = 0; i < L.Length; i++) {
			printf("%d", L.elements[i]);
		}
		printf("\n");
	}
	//�����������
	return True;
}
int FinalResultOfNumCoreN(Sqtable& NegativeNumberCount, int SortType, Sqtable& L) {
	if (SortType == 0) {
		//�����������ű��������ø�ֵ���
		//�������ֵַ
		int location = 0;
		for (int i = NegativeNumberCount.Length - 1; i >= 0; i--) {
			while (NegativeNumberCount.elements[i] != 0)
			{
				L.elements[location] = -i;
				NegativeNumberCount.elements[i]--;
				location++;
			}
		}
		printf("5�����������L��Ϊ:");
		for (int i = 0; i < L.Length; i++) {
			printf("%d", L.elements[i]);
		}
		printf("\n");
	}
	else {
		//����������ֱ�ӱ��������ø�ֵ���
		//�������ֵַ
		int location = 0;
		for (int i = 0; i <= NegativeNumberCount.Length - 1; i++) {
			while (NegativeNumberCount.elements[i] != 0)
			{
				L.elements[location] = -i;
				NegativeNumberCount.elements[i]--;
				location++;
			}
		}
		printf("6�����������L��Ϊ:");
		for (int i = 0; i < L.Length; i++) {
			printf("%d", L.elements[i]);
		}
		printf("\n");
	}
	return True;
}

//�����������
int NumCore(Sqtable& L, int SortType) {
	//��ȡ��������Χ
	int MinNum = 0, MaxNum = 0;
	MaxNum = L.elements[0];
	MinNum = L.elements[1];
	for (int i = 0; i < L.Length ; i++) {
		if (L.elements[i] > MaxNum) {
			MaxNum = L.elements[i];
			//printf("��ֵ��maxnum");
			//printf("maxnum=");
			//printf("%d\n",MaxNum);
		}
		else if (L.elements[i] < MinNum) {
			MinNum = L.elements[i];
		}
	}
	//printf("maxnum=");
	//printf("%d\n",MaxNum);
	//printf("minnum=");
	//printf("%d\n", MinNum);
	//�������
	if (MaxNum >= 0 && MinNum >= 0) {
		//�Բ��������½�Sqtable���ݲ���ʼ������0����
		//��������ͳ������
		Sqtable PositiveNumberCount;
		//��ʼ��
		MSqt_Initial(PositiveNumberCount);
		//����
		MSqt_ExtendedSpace(PositiveNumberCount, MaxNum - MinNum + SafeSpace);
		//printf("MaxNum - MinNum + SafeSpace=");
		//printf("%d\n", MaxNum - MinNum + SafeSpace);
		//printf("PositiveNumberCountԪ��ָ��Ϊ  ");
		//printf("%d\n", PositiveNumberCount.elements);
		//printf("PositiveNumberCount����Ϊ  ");
		//printf("%d\n", PositiveNumberCount.Length);
		//��0
		MSqt_FillWithZero(PositiveNumberCount);
		//��������
		for (int i = 0; i <= L.Length - 1; i++) {
			PositiveNumberCount.elements[L.elements[i]]++;
		}
		//���ý��������
		FinalResultOfNumCoreP(PositiveNumberCount, SortType, L);
		return True;
	}
	else if (MaxNum >= 0 && MinNum < 0) {
		//��������ʼ������ͳ������,���ݣ���0
		Sqtable PositiveNumberCount;
		MSqt_Initial(PositiveNumberCount);
		MSqt_ExtendedSpace(PositiveNumberCount, MaxNum + SafeSpace);
		MSqt_FillWithZero(PositiveNumberCount);
		//��������ʼ������ͳ������,���ݣ���0
		Sqtable NegativeNumberCount;
		MSqt_Initial(NegativeNumberCount);
		MSqt_ExtendedSpace(NegativeNumberCount, abs(MinNum) + SafeSpace);
		MSqt_FillWithZero(NegativeNumberCount);
		//��������
		for (int i = 0; i <= L.Length - 1; i++) {
			if (L.elements[i] >= 0) {
				PositiveNumberCount.elements[L.elements[i]]++;
			}
			else if (L.elements[i] < 0) {
				NegativeNumberCount.elements[abs(L.elements[i])]++;
			}
			else {
				//����������֮����������Ļ�
				return 1015;
			}
		}
		//���ý��������
		FinalResultOfNumCore(PositiveNumberCount, NegativeNumberCount, SortType, L);
		return True;
	}
	else if (MaxNum < 0) {
		//��������ʼ������ͳ������,���ݣ���0
		Sqtable NegativeNumberCount;
		MSqt_Initial(NegativeNumberCount);
		MSqt_ExtendedSpace(NegativeNumberCount, abs(MinNum) + SafeSpace);
		MSqt_FillWithZero(NegativeNumberCount);
		//��������
		for (int i = 0; i <= L.Length - 1; i++) {
			NegativeNumberCount.elements[abs(L.elements[i])]++;
		}
		//���ý��������
		FinalResultOfNumCoreN(NegativeNumberCount, SortType, L);
		return True;
	}
	else {
		//��Ȼ�����ܣ�����һ��0.0
		return 9999;
	}
	return True;
}
//����ʹ�ü�������
//˳��������ܣ�
int MSqt_Sort(Sqtable &L,int SortType) {
	//�жϺϷ��ԣ�������Ҫ��������Ԫ��
	//����0����������1�Ƿ�������
	if (L.Length < 2) {
		return 1008;
	}
	if ((SortType == 0 )|| (SortType == 1)) {
		return NumCore(L, SortType);
	}
	else {
		return  1007;
	}
}
//����
int MSqt_DuplicateChecking(Sqtable &L) {
	for (int i = 0; i < L.Length; i++) {
		for (int b = i+1; b < L.Length-1;b++) {
			if (L.elements[i]==L.elements[b]) {
				MSqt_Drop(L,b);
			}
		}
	}
	return True;
}


//��˳���鲢
Sqtable MSqt_Merge(Sqtable &MainTable, Sqtable OtherTable,bool IsOrderly,bool CanNumberRepeat,bool RepeatOperationOnMainTable) {
	if (!RepeatOperationOnMainTable) {
		//��һ�����������±������ɱ�
		Sqtable newtable;
		MSqt_Initial(newtable);
		for (int i = 0; i <= MainTable.Length - 1; i++) {
			MSqt_Add(newtable, MainTable.elements[i]);
		}
		for (int i = 0; i <= OtherTable.Length - 1; i++) {
			MSqt_Add(newtable, OtherTable.elements[i]);
		}
		if (IsOrderly) {
			//�ڶ��������Ƿ�����
			MSqt_Sort(newtable, 0);
			if (CanNumberRepeat) {
				//�����������Ƿ����
				//RepeatOperationOnMainTable&&IsOrderly&&CanNumberRepeat
				return newtable;
			}
			else {
				//�����������Ƿ����
				//RepeatOperationOnMainTable&&IsOrderly   NO(NumberRepeat)
				MSqt_DuplicateChecking(newtable);
				return newtable;
			}
		}
		else {
			//�ڶ��������Ƿ�����
			//do nothing
			//**********//
			if (CanNumberRepeat) {
				//�����������Ƿ����
				//RepeatOperationOnMainTable&&CanNumberRepeat    NO(Orderly)
				return newtable;
			}
			else {
				//�����������Ƿ����
				//RepeatOperationOnMainTable      NO(Orderly&&NumberRepeat)
				MSqt_DuplicateChecking(newtable);
				return newtable;
			}
		}
	}
	else {
		//��һ�����������±������ɱ�
		for (int i = 0; i <= OtherTable.Length - 1; i++) {
			MSqt_Add(MainTable, OtherTable.elements[i]);
		}
		if (IsOrderly) {
			//�ڶ��������Ƿ�����
			MSqt_Sort(MainTable, 0);
			if (CanNumberRepeat) {
				//�����������Ƿ����
				//IsOrderly&&CanNumberRepeat    NO(RepeatOperationOnMainTable)
				return MainTable;
			}
			else {
				//�����������Ƿ����
				//IsOrderly     NO(Orderly&&RepeatOperationOnMainTable)
				int Number = MainTable.elements[0];
				MSqt_DuplicateChecking(MainTable);
				return MainTable;
			}
		}
		else {
			//�ڶ��������Ƿ�����
			//do nothing
			//***********//
			if (CanNumberRepeat) {
				//�����������Ƿ����
				// CanNumberRepeat       NO(Orderly&&RepeatOperationOnMainTable)
				return MainTable;
			}
			else {
				//�����������Ƿ����
				//NO(RepeatOperationOnMainTable&&Orderly&&NumberRepeat)
				MSqt_DuplicateChecking(MainTable);
				return MainTable;
			}
		}
	}
	return MainTable;
}




////////////////////////////////////����˳����ʵ����ʱ��һ���䣬�����ǹ��������ʵ��//////////////////////////
typedef struct LinkTable{
	struct LinkTable* LTPoint = NULL;
	int *element = (int*)malloc(1 * sizeof(int));
}LinkTable,*linkTable;


//���������õ��ĵݹ麯��
bool InternalFuntion_Recursion_ForInitial(LinkTable *L) {
	if (L->LTPoint==NULL) {
		free(L->element);
		free(L->LTPoint);
		free(L);
		return true;
	}
	else if(InternalFuntion_Recursion_ForInitial(L->LTPoint)){
		free(L->element);
		free(L->LTPoint);
		free(L);
		return true;
	}
}


//��������
int LT_Initial(LinkTable &L) {
	if (L.LTPoint != NULL) {
		InternalFuntion_Recursion_ForInitial(L.LTPoint);
	}
	return True;
}


//������������
int LT_AddElements(LinkTable &L,int elemnet) {
	LinkTable* TemporaryTable = NULL;
	
	TemporaryTable->LTPoint = L.LTPoint;
	while (TemporaryTable->LTPoint==NULL)
	{
		TemporaryTable = TemporaryTable->LTPoint;
	}
	LinkTable* NewLTable = NULL;
	TemporaryTable->LTPoint = NewLTable;
	*NewLTable->element = elemnet;
	return True;
}


//��ѯ������
int LT_SelectLength(LinkTable L) {
	int Long = 1;
	LinkTable* TemporaryTable = NULL;
	TemporaryTable->LTPoint = L.LTPoint;
	while (TemporaryTable->LTPoint!=NULL)
	{
		TemporaryTable = TemporaryTable->LTPoint;
		Long++;
	}
	return Long;
}



//�����������
int LT_InsertElements(LinkTable& L, int location, int element) {
	return 0;
}