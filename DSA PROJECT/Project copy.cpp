#include<bits/stdc++.h>
using namespace std;
int ub = -1, lb = 0; // Static variables
int arr[5];
int s = 5;
int b[10];
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* buildTree(Node* root)
{
    cout<<"ENTER DATA: " <<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1 )
    {
        return NULL;
    }
    cout<<"ENTER DATA TO FOR LEFT NODE : "<<endl;
  
    root->left = buildTree(root->left);
     cout<<"ENTER DATA TO FOR right NODE : "<<endl;
    
    root->right = buildTree(root->right);

    return root;
}
void levelOrdertraversal(Node* root)
{
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		if(temp == NULL)
		{
			cout<<endl;
			if(!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
		cout<<temp->data<<" ";
		if(temp->left)
		{
			q.push(temp->left);
		}
			if(temp->right)
		{
			q.push(temp->right);
		}	
		}
		
	}
}
void postOrdertraversal(Node* root)
{
	if(root  == NULL)
	{
		return;
	}
	else
	{
		
	postOrdertraversal(root->left);
	postOrdertraversal(root->right);
	cout<<root->data<<" ";
	}
	
}
void preOrdertraversal(Node* root)
{
		if(root  == NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preOrdertraversal(root->left);
	preOrdertraversal(root->right);

}
void inOrdertraversal(Node* root)
{
		if(root  == NULL)
	{
		return;
	}
	inOrdertraversal(root->left);

	cout<<root->data<<" ";
		
	inOrdertraversal(root->right);

	
}
class NodeL
{
public:
    int data;
    NodeL* next;
    NodeL(int d)
    {

        this->data = d;
        this->next = NULL;
    }
};
void print(NodeL* &head)
{
    NodeL* temp = head;
    if(temp == NULL)
    {
        cout<<"linked list is empty"<<endl;
        return;
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp= temp->next;
        }
    }

}
void headInsersion(NodeL* &head,int d)
{
    NodeL* temp = new NodeL(d);
    temp->next = head;
    head = temp;

}
void tailInsersion(NodeL* &tail,int d)
{

    NodeL* temp = new NodeL(d);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}
void posInsertion(NodeL* &head,NodeL* &tail,int d,int pos)
{
    int i=1;

    NodeL* temp = head;


    if(pos==1)
    {
        NodeL* n = new NodeL(d);
        headInsersion(head,d);
        return;
    }
    else
    {
        NodeL* n = new NodeL(d);
        while(i<pos-1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if(temp->next == NULL)
        {
            tailInsersion(tail,d);
            return;
        }
        NodeL* cur = temp;
        cur = temp->next;
        temp->next = n;
        n->next = cur;

    }


}
void headDeletion(NodeL* &head)
{
    NodeL* temp = head;
    head = head->next;
    cout<<"REMOVED NodeL head : "<<temp->data<<endl;
    free(temp);

}
void tailDeletion(NodeL* &head,NodeL* &tail)
{
    NodeL* temp = head;
    while(temp->next->next != NULL)
    {
        temp=temp->next;
    }
    NodeL* n = temp ->next;
    cout<<"REMOVED NodeL tail : "<<n->data<<endl;
    temp->next = NULL;
    tail = temp;
    free(n);

}
void posDeletion(NodeL* &head,NodeL* &tail,int pos)
{
    int i = 1;
    NodeL* temp = head;
    if(pos == 1)
    {
        headDeletion(head);
        return;
    }
    else
    {
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        if(temp->next->next == NULL)
        {
            tailDeletion(head,tail);
            return;
        }
        NodeL* cur =temp->next;
        temp->next = cur->next;
        cout<<"REMOVED NodeL : "<<cur->data<<endl;
        free(cur);

    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int array[], int low, int high)
{
    // select the rightmost element as pivot
    int pivot = array[high];
    // pointer for greater element
    int i = (low - 1);
    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;
            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }
    // swap pivot with the greater element at i
    swap(&array[i + 1], &array[high]);
    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(array, low, high);
        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);
        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}
