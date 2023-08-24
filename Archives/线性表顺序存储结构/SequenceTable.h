/**
 * Author:   hellochen
 * DateTime: 2021.04.01-13:15:33
 * Description: 顺序表结构和操作函数声明
 */

/* variable statement*/
#define Size      10
#define DELIMITER "\n------------------------------------------\n"

typedef struct Table {
    int *head;
    int length;
    int size;
} Table;

/* function statement*/
Table initTable();
void showTable(Table t);
Table insertTable(Table t, int elem, int addIndex);
Table deleteTable(Table t, int deleteIndex);
int selectTable(Table t, int elem);
Table updateTable(Table t, int elem, int updateElem);