//¹é²¢ÅÅĞò
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
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

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int m = left + (right - 1) / 2; // middle
        mergeSort(array, left, m);
        mergeSort(array, m + 1, right);
        merge(array, left, m, right);
    }
}

//==========================================================================================================================
void merge(int *array, int start, int mid, int end, int arrSize)
{
    int *ans = calloc(arrSize, sizeof(int));
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (array[i] <= array[j])
        {
            ans[k++] = array[i++];
        }
        else
        {
            ans[k++] = array[j++];
        }
    }
    if (i == mid + 1)
    {
        while (j <= end)
        {
            ans[k++] = array[j++];
        }
    }
    if (j == end + 1)
    {
        while (i <= mid)
        {
            ans[k++] = array[i++];
        }
    }
    int count = 0;
    for (i = start; count < k; i++, count++)
    {
        array[i] = ans[count];
    }
}
void mergesort(int *array, int start, int end, int arrSize)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergesort(array, start, mid, arrSize);
    mergesort(array, mid + 1, end, arrSize);
    merge(array, start, mid, end, arrSize);
}