void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int i = i + 1; i < size; i++)
        {
            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        // put min at the correct position
        swap(&array[min_idx], &array[i]);
    }
}
int linear(int arr[],int number,int size)
{
    for(int i=0 ; i<size ; i++)
    {
        if(arr[i]==number)
        {
            cout<<"ELEMENT FOUND"<<endl;
            return i;
        }
    }
    return -1;

}
int binary(int arr[],int number,int size)
{

    int low=0,high=size-1;

    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == number)
        {
            return mid;
        }

        if(number < arr[mid])
        {
            high = mid - 1;
        }
        else if(number > arr[mid])
        {
            low = mid +1 ;
        }

    }
    return -1;


}
void merg(int a[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }

        k++;

    }

    //To push the remaing elements in the bk array
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= ub)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for(k=lb; k<=ub; k++)
    {
        a[k]=b[k];
        //equalizing array
    }
}
void mergesort(int a[],int lb,int ub)
{

    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merg(a,lb,mid,ub);
    }
}
void traversal(int arr[],int e,int size)
{
    cout<<"\nARRAY IS :"<<endl;

    for(e=0; e<size; e++)
    {

        cout<<"\t"<<arr[e];
    }
    cout<<endl;
}

void traversal(int arr[])
{
    for (int i =0; i <= ub; i++)
    {
        cout << "(" << i << ")" << arr[i] << "\n";
    }
    cout << endl;
}

void enteratend(int arr[], int s, int value)
{
    if (ub == s - 1)
    {
        cout << "____________________________________________________________________________________________________" << endl;
        cout << "\n\n>>>>>\t\t\tERROR\n>>>>\t\t\t\tArray is full. Cannot enter (failure)\n\n" << endl;
        cout << "____________________________________________________________________________________________________" << endl;
    }
    else
    {
        ub++;
        arr[ub] = value;
        cout << "\n\t\t>>>>Successfully entered at index: " << ub << endl;
        cout << "\n\n";
    }
}

