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
//用null填满
int MSqt_FillWithNULL(Sqtable& L) {
	for (int i = 0; i <= L.Length - 1; i++) {
		L.elements[i] = NULL;
	}
	return True;
}
//初始化顺序表
int MSqt_Initial(Sqtable& L) {
	//基地址
	L.elements = (int*)malloc(InitialSpace * sizeof(int));
	//如果创建失败，返回false
	if (L.elements == NULL) {
		return 1001;
	}
	//长度
	L.Length = 0;
	//实际空间
	L.LastSize = InitialSpace;
	return True;
}


//顺序表交换元素位置
int MSqt_SwapElems(Sqtable& L, int location_a, int location_b) {
	int a = L.elements[location_a];
	L.elements[location_a] = L.elements[location_b];
	L.elements[location_b] = a;
	return True;
}


//顺序表重置
int MSqt_Clear(Sqtable& L) {
	MSqt_Initial(L);
	MSqt_FillWithNULL(L);
	return True;
}


//判断是否为空表
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


//用0填满
int MSqt_FillWithZero(Sqtable& L) {
	for (int i = 0; i <= L.Length - 1; i++) {
		L.elements[i] = 0;
	}
	return True;
}


//手动扩容
int MSqt_ExtendedSpace(Sqtable& L, int Size) {
	//合法性检查
	if (Size <= 0) {
		return  10001;
	}
	int* NewPoint = (int*)realloc(L.elements, (L.LastSize + Size) * sizeof(int));
	//检查realloc函数是否分配失败，使用中间量避免影响顺序表
	if (NewPoint != NULL) {
		//指针更新
		//printf("手动扩容指针更新\n");
		L.elements = NewPoint;
		//printf("%d\n", L.elements);
		//容量和长度更新
		L.LastSize = L.LastSize + Size;
		L.Length = L.Length + Size;
		//printf("手动扩容容量更新");
		//printf("%d\n", L.LastSize);
	}
	else {
		//如果分配失败，拒绝赋值给L.elements,避免野指针出现
		printf("分配失败");
		return 10002;
	}
	return True;
}




//顺序表末尾添加操作
int MSqt_Add(Sqtable& L, int elem) {
	//检查安全空间是否足够，不足的话增加空间
	if (L.LastSize - L.Length <= SafeSpace) {
		int* NewPoint = (int*)realloc(L.elements, (L.LastSize + Increased_Memory_Space) * sizeof(int));
		//检查realloc函数是否分配失败，使用中间量避免影响顺序表
		if (NewPoint != NULL) {
			//指针更新
			//printf("指针更新\n");
			L.elements = NewPoint;
			//容量更新
			L.LastSize = L.LastSize + Increased_Memory_Space;
		}
		else {
			//如果分配失败，拒绝赋值给L.elements,避免野指针出现
			printf("指针更新失败\n");
			return 1004;
		}
	}
	//检查合法性(Do Something)


	//添加操作
		//增加长度计数
	L.Length++;
	L.elements[L.Length - 1] = elem;
	//printf("执行add操作");
	//printf("%d\n",L.elements[L.Length - 1]);
	//printf("L.Length=");
	//printf("%d\n",L.Length);
	//增加长度计数
	//printf("THEN L.Length=");
	//printf("%d\n", L.Length);
	//printf("%d\n", L.elements[L.Length - 1]);
	return True;
}


//顺序表的插入操作
int MSqt_Insert(Sqtable &L,int elem,int location) {
	//检查安全空间是否足够，不足的话增加空间
	if (L.LastSize - L.Length <= SafeSpace) {
		int* NewPoint = (int*)realloc(L.elements, (L.LastSize+Increased_Memory_Space)*sizeof(int));
		//检查realloc函数是否分配失败，使用中间量避免影响顺序表
		if (NewPoint != NULL) {
			//指针更新
			L.elements = NewPoint;
			//容量更新
			L.LastSize = L.LastSize + Increased_Memory_Space;
		}
		else {
			//如果分配失败，拒绝赋值给L.elements,避免野指针出现
			return 1002;
		}
	}
	//检查合法性(Do Something)
	if (location < 0 || location >= L.Length) {
		return 1003;
	}
	//插入操作
	int *q = &L.elements[location];
	MSqt_Add(L, L.elements[L.Length - 1]);
	for (int* p = &L.elements[L.Length - 2];  p >= q; p--) {
		*(p + 1) = *p;
	}
	*q = elem;
	//操作完成，长度增加
	L.Length++;
	return True;
}





