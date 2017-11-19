#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTdata;

typedef struct _bTreeNode{
  BTdata data;
  struct _bTreeNode *left;
  struct _bTreeNode *right;
} BTreeNode; //이진트리 특성상 공노드도 노드로 취급하기에 node 구조체를 따로 생성 X

BTreeNode *makeBTreeNode(void); //노드의 생성
BTdata getdata(BTreeNode *bt); // 노드에 저장된 데이터 반환
void setData(BTreeNode *bt, BTdata data); //노드에 데이터 설정
void DeleteTree(BTreeNode *bt);

BTreeNode *getLeftSubTree(BTreeNode *bt); //왼쪽 서브 트리 주소 값 반환
BTreeNode *getRightSubTree(BTreeNode *bt); //오른쪽 서브 트리 주소 값 반환

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);

typedef void VisitFuncPtr(BTdata data);

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);


#endif
