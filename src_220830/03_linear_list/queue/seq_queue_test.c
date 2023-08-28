/**
 * @file    : seq_queue_test.c
 * @author  : KeeneChen
 * @date    : 2022.09.01-16:39:14
 * @details : seq_queue_test
 */

#include "seq_queue.h"

typedef struct {
    char name[20];
    int age;
} Student;

int main(void)
{
    seq_queue queue = seq_queue_init();

    Student stu1 = { "张三", 1 };
    Student stu2 = { "李四", 2 };
    Student stu3 = { "王五", 3 };
    Student stu4 = { "赵六", 4 };
    seq_queue_push(queue, &stu1);
    seq_queue_push(queue, &stu2);
    seq_queue_push(queue, &stu3);
    seq_queue_push(queue, &stu4);
    printf("队列大小:%d\n", seq_queue_size(queue));

    while (seq_queue_isEmpty(queue) == 0) {
        // 访问队头
        Student *pFront = seq_queue_front(queue);
        printf("队头元素 -- 姓名：%s  年龄： %d\n", pFront->name, pFront->age);
        // 访问队尾
        Student *pBack = seq_queue_back(queue);
        printf("队尾元素 -- 姓名：%s  年龄： %d\n", pBack->name, pBack->age);
        // 出队
        seq_queue_pop(queue);
    }
    seq_queue_destory(queue);

    return 0;
}