void enteratstart(int arr[], int s, int value)
{
    if (ub == s - 1)
    {
        cout << "___________________________________________________________________________________________________" << endl;
        cout << "\n\n>>>>>\t\t\tERROR\n>>>>\t\t\t\tArray is full. Cannot enter (failure)\n\n" << endl;
        cout << "___________________________________________________________________________________________________" << endl;
    }
    else
    {
        ub++;
        int index = ub - 1;
        while (index != -1)
        {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[lb] = value;
        cout << "\n\t\t>>>>Successfully entered at index: " << lb << endl;
        cout << "\n\n";
    }
}

void enteratindex(int arr[], int s, int value, int index)
{
    if (ub == s - 1)
    {
        cout << "______________________________________________________________________________________________________" << endl;
        cout << "\n\n>>>>>\t\t\tERROR\n>>>>\t\t\t\tArray is full. Cannot enter (failure)\n\n" << endl;
        cout << "______________________________________________________________________________________________________" << endl;
    }
    else if (ub == -1 && index - 1 > lb)
    {
        cout << "_____________________________________________________________________________________________________" << endl;
        cout << "\n\n>>>>>\t\t\tERROR\n>>>>\t\t\t\tArray is empty. Can only enter at index 1\n\n" << endl;
        cout << "_____________________________________________________________________________________________________" << endl;
        ub++;
        arr[ub] = value;
        cout << "\t INSERTED AT FIRST INDEX " << endl;
    }
    else if (index - 1 == ub + 1)
    {
        ub++;
        arr[ub] = value;
    }
    else if (index > ub + 1)
    {
        cout << "Please enter a correct index" << endl;
    }
    else
    {
        ub++;
        int m = ub;
        while (m >= index)
        {
            arr[m] = arr[m - 1];
            m--;
        }
        arr[m] = value;
        cout << "\n\t\t>>>>Successfully entered at index: " << ub << endl;
        cout << "\n\n";
    }
}

void deletionatend(int arr[])
{
    if (ub == -1)
    {
        cout << "__________________________________________________________________________________________________________" << endl;
        cout << "\n\n>>>>>\t\t\tERROR\n>>>>\t\t\t\tArray is empty. Cannot delete (failure)\n\n" << endl;
        cout << "__________________________________________________________________________________________________________" << endl;
    }
    else
    {
        arr[ub] = '\0';
        ub--;
        cout << "\n\t\t>>>>Successfully deleted from end: " << ub + 1 << endl;
        cout << "\n\n";
    }
}

void deletionfromstart(int arr[])
{
    if (ub == -1)
    {
        cout << "____________________________________________________________________________________________________________" << endl;
        cout << "\n\n>>>>>\t\t\tERROR\n>>>>\t\t\t\tArray is empty. Cannot delete (failure)\n\n" << endl;
        cout << "____________________________________________________________________________________________________________" << endl;
    }
    else
    {
        int m = lb;
        while (m != ub)
        {
            arr[m] = arr[m + 1];
            m++;
        }
        arr[ub] = '\0';
        ub--;
        cout << "\n\t\t>>>>Successfully deleted at index: " << lb << endl;
        cout << "\n\n";
    }
    traversal(arr);
}

void deletionatindex(int arr[], int index)
{
    if (ub == -1)
    {
        cout << "_____________________________________________________________________________________________________" << endl;
        cout << "\n\n>>>>>\t\t\tERROR\n>>>>\t\t\t\tArray is empty. Cannot delete (failure)\n\n" << endl;
        cout << "_____________________________________________________________________________________________________" << endl;
    }
    else if (index == 1)
    {
        deletionfromstart(arr);
    }
    else if (index == ub + 1)
    {
        deletionatend(arr);
    }
    else
    {
        int m = index - 1;
        while (m != ub)
        {
            arr[m] = arr[m + 1];
            m++;
        }
        arr[ub] = '\0';
        ub--;
        cout << "Successfully deleted from position " << index << endl;
    }
}
void searchingFunctions()
{

    int s,number,choice;
    cout<<"PLEASE ENTER SIZE OF ARRAY : ";
    cin>>s;
    int arr1[s];
    cout<<"\n\t\tNOW ENTER ELEMENTS : "<<endl;
    for(int i = 0 ; i< s ; i ++)
    {
        cin>>arr1[i];
    }
    cout<<"ENTER ELEMENT TO SEARCH : ";
    cin>>number;
    cout<<"\t\t1.linear seacrh \t 2.Binary search"<<endl;
    cin>>choice;
    cout<<"\n\n\t\t\t Searching.................................."<<endl;
    if(choice == 1)
    {
        int linear1 = linear(arr1,number,s);
        if(linear1 > -1)
        {
            printf("Element found at index %d \n\n\n", linear1);
            
        }
        else
            printf("Element not found ");
    }
    else
    {
        int binary1 = binary(arr1,number,s);
        if(binary1 >= 0)
        {
            printf("Element found at index %d\n\n\n", binary1);
        }
        else
            printf("Element not found ");
    }
}

int bubblesort(int arr[],int size)
{
    int sorted=1;
    int j=1;
    int n=size;
    for(int l=1; l<=5; l++)
    {
        n--;
        for(int i=0; i<n; i++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                sorted=0;
            }
            else
            {
                arr[i]=arr[i];
                arr[j]=arr[j];
            }
            //printf("I,J= (%d, %d)\t %d ,%d\n",i,j,arr[i],arr[j]);
            j++;
        }
        j=1;

        if(l<2 && sorted)
        {
            printf("Array is sorted already");
            return 1;
        }
    }
}

