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

/**
 * 1.建表
 * 通过实现InsertLinkList（LinkList head，int x,int i）来实现依次增大插入位置i，是新的结点链入到链表中。
 *时间复杂度：O(n^2)
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
/**
 * 建表算法 由于每次插入都从表头开始查找 比较浪费时间。因为每次都是把新的结点链接到表尾，我们可以用一个指针指向尾结点
 * 这样就为下一个新节点指明了插入位置。
 * 表尾链入
 * 时间复杂度：O(n)
 * */
LinkList CreateLinkList2() {
//q是一个LinkList类型的变量，用来指示链入位置
    LinkList head;
    Node *q, *t;
    int x;

    head = malloc(sizeof(Node));//生成头结点
    q = head;                   //尾指针赋初值
    scanf("%d", &x);
    while (x != 0) {
        DataType new;
        t = malloc(sizeof(Node));   //1
        new.num = x;                //2
        t->data = new;              //3 生成一个新结点
        q->next = t;                  //新结点链入
        q = t;                        //修改尾指针q，指向新的尾结点
        scanf("%d", &x);             //读取下一个元素
    }
    q->next = NULL;
    return head;

}
//TODO 建表方法三
/**
 * 前插法
 * 链表顺序与输入顺序相反
 * 时间复杂度：O(n)
 * */
LinkList CreateLinkList3() {
    LinkList head;
    Node *p;
    int x;
    head = malloc(sizeof(Node));
    head->next = NULL;
    scanf("%d", &x);
    while (x) {                  //输入0结束
        p = malloc(sizeof(Node));// 1
        DataType new3;           //2
        new3.num = x;            //3
        p->data = new3;          //4 新建一个结点
        p->next = head->next;
        head->next = p;          //前插：插入到链表的第一个结点处
        scanf("%d", &x);
    }
    return head;
}

/**
 * 删除单链表重复结点
 * 时间复杂度：O(n^2)
 * */
void PurgeLinkList(LinkList head) {
    Node *p, *q, *r;
    q = head->next;                                 //q指示当前检查结点的位置，置其初值指向首结点
    while (q != NULL) {                             //当检查点*q不是结点时，寻找并删除它的重复结点
        p = q;                                      //工作指针p指向*q
        while (p->next != NULL) {                   //若*p的后继结点存在时，将其数据域与*q数据域进行比较
            if (p->next->data.num == q->data.num) { //若*（p->next）时*q的重复结点
                r = p->next;                        //r 指向待删除结点
                p->next = r->next;                  //移出结点*(p->next),p->next指向p->next的后继结点
                free(r);
            } else p = p->next;                     //若 不是重复结点 p指向下一个结点
        }
        q = q->next;                                //跟新检查点

    }
}

/**
 * 循环链表
 * */
struct {
    DataType data;
    struct dbnode *prior, *next;
} dbnode;
typedef struct dbnode *dbpointer;
typedef dbpointer DLinkList;
//对称性
//p=malloc(sizeof(dbpointer));/**/
//p=malloc(sizeof(dbnode));