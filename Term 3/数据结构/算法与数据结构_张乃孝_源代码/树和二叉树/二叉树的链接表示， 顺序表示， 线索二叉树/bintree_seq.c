/* ��������˳���ʾ*/

#define  MAXNODE    20
typedef int DataType;
struct SeqBTree	{ 			/* ˳�������Ͷ��� */
    int       n;			/* �������ȫ�������󣬽��ĸ��� */
    DataType  nodelist[MAXNODE];
};

typedef  struct SeqBTree  *PSeqBTree;

int root_seq(PSeqBTree t) {
    return t->nodelist[0];
}

int parent_seq(PSeqBTree t, int p) {
    return t-> nodelist[(p-1)/2];
}

int leftChild_seq(PSeqBTree t, int p) {
    return t-> nodelist[2*p+1];
}

int rightChild_seq(PSeqBTree t, int p) {
    return t-> nodelist[2*(p+1)];
}

int main() {
    return 0;
}
