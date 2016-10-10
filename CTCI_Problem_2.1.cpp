/*
 * Solutions to Cracking the Coding Interview Edition 4
 *
 * By: Ashwin Krishnan
 * 
 * Problem 2.1
 * ------------
 * Write code to remove duplicates from an unsorted linked list.
 * Do this without a temporary storage buffer
 */

/*remove_duplicates()
 *-------------------
 *Runtime Analysis - O(n^2)
 *Space Complexity - O(1)

 *Note: Quick dirty implementation of linked_list data structure
 *with basic helper functions "append()" and "remove_node()"
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct list
{
	node *head;
};

list* list_init(node *head)
{
	list *linked_list = (list*)malloc(sizeof(list));
	linked_list->head = head;
	
	return linked_list;
}

node* node_init(int data)
{
	node *new_node = (node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;	
	
	return new_node;
}


bool append(list *linked_list, node *new_node)
{
	node *head = linked_list->head;
	node *current = head;
	
	if(head->next == NULL)
	{
		head->next = new_node;
		new_node->next = NULL;
	}
	
	while(current->next != NULL)
	{
		current = current->next;
	}
		
	current->next = new_node;
	new_node->next = NULL;
	
	return true;

}

bool remove_node(list *linked_list, node* new_node)
{
	node *head = linked_list->head;
	node *previous = head;

	if(new_node == head)
	{
		linked_list->head = head->next;
	}

	while(head != NULL)
	{
		if(head == new_node)
		{
			previous->next = head->next;
			return true;
		}

		previous = head;
		head = head->next;
	}

	return false;
}



bool remove_duplicates(list *linked_list)
{
	node *head = linked_list->head;
	node *current = head->next;
	node *runner = head;

	int data_checker = 0;
	int data_current = 0;
	bool flag = false;

	while(current != NULL)
	{
		data_current = current->data;
		
		while(runner != current)
		{
			
			if(runner->data == data_current)
			{
				remove_node(linked_list, runner);
				flag = true;
			}

			runner = runner->next;
			
		}

		current = current->next;
		runner = head;
	}

	return flag;
	
}

void print_list(list *linked_list)
{
	node *head = linked_list->head;
	
	
	while(head != NULL)
	{
		cout << "Data: " << head->data << endl;
		
		head = head->next;
	}
}

int main()
{
	//Testing implementation
	
	node *n1 = node_init(6);
	node *n2 = node_init(3);
	node *n3 = node_init(7);
	node *n4 = node_init(7);
	
	list *linked_list = list_init(n1);
	
	append(linked_list, n2);
	append(linked_list, n3);
	append(linked_list, n4);

	cout << "Original List" << endl;
	cout << "-------------" << endl;

	print_list(linked_list);

	remove_duplicates(linked_list);

	cout << "\nUpdated List (After removing duplicates)" << endl;
	cout << "--------------" << endl;

	print_list(linked_list);
	
	
	return 0;
}

