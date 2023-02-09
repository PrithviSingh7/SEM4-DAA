#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void insertionsort(vector<int> arr, int num)
{
    int key, j;
    for (int i = 1; i < num; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionsort(vector<int> arr, int num)
{
    int key;
    for (int i = 0; i < num - 1; i++)
    {
        key = i;
        for (int j = i + 1; j < num; j++)
        {
            if (arr[j] < arr[key])
            {
                key = j;
            }
        }
        int temp;
        temp = arr[key];
        arr[key] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    vector<int> arr;
    clock_t t1, t2, t3, t4;
    string filename("values.txt");
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
        insertionsort(arr, num);
        t2 = clock();
        t3 = clock();
        selectionsort(arr, num);
        t4 = clock();
        double insertiontime = double(t2 - t1) / double(CLOCKS_PER_SEC);
        double selectiontime = double(t4 - t3) / double(CLOCKS_PER_SEC);
        cout << endl;
        cout << i+1 <<" "<<fixed << insertiontime << setprecision(5) << '\t';
        cout << fixed << selectiontime << setprecision(5);

        num += 100;
    }
    fin.close();
    return 0;
}