#include <iostream>
using namespace std;
int ub = -1, lb = 0; // Static variables
int arr[5];
int s = 5;
int b[10];
void merg(int a[],int lb,int mid,int ub)
{
    cout<<" \nMERGING AFTER DIVIDING "<<endl;
    int i=lb;
    int j=mid+1;
    int k=lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
           b[k]=a[i];
           i++;
        }else{
         b[k]=a[j];
         j++;
        }

        k++;

    }

    //To push the remaing elements in the bk array
     while (i <= mid){
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= ub) {
        b[k] = a[j];
        j++;
        k++;
    }
    for(k=lb;k<=ub;k++)
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
    for(e=0;e<=size;e++)
    cout<<"\t"<<arr[e];
}

void traversal(int arr[])
{
    for (int i = lb; i <= ub; i++)
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
        cout << "Successfully deleted from index " << index << endl;
    }
}

void entry()
{
    if (ub == s - 1)
    {
        cout << "\tArray is full. Cannot enter" << endl;
    }
    else
    {
        int choice, value, index;
        while (choice != 8)
        {
            cout << "\n\n\t 1. Insert at end \t 2. Insert at start \t 3. Enter at random index\n";
            cout << "\t 4. Delete from front \t 5. Deletion from end \t 6. Deletion at index \n";
            cout << "\t 7. Merge sort \t 8.view array 9. Exit\n" << endl;
            cout << "\n\tENTER CHOICE: ";
            cin >> choice;
            if (choice == 1)
            {
                cout << "\n\tENTER ELEMENT TO INSERT: ";
                cin >> value;
                enteratend(arr, 5, value);
            }
            else if (choice == 2)
            {
                cout << "\n\tENTER ELEMENT TO INSERT: ";
                cin >> value;
                enteratstart(arr, 5, value);
            }
            else if (choice == 3)
            {
                cout << "\n\tENTER INDEX NO (e.g., 1, 2, 3, etc.): ";
                cin >> index;
                cout << "\n\tENTER ELEMENT TO INSERT: ";
                cin >> value;
                enteratindex(arr, 5, value, index);
            }
            else if (choice == 4)
            {
                deletionfromstart(arr);
            }
            else if (choice == 5)
            {
                deletionatend(arr);
            }
            else if (choice == 6)
            {
                cout << "\n\tENTER INDEX NO: ";
                cin >> index;
                if (index > ub + 1 || index < lb)
                {
                    cout << "Enter a correct index location" << endl;
                }
                else
                {
                    deletionatindex(arr, index);
                }
            }
             else if (choice == 7)
            {
                cout << "\n\THE Array to sort is =  ";
                int size=9;
                int a[9]={15,5,24,8,1,3,16,10,20};
                traversal(a,0,size-1);
                mergesort(a,0,size-1);
                traversal(a,0,size-1);

            }
            else if (choice == 8)
            {
                traversal(arr);
            }
            else if (choice == 9)
            {
                exit(0);
            }
        }
    }
}

int main()
{
    entry();
    return 0;
}