//顺序表销毁操作
int MSqt_Desdroy(Sqtable& L) {
	//直接释放内存,简单粗暴有效
	free(L.elements);
	return True;
}


//顺序表删除操作
int MSqt_Drop(Sqtable &L,int location) {
	//判断参数合法性
	if (location <0 || location >L.Length - 1) {
		return 1005;
	}
	//删除操作
	for (int* p = &L.elements[location + 1]; p <= &L.elements[L.Length - 1]; p++) {
		*(p - 1) = *p;
	}
	//操作完成，长度减少
	L.Length--;
	//表自检，删除多余安全空间
	if (L.LastSize - L.Length >= RedundantSpace) {
		int* NewPoint = (int*)realloc(L.elements, (L.LastSize - SafeSpace) * sizeof(int));
		//检查realloc函数是否分配失败，使用中间量避免影响顺序表
		if (NewPoint != NULL) {
			//指针更新
			L.elements = NewPoint;
			//容量更新
			L.LastSize = L.LastSize - SafeSpace;
		}
		else {
			//如果分配失败，拒绝赋值给L.elements,避免野指针出现
			return 1006;
		}
	}
	return True;
}


int FinalResultOfNumCoreP(Sqtable& PositiveNumberCount, int SortType, Sqtable& L) {
	if (SortType == 0) {
		//操作表地址值
		int location = 0;
		//直接遍历正表并输出
		printf("正表为:");
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
		printf("1号排序操作后L表为:");
		for (int i = 0; i < L.Length;i++) {
			printf(",");
			printf("%d",L.elements[i]);
		}
		printf("\n");
	}
	//结束
	//如果倒序，就倒着遍历正表
	else {
		//操作表地址值
		int location = 0;
		for (int i = PositiveNumberCount.Length - 1; i >= 0; i--) {
			while (PositiveNumberCount.elements[i] != 0)
			{
				L.elements[location] = i;
				PositiveNumberCount.elements[i]--;
				location++;
			}
		}
		printf("2号排序操作后L表为:");
		for (int i = 0; i < L.Length; i++) {
			printf("%d", L.elements[i]);
		}
		printf("\n");
	}
	return True;

}
int FinalResultOfNumCore(Sqtable& PositiveNumberCount, Sqtable& NegativeNumberCount, int SortType, Sqtable& L) {
	//正向排序
	if (SortType == 0) {
		//操作表地址值
		int location = 0;
		//首先倒着遍历负表，用负值输出
		for (int i = NegativeNumberCount.Length - 1; i >= 0; i--) {
			while (NegativeNumberCount.elements[i] != 0)
			{
				L.elements[location] = -i;
				NegativeNumberCount.elements[i]--;
				location++;
			}
		}
		//然后正着遍历正表，接着负表末尾输出
		for (int i = 0; i <= PositiveNumberCount.Length - 1; i++) {
			while (PositiveNumberCount.elements[i] != 0)
			{
				L.elements[location] = i;
				PositiveNumberCount.elements[i]--;
				location++;
			}
		}
		printf("3号排序操作后L表为:");
		for (int i = 0; i < L.Length; i++) {
			printf("%d", L.elements[i]);
		}
		printf("\n");
	}
	//正向排序操作结束
	//如果参数为负向排序
	else {
		//操作表地址值
		int location = 0;
		//首先倒着遍历正表
		for (int i = PositiveNumberCount.Length - 1; i >= 0; i--) {
			while (PositiveNumberCount.elements[i] != 0)
			{
				L.elements[location] = i;
				PositiveNumberCount.elements[i]--;
				location++;
			}
		}
		//然后遍历负表，用负值输出
		for (int i = 0; i <= NegativeNumberCount.Length - 1; i++) {
			while (NegativeNumberCount.elements[i] != 0)
			{
				L.elements[location] = -i;
				NegativeNumberCount.elements[i]--;
				location++;
			}
		}
		printf("4号排序操作后L表为:");
		for (int i = 0; i < L.Length; i++) {
			printf("%d", L.elements[i]);
		}
		printf("\n");
	}
	//负向排序结束
	return True;
}
int FinalResultOfNumCoreN(Sqtable& NegativeNumberCount, int SortType, Sqtable& L) {
	if (SortType == 0) {
		//正向排序，则倒着遍历负表，用负值输出
		//操作表地址值
		int location = 0;
		for (int i = NegativeNumberCount.Length - 1; i >= 0; i--) {
			while (NegativeNumberCount.elements[i] != 0)
			{
				L.elements[location] = -i;
				NegativeNumberCount.elements[i]--;
				location++;
			}
		}
		printf("5号排序操作后L表为:");
		for (int i = 0; i < L.Length; i++) {
			printf("%d", L.elements[i]);
		}
		printf("\n");
	}
	else {
		//负向排序，则直接遍历负表，用负值输出
		//操作表地址值
		int location = 0;
		for (int i = 0; i <= NegativeNumberCount.Length - 1; i++) {
			while (NegativeNumberCount.elements[i] != 0)
			{
				L.elements[location] = -i;
				NegativeNumberCount.elements[i]--;
				location++;
			}
		}
		printf("6号排序操作后L表为:");
		for (int i = 0; i < L.Length; i++) {
			printf("%d", L.elements[i]);
		}
		printf("\n");
	}
	return True;
}

