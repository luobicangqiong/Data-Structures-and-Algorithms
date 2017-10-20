/**
*
* �鲢������һ�־���ķ��εݹ��㷨���㷨�ȶ��Ժã�ʱ�临�ӶȺͿռ临�Ӷȶ�Ϊnlogn
* ȱ���ǣ�������Ĺ����л�����ϵͳ�Ķ��⿪�������¿ռ临�Ӷȱ����Щ���ӵĹ���Ҳ��Ӱ��ϵͳ�������ٶ�
* ������Ҫ���ڲ�������������ڴ��������»���ѡ���������
*
*/
//�鲢��������
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

		printf("NO space fot tmp array������");
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
	//��ʣ�µ�Ԫ�ط���������ʱ����
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