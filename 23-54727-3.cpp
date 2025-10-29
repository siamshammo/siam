#include <iostream>
using namespace std;

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = A[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
    else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
        {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
        {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int left, int right)
{
    if (left >= right)
        {
        return;
    }
    int mid = left + (right - left) / 2;

    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice;

    cout << "Choose input method:"<<endl;
    cout << "1. Input size and elements manually"<<endl;
    cout << "2. Input space-separated elements"<<endl;
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    int n;
    int arr[100];

    if (choice == 1)
        {

        cout << "Enter the number of elements: ";
        cin >> n;
        cout << "Enter " << n << " integers: ";
        for (int i = 0; i < n; i++)
            {
            cin >> arr[i];
        }
    } else if (choice == 2)
    {

        cout << "Enter space-separated integers: ";
        n = 0;
        while (cin >> arr[n])
            {
            n++;
            if (n >= 100) break;
        }
    }
    else
        {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    cout << "Original array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

