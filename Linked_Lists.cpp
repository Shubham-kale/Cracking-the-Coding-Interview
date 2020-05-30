/*
Chapter-2. Linked Lists

Each of the problems is implemented as a function
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<cmath>
using namespace std;


template<class T>
class SLLNode
{
   private:
	     T data;
	   	 SLLNode<T>* ptr;
   public:
	     T getData()
		 {
		   return this->data;	
	     }
		 void setData(T d)
		 {
		   this->data = d;	
	     }	
	     void setNext(SLLNode<T>* next)
		 {
		   this->ptr = next;	
	     }	
	     SLLNode<T>* next()
	     {
	     	return this->ptr;
		 }
};

template<class T>
class SinglyLinkedList
{
	private:
		SLLNode<T>* head;
		int size;
	public:
	    SinglyLinkedList<T>()
		{
			head = NULL;
			size = 0;
		}	
		SLLNode<T>* getHeadNode()
		{
			return head;
		}
		SLLNode<T>* newNode(T data)
		{
			SLLNode<T>* n = new SLLNode<T>();
			n->setData(data);
			n->setNext(NULL);
			if(head == NULL)
			{
				head = n;
				size++;
			}
			return n;	
		}
		int getSize()
		{
			return this->size;
		}
		void addNode(SLLNode<T>* n)
		{
			SLLNode<T>* temp = head;
			if(n == head)
			  return;
			while(temp->next() != NULL)
			{
				temp = temp->next();
			}
			temp->setNext(n);
			size++;
		}
		void addNodeAtHead(SLLNode<T>* n)
		{
			if(head)
			{
			   n->setNext(head);
			   head = n;
		    }
			else
			{
			   head = n;	
			}
			size++;
		}
		void display()
		{
			cout<<"LIST :-";
			if(head == NULL)
			{
				cout<<"\nList Empty !!!\n";
				return;
			}
			SLLNode<T>* temp = head;
			cout<<endl;
			while(temp != NULL)
			{
				cout<<temp->getData()<<" <---> ";
				temp = temp->next();
			}
			cout<<"NULL\n"<<endl;
		}
		
		void deleteNodeWithData(T data)
		{
			SLLNode<T>* temp = head;
		    SLLNode<T>* temp2 = NULL;
			if(head == NULL)
			{
				cout<<"\nList Empty !!!\n";
				return;
			}
			if(head->getData() == data)
			{
				temp2 = head;
			    head = head->next();
			    delete temp2;
			    size--;
			    return;
			}
			if(temp->next() == NULL)
			{
				cout<<"\nElement not found !!\n";
				return;
			}
			while(temp->next()->getData() != data)
			{
				temp = temp->next();
				if(temp->next() == NULL)
				{
					cout<<"\nElement not found !!\n";
					return;
				}
			}
			temp2 = temp->next();
			temp->setNext( temp->next()->next() );
			if(temp2 == head)
			  head = temp2->next();
			delete temp2;
			size--;
		}
		/*
		2.1 RemoveDups: Write code to remove duplicates from an unsorted linked list.
		FOLLOW UP
		How would you solve this problem if a temporary buffer is not allowed?
		*/
		void removeDups() //takes O(n^2) in worst case
		{
			set<T> record;
			SLLNode<T>* temp = head;
			while(temp != NULL)
			{
				auto ptr = record.find(temp->getData());
				if(ptr == record.end())
				{
					record.insert(temp->getData());
				}
				else
				{
					temp = deleteNode(temp);
				}
				temp = temp->next();
			}
		}
		SLLNode<T>* deleteNode(SLLNode<T>* n)  //takes O(n) time in worst case
		{
			SLLNode<T>* temp = head;
		    SLLNode<T>* prev = NULL;
			if(head == NULL)
			{
				cout<<"\nList Empty !!!\n";
				return NULL;
			}
			if(head == n)
			{
				temp = head;
			    head = head->next();
			    delete temp;
			    size--;
			    return head;
			}
			while(temp != n)
			{
				prev = temp;
				temp = temp->next();
			}
			prev->setNext( temp->next() );
			delete temp;
			size--;
			return prev;
		}
		/*
		2.2 Return Kth to Last: Implement an algorithm to find the kth to last element of 
		    a singly linked list.
		*/
		T findFromLast(int index)
		{
			T data = 0;
			int cnt = size - index;
			int c = 0;
			if(cnt <= 0)
			{
				cout<<"Data out of bounds, No data found/exists!!"<<endl;
			}
			else
			{
				SLLNode<T>* temp = head;
				while(c != cnt && temp)
				{
					data = temp->getData();
					c++;
					temp=temp->next();
				}
			}
			return data;
		}
		/*
		2.3 Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
		the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
		that node.
		*/
		void deleteMiddle()
		{
			int cnt = (size/2) + 1;
			cout<<"\nMiddle at :- \t"<<cnt<<endl;
			if(cnt < 1)
			  return;
			SLLNode<T>* temp = head;
			SLLNode<T>* prev = NULL;
			while(cnt != 0 && temp)
			{
				prev=temp;
				temp=temp->next();
				cnt--;
			}
			deleteNode(prev);
		}
		/*
		2.4 Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
		before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
		to be after the elements less than x (see below). The partition element x can appear anywhere in the
		"right partition"; it does not need to appear between the left and right partitions.
		EXAMPLE
		Input:
		3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
		Output:
		3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8		
		*/
		void partition(T x)
		{
			SLLNode<T>* arr[size];
			int lesser = 0;
			int i,j;
			i = j = 0;
			SLLNode<T>* temp = head;
			while(temp != NULL)
			{
				if(temp->getData() < x)
				   lesser++;
				temp = temp->next();   
			}
			temp = head;
			while(temp != NULL)
			{
				if(temp->getData() < x && i < lesser)
				{
					arr[i] = temp;
					i++;
				}
				if(temp->getData() >= x && (j + lesser) < size)
				{
				    arr[lesser + j] = temp;	
				    j++;
				}
				temp = temp->next();   
			}
			for(int k=0;k<size;k++)
			{
				if(k+1 != size)
				  arr[k]->setNext(arr[k+1]);
				else
				  arr[k]->setNext(NULL);  
			}
			head = arr[0];
		}
		
		void reverseList()
		{
			SLLNode<T>* p;
			SLLNode<T>* q;
			SLLNode<T>* r;
			p = head;
			q = NULL;
			r = q;
			while(p!=NULL)
			{
				q = p;
				p = p->next();
				q->setNext(r);
				r = q;
			}
			head = q;
		}
		
		vector<SLLNode<T>*> findDataFrequency(T data)
		{
			int count=0;
			vector<SLLNode<T>*> locations;
			SLLNode<T>* temp = head;
			while(temp->next() != NULL)
			{
				if(temp->getData() == data)
				{
					locations.push_back(temp);
					count++;
				}
				temp = temp->next();
			}
			cout<<"\n"<<count<<" occurences found !"<<endl;
			return locations;
		}
		~SinglyLinkedList<T>()
		{
			if(head == NULL)
			  return;
		  	SLLNode<T>* temp = head;
		  	SLLNode<T>* temp1 = NULL;
			while(temp != NULL)
			{
				temp1 = temp;
				temp = temp->next();
				delete temp1;
			}	
		}
};

