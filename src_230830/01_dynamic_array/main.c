/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.08.24-18:13:42
 * @details : 测试动态数组,数据类型为char,int,struct
 */

#include "dynamic_array.h"
#include <string.h>

static inline void print_char(void *arg)
{
    char *temp = arg;
    printf("%c", *temp);
}

static inline int compare_char(void *value1, void *value2)
{
    const char *temp1 = value1;
    const char *temp2 = value2;

    return (strcmp(temp1, temp2) == 0);
}

#define SHOW(x)                                                          \
    do {                                                                 \
        printf("\n---- %s ----\n", x);                                   \
        printf("capacity: %d size: %d\n", array->capacity, array->size); \
    } while (0);

static void test_char(char *str)
{
    // 初始化动态数组
    struct dynamic_array *array = dynarr_init(2);
    SHOW("dynarr_init");

    // 插入数据
    dynarr_insert(array, 2, &str[2]);
    dynarr_insert(array, 1, &str[0]);
    dynarr_insert(array, 0, &str[1]);
    dynarr_insert(array, 3, &str[3]);
    dynarr_insert(array, 4, &str[4]);
    SHOW("dynarr_insert");

    // 遍历数组
    SHOW("dynarr_foreach");
    dynarr_foreach(array, print_char);
    printf("\n");

    // 删除元素
    dynarr_del_by_index(array, 1);
    SHOW("dynarr_del_by_index");
    dynarr_foreach(array, print_char);
    printf("\n");

    // 根据值删除元素
    dynarr_del_by_value(array, &str[1], compare_char);
    SHOW("dynarr_del_by_value");
    dynarr_foreach(array, print_char);
    printf("\n");

    // 查看第一个元素
    SHOW("dynarr_first");
    printf("%c\n", *(char *)dynarr_first(array));

    // 查看最后一个元素
    SHOW("dynarr_last");
    printf("%c\n", *(char *)dynarr_last(array));

    // 销毁动态数组
    dynarr_destroy(array);
}

/**************************** test_int *********************************/

static inline void print_int(void *arg)
{
    int *temp = arg;
    printf("%d", *temp);
}

static inline int compare_int(void *value1, void *value2)
{
    const int *temp1 = value1;
    const int *temp2 = value2;

    return (temp1 == temp2);
}

static void test_int(int *arr)
{
    // 初始化动态数组
    struct dynamic_array *array = dynarr_init(2);
    SHOW("dynarr_init");

    // 插入数据
    dynarr_insert(array, 2, &arr[2]);
    dynarr_insert(array, 1, &arr[0]);
    dynarr_insert(array, 0, &arr[1]);
    dynarr_insert(array, 3, &arr[3]);
    dynarr_insert(array, 4, &arr[4]);
    SHOW("dynarr_insert");

    // 遍历数组
    SHOW("dynarr_foreach");
    dynarr_foreach(array, print_int);
    printf("\n");

    // 删除元素
    dynarr_del_by_index(array, 1);
    SHOW("dynarr_del_by_index");
    dynarr_foreach(array, print_int);
    printf("\n");

    // 根据值删除元素
    dynarr_del_by_value(array, &arr[1], compare_int);
    SHOW("dynarr_del_by_value");
    dynarr_foreach(array, print_int);
    printf("\n");

    // 查看第一个元素
    SHOW("dynarr_first");
    printf("%d\n", *(int *)dynarr_first(array));

    // 查看最后一个元素
    SHOW("dynarr_last");
    printf("%d\n", *(int *)dynarr_last(array));

    // 销毁动态数组
    dynarr_destroy(array);
}

/**************************** test_struct *********************************/

struct student {
    char name[20];
    int age;
};

static inline void print_struct(void *arg)
{
    struct student *stu = arg;
    printf("name: %s age: %d\n", stu->name, stu->age);
}

static inline int compare_struct(void *value1, void *value2)
{
    struct student *stu1 = value1;
    struct student *stu2 = value2;

    return (strcmp(stu1->name, stu2->name) == 0) && (stu1->age == stu2->age);
}

static void test_struct(struct student *stu)
{
    // 初始化动态数组
    struct dynamic_array *array = dynarr_init(2);
    SHOW("dynarr_init");

    // 插入数据
    dynarr_insert(array, 2, &stu[2]);
    dynarr_insert(array, 1, &stu[0]);
    dynarr_insert(array, 0, &stu[1]);
    dynarr_insert(array, 3, &stu[3]);
    dynarr_insert(array, 4, &stu[4]);
    SHOW("dynarr_insert");

    // 遍历数组
    SHOW("dynarr_foreach");
    dynarr_foreach(array, print_struct);
    printf("\n");

    // 删除元素
    dynarr_del_by_index(array, 1);
    SHOW("dynarr_del_by_index");
    dynarr_foreach(array, print_struct);
    printf("\n");

    // 根据值删除元素
    struct student temp = { "李四", 20 };
    dynarr_del_by_value(array, &temp, compare_struct);
    SHOW("dynarr_del_by_value");
    dynarr_foreach(array, print_struct);
    printf("\n");

    // 查看第一个元素
    SHOW("dynarr_first");
    struct student *stu1 = dynarr_first(array);
    printf("name: %s age: %d\n", stu1->name, stu1->age);

    // 查看最后一个元素
    SHOW("dynarr_last");
    struct student *stu2 = dynarr_last(array);
    printf("name: %s age: %d\n", stu2->name, stu2->age);

    // 销毁动态数组
    dynarr_destroy(array);
}

int main(void)
{
    char *str = "hello";
    // test_char(str);

    int arr[] = { 1, 2, 3, 4, 5 };
    // test_int(arr);

    /*  struct student stu[5] = { [0] = { .name = "张三", .age = 10 },
                               [1] = { .name = "李四", .age = 20 },
                               [2] = { .name = "王五", .age = 30 },
                               [3] = { .name = "赵六", .age = 40 },
                               [4] = { .name = "孙七", .age = 50 } };
     strcpy(stu[0].name, "张三");
     stu[0].age = 10;
     strcpy(stu[1].name, "李四");
     stu[1].age = 20;
     strcpy(stu[2].name, "王五");
     stu[2].age = 30;
     strcpy(stu[3].name, "赵六");
     stu[3].age = 40;
     strcpy(stu[4].name, "孙七");
     stu[4].age = 50; */

    struct student stu[5] = { { "张三", 10 },
                              { "李四", 20 },
                              { "王五", 30 },
                              { "赵六", 40 },
                              { "孙七", 50 } };
    test_struct(stu);

    return 0;
}