#include <iostream>
#include <fstream>
#include <ctime>
#include <stdio.h>
using namespace std;
int a[11000000];
int b[20000];
int N;
int M;
int dem = 0;

void SapXep(int a[], int N)
{
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            if (a[i] > a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}
void InRa(int a[], int N)
{
    for (int i = 0; i < N; i++)
        cout << a[i] << "; ";
    cout << endl;
}

void SinhDuLieu(int k, const char *FileName)
{
    srand(time(0));
    ofstream fout(FileName);
    fout << k << endl;
    for (int i = 0; i < k; i++)
    {
        int x = rand() % k;
        fout << x << " ";
    }
    fout.close();
}

void GhiFile(int a[], int N, const char *FileName)
{
    ofstream fout(FileName);
    fout << N << endl;
    for (int i = 0; i < N; i++)
    {
        fout << a[i] << " ";
    }
    fout.close();
}

void DocFile(const char *FileName, int &N, int a[])
{
    ifstream fin(FileName);
    fin >> N;
    for (int i = 0; i < N; i++)
    {
        fin >> a[i];
    }
    fin.close();
}

void Merge(int a[], int s, int f)
{
    int m = (s + f) / 2;
    int *b = new int[f - s + 1];
    int ib = 0;
    int l = s, r = m + 1;
    while (l <= m && r <= f)
    {
        if (a[l - 1] < a[r - 1])
        {
            b[ib] = a[l - 1];
            l++;
        }
        else
        {
            b[ib] = a[r - 1];
            r++;
        }
        ib++;
    }
    for (int i = l; i <= m; i++)
    {
        b[ib] = a[i - 1];
        ib++;
    }
    for (int i = r; i <= f; i++)
    {
        b[ib] = a[i - 1];
        ib++;
    }
    for (int i = 0; i < ib; i++)
    {
        a[s - 1 + i] = b[i];
    }
}

void MergeSort(int a[], int s, int f)
{
    int m = (s + f) / 2;
    if (s < f) //cos nhieu hon 1 phan tu
    {
        MergeSort(a, s, m);
        MergeSort(a, m + 1, f);
        Merge(a, s, f);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high]; // pivot
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && a[left] < pivot)
            left++; // T??m ph???n t??? >= arr[pivot]
        while (right >= left && a[right] > pivot)
            right--; // T??m ph???n t??? <= arr[pivot]
        if (left >= right)
            break;                   // ???? duy???t xong th?? tho??t v??ng l???p
        swap(&a[left], &arr[right]); // N???u ch??a xong, ?????i ch???.
        left++;                      // V?? left hi???n t???i ???? x??t, n??n c???n t??ng
        right--;                     // V?? right hi???n t???i ???? x??t, n??n c???n gi???m
    }
    swap(&a[left], &a[high]);
    return left; // Tr??? v??? ch??? s??? s??? d??ng ????? chia ?????i m???ng
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        /* pi l?? ch??? s??? n??i ph???n t??? n??y ???? ?????ng ????ng v??? tr??
         v?? l?? ph???n t??? chia m???ng l??m 2 m???ng con tr??i & ph???i */
        int pi = partition(a, low, high);

        // G???i ????? quy s???p x???p 2 m???ng con tr??i v?? ph???i
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int BinarySearch(int a[], int N, int x) //T??m ki???m nh??? ph??n
{

    int left = 0;
    int right = N - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
            return mid; // t??m th???y x, tr??? v??? mid l?? v??? tr?? c???a x trong m???ng A
        if (a[mid] > x)
            right = mid - 1; // Gi???i h???n kho???ng t??m ki???m l???i l?? n???a kho???ng tr?????c
        else if (a[mid] < x)
            left = mid + 1; // Gi???i h???n kho???ng t??m ki???m l???i l?? n???a kho???ng sau
    }
    return -1; // kh??ng t??m th???y x
}

int main()
{

    // SinhDuLieu(1000000, "data1tr.txt");
    DocFile("data1tr.txt", N, a);
    // SapXep(a, N);
    MergeSort(a, 1, N);
    GhiFile(a, N, "data1trsx.txt");

    /*cout<<"So ph???n t???: ";
  cin>>N;

  for(int i = 1; i<= N; i++)
  {
    cout<<"Nh???p ph???n t??? th??? "<<i<<": ";
    cin>>a[i-1];
  }*/

    // cout << a[0] << " " << a[N - 1] << endl;

    // SinhDuLieu(20000, "data1.txt");

    // /*cout<<"So ph???n t???: ";
    //   cin>>N;

    //   for(int i = 1; i<= N; i++)
    //   {
    //     cout<<"Nh???p ph???n t??? th??? "<<i<<": ";
    //     cin>>a[i-1];
    //   }*/
    // SapXep(b, M);

    // // cout << b[0] << " " << b[M - 1] << endl;

    // for (int i = 0; i <= 20000; i++)
    // {
    //     if (BinarySearch(b, 20000, a[i]) != -1 /*n???u t??m th???y x*/)
    //     {
    //         dem++;
    //     }
    // }
    // cout << dem << endl;
}