/*
2.5 Sum Lists: You have two numbers represented by a linked list, where each node contains a single
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
Output: 2 -> 1 -> 9. That is, 912.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
lnput:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
Output: 9 - > 1 -> 2. That is, 912.
*/

void sumLists(SinglyLinkedList<int> l1, SinglyLinkedList<int> l2, bool inputOrder, SinglyLinkedList<int>& sum)
{	
	SLLNode<int>* temp1 = l1.getHeadNode();
	SLLNode<int>* temp2 = l2.getHeadNode();
	// if inputOrder is True, it means lists are stored in forward order
	// else it means Lists are stored in reverse/backward order
	if(inputOrder)
	{
       l1.reverseList();
       l2.reverseList();
       temp1 = l1.getHeadNode();
       temp2 = l2.getHeadNode();
	   /*
		string s1 = "";        //converting both the numbers to string by concatenating
		string s2 = "";        // each digit in the linked list in forward order
		char ch1[1];           // Then converting those strings to numbers again and adding them
		char ch2[1];          // Again converting the result to a linked  list
		while(temp1!=NULL)
		{
			itoa((temp1->getData()),ch1,10);
			s1 = s1 + ch1;
			temp1 = temp1->next();
		}
		while(temp2!=NULL)
		{
			itoa((temp2->getData()),ch2,10);
			s2 = s2 + ch2;
			temp2 = temp2->next();
		}
		int i1,i2;
		i1 = atoi(s1.c_str());
		i2 = atoi(s2.c_str());
		i1+=i2;
		i2 = i1;
		int r;
		while(i1)
		{
			r = i1 % 10;
			sum.addNodeAtHead(sum.newNode(r));
			i1 = i1/10;
		}
		*/
		
		
	}
	int carry = 0,t = 0;
	bool larger,equal = false;
	int s = l1.getSize() < l2.getSize() ? l1.getSize() : l2.getSize();
	if(l1.getSize() != l2.getSize())
	      larger = 	l1.getSize() > l2.getSize() ? false : true;
	else
	      equal = true;      
	while(s!=0 && temp1 && temp2)
	{
		t = temp1->getData() + temp2->getData() + carry;
		if(t>=10)
		 {
		 	carry = t / 10;
		 	t = t % 10;
		 }
		 else
			carry = 0;
		sum.addNode(sum.newNode(t));
		temp1 = temp1->next();
		temp2 = temp2->next(); 
		s--;
	}
	if(!equal)
	{
		if(!larger)
		{
			while(temp1)
			{
			   	t = temp1->getData() + carry;
				if(t>=10)
				 {
				 	carry = t / 10;
				 	t = t % 10;
				 }
				else
				  carry = 0; 
				sum.addNode(sum.newNode(t));
				temp1 = temp1->next();	
			}
		}
		else
		{
			while(temp2)
			{
			   	t = temp2->getData() + carry;
				if(t>=10)
				 {
				 	carry = t / 10;
				 	t = t % 10;
				 }
				 else
				   carry = 0;
				sum.addNode(sum.newNode(t));
				temp2 = temp2->next();	
			}
		}
	}
	
}

