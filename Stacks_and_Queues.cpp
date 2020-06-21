/*
Chapter-3. Stacks and Queues

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

//Template Linked list Node class
template<class T>
class Node
{
   private:
	     T data;
	   	 Node<T>* ptr;
   public:
	     T getData()
		 {
		   return this->data;	
	     }
		 void setData(T d)
		 {
		   this->data = d;	
	     }	
	     void setNext(Node<T>* next)
		 {
		   this->ptr = next;	
	     }	
	     Node<T>* next()
	     {
	     	return this->ptr;
		 }
};


//Template stack class
template <class T>
class Stack
{
	private:
		  Node<T>* top;
		  int size;
	public:
	      Stack()
		  {
		     top = NULL;
			 size = 0;	
		  }
		  Node<T>* getNode(T data)
		  {
		      Node<T>* temp = new Node<T>();
			  temp->setData(data);
			  temp->setNext(NULL);
			  return temp;	
	      }
		  void push(T data)
		  {
		  	size++;  
		  	if(top == NULL)
		  	{
		  	    top = getNode(data);	
			}
			else
			{
				Node<T>* t = getNode(data);
				t->setNext(top);
				top = t; 
			}
		  }
		 T pop()
		 {
		     if(top == NULL)
			 {
			 	cout<<"STACK EMPTY !!!"<<endl;
			 	return 0;
			 }
			 Node<T>* temp = top;
			 top = top->next();
			 T data = temp->getData();
			 delete temp;
			 size--;
			 return data;	
		 } 
		 T peek()
		 {
		 	return top->getData();
		 }
		 bool isEmpty()
		 {
		 	return top == NULL;
		 }
		 void display()
		 {
		 	cout<<"STACK contents :-"<<endl;
		 	cout<<" TOP ===> \t";
		 	Node<T>* temp = top;
		 	while(temp != NULL)
		 	{
		 	   cout<<temp->getData()<<"\t";	
		 	   temp = temp->next();
			}
			cout<<endl;
		 }
		 ~Stack()
		 {
		 	if(top == NULL)
		 	  return;
		 	while(top!=NULL)
			 {  
		 	    Node<T>* temp = top;
		 	    top = top->next();
		 	    delete temp;
		 	 }
		 }
};


//Template Queue class
template <class T>
class Queue
{
	  private:
		    Node<T>* front;
			Node<T>* rear;
			int size; 
	  public:
		   Queue()
		   {
		      front = rear = NULL;
			  size = 0; 	
		   }
		   Node<T>* getNode(T data)
		   {
		      Node<T>* temp = new Node<T>();
			  temp->setData(data);
			  temp->setNext(NULL);
			  return temp;	
	       }
		   void enqueue(T data)
		   {
		   	  size++;
		   	  if(rear == NULL && front == NULL)
		   	  {
		   	    	rear = getNode(data);
		   	    	front = rear;
		   	    	return;
			  }
			  Node<T>* temp = getNode(data);
			  rear->setNext(temp);
			  rear = temp;
		   }	   	
		   T dequeue()
		   {
		   	 T data = 0;
		   	 if(front == NULL)
		   	 {
		   	     cout<<"QUEUE EMPTY !!!"<<endl;
				 return data;		
			 }
			  Node<T>* temp = front;
			  data = temp->getData();
			  front = front->next();
			  size--;
			  delete temp;
			  return data;
		   }
		   void display()
		   {
		   	    cout<<"QUEUE Contents :-"<<endl;
		   	    cout<<"Front ===> \t";
			  	Node<T>* temp = front;
			 	while(temp != NULL)
			 	{
			 	   cout<<temp->getData()<<"\t";	
			 	   temp = temp->next();
				}
				cout<<"\t<=== Rear";
				cout<<endl;
		   }
		   ~Queue()
			{
			 	if(front == NULL && rear == NULL)
			 	  return;
			 	while(front!=NULL)
				 {  
			 	    Node<T>* temp = front;
			 	    front = front->next();
			 	    delete temp;
			 	 }
			 	rear = NULL; 
			}
};

/*
3.1 Three in One: Describe how you could use a single array to implement three stacks.
*/
void threeInOne()
{
	int l,top1,top2,top3,bot1,bot2,bot3,s1,s2,s3,temp,choice;
	bool b1,b2,b3;
	cout<<"Enter size of array :-\t";
	cin>>l;
	int arr[l];
	choice = 0;
	s1=l/3;
	s2=2*(l/3);
	s3= l;
	bot1=0;
	bot2=(l/3);
	bot3=2*(l/3);
	top1= bot1 - 1;
	top2= bot2 - 1;
	top3= bot3 - 1;
	while(choice!=10)
	{
		cout<<"Enter a option :"<<endl;
		cout<<"1.Push onto stack1"<<endl;
		cout<<"2.Push onto stack2"<<endl;
		cout<<"3.Push onto stack3"<<endl;
		cout<<"4.Pop off stack1"<<endl;
		cout<<"5.Pop off stack2"<<endl;
		cout<<"6.Pop off stack3"<<endl;
		cout<<"7.Display Stack1"<<endl;
		cout<<"8.Display Stack2"<<endl;
		cout<<"9.Display Stack3"<<endl;
		cout<<"10.Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: top1++;
			        if(top1 >= s1)
			        {
			        	top1--;
			        	cout<<"STACK1 IS FULL, CANNOT PUSH MORE ELEMENTS"<<endl;
					}
					else
					{
					    cout<<"Enter the element to push on stack1 :-\t";
					    cin>>temp;
					    arr[top1] =temp; 
					}
					break;
			case 2: top2++;
					if(top2 >= s2)
			        {
			        	top2--;
			        	cout<<"STACK2 IS FULL, CANNOT PUSH MORE ELEMENTS"<<endl;
					}
					else
					{
					    cout<<"Enter the element to push on stack2 :-\t";
					    cin>>temp;
					    arr[top2] =temp; 
					}
					break;
			case 3: top3++;
					if(top3 >= s3)
			        {
			        	top3--;
			        	cout<<"STACK3 IS FULL, CANNOT PUSH MORE ELEMENTS"<<endl;
					}
					else
					{
					    cout<<"Enter the element to push on stack3 :-\t";
					    cin>>temp;
					    arr[top3] =temp;
					}
					break; 	
			case 4: temp = arr[top1];
			        if(top1 >= bot1)
			        {
			           cout<<"The element popped off of stack1 :-\t"<<temp<<endl;	
			           top1--;
			        }
			        if(top1 < bot1)
			        {
			        	cout<<"STACK1 IS EMPTY, CANNOT POP ELEMENTS"<<endl;		
			        	temp = 0;
					}	
					break;
			case 5: temp = arr[top2];
			        if(top2 >= bot2)
			        {
			           cout<<"The element popped off of stack2 :-\t"<<temp<<endl;
					   top2--; 
			        }
			        if(top2 < bot2)
			        {
			        	cout<<"STACK2 IS EMPTY, CANNOT POP ELEMENTS"<<endl;	
			        	temp = 0;
					}	
					break;					 									
			case 6: temp = arr[top3];
					if(top3 >= bot3)
					{
			           cout<<"The element popped off of stack3 :-\t"<<temp<<endl;	  
					   top3--;
			        }
			        if(top3 < bot3)
			        {	
			        	cout<<"STACK3 IS EMPTY, CANNOT POP ELEMENTS"<<endl;	
			        	temp = 0;
					}
					break;	
			case 7: cout<<"STACK-1 is :-"<<endl;
			        if(top1>=bot1)
			        {
				        for(int i=bot1;i<=top1;i++)
						{
						   cout<<arr[i]<<"\t";	
						}
					}
					else
					{
						cout<<"EMPTY"<<"\t";
					}
					cout<<"  <====== TOP "<<endl;
					break;
			case 8: cout<<"STACK-2 is :-"<<endl;
					if(top2>=bot2)
			        {
				        for(int i=bot2;i<=top2;i++)
						{
						   cout<<arr[i]<<"\t";	
						}		
					}
					else
					{
						cout<<"EMPTY"<<"\t";
					}
					cout<<"  <====== TOP "<<endl;
					break;
			case 9: cout<<"STACK-3 is :-"<<endl;
			        if(top3>=bot3)
			        {
				        for(int i=bot3;i<=top3;i++)
						{
						   cout<<arr[i]<<"\t";	
						}
					}
					else
					{
						cout<<"EMPTY"<<"\t";
					}
					cout<<"  <====== TOP "<<endl;
					break;
			case 10: break;		 				
			default: cout<<"Wrong Choice !! Enter Again !!!"<<endl;		 								
		}
	}
	
}

