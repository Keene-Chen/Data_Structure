#ifndef __DOUBLE_CIRCULAR_LINKED_LIST_H__
#define __DOUBLE_CIRCULAR_LINKED_LIST_H__

#define HEAD_INSERT 1
#define TAIL_INSERT 2

/**
 * ? 函数指针
 */
typedef void node_print(void *data);
typedef int node_compare(void *value1, void *value2);

/* 结点结构体 */
struct node {
    void *data;
    struct node *prev;
    struct node *next;
};

/* 链表结构体 */
struct list {
    struct node *head;
    int size;
};

/* 防止用户修改结构 */
typedef void *linkedlist;

/**
 * @brief  list_create 初始化链表,创建头结点用来管理链表
 * @param  int initsize 有效结点 malloc 大小
 * @return linkedlist 带头结点的链表
 */
linkedlist list_create(int initsize);

/**
 * @brief  list_destroy 释放链表
 * @param  linedlist list 带头链表
 * @return void
 */
void list_destroy(linkedlist list);

/**
 * @brief  list_insert 链表插入
 * @param  linedlist list 带头链表
 * @param  void *data 待插入数据
 * @param  int mode 插入模式
 * @return int 插入是否成功
 * @retval 0   插入成功
 * @retval -1  插入失败
 */
int list_insert(linkedlist list, void *data, int mode);

/**
 * @brief  find_ 辅助函数
 * @param  linedlist list 带头链表
 * @param  void *key 带比较的值
 * @param  node_compare *compare_cb 用户传来的比较函数指针
 * @return 是否查找到对应key值的结点
 * @retval struct node * 指针
 * @retval list->head 头结点
 */
static struct node *find_(linkedlist list, void *key, node_compare *compare_cb);

/**
 * @brief  list_find 查找链表中的值
 * @param  linedlist list 带头链表
 * @param  void *key 带比较的值
 * @param  node_compare *compare_cb 用户传来的比较函数指针
 * @return void* 是否查找到对应 key 值的结点
 * @retval 非空  查找到对应 key 值的结点
 * @retval NULL 未查找到
 */
void *list_find(linkedlist list, void *key, node_compare *compare_cb);

/**
 * @brief  list_delete 删除链表中的值
 * @param  linedlist list 带头链表
 * @param  void *key 带比较的值
 * @param  node_compare *compare_cb 用户传来的比较函数指针
 * @return int 删除是否成功
 * @retval 0   删除成功
 * @retval -1  删除失败
 */
int list_delete(linkedlist list, void *key, node_compare *compare_cb);

/**
 * @brief  list_fetch 获取并删除链表中的值
 * @param  linedlist list 带头链表
 * @param  void *key 带比较的值
 * @param  node_compare *compare_cb 用户传来的比较函数指针
 * @return int 是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_fetch(linkedlist list, void *key, node_compare *compare_cb, void *data);

/**
 * @brief  list_foreach 遍历链表中的值
 * @param  linedlist list 带头链表
 * @param  node_print *print_cb 用户传来的打印函数
 * @return int 遍历是否成功
 * @retval 0   遍历成功
 * @retval -1  遍历失败
 */
int list_foreach(linkedlist list, node_print *print_cb);

#endif // __DOUBLE_CIRCULAR_LINKED_LIST_H__