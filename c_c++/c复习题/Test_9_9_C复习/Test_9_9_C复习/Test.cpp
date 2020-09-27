#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>

#define ID_LEN   32
struct STR_A
{
	char aucID[ID_LEN];
	int iA;
};
struct STR_B
{
	char *paucID;
	int iB;
};
void funcA(struct STR_A stA, struct STR_B *pstB)
{
	pstB->paucID = stA.aucID;
}
void main()
{
	STR_A stA = { 0 };
	STR_B stB;

	strcpy(stA.aucID, "12345");
	funcA(stA, &stB);
	printf("%s\n", stB.paucID);
}



/*
void AddFunc(unsigned int a, unsigned int b, unsigned int *c)
{
	*c = a + b; //300  255
}
void main()
{
	unsigned char e = 20;
	unsigned char f = 100;
	unsigned char g = 0;

	AddFunc((unsigned int)e, (unsigned int)f, (unsigned int*)&g);

	printf("%d", g);
}


/*
void VarInit(unsigned long *pucArg)
{
	*pucArg = 1;
	return;
}
void main()
{
	unsigned long ulGlobal;
	VarInit((unsigned long*)&ulGlobal);
	printf("%lu\n", ulGlobal);
	return;
}


/*
#pragma pack(4)
int main()
{
	unsigned char puc[4];
	struct tagPIM
	{
		unsigned char ucPim1;
		unsigned char ucData0 : 1;
		unsigned char ucData1 : 2;
		unsigned char ucData2 : 3;
	}*pstPimData;

	pstPimData = (struct tagPIM*)puc;
	memset(puc, 0, 4);
	pstPimData->ucPim1 = 2;
	pstPimData->ucData0 = 3;
	pstPimData->ucData1 = 4;
	pstPimData->ucData2 = 5;

	printf("% 02x % 02x % 02x % 02x\n",  puc[0], puc[1], puc[2], puc[3]);
	return 0;
}
#pragma pack() /*恢复缺省对齐方式*/