/*
2.6 Palindrome: Implement a function to check if a linked list is a palindrome.
*/
template <class T>
bool isPalindrome(SinglyLinkedList<T> l)
{
	T arr[l.getSize()];
	SLLNode<T>* temp = l.getHeadNode();
	int i=0;
	while(temp!=NULL)
	{
		arr[i] = temp->getData();
		i++;
		temp= temp->next();
	}
	for(int k=0,j=l.getSize()-1;j>=0 && k<l.getSize();k++,j--)
	{
		if(arr[k] != arr[j])
		  return false;
	}
	return true;
}

/*
2.7 Intersection: Given two (singly) linked lists, determine if the two lists intersect. 
Return the intersecting node. Note that the intersection is defined based on reference, not value. 
That is, if the kth node of the first linked list is the exact same node (by reference) as the 
jth node of the second linked list, then they are intersecting.
*/
template <class T>
bool intersection(SinglyLinkedList<T>& l1, SinglyLinkedList<T>& l2, SLLNode<T>*& ans)
{
	map<SLLNode<T>*,int> record;
	SLLNode<T>* temp1 = l1.getHeadNode();
	SLLNode<T>* temp2 = l2.getHeadNode();
	
	/*
	while(temp1!=NULL)     //brute force approach to check
	{
	    while(temp2!=NULL)
		{
		     if(temp1 == temp2)
			 {
			   ans = temp1;
			   return true;	
			 }	
		  temp2 = temp2->next();
	    }	
	    temp2 = l2.getHeadNode();  
	    temp1 = temp1->next();  
	}
	*/
	
	//approch using a map
	while(temp1!=NULL) 
	{
		record.insert(make_pair(temp1,1));
		temp1 = temp1->next();
	}
	while(temp2!=NULL)
	{
		auto ptr = record.find(temp2);
		if(ptr != record.end())
		{
			ans = ptr->first;
			return true;
		}
		temp2 = temp2->next();
	}
	
	return false;
}


/*
2.8 Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
beginning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
as to make a loop in the linked list.
EXAMPLE
Input: A -> B -> C - > D -> E -> F -> G -> C [the same C as earlier]
Output: C
*/
template <class T>
bool isLoopDetected(SinglyLinkedList<T>& l, SLLNode<T>*& start)
{
	bool result = false;
	/*
	//the two pointer approach
	SLLNode<T>* temp1 = l.getHeadNode();
	SLLNode<T>* temp2 = l.getHeadNode();
	while(temp1!=NULL && temp2!=NULL)
	{
		temp1 = temp1->next();
		temp2 = temp2->next()->next();
		if(temp1 == temp2)
		{
			result = true;
			break;
		}
		
	}
	if(temp1 && temp2)
	{	
		while(temp1->next() != temp2)
		{
		   temp1 = temp1->next();
		}
		start = temp1;
    }
    */
    
    //Map approch
    map<SLLNode<T>*,int> record;
    SLLNode<T>* temp = l.getHeadNode();
    while(temp)
    {
    	auto ptr = record.find(temp);
    	if(ptr == record.end())
    	{
    		record.insert(make_pair(temp,1));
    		temp = temp->next();
		}
		else
		{
			start = ptr->first;
			result = true;
			break;
		}
	}
    
	return result;
}

