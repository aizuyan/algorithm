#include <stdio.h>
#include <malloc.h>

typedef enum {
    false, 
    true
} bool;

/**
 * 保存堆的结构体
 *
 * size int 保存的数据量
 * heap int[] 保存数据的地方
 */
typedef struct _Heap
{
    int size;
    int *heap;
} Heap;

Heap* initHeap(int num);
int parentIdx(int nodeIdx);
int leftChildIdx(int nodeIdx);
int rightChildIdx(int nodeIdx);
bool insertHeap(Heap *heap, int val);
void printHeap(Heap* heap, int size);
bool deleteHeap(Heap *heap, int pos);

int main()
{
    Heap* heap = initHeap(100);
    int i = 0;

    int num[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
    for(; i<9; i++)
    {
        insertHeap(heap, num[i]);
    }
    printHeap(heap, 10);
    insertHeap(heap, 85);
    printHeap(heap, 10);
    deleteHeap(heap, 0);
    printHeap(heap, 10);
    return 0;
}

/*-------------------------------+
| 初始化堆                       |
|                                |
| 参数: int num 堆的大小         |
+-------------------------------*/
Heap* initHeap(int num)
{
    Heap* heap = (Heap *)malloc(sizeof(Heap));
    if(NULL == heap)
    {
        printf("分配内存失败！\n");
        return NULL;
    }
    heap->heap = NULL;
    heap->size = 0;

    heap->heap = (int *)malloc(sizeof(int) * num);
    if(NULL == heap->heap)
    {
        free(heap);
        printf("分配内存失败!\n");
        return NULL;
    }

    return heap;
}

/*-------------------------------+
| 插入数据到堆中                 |
|                                |
| 参数: heap 堆结构体            |
| 参数: val 结构体中元素数量     |
+-------------------------------*/
bool insertHeap(Heap *heap, int val)
{
    int node, parentNode,tmp;
    heap->heap[heap->size] = val;
    node = heap->size;

    while(node>0)
    {
        parentNode = parentIdx(node);
        if(heap->heap[node] < heap->heap[parentNode])
        {
            break;
        }
        tmp = heap->heap[node];
        heap->heap[node] = heap->heap[parentNode];
        heap->heap[parentNode] = tmp;
        node = parentNode;
    }

    heap->size++;
    return true;
}

bool deleteHeap(Heap *heap, int pos)
{
    int leftNode, rightNode, node, tmp;
    heap->heap[pos] = heap->heap[heap->size - 1];
    heap->heap[heap->size - 1] = 0;
    heap->size--;
    node = pos;
    leftNode = 0;
    rightNode = 0;

    while(leftNode<heap->size || rightNode<heap->size)
    {
        leftNode = leftChildIdx(node);
        rightNode = rightChildIdx(node);
        if(heap->heap[node]>=heap->heap[leftNode] && heap->heap[node]>=heap->heap[leftNode])
            break;
        if (heap->heap[leftNode] >= heap->heap[rightNode])
        {
            tmp = heap->heap[leftNode];
            heap->heap[leftNode] = heap->heap[node];
            heap->heap[node] = tmp;
            node = leftNode;
        } else
        {
            tmp = heap->heap[rightNode];
            heap->heap[rightNode] = heap->heap[node];
            heap->heap[node] = tmp;
            node = rightNode;
        }
    }

    return true;
}

int parentIdx(int nodeIdx)
{
    return (nodeIdx - 1) /2;
}

int leftChildIdx(int nodeIdx)
{
    return nodeIdx * 2 + 1;
}

int rightChildIdx(int nodeIdx)
{
    return nodeIdx * 2 + 2;
}

void printHeap(Heap* heap, int size)
{
    int i = 0;
    for(; i < size; i++)
    {
        printf("%d ",heap->heap[i]);
    }
    printf("\n");
}
