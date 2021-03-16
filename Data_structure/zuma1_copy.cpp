/*
 * @Description: 
 * @Sample Intput: 
 * @Output: 
 * @Author: GengchenXu
 * @CreateDate: 2021-03-13 11:32:30
 * @LastEditTime: 2021-03-15 21:42:27
 */
#include<iostream>
#include<cstring>
using namespace std; 
typedef struct node{
    /* data */
    char data;
    struct node *next;
}linklist, *plist;
void eliminate();
void display(linklist *pHead);
linklist *pHead=new linklist;
linklist *PTail=new linklist;
void createlist(char *a,int len){
    linklist *pt=pHead;
    PTail->next=NULL;
    pHead->next=PTail;
    //pHead->data=PTail->data='-';
    for(int i=0;i<len;i++){
        linklist *tmp=new linklist;
        tmp->data=a[i];
        tmp->next=pt->next;
        pt->next=tmp;
        pt=tmp;
    }
}
void display(linklist *p) {
    linklist* temp = p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    if (temp->next == PTail) cout<<"-"<<endl;
    else {
        while (temp->next->next) {
        temp = temp->next;
        cout<<temp->data;
        }
        cout<<endl;
    }
}
void insert(int pos,char ch){
        linklist *before =pHead;
        int count = -1;
        for (before = pHead; before->next && count != pos - 1; before = before->next, ++count);
        linklist *temp = new linklist;
        temp->next = before->next;
        temp->data = ch;
        before->next = temp;
        if (before == pHead)
            PTail = temp;
        eliminate();  
        display(pHead);
}
void eliminate(){
    linklist *end = nullptr;
    linklist *first = nullptr;
    linklist *before = nullptr;
        // before 记录first的前一个结点，first记录第一个，
        // end记录最后一个与first颜色相同的结点的后一个结点
    linklist *lastSame = nullptr;
        // lastSame记录最后一个与first颜色相同的结点
    while (PTail != pHead){
        bool elimination = false;
        for (before = pHead; before->next;){
            first = before->next;
            if (!first->next){
                PTail = first;
                break;
            }
            int count = 1;
            lastSame = first;
            for (end = first->next; end && end->data == first->data; end = end->next){
                lastSame = end;
                ++count;
            }
            if (count >= 3){
                elimination = true;
                for (linklist *now = first; now != end;){
                    linklist *temp = now;
                    now = now->next;
                    delete temp;
                }
                before->next = end;
                if (!end)PTail = pHead;
            }
            else before = lastSame;
        }
        if (!elimination)break;
    }
}
int main(){
    string a;
    int len;
    linklist *pHead=NULL;
    char c;
    getline(cin,a);
    cin>>len;
    char t[20000];
    for(int i=0;i<a.length();i++) t[i]=a[i];
    createlist(t,strlen(t));
    while(len--){
        int pos;
        char ch;
        cin>>pos>>ch;
        insert(pos,ch);
    }
    return 0;
}