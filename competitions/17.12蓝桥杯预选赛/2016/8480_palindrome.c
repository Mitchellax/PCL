/*
 * 描述
 * 
 *     回文指一个顺着读和反过来读都一样的字符串，比如a是回文， madam是回文，aaa是回文，adda也是回文；而add不是回文。
 * 输入
 *     输入的第一行是1个整数m，表示以下会有m行字符串。每个字符串不超过30个字符，且不含空格。
 * 输出
 *    对应行的字符串如果是回文，则输出YES，否则输出NO。
 * 
 * 样例输入
 * 
 *    4
 *    aba
 *    cdx
 *    moom
 *    7a7
 * 
 * 样例输出
 * 
 *    YES
 *    NO
 *    YES
 *    YES
 */

#include <stdio.h>
#include <memory.h>
#include <string.h>

int judge(int low, int high, char *str, int length)  
{  
    if (length == 0 || length == 1)  
        return 1;  
    if (str[low] != str[high])  
        return 0;  
    return judge(low+1, high-1, str, length-2);  
}

int main(int argc, char const *argv[])
{
    char str[30];
    int m, i;
    scanf("%d", &m);
    for (i = 0; i < m; ++i)
    {   
        memset(str, 0, sizeof(str));
        scanf("%s", &str);
        if(judge(0, strlen(str) - 1, str, strlen(str)))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}