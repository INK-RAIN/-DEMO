#include "SequenceTableDemo.h"
int main() {
	printf("hello\n");
	Sqtable table;
	MSqt_Initial(table);
	for (int i = 0; i <= 10; i++) {
		MSqt_Add(table, i);
	}
	printf("Ŀ�������Ϊ:");
	for (int i = 0; i < table.Length; i++) {
		printf("%d",table.elements[i]);
		printf(",");
	}
	printf("����Ŀ��\n");
	MSqt_Add(table, 5);
	MSqt_Sort(table, 0);
	printf("Ŀ�������Ϊ:");
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
    //˳��������
	printf("˳�������ý������:\n");
	MSqt_Sort(table, 1);
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
	printf("\n");
	//˳���ϲ�
	Sqtable tabletwo;
	MSqt_Initial(tabletwo);
	for (int i = 0; i <= 10; i++) {
		MSqt_Add(tabletwo, 2*i);
	}
	printf("Ŀ�������2Ϊ:");
	for (int i = 0; i < tabletwo.Length; i++) {
		printf("%d", tabletwo.elements[i]);
		printf(",");
	}
	printf("\n");
	//ʹ��ģʽ  ���򣬿��ظ��������±�
	printf("˳���ϲ�\n");
	printf("ʹ��ģʽ:���򣬿��ظ��������±�\n");
	Sqtable newtable = MSqt_Merge(table,tabletwo,true,true,false);
	printf("������һΪ  ");
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("�������Ϊ  ");
	for (int i = 0; i < tabletwo.Length; i++) {
		printf("%d", tabletwo.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("������±�Ϊ  ");
	for (int i = 0; i < newtable.Length; i++) {
		printf("%d", newtable.elements[i]);
		printf(",");
	}
	printf("\n");
	////ʹ��ģʽ  ���򣬲����ظ��������±�
	printf("˳���ϲ�\n");
	printf("ʹ��ģʽ:���򣬲����ظ��������±�\n");
	newtable = MSqt_Merge(table, tabletwo, true,false,false);
	printf("������һΪ  ");
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("�������Ϊ  ");
	for (int i = 0; i < tabletwo.Length; i++) {
		printf("%d", tabletwo.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("������±�Ϊ  ");
	for (int i = 0; i < newtable.Length; i++) {
		printf("%d", newtable.elements[i]);
		printf(",");
	}
	printf("\n");
	////ʹ��ģʽ  ���򣬲����ظ��������±�
	printf("˳���ϲ�\n");
	printf("ʹ��ģʽ:���򣬲����ظ��������±�\n");
	newtable = MSqt_Merge(table, tabletwo, false, false, false);
	printf("������һΪ  ");
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("�������Ϊ  ");
	for (int i = 0; i < tabletwo.Length; i++) {
		printf("%d", tabletwo.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("������±�Ϊ  ");
	for (int i = 0; i < newtable.Length; i++) {
		printf("%d", newtable.elements[i]);
		printf(",");
	}
	////ʹ��ģʽ  ���򣬿��ظ����������±�
	printf("˳���ϲ�\n");
	printf("ʹ��ģʽ:���򣬿��ظ����������±�\n");
	printf("������һΪ  ");
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
	printf("\n");
	printf("�������Ϊ  ");
	for (int i = 0; i < tabletwo.Length; i++) {
		printf("%d", tabletwo.elements[i]);
		printf(",");
	}
	printf("\n");
	MSqt_Merge(table, tabletwo, true, true, true);
	printf("�����һΪ  ");
	for (int i = 0; i < table.Length; i++) {
		printf("%d", table.elements[i]);
		printf(",");
	}
	return 1221;
}