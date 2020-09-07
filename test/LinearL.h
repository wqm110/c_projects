//
// Created by mac on 2020/9/5.
// 线性表 链表//
//学生信息

typedef struct node {
    DataType data;      //数据域
    struct node *next;  //指针域
} Node, *LinkList;      //Node 链表节点的类型
//LinkList head;


/*初始化链表*/
LinkList InitSeqLinkList() {
//    建立一个空链表
    LinkList head;                  //头指针
    head = malloc(sizeof(Node));    //动态构建一个节点，他是头结点
    head->next = NULL;
    return head;

}

/*求表长*/
int LengthLinkList(LinkList head) {
    //求链表的长度

    Node *p = head;        //p 是工作指针指向头结点
    int cnt = 0;
    while (p->next != NULL) {
        p = p->next;
        printf("指向下一个");
        cnt++;
        printf("\t计数器加1");
    }
    printf("共发现%d个元素。bye....", cnt);
    return cnt;

}