void arrayOperations()
{

    if (ub == s - 1)
    {
        cout << "\tArray is full. Cannot enter" << endl;
    }
    else
    {
        int choice, value, index;
        while (choice != 7)
        {
            cout << "\n\n\t 1. Insert at end \t 2. Insert at start \t 3. Enter at random index\n";
            cout << "\t 4. Delete from front \t 5. Deletion from end \t 6. Deletion at index \n";
            cout << "\t 7.view array \t 8. Exit\n" << endl;
            cout << "\n\tENTER CHOICE: ";
            cin >> choice;
            if (choice == 1)
            {
                cout << "\n\tENTER ELEMENT TO INSERT: ";
                cin >> value;
                enteratend(arr, 5, value);
                traversal(arr);
            }
            else if (choice == 2)
            {
                cout << "\n\tENTER ELEMENT TO INSERT: ";
                cin >> value;
                enteratstart(arr, 5, value);
                traversal(arr);
            }
            else if (choice == 3)
            {
                cout << "\n\tENTER INDEX NO (e.g., 1, 2, 3, etc.): ";
                cin >> index;
                cout << "\n\tENTER ELEMENT TO INSERT: ";
                cin >> value;
                enteratindex(arr, 5, value, index);
                traversal(arr);
            }
            else if (choice == 4)
            {
                deletionfromstart(arr);
                traversal(arr);
            }
            else if (choice == 5)
            {
                deletionatend(arr);
                traversal(arr);
            }
            else if (choice == 6)
            {
                cout << "\n\tENTER position NO: ";
                cin >> index;
                if (index > ub + 1 || index < lb)
                {
                    cout << "Enter a correct positiion" << endl;
                }
                else
                {
                    deletionatindex(arr, index);
                    traversal(arr);
                }
            }
            else if (choice == 7)
            {
            	traversal(arr);
            }
            else if (choice == 7)
            {
            	break;
                return;
            }


        }
    }
}
void sortingAlgo()
{

    int s1,choice;
    cout<<"SELECT THE SORTING ALGORTHM TO SORT FROM"<<endl;
    while (choice != 6)
    {
        cout << "\n\n\t 1. Insertion Sort \t 2. Bubble sort\t 3. Merge Sort\n";
        cout << "\t 4. Quick Sort \t\t 5. Selection Sort\n";
        cout << "\t 6. Exit\n" << endl;
        cout << "\n\tENTER CHOICE: ";
        cin >> choice;
        cout<<"\n\t\t\t\tALGORITHM SELECTED \n\n"<<endl;
        cout<<"PLEASE ENTER SIZE OF ARRAY : ";
        cin>>s1;
        int arr1[s1];
        cout<<"\n\t\tNOW ENTER ELEMENTS : "<<endl;
        for(int i = 0 ; i< s1 ; i ++)
        {
            cin>>arr1[i];
        }
        if (choice == 1)
        {
            int i;
            traversal(arr1,i,s1);
            insertionSort(arr1,s1);
            traversal(arr1,i,s1);
        }
        else if (choice == 2)
        {
            int i;
            traversal(arr1,i,s1);
            bubblesort(arr1,s1);
            traversal(arr1,i,s1);
        }
        else if (choice == 3)
        {
            int i;
            traversal(arr1,i,s1);
            mergesort(arr1,0,s1-1);
            traversal(arr1,i,s1);
        }
        else if (choice == 4)
        {
            int i;
            cout << "Unsorted Array: \n";
            traversal(arr1,i,s1);
            quickSort(arr1, 0, s1 - 1);
            cout << "Sorted array in ascending order: \n";
            traversal(arr1,i,s1);
        }
        else if (choice == 5)
        {
            int i;
            traversal(arr1,i,s1);
            selectionSort(arr1,s1);
            traversal(arr1,i,s1);

        }
        else if(choice == 6)
        {
        	break;
           
        }
    }
}
void linkedlistOperations()
{
    int ch,pos,value;
    NodeL* NodeL1 = new NodeL(10);  // first NodeL 10 //
    NodeL* head = NodeL1;
    NodeL* tail = NodeL1;
    while(ch!=8)
    {
        cout<<"\t\t1.Enter at start \t 2.Enter at End \t 3.Enter at position \t 4.Delete From start "<<endl;
        cout<<"\t\t5.Delete From position \t 6.Delete From End \t 7.Traverse \t 8.Exit  \n\n"<<endl;
        cout<<"Enter Your Choice \t ";
        cin>>ch;


        switch(ch)
        {
        case 1:
        {
            cout<<"\n\nEnter value to insert"<<endl;
            cin>>value;
            cout<<"BEFORE :: "<<endl;
            print(head);

            headInsersion(head,value);
            cout<<"AFTER :: "<<endl;
            print(head);
            break;
        }
        case 2:
        {
            cout<<"\n\nEnter value to insert"<<endl;
            cin>>value;
            cout<<"BEFORE :: "<<endl;
            print(head);

            tailInsersion(tail,value);
            cout<<"AFTER :: "<<endl;
            print(head);
            break;
        }
        case 3:
        {
            cout<<"\n\nEnter value to insert"<<endl;
            cin>>value;
            cout<<"Enter at which position u want to insert the NodeL at "<<endl;
            cin>>pos;

            cout<<"BEFORE :: "<<endl;
            print(head);
            posInsertion(head,tail,value,pos);
            cout<<"AFTER :: "<<endl;
            print(head);
            break;
        }
        case 4:
        {
            cout<<"BEFORE :: "<<endl;
            print(head);

            headDeletion(head);
            cout<<"AFTER :: "<<endl;
            print(head);
            break;
        }
        case 5:
        {
            cout<<"Enter at which position u want to insert the NodeL at "<<endl;
            cin>>pos;

            cout<<"BEFORE :: "<<endl;
            print(head);
            posDeletion(head,tail,pos);
            cout<<"AFTER :: "<<endl;
            print(head);
            break;
        }
        case 6:
        {
            cout<<"BEFORE :: "<<endl;
            print(head);
            tailDeletion(head,tail);
            cout<<"AFTER :: "<<endl;
            print(head);
            break;
        }
        case 7:
        {
            print(head);
            break;
        }
        case 8:
        {
            break;
        }


        }
    }

}

