/**
 * @file    : link_queue_test.c
 * @author  : KeeneChen
 * @date    : 2022.09.01-16:52:46
 * @details : link_queue_test
 */

#include "link_queue.h"

typedef struct {
    void *node;
    char name[20];
    int age;
} Student;

int main(void)
{
    link_queue queue = link_queue_init();

    printf("------入队后------\n");
    Student stu1 = { NULL, "张三", 1 };
    Student stu2 = { NULL, "李四", 2 };
    Student stu3 = { NULL, "王五", 3 };
    Student stu4 = { NULL, "赵六", 4 };
    link_queue_push(queue, &stu1);
    link_queue_push(queue, &stu2);
    link_queue_push(queue, &stu3);
    link_queue_push(queue, &stu4);
    printf("链队大小:%d\n", link_queue_size(queue));

    printf("------出队后------\n");
    while (link_queue_isEmpty(queue) == 0) {
        // 访问队头
        Student *front = link_queue_front(queue);
        printf("队头元素 -- 姓名：%s  年龄： %d\n", front->name, front->age);
        // 访问队尾
        Student *back = link_queue_back(queue);
        printf("队尾元素 -- 姓名：%s  年龄： %d\n", back->name, back->age);
        // 出队
        link_queue_pop(queue);
    }

    printf("链队大小:%d\n", link_queue_size(queue));

    link_queue_destory(queue);

    return 0;
}