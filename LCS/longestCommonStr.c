#include <stdio.h>
#include <string.h>
#include <malloc.h>

char *longestCommonStr(char *strA, char *strB)
{
    int lenA, lenB, i, m, n, mIdx, nIdx, maxIdx, maxVal;
    lenA = strlen(strA);
    lenB = strlen(strB);

    //初始化，分配内存
    int** info = (int**)malloc(sizeof(int*) * (lenA + 1));
    for(i=0; i<=lenA; i++)
    {
        info[i] = (int*)calloc((lenB + 1), sizeof(int));
    }

    //计算最长公共子串
    m = 0;
    while((m)<lenA)
    {
        mIdx = m + 1;
        n = 0;
        while((n)<lenB)
        {
            nIdx = n + 1;
            if(*(strA+m) == *(strB+n))
            {
                info[mIdx][nIdx] = info[mIdx-1][nIdx-1] + 1;
            }else
            {
                info[mIdx][nIdx] = 0;
            }
            n++;
        }
        m++;
    }

    //格式化输出
    printf("%c  %c  ", '*', '*');
    while(0!=*strB)
    {
        printf("%c  ", *strB);
        strB++;
    }
    printf("\n\n");
    m = 0;
    for(; m<=lenA; m++)
    {
        if(0==m)
            printf("%c  ", '*');
        else
            printf("%c  ", *(strA+m-1));
        n = 0;
        for(; n<=lenB; n++)
        {
            printf("%d  ", info[m][n]);
        }
        printf("\n");
    }

    //计算最长公共字符串
    maxIdx = 0;
    maxVal = 0;
    m = 1;
    for(; m<=lenA; m++)
    {
        n = 1;
        for(; n<=lenB; n++)
        {
            if(info[m][n]>maxVal)
            {
                maxIdx = m;
                maxVal = info[m][n];
            }
        }
    }

    char* ret = (char*)malloc(sizeof(char)*(maxVal+1));
    m = maxIdx - maxVal;
    n = 0;
    while(m<=maxIdx)
    {
        ret[n] = *(strA+m);
        m++;
        n++;
    }
    ret[maxVal] = 0;
    return ret;
}

int main()
{
    printf("%s\n", longestCommonStr("asdasdas", "jasdasd"));
    return 0;
}
