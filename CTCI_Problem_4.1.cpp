/*
 * Solutions to Cracking the Coding Interview Edition 4
 *
 * By: Ashwin Krishnan
 * 
 * Problem 4.1
 * ------------
 * Implement a function to check if a tree is balanced. For the purposes of 
 * this question, a balanced tree is defined to be a tree such that no 
 * two leaf nodes differ in distance from the root by more than one.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
  int data;
  node *left_child;
  node *right_child;
};

node* node_init(int data)
{
  node *new_node = (node*)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->left_child = NULL;
  new_node->right_child = NULL;

  return new_node;
}

bool set_child(node *current, node *new_node, int child)
{
  if(child == 0 && current->left_child == NULL)
  {
    current->left_child = new_node;
    return 1;
  }

  if(child == 1 && current->right_child == NULL)
  {
    current->right_child = new_node;
    return 1;
  }

  else
  {
    cout << "Error: Child already exists!" << endl;
    return 0;
  }

  return 1;

}

void get_leaf_depths(node *root, int distance, vector<int> *leaf_vector)
{

  if(root == NULL)
  {
    return;
  }

  if(root->left_child == NULL && root->right_child == NULL)
  {
    leaf_vector->push_back(distance);
    return;
  }

  distance++;
  get_leaf_depths(root->left_child, distance, leaf_vector);
  get_leaf_depths(root->right_child, distance, leaf_vector);

  return;


}

void check_if_balanced(vector<int> *leaf_vector)
{
  int max_depth = *max_element(leaf_vector->begin(), leaf_vector->end());
  int min_depth = *min_element(leaf_vector->begin(), leaf_vector->end());

  if(max_depth - min_depth > 1)
  {
    cout << "Tree is unbalanced" << endl;
    return;
  }

  else
  {
    cout << "Tree is balanced" << endl;
  }
}

void print_tree(node *root, int distance)
{

  if(root == NULL)
  {
    return;
  }

  if(root->left_child == NULL && root->right_child == NULL)
  {
    cout << "LEAF Data: " << root->data << " Depth(" << distance << ")" << endl;
    return;
  }

  cout << "Node Data: " << root->data << endl;

  distance++;
  print_tree(root->left_child, distance);
  print_tree(root->right_child, distance);

  return;

}

node* setup_tree()
{
    node *root = node_init(1);
    node *n2 = node_init(2);
    node *n3 = node_init(3);
    node *n4 = node_init(4);
    node *n5 = node_init(5);
    node *n6 = node_init(6);
    node *n7 = node_init(7);
    node *n8 = node_init(8);
    node *n9 = node_init(9);
    node *n10 = node_init(10);
    node *n11 = node_init(11);

    set_child(root, n2, 0);
    set_child(root, n9, 1);
    set_child(n2, n3, 0);
    set_child(n2, n6, 1);
    set_child(n3, n4, 0);
    set_child(n3, n5, 1);
    set_child(n6, n7, 0);
    set_child(n6, n8, 1);     
    //set_child(n9,n10,0);
    //set_child(n10, n11, 0);

    return root;
}

int main()
{

  //Testing implementation
  node *root = setup_tree();
  vector<int> *leaf_vector = new vector<int>();

  get_leaf_depths(root, 0, leaf_vector);
  print_tree(root, 0);
  check_if_balanced(leaf_vector);

  return 0;
}
