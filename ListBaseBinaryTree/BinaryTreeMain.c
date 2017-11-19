#include <stdio.h>
#include "BinaryTree.h"

void ShowInData(int data);

int main(void){
  BTreeNode *bt1 = makeBTreeNode();
  BTreeNode *bt2 = makeBTreeNode();
  BTreeNode *bt3 = makeBTreeNode();
  BTreeNode *bt4 = makeBTreeNode();
  BTreeNode *bt5 = makeBTreeNode();
  BTreeNode *bt6 = makeBTreeNode();

  setData(bt1, 1);
  setData(bt2, 2);
  setData(bt3, 3);
  setData(bt4, 4);
  setData(bt5, 5);
  setData(bt6, 6);

  MakeLeftSubTree(bt1, bt2);
  MakeRightSubTree(bt1, bt3);
  MakeLeftSubTree(bt2, bt4);
  MakeRightSubTree(bt2, bt5);
  MakeRightSubTree(bt3, bt6);

  InorderTraverse(bt1, ShowInData);
  printf("\n");
  PreorderTraverse(bt1, ShowInData);
  printf("\n");
  PostorderTraverse(bt1, ShowInData);
  printf("\n");

  DeleteTree(bt1);
}

void ShowInData(int Data){
  printf("%d ", Data);
}
