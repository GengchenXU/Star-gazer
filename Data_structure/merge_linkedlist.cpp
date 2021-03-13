/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Author: GengchenXu
 * @CreateDate: 2021-03-11 16:58:58
 * @LastEditTime: 2021-03-12 20:12:10
 */
#include<iostream>
using namespace std;
typedef struct Link {
    int  elem;//存储整形元素
    struct Link *next;//指向直接后继元素的指针
}linklist;
linklist * createLink(int len);
linklist * reverse(linklist *head);
void display(linklist *p);
void merge(linklist *l1,linklist *l2);
linklist * createLink1(int len) {
    linklist * p = (linklist*)malloc(sizeof(linklist));//创建一个头结点
    linklist * temp = p;//声明一个指针指向头结点，用于遍历链表
    int i = 0;
    //生成链表
    for (i=1; i < len+1; i++) {
        //创建节点并初始化
        linklist *a = (linklist*)malloc(sizeof(linklist));
        a->elem = i;
        a->next = NULL;
        //建立新节点与直接前驱节点的逻辑关系
        temp->next = a;
        temp = temp->next;
    }
    return p;
}
linklist * createLink2(int len) {
    linklist * p = (linklist*)malloc(sizeof(linklist));//创建一个头结点
    linklist * temp = p;//声明一个指针指向头结点，用于遍历链表
    int i = 0;
    //生成链表
    for (i=8; i < len+8; i++) {
        //创建节点并初始化
        linklist *a = (linklist*)malloc(sizeof(linklist));
        a->elem = i;
        a->next = NULL;
        //建立新节点与直接前驱节点的逻辑关系
        temp->next = a;
        temp = temp->next;
    }
    return p;
}
void display(linklist *p) {
    linklist* temp = p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next) {
        temp = temp->next;
        cout<<temp->elem<<" ";
    }
    cout<<endl;
    cout<<"###########################"<<endl;
}
linklist * reverse(linklist * head) {  
 if(NULL==head|| NULL==head->next) return head;    //少于两个节点没有反转的必要。
    linklist *p,*q,*r;
    p = head;  
    q = head->next;
    head->next = NULL; //旧的头指针是新的尾指针，next需要指向NULL
    while(q){
        r = q->next; //先保留下一个step要处理的指针
        q->next = p; //然后p q交替工作进行反向
        p = q; 
        q = r; 
    }
	head=p; // 最后q必然指向NULL，所以返回了p作为新的头指针
    linklist* temp = head;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next) {
        cout<<temp->elem<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"####################"<<endl;
    return head;
}
void merge(linklist* l1, linklist* l2) {
	linklist * h1,*h2;
	linklist * u;
	h1 = l1->next;
	h2 = l2;
	u = h1;
    while(NULL!=(h1->next) && NULL!=(h2->next)) {
		h1 = h1->next;
		u->next = h2;
		u = h2;
		h2 = h2->next;
		u->next = h1;
		u = h1;
	}
	if(h1->next==NULL) {
        u->next=h1;
        u=h1;
        u->next=h2;
	} 
    else if(h2->next==NULL) {
		h1 = h1->next;
	}
    linklist* L = l1;//将L指针重新指向头结点
    //只要l指针指向的结点的next不是Null，就执行输出语句。
    display(l1);
}
int main(){
    int lena,lenb;
    linklist *pa,*pb,*pc= NULL;
    cin>>lena>>lenb;
    pa = createLink1(lena);
    pb = createLink2(lenb);
    display(pa);
    display(pb);
    pc = reverse(pb);
    merge(pa,pc);
    return 0;
}