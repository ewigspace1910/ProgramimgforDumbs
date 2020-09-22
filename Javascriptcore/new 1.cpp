//void merge(int arr[], int l, int m, int r)
int* merge(int* firstArr, int lenArr1, int* secondArr, int lenArr2)
{
    int i, j, k;
	int *arr = new int[lenArr1+lenArr2];
    /* Tạo các mảng tạm */

 
    /* Gộp hai mảng tạm vừa rồi vào mảng arr*/
    i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
    j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
	
    while (i < lenArr1 && j < lenArr2)
    {
        if (firstArr[i] <= secondArr[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy các phần tử còn lại của mảng 1 vào arr nếu có */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy các phần tử còn lại của mảng 2 vào arr nếu có */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}