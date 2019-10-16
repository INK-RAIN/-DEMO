#include "SequenceTableDemo.h"
int main() {
	printf("hello\n");
	Sqtable table;
	MSqt_Initial(table);
	for (int i = 0; i <= 10; i++) {
		MSqt_Add(table, i);
	}
	printf("目标操作表为:");
	for (int i = 0; i < table.Length; i++) {
		printf("%d",table.elements[i]);
		printf(",");
	}
	printf("操作目标\n");
	MSqt_Add(table, 5);
	MSqt_Sort(table, 0);
	printf("目标操作后为:");
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
    //顺序表的逆置
	printf("顺序表的逆置结果如下:\n");
	MSqt_Sort(table, 1);
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
	printf("\n");
	//顺序表合并
	Sqtable tabletwo;
	MSqt_Initial(tabletwo);
	for (int i = 0; i <= 10; i++) {
		MSqt_Add(tabletwo, 2*i);
	}
	printf("目标操作表2为:");
	for (int i = 0; i < tabletwo.Length; i++) {
		printf("%d", tabletwo.elements[i]);
		printf(",");
	}
	printf("\n");
	//使用模式  有序，可重复，创建新表
	printf("顺序表合并\n");
	printf("使用模式:有序，可重复，创建新表\n");
	Sqtable newtable = MSqt_Merge(table,tabletwo,true,true,false);
	printf("操作表一为  ");
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("操作表二为  ");
	for (int i = 0; i < tabletwo.Length; i++) {
		printf("%d", tabletwo.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("结果表新表为  ");
	for (int i = 0; i < newtable.Length; i++) {
		printf("%d", newtable.elements[i]);
		printf(",");
	}
	printf("\n");
	////使用模式  有序，不可重复，创建新表
	printf("顺序表合并\n");
	printf("使用模式:有序，不可重复，创建新表\n");
	newtable = MSqt_Merge(table, tabletwo, true,false,false);
	printf("操作表一为  ");
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("操作表二为  ");
	for (int i = 0; i < tabletwo.Length; i++) {
		printf("%d", tabletwo.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("结果表新表为  ");
	for (int i = 0; i < newtable.Length; i++) {
		printf("%d", newtable.elements[i]);
		printf(",");
	}
	printf("\n");
	////使用模式  无序，不可重复，创建新表
	printf("顺序表合并\n");
	printf("使用模式:无序，不可重复，创建新表\n");
	newtable = MSqt_Merge(table, tabletwo, false, false, false);
	printf("操作表一为  ");
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("操作表二为  ");
	for (int i = 0; i < tabletwo.Length; i++) {
		printf("%d", tabletwo.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("结果表新表为  ");
	for (int i = 0; i < newtable.Length; i++) {
		printf("%d", newtable.elements[i]);
		printf(",");
	}
	////使用模式  有序，可重复，不创建新表
	printf("顺序表合并\n");
	printf("使用模式:有序，可重复，不创建新表\n");
	printf("操作表一为  ");
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("操作表二为  ");
	for (int i = 0; i < tabletwo.Length; i++) {
		printf("%d", tabletwo.elements[i]);
		printf(",");
	}
	printf("\n");
	MSqt_Merge(table, tabletwo, true, true, true);
	printf("结果表一为  ");
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
	return 1221;
}