void binarytreeoperations()
{
    int ch,pos,value;
     Node* root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 8 -1 -1 -1
    cout<<"\n\n\tNOTE! \n\t\t\tCOPY THIS DATA for tree building:  1 3 7 -1 -1 11 -1 -1 5 8 -1 -1 -1\n\n\n"<<endl;
   root =  buildTree(root);cout<<endl;
    while(ch!=5)
    {
    
        cout<<"\n\n\t\t1.Level order traversal \t 2.postorder traversal\t 3.preorder traversal\t 4.Inorder traversal "<<endl;
        cout<<"\t \t 5.Exit  \n\n"<<endl;
        cout<<"Enter Your Choice \t ";
        cin>>ch;


        switch(ch)
        {
        case 1:
        {
            cout<<endl;
    cout<<"Level ORDER TRAVERSAL : "<<endl;
    
    levelOrdertraversal(root);
            break;
        }
        case 2:
        {
            cout<<endl;
    cout<<"POST ORDER TRAVERSAL : "<<endl;
    
    postOrdertraversal(root);
            break;
        }
        case 3:
        {
            	cout<<endl;
    cout<<"PRE ORDER TRAVERSAL : "<<endl;
    
    preOrdertraversal(root);
            break;
        }
        case 4:
        {
           cout<<endl;
    cout<<"Inorder ORDER TRAVERSAL : "<<endl;
    inOrdertraversal(root);
            break;
        }
       
        case 5:
        {
            break;
        }


        }
    }

}
void entry()
{
    int choice, value, index;
    while (choice != 20)
    {
        cout<<"\t 1. Array Operations \t 2. Sorting Algorithms \t 3. Searching Algorithms \t 4.LinkedList Operations";
        cout<<"\t\t 5. Binary tree operations \t 6.EXIT."<<endl;;
        cout << "\n\tENTER CHOICE: ";
        cin >> choice;
        if (choice == 1)
        {
            arrayOperations();
        }
        else if (choice == 2)
        {
            sortingAlgo();
        }
        else if (choice == 3)
        {
            searchingFunctions();
        }
        else if(choice == 4)
        {
            linkedlistOperations();
        }
        else if(choice == 5)
        {
        	binarytreeoperations();
		}
        else if(choice == 6)
        {

            return;
        }


    }
}


int main()
{
    entry();
    return 0;
}
