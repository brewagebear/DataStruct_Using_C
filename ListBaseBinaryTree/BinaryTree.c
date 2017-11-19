#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode *makeBTreeNode(void){
  BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));
  nd->left = NULL;
  nd->right = NULL;
  return nd;
}

BTdata getdata(BTreeNode *bt){
  return bt->data;
}

void setData(BTreeNode *bt, BTdata data){
    bt->data = data;
}

void DeleteTree(BTreeNode *bt){ //루트노드가 맨 마지막에 삭제 반드시 후위순회!
  if(bt == NULL){
    return;
  }
  DeleteTree(bt->left);
  DeleteTree(bt->right);
  printf("del tree data: %d \n", bt->data);
  free(bt);
}

BTreeNode *getLeftSubTree(BTreeNode *bt){
  return bt->left;
}
BTreeNode *getRightSubTree(BTreeNode *bt){
  return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub){
  if(main->left != NULL){
    free(main->left);
  }
  main->left = sub;
}
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub){
  if(main->right != NULL){
    free(main->right);
  }
  main->right = sub;
}

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action){
  if(bt == NULL){
    return;
  }
  printf("%d ", bt->data);
  PreorderTraverse(bt->left, action);
  PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action){
  if(bt == NULL){
    return;
  }
  InorderTraverse(bt->left, action);
  printf("%d ", bt->data);
  InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action){
  if(bt == NULL){
    return;
  }
  PostorderTraverse(bt->left, action);
  PostorderTraverse(bt->right, action);
  printf("%d ", bt->data);
}
