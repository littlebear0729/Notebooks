struct PriorityQueue{
int MAXNUM; /*����Ԫ�ظ���������*/
int n; /*����ʵ��Ԫ�صĸ���*/
DataType *pq; /*����Ԫ�ص�˳���ʾ*/
}; /*���ȶ�������*/
typedef struct PriorityQueue *PPriorityQueue;/


void add_heap(PPriorityQueue papq,DataType x){
int i;
if(papq->n>=papq->MAXNUM-1){printf(��Full!\n��);return;}
for(i=paqu->n;i> 0&& papq->pq[(i-1)/2]>x; i =(i-1)/2)
papq->pq[i]=papq->pq[(i-1)/2];
/*��λ����ƶ����Ҳ���λ��*/
papq->pq[i] =x;n++; /*��x����*/
}

int isEmpty_heap(PriorityQueue papa){
                           return (papa->n==0);
                           }
                           
void sift(PriorityQueue paqa,  int size,int p)
{
     DataType temp=paqa->pq[p];
     i=p;child=2*i+1;
     while(child<size)
     {
                      if (child<size-1&&paqa->pq[child].key>paqa->pq[child+1].key
                      child=child+1;
                      if(temp<paqa->pq[child].key)
                      {
                                                  paqa->pq[i]=paqa->pq[child];
                                                  i=child;child=2*i+1;                      
                      }
                      else break;
     }
     paqa->pq[i]=temp;
} 

     
     
     
     
     
     }
void removeMin_heap(PriorityQueue papq){
int s;
if(isEmpty_heap(papa)){printf(��Empty!\n��);return;}
s=--paqu->n;
papq->pq[0]=papq->pq[s];
/*��ɾ��,����� ��Ԫ���ƶ����� ��λ�� һ��Ԫ���ƶ�����һ��λ��*/
sift(papq,s,0);
/*��papq��ָ����ȫ�������Ӹ�������Ϊ��*/
}