//计数排序核心
int NumCore(Sqtable& L, int SortType) {
	//获取计数排序范围
	int MinNum = 0, MaxNum = 0;
	MaxNum = L.elements[0];
	MinNum = L.elements[1];
	for (int i = 0; i < L.Length ; i++) {
		if (L.elements[i] > MaxNum) {
			MaxNum = L.elements[i];
			//printf("赋值了maxnum");
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
	//结果处理
	if (MaxNum >= 0 && MinNum >= 0) {
		//自产自销，新建Sqtable数据并初始化，用0填满
		//创建正数统计数组
		Sqtable PositiveNumberCount;
		//初始化
		MSqt_Initial(PositiveNumberCount);
		//扩容
		MSqt_ExtendedSpace(PositiveNumberCount, MaxNum - MinNum + SafeSpace);
		//printf("MaxNum - MinNum + SafeSpace=");
		//printf("%d\n", MaxNum - MinNum + SafeSpace);
		//printf("PositiveNumberCount元素指针为  ");
		//printf("%d\n", PositiveNumberCount.elements);
		//printf("PositiveNumberCount长度为  ");
		//printf("%d\n", PositiveNumberCount.Length);
		//置0
		MSqt_FillWithZero(PositiveNumberCount);
		//遍历计数
		for (int i = 0; i <= L.Length - 1; i++) {
			PositiveNumberCount.elements[L.elements[i]]++;
		}
		//调用结果处理函数
		FinalResultOfNumCoreP(PositiveNumberCount, SortType, L);
		return True;
	}
	else if (MaxNum >= 0 && MinNum < 0) {
		//创建并初始化正数统计数组,扩容，置0
		Sqtable PositiveNumberCount;
		MSqt_Initial(PositiveNumberCount);
		MSqt_ExtendedSpace(PositiveNumberCount, MaxNum + SafeSpace);
		MSqt_FillWithZero(PositiveNumberCount);
		//创建并初始化负数统计数组,扩容，置0
		Sqtable NegativeNumberCount;
		MSqt_Initial(NegativeNumberCount);
		MSqt_ExtendedSpace(NegativeNumberCount, abs(MinNum) + SafeSpace);
		MSqt_FillWithZero(NegativeNumberCount);
		//遍历计数
		for (int i = 0; i <= L.Length - 1; i++) {
			if (L.elements[i] >= 0) {
				PositiveNumberCount.elements[L.elements[i]]++;
			}
			else if (L.elements[i] < 0) {
				NegativeNumberCount.elements[abs(L.elements[i])]++;
			}
			else {
				//出现了意料之外的奇葩错误的话
				return 1015;
			}
		}
		//调用结果处理函数
		FinalResultOfNumCore(PositiveNumberCount, NegativeNumberCount, SortType, L);
		return True;
	}
	else if (MaxNum < 0) {
		//创建并初始化负数统计数组,扩容，置0
		Sqtable NegativeNumberCount;
		MSqt_Initial(NegativeNumberCount);
		MSqt_ExtendedSpace(NegativeNumberCount, abs(MinNum) + SafeSpace);
		MSqt_FillWithZero(NegativeNumberCount);
		//遍历计数
		for (int i = 0; i <= L.Length - 1; i++) {
			NegativeNumberCount.elements[abs(L.elements[i])]++;
		}
		//调用结果处理函数
		FinalResultOfNumCoreN(NegativeNumberCount, SortType, L);
		return True;
	}
	else {
		//虽然不可能，但万一呢0.0
		return 9999;
	}
	return True;
}
//尝试使用计数排序
//顺序表排序（总）
int MSqt_Sort(Sqtable &L,int SortType) {
	//判断合法性，排序需要至少两个元素
	//参数0是正向排序，1是反向排序
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
//查重
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


//两顺序表归并
Sqtable MSqt_Merge(Sqtable &MainTable, Sqtable OtherTable,bool IsOrderly,bool CanNumberRepeat,bool RepeatOperationOnMainTable) {
	if (!RepeatOperationOnMainTable) {
		//第一步处理：创建新表或操作旧表
		Sqtable newtable;
		MSqt_Initial(newtable);
		for (int i = 0; i <= MainTable.Length - 1; i++) {
			MSqt_Add(newtable, MainTable.elements[i]);
		}
		for (int i = 0; i <= OtherTable.Length - 1; i++) {
			MSqt_Add(newtable, OtherTable.elements[i]);
		}
		if (IsOrderly) {
			//第二步处理：是否排序
			MSqt_Sort(newtable, 0);
			if (CanNumberRepeat) {
				//第三步处理：是否查重
				//RepeatOperationOnMainTable&&IsOrderly&&CanNumberRepeat
				return newtable;
			}
			else {
				//第三步处理：是否查重
				//RepeatOperationOnMainTable&&IsOrderly   NO(NumberRepeat)
				MSqt_DuplicateChecking(newtable);
				return newtable;
			}
		}
		else {
			//第二步处理：是否排序
			//do nothing
			//**********//
			if (CanNumberRepeat) {
				//第三步处理：是否查重
				//RepeatOperationOnMainTable&&CanNumberRepeat    NO(Orderly)
				return newtable;
			}
			else {
				//第三步处理：是否查重
				//RepeatOperationOnMainTable      NO(Orderly&&NumberRepeat)
				MSqt_DuplicateChecking(newtable);
				return newtable;
			}
		}
	}
	else {
		//第一步处理：创建新表或操作旧表
		for (int i = 0; i <= OtherTable.Length - 1; i++) {
			MSqt_Add(MainTable, OtherTable.elements[i]);
		}
		if (IsOrderly) {
			//第二步处理：是否排序
			MSqt_Sort(MainTable, 0);
			if (CanNumberRepeat) {
				//第三步处理：是否查重
				//IsOrderly&&CanNumberRepeat    NO(RepeatOperationOnMainTable)
				return MainTable;
			}
			else {
				//第三步处理：是否查重
				//IsOrderly     NO(Orderly&&RepeatOperationOnMainTable)
				int Number = MainTable.elements[0];
				MSqt_DuplicateChecking(MainTable);
				return MainTable;
			}
		}
		else {
			//第二步处理：是否排序
			//do nothing
			//***********//
			if (CanNumberRepeat) {
				//第三步处理：是否查重
				// CanNumberRepeat       NO(Orderly&&RepeatOperationOnMainTable)
				return MainTable;
			}
			else {
				//第三步处理：是否查重
				//NO(RepeatOperationOnMainTable&&Orderly&&NumberRepeat)
				MSqt_DuplicateChecking(MainTable);
				return MainTable;
			}
		}
	}
	return MainTable;
}




////////////////////////////////////关于顺序表的实现暂时告一段落，下面是关于链表的实现//////////////////////////
typedef struct LinkTable{
	struct LinkTable* LTPoint = NULL;
	int *element = (int*)malloc(1 * sizeof(int));
}LinkTable,*linkTable;


//重置链表用到的递归函数
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


//重置链表
int LT_Initial(LinkTable &L) {
	if (L.LTPoint != NULL) {
		InternalFuntion_Recursion_ForInitial(L.LTPoint);
	}
	return True;
}


//链表新增数据
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


//查询链表长度
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



//链表插入数据
int LT_InsertElements(LinkTable& L, int location, int element) {
	return 0;
}