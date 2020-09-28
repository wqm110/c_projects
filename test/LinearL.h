//
// Created by mac on 2020/9/5.
/**
 * 线性表的基本运算在单链表上的实现
 * */

/*学生信息*/
typedef struct node {
    DataType data;      //数据域
    struct node *next;  //指针域
} Node, *LinkList;      //Node 链表节点的类型
//LinkList head;


LinkList InitiateLinkList();

/*初始化链表*/
//初始化单链表
LinkList InitiateLinkList() {
//    建立一个空链表
    printf("建立一个空链表。。\n");
    LinkList head;                  //头指针
    head = malloc(sizeof(Node));    //动态构建一个节点，他是头结点
    head->next = NULL;
    return head;

}

/*求表长*/
int LengthLinkList(LinkList head) {
    //求单链表的长度

    Node *p = head;                 //p 是工作指针指向头结点
    int cnt = 0;                    //计数器初值
    while (p->next != NULL) {       //指针移动到下一个节点
        p = p->next;
        printf("指向下一个\n");
        cnt++;
        printf("\t计数器加1,当前值为：%d\n", cnt);
    }
    printf("共发现%d个元素。bye....\n", cnt);
    return cnt;

}


/*读取数据*/
Node *GetLinklist(LinkList head, int i) {
    //在单链表head中查找第i个元素节点。
    //若找到返回该节点的指针
    //若没找到返回 Null
    printf("查找第%d个元素\n", i);
    Node *p;//工作指针
    p = head->next;//出始 p 指向 首节点
    int c = 1;
    while ((c < i) && (p != NULL)) {
        p = p->next;
        c++;
        printf("c的值%d\n", c);
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
    if (q == NULL)
        exit("找不到插入的位置\n");
    else {
        p = malloc(sizeof(Node));
        p->data = x;                          //生成新结点
        p->next = q->next;                    //新结点链域指向*q的后继结点
        q->next = p;                          //修改*q的链域
    }

}

/*定位*/
int LocateLinkList(LinkList head, DataType x) {
    Node *p = head;
    p = p->next;
    int loc = 0;
    while ((p != NULL) && (p->data.num != x.num)) {
        loc++;
        p = p->next;
        printf("当前位置loc:%d\n", loc);
    }
    if (p != NULL) {
        printf("找到了他在%d\n", loc + 1);
        return loc + 1;
    } else return 0;
}

/*删除*/

void DeleteLinkList(LinkList head, int i) {
    //删除 表head 的第i个结点
    Node *q;
    if (i == 1) q = head;
    else q = GetLinklist(head, i - 1);
    if (q != NULL && q->next != NULL) {
        struct node *p = q->next; //p指向待删结点
        q->next = p->next;        //移除待删结点
        free(p);
    } else exit("找不到待删除的结点");
}

/**
 * 其他运算在单链表上的实现
 * */

/*
 * 1.建表
 * */
//方法一

LinkList CreateLinkList1() {
    //通过调用 InitialLinkList 和 Insertlinkelist 实现建表算法。
    //假定0 是输入结束标志
    LinkList head;
    int x, i;
    head = InitiateLinkList();
    i = 1;
    printf("请输入数字，建立新的链表，0 结束\n请输入下一个数字：");
    scanf("%d", &x);
    while (x != 0) {
        printf("您输入的是：%d\n", x);
        DataType newone;
        newone.num = x;
        InsertLinkList(head, newone, i);
        i++;

        printf("请输入下一个数字：");
        scanf("%d", &x);
    }
    return head;
}

//TODO //建表方法二

//TODO 建表方法三
//TODO 删除重复结点
void PurgeLinkList(LinkList head) {
    Node *p, *q, *r;
    q = head->next;   //指示当前检查结点的位置，置其初值指向首结点
    while (q != NULL) {
        p = q;                                      //工作指针p指向*q
        while (p->next != NULL) {
            if (p->next->data.num == q->data.num) {
                r = p->next;
                p->next = r->next;
                free(r);
            } else p = p->next;
        }
        q = q->next;

    }
}