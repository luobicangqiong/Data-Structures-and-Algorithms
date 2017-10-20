/**
*
* 归并排序是一种经典的分治递归算法，算法稳定性好，时间复杂度和空间复杂度都为nlogn
* 缺点是：在排序的过程中会增加系统的额外开销。导致空间复杂度变大。这些附加的工作也会影响系统的运行速度
* 对于重要的内部排序而言我们在大多数情况下还是选择快速排序
*
*/
//归并排序历程
void Msort(int A[],int TmpArray[],int left,int right)
{
	int center;

	if(left < right){

		center = (left+right)/2;
		Msort(A,TmpArray,left,center);
		Msort(A,TmpArray,center+1,right);
		Merge(A,TmpArray,left,center+1,right);

	}


}

void MergeSort(int A[],int N)
{

	int *TmpArray;

	TmpArray = malloc(N*sizeof(int));
	if(TmpArray != NULL)
	{

		Msort(A,TmpArray,0,N-1);
		free(TmpArray);
	}else{

		printf("NO space fot tmp array！！！");
	}

}

//lpos = start of left half ,rpos = start of right half
void Merge(int A[],int TmpArray[],int lpos,int rpos,int rightend)
{
	int i,leftend,numelements,Tmpos;

	leftend = rpos -1;
	Tmpos = lpos;
	numelements = rightend - lpos + 1;

	//main loop
	while(lpos <= leftend && rpos <= rightend)
	{
		if(A[lpos]<= A[rpos])
		{
			TmpArray[Tmpos++] = A[lpos++];
		}else{

			TmpArray[Tmpos++] = A[rpos++];
		}

	}
	//把剩下的元素放入输入临时数组
	while(lpos <= leftend)
	{
		TmpArray[Tmpos++] = A[lpos++];
	}
	while(rpos <= rightend)
	{
		TmpArray[Tmpos++] = A[rpos++];
	}

	//copy TmpArray back
	for(i = 0;i<numelements;i++,rightend--)
	{
		A[rightend] = TmpArray[rightend];

	}
}