int main()
{
	/*
	int choice = 10;
	SinglyLinkedList<int> l1;
	SinglyLinkedList<int> l2,l3,l4,l5;
	while(choice != 9)
	{
	
		cout<<"\nEnter the Linked list"<<endl;
		cout<<"Select operation number to perform \n";
		cout<<"1.Add Node"<<endl;
		cout<<"2.Display"<<endl;
		cout<<"3.Delete a Node"<<endl;
		cout<<"4.Remove Duplicates"<<endl;
		cout<<"5.Find kth from Last"<<endl;
		cout<<"6.Delete Middle"<<endl;
		cout<<"7.Partition the list"<<endl;
		cout<<"8.Reverse the list"<<endl;
		cout<<"9.Quit \t:-";
		cin>>choice;
		int temp;
		switch(choice)
		{
			case 1:cout<<"\nEnter data to be stored \t:-"<<endl;
			       cin>>temp;
			       l1.addNode(l1.newNode(temp));
			       break;
			case 2:cout<<"\n\n Size of list is :- "<<l1.getSize()<<"\n\n";
			       l1.display();
			       break;
			case 3:cout<<"\nEnter data to be deleted \t:-"<<endl;
			       cin>>temp;
			       l1.deleteNodeWithData(temp);	 
			       break;
			case 4:l1.removeDups(); 
			       break;
			case 5:cout<<"\nEnter the index to be found from Last node\t:-";
			       cin>>temp;
			       cout<<"\nElement is :-\t"<<l1.findFromLast(temp);
			       break;
			case 6:l1.deleteMiddle();
			       break;
			case 7:cout<<"\nEnter the data to partition the list on\t:-";
			       cin>>temp;
			       l1.partition(temp);
			       l1.display();
			       break;
			case 8:l1.reverseList();
			       cout<<"\nReverse list is :-\n";
			       l1.display();
			       break;
			case 9:break;       
			default : cout<<"Wrong choice!! Enter Again"<<endl;	            
		}
    }
    */
    
    //Testing sum lists
    /*
    l2.addNode(l2.newNode(7));
    l2.addNode(l2.newNode(1));
    l2.addNode(l2.newNode(6));
    l2.addNode(l2.newNode(1));
    l2.addNode(l2.newNode(5));
    
    l3.addNode(l3.newNode(5));
    l3.addNode(l3.newNode(9));
    l3.addNode(l3.newNode(2));
    
    l4.addNode(l4.newNode(1));
    l4.addNode(l4.newNode(6));
    l4.addNode(l4.newNode(1));
    l4.addNode(l4.newNode(7));
    
    l5.addNode(l5.newNode(2));
    l5.addNode(l5.newNode(9));
    l5.addNode(l5.newNode(5));
    
    SinglyLinkedList<int> sum;
    //sumLists(l2,l3,false,sum);
    sumLists(l4,l5,true,sum);
	sum.reverseList();
	sum.display();
    */
    
    /*
    //Testing is_Palindrome
    SinglyLinkedList<char> l6;
    l6.addNode(l6.newNode('a'));
    l6.addNode(l6.newNode('b'));
    l6.addNode(l6.newNode('c'));
    l6.addNode(l6.newNode('a'));
    
    if(isPalindrome(l6))
      cout<<"\nThe list is Palindrome\n";
    else
	  cout<<"\nThe list is not Palindrome\n";  
    */
    
    /*
    //Testing Intersetion of Lists
    SinglyLinkedList<int> l7;
    SinglyLinkedList<int> l8;
    SLLNode<int>* intersect = new SLLNode<int>();
    intersect->setData(25);
	intersect->setNext(NULL);
    l7.addNode(l7.newNode(5));
    l7.addNode(l7.newNode(10));
    l7.addNode(l7.newNode(15));
    l7.addNode(l7.newNode(20));
    l7.addNode(intersect);
    l7.addNode(l7.newNode(30));
    cout<<"\nList - 1 is :-\n";
    l7.display();
    
    l8.addNode(l8.newNode(23));
    l8.addNode(l8.newNode(24));
    l8.addNode(intersect);
    cout<<"\nList - 2 is :-\n";
    l8.display();
    
    SLLNode<int>* temp;	
    if(intersection(l7,l8,temp))
    {
    	cout<<"\nThe Lists Intersect at :-\n";
    	cout<<temp->getData()<<endl;
	}
	else
	  cout<<"The Lists do not Intersect!";
	*/
	
	//Testing loop detection
	//Testing Intersetion of Lists
    SinglyLinkedList<int> l9;
    SLLNode<int>* loopNode = new SLLNode<int>();
    loopNode->setData(15);
	loopNode->setNext(NULL);
    l9.addNode(l9.newNode(5));
    l9.addNode(l9.newNode(10));
    l9.addNode(loopNode);
    l9.addNode(l9.newNode(20));
    l9.addNode(l9.newNode(25));
    SLLNode<int>* loopEnd = new SLLNode<int>();
    loopEnd->setData(30);
	loopEnd->setNext(loopNode);
    l9.addNode(loopEnd);
    
    SLLNode<int>* start = NULL;	
    if(isLoopDetected(l9,start))
    {
    	cout<<"\nThe Loop starts at :-\n";
    	cout<<start->getData()<<endl;
	}
	else
	  cout<<"\nThe List does not have a loop\n";
	  	  
	return 0;
}