/*
#pragma pack(4)
union tagAAAA
{
	struct
	{
		char ucFirst;   //1+1
		short usSecond; //2
		char ucThird;   //1+1
	}half;
	short kk;
}number;

struct tagBBBB
{
	char ucFirst;   //1+1
	short usSecond; //2
	char ucThird;   //1+1
	short usForth;  //2
}half;

struct tagCCCC
{
	struct
	{
		char ucFirst;   //1+1
		short usSecond; //2
		char ucThird;   //1+1 + 2
	}half;
	long kk;  //4
};

void main()
{
	printf("%d\n", sizeof(union tagAAAA));
	printf("%d\n", sizeof(struct tagBBBB));
	printf("%d\n",sizeof(struct tagCCCC));
}


/*
int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}
void main()
{
	int j = 4;
	int m = 1;
	int k;
	k = fun(j, m);
	printf("%d\n", k);  //

	k = fun(j, m);
	printf("%d\n", k);  //
	return;
}


/*
#pragma pack(4)

struct tagAAA
{
	unsigned char ucld : 1;
	unsigned char ucPara0 : 2;  //1
	unsigned char ucState : 6;  //1
	unsigned char ucTail : 4;   //1
	unsigned char ucAvail;      //1
	unsigned char ucTail2 : 4;  //1
	unsigned char ucData;       //1 
}AAA_S;

void main()
{
	//问：AAA_S在分别为1字节对齐和四字节对齐的情况下，占用的空间大小是：______
	printf("%d\n" ,sizeof(AAA_S));
}


/*
#define CHAR char
#define ULONG unsigned long
#define VOID void

CHAR *VOS_strncpy(CHAR *pcDest, const CHAR *szSrc, ULONG ulLength)
{
	CHAR *pcPoint = pcDest;
	if ((NULL == szSrc) || (NULL == pcDest))
	{
		return NULL;
	}
	while (ulLength && (*pcPoint = *szSrc))
	{
		pcPoint++;
		szSrc++;
		ulLength--;
	}
	if (!ulLength)
	{
		*pcPoint = '\0';
	}
	return pcDest;
}
VOID main(VOID)
{
	CHAR szStrBuf[]  = "1234567890";
	CHAR szStrBuf1[] = "1234567890";
	
	strncpy(szStrBuf, "ABC", strlen("ABC"));  //系统函数  "ABC4567890"

	VOS_strncpy(szStrBuf1, "ABC", strlen("ABC")); //ABC\0567890

	printf("Str1 = %s\n Str2 = %s", szStrBuf, szStrBuf1);
}


/*
struct BBB
{
	long lA1; //4
	char cA2; //1
	char cA3; //1+2
	long lA4; //4
	long lA5; //4
}*p;

void main()
{
	p = (struct BBB*)0x100000;
	printf("%p\n", p + 0x1);  //0x100010
	printf("%p\n", (unsigned long)p + 0x1); //0x100001
	printf("%p\n", (unsigned long*)p + 0x1);//0x100004
	printf("%p\n", (char *)p + 0x1); //0x100001
}

/*
#pragma pack(8)

unsigned short *pucCharArray[10][10];
typedef union unRec
{
	unsigned short ullndex;     //4
	unsigned short usLevel[7]; //14 + 2
	unsigned char ucPos;       //1
}REC_S;
REC_S stMax, *pstMax;

void main()
{
	printf("%d\n", sizeof(pucCharArray));  //400
	printf("%d\n", sizeof(stMax));         //16
	printf("%d\n", sizeof(pstMax));        //4
	printf("%d\n", sizeof(*pstMax));       //16
}

/*
int main()
{
	char c;                //-128 ~ 127
	unsigned char uc;      //0 ~ 255
	unsigned short us;     //0 ~ 65535

	c = 128;
	uc = 128;
	us = c + uc;
	printf("0x%x\n", us);   //?0x0

	us = (unsigned char)c + uc; //128 + 128
	printf("0x%x\n", us);   //?0x100

	us = c + (char)uc;    //-128 + -128 = -256
	printf("0x%x\n", us);   //?0xff00
	return 0;
}


/*
void main()
{
	//0~255
	unsigned char a = 200;
	unsigned char b = 100;
	unsigned char c = 0;
	c = a + b;
	printf("%d %d", a + b, c);
	//300 44
}


/*
//心急不能吃热豆腐
#define N 4
#define Y(n) ((N+2)*n) /*这种定义在编程规范中是严格禁止的
则执行语句：z = 2 * (N + Y(5+1));后，z的值为（    ）

            z = 2 * (4 + (4+2) * 6) = 80
			z = 2 * (4 + ((4+2)*5+1)) = 70


/*
void main()
{
	char pc[4] = "abcd";   //a b c d \0 C++
	printf("pc = %s\n", pc);
}

/*
void main()
{
	char pc[4] = "abcd";
	union
	{
		short k;
		char i[2];
	}*s, a;
	s = &a;
	s->i[0] = 0x39;
	s->i[1] = 0x38;
	printf("%x\n", a.k);
}


/*
struct stu
{
	int num;
	char name[10];
	int age;
};
void fun(struct stu *p)
{
	printf("%s\n", (*p).name);
	return;
}
void main()
{
	struct stu students[3] = { { 9801, "zhang", 20 },
	{ 9802, "wang", 19 },
	{ 9803, "zhao", 18 } };
	fun(students + 1);
	return;
}


/*
void main()
{
	Min();
	Max();
}

/*
void main()
{
	unsigned long pulArray[] = {6,7,8,9,10};
	unsigned long *pulPtr;

	pulPtr = pulArray;
	*(pulPtr + 3) += 3;
	printf("%d ,%d\n",*pulPtr, *(pulPtr + 3));
}

/*
void func1(int x)
{
	int a = x;

	{
		int b = 20;
		printf("b = %d\n", b);
	}
	printf("b = %d\n", b);
}

void func2()
{
	int a = 20;
}

void main()
{
	func1(10);
	func2();
}

/*
void RightLoopMove(char *pStr, unsigned short steps)
{
	assert(pStr != NULL && *pStr!='\0');
	int len = strlen(pStr);
	steps %= len;
	for(int i=0; i<steps; ++i)
	{
		char tmp = pStr[len-1];              //空间复杂度O(1)
		for(int end=len-1; end>0; --end)     //时间复杂度O(n^2)
			pStr[end] = pStr[end-1];
		pStr[0] = tmp;
	}
}
void main()
{
	char str[] = "abcdefghi";
	printf("str = %s\n", str);
	RightLoopMove(str, 40);
	printf("str = %s\n", str);
}

/*
void RightLoopMove(char *pStr, unsigned short steps)
{
	assert(pStr != NULL && *pStr!='\0');
	int len = strlen(pStr);
	char *tmp = (char*)malloc(sizeof(char) * (len+1)); //空间复杂度O(n)
	assert(tmp != NULL);

	steps %= len;  //

	strcpy(tmp, pStr+(len-steps));
	strncat(tmp, pStr, len-steps);

	strncpy(pStr, tmp, len);
	free(tmp);
	tmp = NULL;
}
void main()
{
	char str[] = "abcdefghi";
	printf("str = %s\n", str);
	RightLoopMove(str, 20);
	printf("str = %s\n", str);
}

/*
void bit_set(unsigned char *p_data, unsigned char position, bool flag)
{
	assert(p_data != NULL || (position>=1 && position<=8)); //更加完美

	if(flag)  //1
	{
		*p_data |= (0x01<<(position-1));
	}
	else      //0
	{
		*p_data &= ~(0x01<<(position-1));
	}
}
void main()
{
	unsigned char data = 123; //0 ~255  //0111 1011   double
	unsigned char pos = 3;
	bool flag = true;

	bit_set(&data, pos, flag);

	printf("data = %d\n", (int)data);  //0111 1111 ==> 127
}

/*
void bit_set(unsigned char *p_data, unsigned char position, bool flag)
{
	if(flag)  //1
	{
		switch(position)
		{
		case 1:
			*p_data |= 0x01;  //0000 0001
			break;
		case 2:
			*p_data |= 0x02;  //0000 0010
			break;
		case 3:
			*p_data |= 0x04;  //0000 0100
			break;
		case 4:
			*p_data |= 0x08;  //0000 1000
			break;
		case 5:
			*p_data |= 0x10;  //0001 0000
			break;
		case 6:
			*p_data |= 0x20;  //0010 0000
			break;
		case 7:
			*p_data |= 0x40;  //0100 0000
			break;
		case 8:
			*p_data |= 0x80;  //1000 0000
			break;
		}
	}
	else   //0
	{
		switch(position)
		{
		case 1:
			*p_data &= ~0x01;  //~0000 0001 =>1111 1110
			break;
		case 2:
			*p_data &= ~0x02;  //0000 0010
			break;
		case 3:
			*p_data &= ~0x04;  //0000 0100
			break;
		case 4:
			*p_data &= ~0x08;  //0000 1000
			break;
		case 5:
			*p_data &= ~0x10;  //0001 0000
			break;
		case 6:
			*p_data &= ~0x20;  //0010 0000
			break;
		case 7:
			*p_data &= ~0x40;  //0100 0000
			break;
		case 8:
			*p_data &= ~0x80;  //1000 0000
			break;
		}
	}
}
void main()
{
	unsigned char data = 123; //0 ~255  //0111 1011
	unsigned char pos = 4;
	bool flag = false;

	bit_set(&data, pos, flag);

	printf("data = %d\n", (int)data);  //0111 1111 ==> 127
}

/*
void main()
{
	char *str = (char *)malloc(57);
	strcpy(str, "Hello");
	free(str);
	str = NULL; //预防野指针
	if (str != NULL)
	{
		strcpy(str, "C++");
		printf(str);
	}
}


/*
void GetMemory(char **p)
{
		*p = (char *)malloc(57);
		assert(*p != NULL);
}
void main()
{
		char *str = NULL;
		GetMemory(&str);
		strcpy(str,"HelloBIt");
		printf(str);

		free(str);
}


/*
char* GetMemory(void)
{
	char p[] = "HelloBit";
	return p;  //可以被返回
}
void main()
{
	char *str = NULL;
	str = GetMemory();
	printf(str);
}


/*
void GetMemory(char **p)
{
	*p = (char*)malloc(57);
}
void main()
{
	char *str = NULL;
	GetMemory(&str);
	strcpy(str, "HelloBit");
	printf(str);
}



/*
#define MAX_SIZE 255
void main()
{
	unsigned char buff[MAX_SIZE + 1];
	unsigned char i;
	for (i = 0; i <= MAX_SIZE; i++)
	{
		buff[i] = i;
		printf("sssssssssssss\n");
	}
}


/*
char str6[10];  //全局数组

//strlen  sizeof
int main()
{
	char ch = 5;

	char str1[] = "HelloBit";
	printf("len = %d\n", strlen(str1));
	printf("size = %d\n", sizeof(str1));

	char str2[10] = "HelloBit";
	printf("len = %d\n",  strlen(str2)); //
	printf("size = %d\n", sizeof(str2)); //

	char str3[10] ={'H','e', 'l', 'l', 'o', 'B','i','t'};
	printf("len = %d\n",  strlen(str3)); //
	printf("size = %d\n", sizeof(str3)); //

	char str4[] ={'H','e', 'l', 'l', 'o', 'B','i','t'};
	printf("len = %d\n",  strlen(str4)); //
	printf("size = %d\n", sizeof(str4)); //8

	char str5[10];
	for(int i=0; i<5; ++i)
		str5[i] = 'a' + i;
	printf("len = %d\n",  strlen(str5)); //随机
	printf("size = %d\n", sizeof(str5)); //

	for(int i=0; i<5; ++i)
		str6[i] = 'a' + i;
	printf("len = %d\n",  strlen(str6)); //5
	printf("size = %d\n", sizeof(str6)); //10

	char str7[10];
	for(int i=0; i<5; ++i)
		str7[i] = '0';  //'0'   '\0'
	printf("len = %d\n",  strlen(str7)); //随机
	printf("size = %d\n", sizeof(str7)); //10

	char str8[10];
	for(int i=0; i<5; ++i)
		str8[i] = 0; //str8[i] = '\0';  //'0'   '\0'   // '\0'==0
	printf("len = %d\n",  strlen(str8)); //随机
	printf("size = %d\n", sizeof(str8)); //10

	short *par[10][10]; //数组 10*10=100  short*=4
	printf("size = %d\n", sizeof(par));  //400

}
/*
int func( int a[] )
{
	//如果函数func参数传递数组Array,那么sizeof(a)呢？
	printf("%d\n", sizeof(a));  //4
	return 0;
}

void main()
{
	char str[] = "Welcome to Bit";
	int Array[] = {1,2,3,4,5,6,7,8,9};
	char *p = str;
	int  n;
	
	printf("len = %d\n",strlen(str));   //14
	printf("size = %d\n",sizeof(str));  //15
	printf("%d\n",sizeof(Array));       //36
	printf("%d\n", sizeof(p));          //4
	printf("%d\n",sizeof(n));           //4
	
	func(Array);

}
*/