/*
3.2 Stack Min: How would you design a stack which, in addition to push and pop, has a function min
which returns the minimum element? Push, pop and min should all operate in 0(1) time.
*/
class MinStackNode
{
	private:
		int data;
		int minTillNow;
	public:
	 MinStackNode(int d=0)
	 { 
	   data = d;
	   minTillNow = d;  	
	 }	
	 int getData()
	 {
	 	return data;
	 }
	 void setData(int d)
	 {
	 	data = d;
	 }
	 int getMinTillNow()
	 {
	 	return minTillNow;
	 }
	 void setMinTillNow(int m)
	 {
	 	minTillNow = m;
     }	
};
class MinStack
{
	private:
		vector<MinStackNode> stack;
		int top;
	public:
	MinStack()
	{
	   top = -1;	
	}	
	void push(int data)
	{
		top++;
		stack.push_back(MinStackNode(data));
		if(top >= 1)
		{
			if(data > stack[top-1].getMinTillNow())
			{
				stack[top].setMinTillNow(stack[top-1].getMinTillNow());
			}
		}
	}
	int pop()
	{
		if(top <= -1)
		{
			cout<<"Stack Empty, cannot Pop!!"<<endl;
			return 0;
		}
		cout<< stack[top].getData() << " is popped"<<endl;
		stack.pop_back();
		top--;
	}
	int getMin()
	{
		if(top>=0)
		  return stack[top].getMinTillNow();
		return 0;  
	}
	void displayMinStack()
	{
		for(int i=0;i<=top;i++)
		{
			cout<<stack[i].getData()<<"\t";
		}
		cout<<"   <====== TOP"<<endl;
	}
};


