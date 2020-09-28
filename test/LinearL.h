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
    printf("建立一个空链表。。");
    LinkList head;                  //头指针
    head = malloc(sizeof(Node));    //动态构建一个节点，他是头结点
    head->next = NULL;
    return head;

}

/*求表长*/
int LengthLinkList(LinkList head) {
    //求链表的长度

    Node *p = head;                 //p 是工作指针指向头结点
    int cnt = 0;                    //计数器初值
    while (p->next != NULL) {       //指针移动到下一个节点
        p = p->next;
        printf("指向下一个");
        cnt++;
        printf("\t计数器加1");
    }
    printf("共发现%d个元素。bye....", cnt);
    return cnt;

}


/*读取数据*/
Node *GetLinklist(LinkList head, int i) {
    //在单链表head中查找第i个元素节点。
    //若找到返回该节点的指针
    //若没找到返回 Null
    printf("查找第%d个元素", i);
    Node *p;//工作指针
    p = head->next;//出始 p 指向 首节点
    int c = 1;
    while ((c < i) && (p != NULL)) {
        p = p->next;
        c++;
    }
    if (i == c) return p;
    else return NULL;
}

/*插入*/
LinkList InsertLinkList(LinkList head, DataType x, int i) {
    //在表head的第i个数据元素节点之前插入一个以x为值得新节点
    //先找到 i-1 这个节点q
    //生成一个值为x的新节点p
    //p的指针域指向q的直接后续节点
    //q的指针域指向p
    Node *p, *q;
    if (i == 1) q = head;
    else q = GetLinklist(head, i - 1);
    if (q == NULL) exit("找不到插入的位置");

}

/*定位*/
int LocateLinkList(LinkList head, DataType x) {
    Node *p = head;
    p = p->next;
    int loc = 0;
    while ((p != NULL) && (p->data.num != x.num)) {
        loc++;
    }
    if (p != NULL) return loc + 1;
    else return 0;
}
