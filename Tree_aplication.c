#include <stdio.h>
#define MAXLENGTH 100
#define NULL_NODE -1

typedef int Node;
typedef char LabelType;

typedef struct {
    Node P[MAXLENGTH];
    LabelType L[MAXLENGTH];
    int maxNode;
}Tree;

void makeNull (Tree *pT) {
    pT -> maxNode = -1;
}
int empty (Tree *pT) {
    if (pT -> maxNode == -1) 
        return 1;
    return 0;
}
Node parent (Node n, Tree *pT) {
    if (n<1 || n>pT->maxNode ) 
        return -1;
    return pT-> P[n];
}
LabelType label(Node n, Tree *pT) {
    if (n<0 || n>pT->maxNode) 
        return '7';
    return pT->L[n];
}
Node root(Tree *pT) {
    if (pT -> maxNode == -1) 
        return NULL_NODE;
    return 0;
}
Node leftmostChild (Node n, Tree *pT) {
    if (n<0 || n > pT->maxNode) 
        return -1;
    int i;
    for (i=n+1;i<= pT->maxNode;i++) {
        if (pT->P[i] == n) 
            return i;
    }
    return NULL_NODE;
}
Node rightSibling(Node n, Tree *pT) {
    if (n<0 || n>pT->maxNode) 
        return NULL_NODE;
    int i;
    for (i=n;i<=pT->maxNode;i++) {
        if (i>n && pT->P[i] == pT->P[n])
            return i;
    }
    return NULL_NODE;}
void preorder(Node n, Tree *pT) {
    if (n==NULL_NODE) 
        return;
    printf("%c ", label(n,pT));
    Node child = leftmostChild(n,pT);
    while (child != NULL_NODE) {
        preorder(child,pT);
        child = rightSibling(child,pT);
    }
}
void inorder(Node n, Tree *pT) {
    if (n == NULL_NODE)
        return;
    Node child = leftmostChild(n,pT);
    if (child == NULL_NODE) {
        printf("%c ", label(n,pT));
        return;
    }
void inorder(child,pT);
    printf("%c ", label(n,pT));
    child = rightSibling(child,pT);
    while (child != NULL_NODE) {
        inorder(child,pT);
        child = rightSibling(child,pT);
    }
}
void postorder(Node n, Tree *pT) {
    if (n==NULL_NODE) 
        return;
    Node child = leftmostChild(n,pT);
    while (child != NULL_NODE) {
        postorder(child,pT);
        child = rightSibling(child,pT);
    }
    printf("%c ", label(n,pT));
}
int height (Node n, Tree *pT) {
    if (n<0 || n>pT->maxNode)
        return -1;
    Node child = leftmostChild(n,pT);
    if (child == NULL_NODE) {
        return 0;
    }
    int max = 1;
    while (child != NULL_NODE) {
        if (height(child,pT)+1>max) {
            max = height(child,pT)+1;
        }
        child = rightSibling(child,pT);
    }
    return max;
}
int depth(Node n, Tree *pT) {
    if (n<0 || n>pT->maxNode) 
        return -1;
    if (n==0)
        return 0;
    return depth(pT->P[n],pT)+1;
}

int main() {
    Tree T;
    int n;
    scanf("%d", &n);   
    T.maxNode = n - 1; 
	int i;
    for (i = 0; i < n; i++) 
        scanf(" %c", &T.L[i]);

    T.P[0] = NULL_NODE;         
    for (i = 1; i < n; i++) 
        scanf("%d", &T.P[i]);
	
	preorder(0,&T);
	printf("\n");
	inorder(0,&T);
	printf("\n");
	postorder(0,&T);
	printf("\n");
	
	Node u;
	scanf("%d", &u);
	printf("%d\n", height(u,&T));
	printf("%d\n", depth(u,&T));
	
	return 0;
	
	
}
