#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> arr, int p, int q, int r) 
{
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> arr, int l, int r) {
  if (l < r) 
  {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int divide(int array[], int low, int high) {
  
  
  int pivot = array[high];
  
  
  int i = (low - 1);

  
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
       
      i++;
      
      
      swap(&array[i], &array[j]);
    }
  }

 
  swap(&array[i + 1], &array[high]);
  
 
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    
    int pi = divide(array, low, high);
    
   
    quickSort(array, low, pi - 1);
    
    
    quickSort(array, pi + 1, high);
  }
}

int main()
{
    vector<int> arr;
    clock_t t1, t2, t3, t4;
    string filename("2nd.txt");
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (!fin.eof())
    {
        int tmp;
        fin >> tmp;
        arr.push_back(tmp);
    }

    int num = 100;
    for (int i = 0; i <1000; i++)
    {
        t1 = clock();
        mergeSort(arr,0, num);
        t2 = clock();
        t3 = clock();
        quickSort(arr,0, num);
        t4 = clock();
        double mergetime = double(t2 - t1) / double(CLOCKS_PER_SEC);
        double quicktime = double(t4 - t3) / double(CLOCKS_PER_SEC);
        cout << endl;
        cout << i+1 <<" "<<fixed << mergetime << setprecision(5) << '\t';
        cout << fixed << quicktime << setprecision(5);

        num += 100;
    }
    fin.close();
    return 0;
}