/*
3.3 Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be
composed of several stacks and should create a new stack once the previous one exceeds capacity.
push() and pop() should behave identically to a single stack SetOfStacks.
(that is, pop () should return the same values as it would if there were just a single stack).
FOLLOW UP
Implement a function popAt ( int index) which performs a pop operation on a specific sub-stack.
*/
template <class T>
class SetOfStacks
{
	private:
		int vtop,htop;
		vector<vector<T>> sos;
		int capacity;
	public:
	SetOfStacks(int c=5):vtop(-1), htop(-1), capacity(c)
	{
	}
	void push(T data)
	{
		vtop++;
		if(vtop >= capacity || htop == -1)
		  {
		  	 htop++;
		  	 vector<int> vec;
		     sos.push_back(vec);
		     vtop=0;	
		  }  
		sos[htop].push_back(data);    
	}
	void pop()
	{
	   	if(htop == -1)
	   	{
	   	   cout<<"\nCannot pop as the Set-Of-Stacks is Empty!\n";
		   return;  	
		}
		T temp = sos[htop][vtop];
		sos[htop].pop_back();
		vtop--;
		if(sos[htop].size() == 0)
		{
			vtop = capacity - 1;
			sos.pop_back();
			htop--;
		}
		cout<< temp<<" is popped !"<<endl;
	}	
	void display()
	{
		if(htop == -1)
		{
			cout<<"SET OF STACKS EMPTY !!!"<<endl;
		}
		for(int i = 0;i<sos.size();i++)
		{
			for(int j=0;j<sos[i].size();j++)
			{
				cout<<sos[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
};

/*
3.4 Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.
*/
template <class T>
class MyQueue
{
  private:
   Stack<T> s1,s2;	
   int cnt;
  public:
  MyQueue():cnt(0)
  {} 
  int size()
  {
  	return cnt;
  }
  void enqueue(T data)
  {
  	s1.push(data);
  	cnt++;
  }
  void dequeue()
  {
  	if(s1.isEmpty())
  	{
  	   cout<<"Queue empty, cannot Dequeue!!!"<<endl;
	   return; 	
	}
	cnt--;
	while(!s1.isEmpty())
	{
		s2.push(s1.pop());
	}
	T temp = s2.pop();
	cout<<temp<<" is dequeued"<<endl;
	while(!s2.isEmpty())
	{
		s1.push(s2.pop());
	}
  }
  void display()
  {
  	if(s1.isEmpty())
  	{
  	  cout<<"Queue Empty!!!"<<endl;
	  return;	
	}
  	cout<<"REAR ===> "<<endl;
  	s1.display();
  	cout<<"  <=== FRONT"<<endl;
  }
};

/*
3.5 Sort Stack: Write a program to sort a stack such that the smallest items are on the top.You can use
an additional temporary stack, but you may not copy the elements into any other data structure
(such as an array). The stack supports the following operations: push, pop, peek, and is Empty.
*/
template <class T>
void sortStack(Stack<T>& s)
{
	Stack<T> temp;
	int gt;
	if(s.isEmpty())
	{
		return;
	}
	while(!s.isEmpty())
	{
		gt = 0;
		if(temp.isEmpty())
		{
			temp.push(s.pop());
		}	
		if( s.peek() > temp.peek())
		{
			temp.push(s.pop());
		}
		else
		{
			T buffer = s.pop();
			while( !temp.isEmpty() && buffer <= temp.peek())
			{
				gt++;
				s.push(temp.pop());
			}
			temp.push(buffer);
			while(gt)
			{
				temp.push(s.pop());
				gt--;
			}
		}
	}
	while(!temp.isEmpty())
	{
		s.push(temp.pop());
	}
}



/*
3.6 Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first
out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
that type). They cannot select which specific animal they would like. Create the data structures to
maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
and dequeueCat. You may use the built-in Linked list data structure.
*/
class AnimalShelter
{
	private:
		Node<char>* front;
		Node<char>* rear;
	public:
	    AnimalShelter(): front(NULL),rear(NULL){
		}	
		Node<char>* getPetNode(char ch) // "d" for dog and "c" for cat
		{
		   Node<char>* n = new Node<char>();
		   while(ch != 'd' && ch != 'c')
		   {
		      cout << "Enter \"d\" for dog or \"c\" for cat\t:-";
		      cin>>ch;
		   }
		   n->setData(ch);
		   n->setNext(NULL);
		   return n;
		}
		void enqueue(char ch)
		{
		   if(rear == NULL || front == NULL)
		   {
		   	  rear = front = getPetNode(ch);
		   	  return;
		   }	
		   Node<char>* temp = getPetNode(ch);
		   rear->setNext(temp);
		   rear = temp;
		}
		void dequeueAny()   //performs normal dequeue over the queue
		{
			if( front == NULL || rear == NULL)
			{
				cout<<"No animals in the shelter!!"<<endl;
				return;
			}
		    Node<char>* temp = front;
			front = front->next();
			char ch = temp->getData();
			if(ch == 'd')
			  cout<<"Yay !! you got a loyal dog !!!"<<endl;	
			if(ch == 'c')
			  cout<<"Yay !! you got a cute kitty cat !!!"<<endl;
			delete temp;  
		}	
		void dequeueDog() // performs removal of oldest dog available if any
		{
			if( front == NULL || rear == NULL)
			{
				cout<<"No animals in the shelter!!"<<endl;
				return;
			}
			Node<char>* temp = front;
			Node<char>* prev = NULL;
			while(temp && temp->getData() != 'd')
			{
				prev = temp;
				temp = temp->next();
			}
			if(temp == NULL && prev == rear)
			  dequeueAny();
			else
			{
			  	char ch = temp->getData();
				if(ch == 'd')
				  cout<<"Yay !! you got a loyal dog !!!"<<endl;	
				if(ch == 'c')
				  cout<<"Yay !! you got a cute kitty cat !!!"<<endl;
				if(temp == front)
				   front = front->next();
				else     
				   prev->setNext(temp->next());
				delete temp;  
		    }
		}
		void dequeueCat() // performs removal of oldest dog available if any
		{
			if( front == NULL || rear == NULL)
			{
				cout<<"No animals in the shelter!!"<<endl;
				return;
			}
			Node<char>* temp = front;
			Node<char>* prev = NULL;
			while(temp && temp->getData() != 'c')
			{
				prev = temp;
				temp = temp->next();
			}
			if(temp == NULL && prev == rear)
			  dequeueAny();
			else
			{
			  	char ch = temp->getData();
				if(ch == 'd')
				  cout<<"Yay !! you got a loyal dog !!!"<<endl;	
				if(ch == 'c')
				  cout<<"Yay !! you got a cute kitty cat !!!"<<endl;
				if(temp == front)
				  front = front->next();
				else     
				  prev->setNext(temp->next());
				delete temp;  
		    }
		}
		void displayAnimalShelter()
		{
			if( front == NULL || rear == NULL)
			{
				cout<<"No animals in the shelter!!"<<endl;
				return;
			}
			cout<<"FRONT ===> ";
			Node<char>* temp = front;
			while(temp!=NULL)
			{
				cout<<temp->getData()<<"\t";
				temp = temp->next();
			}
			cout<<" <=== REAR"<<endl;
			
		}
		~AnimalShelter()
		{
			if(front == NULL || rear == NULL)
			  return;
			Node<char>* temp = front;
			while(front != NULL)
			{
			   front = front->next();
			   delete temp;
			   temp = front;	
		    }
		}
};



int main()
{
	//Testing the created template classes for Stack and Queue, which are implemented as linked lists
	/*
	int choice = 8,temp;
	Stack<int> s1;
	Queue<char> q1;
	char ct;
	while(choice != 4)
	{
		cout<<"\nEnter the operation number to be performed on stack :-\n";
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Display Stack"<<endl;
		cout<<"4.Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nEnter Element to push :-\t";
			        cin>>temp;
			        s1.push(temp);
			        break;
			case 2: temp=s1.pop();
			        cout<<"\n"<<temp<<" is popped"<<endl;
					break;
			case 3: s1.display();
			        break;
			case 4: break;
			default: cout<<"Wrong Choice !! Enter again !!!"<<endl; 				        
		}
	}
	choice = 10;
	while(choice != 4)
	{
		cout<<"\nEnter the operation number to be performed on Queue :-\n";
		cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.Display Queue"<<endl;
		cout<<"4.Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nEnter Element to enqueue :-\t";
			        cin>>ct;
			        q1.enqueue(ct);
			        break;
			case 2: ct=q1.dequeue();
			        cout<<"\n"<<ct<<" is dequeued"<<endl;
					break;
			case 3: q1.display();
			        break;
			case 4: break;
			default: cout<<"Wrong Choice !! Enter again !!!"<<endl; 				        
		}
	}
	*/
	
	//Menu-driven Testing for 3.1
	//threeInOne();
	
	
	//Menu-driven Testing for 3.2 : MinStack
	/*
	int choice = 0,temp;
	MinStack mstk;
	while(choice != 5)
	{
		cout<<"\nEnter the operation number to be performed on min-stack :-\n";
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Get Minimum in the stack"<<endl;
		cout<<"4.Display Stack"<<endl;
		cout<<"5.Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nEnter Element to push :-\t";
			        cin>>temp;
			        mstk.push(temp);
			        break;
			case 2: mstk.pop();
					break;
			case 3: cout<<"The Minimun is :- \t"<<mstk.getMin()<<endl;
			        break;
			case 4: mstk.displayMinStack();
			        break;
			case 5: break;
			default: cout<<"Wrong Choice !! Enter again !!!"<<endl; 				        
		}
	}
	*/
	
	//Menu-driven Testing for 3.3 : Set of Stacks
	/*
	int choice = 0,temp;
	SetOfStacks<int> ss(3); //set-of-stacks with each stack having capacity 3
	while(choice != 4)
	{
		cout<<"\nEnter the operation number to be performed on min-stack :-\n";
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Display SOS"<<endl;
		cout<<"4.Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nEnter Element to push :-\t";
			        cin>>temp;
			        ss.push(temp);
			        break;
			case 2: ss.pop();
					break;
			case 3: ss.display();
			        break;
			case 4: break;
			default: cout<<"Wrong Choice !! Enter again !!!"<<endl; 				        
		}
	}
	*/

	//Menu-driven Testing for 3.4 : MyQueue
    /*
	int choice = 0,temp;
	MyQueue<int> q; 
	while(choice != 4)
	{
		cout<<"\nEnter the operation number to be performed on MyQueue :-\n";
		cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.Display Queue"<<endl;
		cout<<"4.Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nEnter Element to push :-\t";
			        cin>>temp;
			        q.enqueue(temp);
			        break;
			case 2: q.dequeue();
					break;
			case 3: q.display();
			        break;
			case 4: break;
			default: cout<<"Wrong Choice !! Enter again !!!"<<endl; 				        
		}
	}*/
	
	//Testing for 3.5 : Sort Stack
	/*
	Stack<int> s;
	s.push(4);
	s.push(5);
	s.push(1);
	s.push(3);
	s.push(2);
	cout<<"Intial Stack state :-"<<endl;
	s.display();
	sortStack(s);
	cout<<"Sorted stack is:-"<<endl;
	s.display(); 
	*/
	
	
    //Menu-driven Testing for 3.6 : Animal Shelter
	int choice = 0;
	char temp;
	AnimalShelter shelter;
	while(choice != 6)
	{
		cout<<"\nEnter the operation number to be performed on Animal Shelter :-\n";
		cout<<"1.Add an animal to the shelter"<<endl;
		cout<<"2.Get a pet"<<endl;
		cout<<"3.Get a pet dog"<<endl;
		cout<<"4.Get a pet cat"<<endl;
		cout<<"5.Display Shelter Animals"<<endl;
		cout<<"6.Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: shelter.enqueue(' ');
			        break;
			case 2: shelter.dequeueAny();
					break;
			case 3: shelter.dequeueDog();
			        break;
			case 4: shelter.dequeueCat();
			        break;
			case 5: shelter.displayAnimalShelter();
			        break;
			case 6: break;
			default: cout<<"Wrong Choice !! Enter again !!!"<<endl; 				        
		}
	}
		
	return 0;
}
