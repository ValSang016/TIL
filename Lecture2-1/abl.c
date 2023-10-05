#include<stdio.h>
#include <stdlib.h>
#include <time.h>
 
typedef struct node
{
int data; 
struct node *left,*right;
int ht;
}node;
 
node *insert(node *,int);
void preorder(node *);
void inorder(node *);
void postorder(node *);
int height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);

node *Search(node *, int);
void FindMax(node*);
void Range(node*, int, int);
 
int main()
{
    node *root=NULL;
    srand(time(NULL));

    // 리스트 생성
    int list[200] = { 15, 50 };
    for (int i = 2; i < 200; i++) {
        list[i] = rand() % 100 + 1;
    }

    // Tree 생성
    int numUniqueKeys = 0;
    for (int i = 0; i < 200 && numUniqueKeys < 50; i++) {
        // 중복되는 키는 Tree에 삽입하지 않음
        int isDuplicate = 0;
        for (int j = 0; j < i; j++) {
            if (list[i] == list[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate) {
            continue;  // 중복이라면 numUniqueKeys에 +연산을 하지 않아 50회 실시될 수 있게 함
        }

        root = insert(root, list[i]);
        numUniqueKeys++;
    }
    node *x = NULL;
    int op;
    do{
        printf("\n1)Print(inorder, preorder, postorder)");
        printf("\n2)Search Key(15, 20, 50,70, 90)");
        printf("\n3)Highest Key");
        printf("\n4)Print Key(<15)");
        printf("\n5)Print Key(>15)");
        printf("\n6)Print Key(15<key<50)");
        printf("\n7)Quit");
        printf("\n\nEnter Your Choice");
        scanf("%d",&op);

        switch(op){
        case 1:
            printf("\n\nInorder sequence:\n");
            inorder(root);
            printf("\nPreorder sequence:\n");
            preorder(root);
            printf("\nPostorder sequence:\n");
            postorder(root);
            printf("\n");
            break;
        case 2:
            printf("\nSearch Key(15, 20, 50, 70, 90):");
            int searchKey[5] = { 15, 20, 50, 70, 90 };
            for (int i = 0; i < 5; i++){
                x = Search(root, searchKey[i]);
                if(x != NULL)
                    printf("%d를 찾았습니다. \n", x->data); 
                else  //리턴값이 트리에 없는 경우(찾지 못한 경우)
                    printf("%d를 찾지 못했습니다.\n", searchKey[i]);
            }
            break;
        case 3: 
            FindMax(root);
            break;
        case 4:
            Range(root, 0, 15);
            break;
        case 5:
            Range(root, 50, 201);
            break;
        case 6:
            Range(root, 15, 50);
            break;
        }
    }while(op!=7);
    return 0;
}
 
 
node * insert(node *T,int x) // 리스트의 값을 트리에 삽입하는 함수
{
if(T==NULL){
    T=(node*)malloc(sizeof(node));
    T->data=x;
    T->left=NULL;
    T->right=NULL;
}else if(x > T->data){ // 오른쪽 트리에 삽입
    T->right=insert(T->right,x);

    if(BF(T)==-2){   //밸런스가 맞는지 확인 => 만약 맞지 않다면
            if(x > T->right->data){   
                T=RR(T);
            }else{  
                T=RL(T);
        }
    }
}
else if(x<T->data){  //왼쪽 트리에 삽입
    T->left=insert(T->left,x);
    if(BF(T)==2)
    if(x < T->left->data)
        T=LL(T);
    else
        T=LR(T);
}
    T->ht = height(T);
return(T);
}
 
 
int height(node *T){
    int lh,rh;
    if(T==NULL)  //아무것도 없으면 높이는 0
        return(0);  

    if(T->left==NULL)  // 왼쪽 자식이 없으면 왼쪽 높이는 0
        lh=0;
    else     //왼쪽 자식이 있다면 자식의 높이에 +1
        lh=1+T->left->ht;

    if(T->right==NULL) // 오른쪽 자식이 없으면 오른쪽 높이는 0
        rh=0;
    else  //오른쪽 자식이 있다면 오른쪽 높이는 자식의 높이에 +1
        rh=1+T->right->ht;
    
    if(lh>rh)    //왼쪽 높이가 오른쪽 높이보다 높다면 왼쪽 높이 리턴
        return(lh);
    return(rh);
}
 
node * rotateright(node *x){
    node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}
 
node * rotateleft(node *x){
    node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}
 
node * RR(node *T){
    T=rotateleft(T);
    return(T);
}
 
node * LL(node *T){
    T=rotateright(T);
    return(T);
}
 
node * LR(node *T){
    T->left=rotateleft(T->left);
    T=rotateright(T);
    return(T);
}
 
node * RL(node *T){
    T->right=rotateright(T->right);
    T=rotateleft(T);
    return(T);
}
 
int BF(node *T){   //좌우 자식이 비었는지 확인하여 왼쪽 높이와 오른쪽 높이를 설정 => 둘이 빼서 BF구해서 리턴
    int lh,rh;
    if(T == NULL)
    return(0);
    
    if(T->left==NULL)
    lh=0;
    else
    lh=1+T->left->ht;
    
    if(T->right==NULL)
    rh=0;
    else
    rh=1+T->right->ht;
    
    return(lh-rh);
}
 
void preorder(node *T){
    if(T!=NULL){
        printf("%d(Bf=%d)",T->data,BF(T));
        preorder(T->left);
        preorder(T->right);
    }
}
 
void inorder(node *T){
    if(T!=NULL){
        inorder(T->left);
        printf("%d(Bf=%d)",T->data,BF(T));
        inorder(T->right);
    }
}

void postorder(node* T) {
    if (T != NULL) {
        postorder(T->left);
        postorder(T->right);
        printf("%d(Bf=%d)",T->data,BF(T));
    }
}

node* Search(node* T, int key) {
    if(T == NULL || T->data == key) {  // 찾으려는 값이 없거나, 찾은 경우 T 리턴
        return T;
    }
    else if(T->data < key) {    //찾으려는 값이 T->data보다 큰 경우 오른쪽 트리로 이동(재귀)
        printf("%d -> ",T->data);
        return Search(T->right, key);
    }
    else {
        printf("%d -> ",T->data);     //찾으려는 값이 T->data보다 작은 경우 왼쪽 트리로 이동(재귀)
        return Search(T->left, key);
    }
}

void FindMax(struct node* T) {
    if (T == NULL) {
        printf("Tree is empty\n");
        return;
    }

    while (T->right != NULL) //최대값은 트리의 맨 오른쪽 끝에 있을 것임
        T = T->right;

    printf("Max key: %d\n", T->data);
}

void Range(node* T, int l, int h) {  //범위를 정하여 범위 내의 숫자를 출력
    if (T == NULL)
        return;
    if (l < T->data)
        Range(T->left, l, h);
    if (l < T->data && h > T->data)
        printf("%d ", T->data);
    if (h > T->data)
        Range(T->right, l, h);
}