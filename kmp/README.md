## 字符串查找算法KMP


### 一, 正常字符串匹配的算法

一个一个匹配不对就从头从新再来匹配这样的算法

例子:

在字符串A = 'ababacabcdab'中找出 字符串B = 'acab'的过程

主串和模式串匹配的过程

|第一趟|a|b|a|b|a|c|a|b|c|d|a|b|
|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
|失败|a|c||||||
|第二趟|a|b|a|b|a|c|a|b|c|d|a|b|
|失败||a|||
|第三趟|a|b|a|b|a|c|a|b|c|d|a|b|
|失败|||a|c|
|第四趟|a|b|a|b|a|c|a|b|c|d|a|b|
|失败||||a|
|第五趟|a|b|a|b|a|c|a|b|c|d|a|b|
|成功|||||a|c|a|b| 


```
#include <stdio.h>
#include <stdlib.h>

int search(char ** str, char ** p)
{

	char * ptr = *str;
	char * p_str = * p;

	int dst_len = strlen(ptr);
	int str_len = strlen(p_str);
	int i = 0, j = 0;
	while (i < dst_len && j < str_len)
	{
		if (*ptr == * p_str)
		{
			++ptr;
			++p_str;
			++i
		}
		else 
		{
			++j;
			p_str = *p;
			ptr = *str;
			ptr = ptr + j;
			i = j;
		}
	}
	
	if (i > dst_len)
	{
		return j;
	}

	return  0;
}

int main(int argc, char * argv[])
{

	char * str = "abababcdfd";
	char * ptr = "abcd";
	if (search(&str, &ptr))
	{
		printf("[ok]\n");
	}
	else 
	{
		printf("[no]\n");
	}
	return 0;
}
```




