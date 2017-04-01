
#include"southair.h"



using namespace std;
//相亲数
/*
如果对于两个大于 1 的正整数 x 和 y，x 除了本身以外的因子之和等于 y，y 除了本身以外的
因子之和等于 x，则称 x 和 y 是一对相亲数。
比如 220 除了本身以外的因子之和 110+55+44+22+20+11+10+5+4+2+1=284，而 284 除了
本身以外的因子之和 142+71+4+2+1=220，则 220 和 284 就是一对相亲数。
请你编写一个程序计算 x 和 y 分别除了本身以外的因子之和，并判断 x 和 y 是不是一对相亲
数。x 和 y 为大于 1 的 int 范围内的整数。
入】x 和 y，空格隔开。
【输出】
第一行输出 x，一个逗号，x 的除了本身以外的因子之和的计算过程（见题意，要求降序输出
每个因子） ，不要有多余的空格。
第二行输出 y，一个逗号，y 的除了本身以外的因子之和的计算过程（见题意，要求降序输出
每个因子） ，不要有多余的空格。
第三行，如果 x 和 y 是一对相亲数输出 1，否则输出 0。文末换行可有可无。
*/
void KinsfolkNumber(int num, int num1)
{
	int a = num / 2;
	int num_re = 0;
	int num1_re = 0;
	while (a>0)
	{
		if ((num%a) == 0)
		{
			printf("%d+", a);
			num_re += a;
		}
		--a;
	}

	printf("\n");

	a = num1 / 2;
	while (a>0)
	{
		if ((num1%a) == 0)
		{
			printf("%d+", a);
			num1_re += a;
		}
		--a;
	}

	printf("\n");


	if (num == num1_re&&num1 == num_re)
	{
		printf("是相亲数\n");
	}



}
//坐标位置
struct _coord {
	unsigned int x;//x的位置
	unsigned int y;//y的位置
};
typedef struct _coord Coord;
//窗体
struct _form {
	Coord LCoord;//左下角坐标
	Coord RCoord;//右上角坐标
	int OrderId;//窗口编号
	int Rank;
};
typedef struct _form MyForm;

//模拟窗口点击
/*
二、窗口点击模拟
【题意】
在计算机屏幕上，有 N 个窗口。窗口的边界上的点也属于该窗口。窗口之间有层次的区别，
在多于一个窗口重叠的区域里，只会显示位于顶层的窗口里的内容。当你用鼠标点击某个点
的时候，若其在窗口内，你就选择了处于被点击位置所属的最顶层窗口，并且这个窗口就会
被移到所有窗口的顶层，而剩余的窗口的层次顺序不变，如果你点击的位置不属于任何窗口
计算机就会忽略你这次点击。编写一个程序模拟点击窗口的过程：先从标准输入读入窗口的
个数，窗口编号和位置（以窗口的左上角和右下角的坐标表示，先输入的窗口层次高） ，然后
3
读入点击的次数和位置 （以点击的坐标表示） ， 编写程序求得经过上述点击后的窗口叠放次序。
【假设】 ：
1、屏幕左下角作为 X 轴和 Y 轴坐标原点，即坐标为（0，0） ，所有输入的坐标
数值都是整数，并且都大于等于 0，小于等于 1000。
2出窗口的叠放次序时从最后点击后最顶层的窗口编号开始按层次依次输出；
3、输入的窗口个数大于 0 并且小于等于 10，点击次数大于 0 并且小于等于 20。
【输入】
第一行窗口个数 n，接下来 n 行每行一个窗口的编号、左下角坐标、右上角坐标。
接下来一行点击次数 k，接下来 k 行每行一个点击坐标。
【输出】
一行 n 个数字，表示 K 次点击后按层次排列的窗
*/
void SumulateFormsClick()
{
	int FormCount = 0;
	int i = 0;
	printf("窗口个数\n");
	scanf("%d", &FormCount);
	printf("每个窗口的编号,左下角坐标(x,y)，右上角坐标(x,y)。（以空格区分）\n");
	MyForm* p_Forms = (MyForm*)calloc(FormCount, sizeof(MyForm));
	if (NULL == p_Forms)
	{
		return;
	}
	
#if 1 
	/*
	for ( i = 0; i < FormCount; ++i)
	{
		scanf("%d%d%d%d%d", &(p_Forms[i].OrderId), &(p_Forms[i].LCoord.x), &(p_Forms[i].LCoord.y), &(p_Forms[i].RCoord.x), &(p_Forms[i].RCoord.y));
		p_Forms[i].Rank=i;//权限
	}
	*/
	p_Forms[0].OrderId = 1, (p_Forms[0].LCoord.x = 4), p_Forms[0].LCoord.y = 7, p_Forms[0].RCoord.x = 19, p_Forms[0].RCoord.y = 17, p_Forms[0].Rank = 1;
	p_Forms[1].OrderId = 2, (p_Forms[2].LCoord.x = 9), p_Forms[2].LCoord.y = 1, p_Forms[2].RCoord.x = 20, p_Forms[2].RCoord.y = 10, p_Forms[2].Rank = 2;
	p_Forms[2].OrderId = 3, (p_Forms[1].LCoord.x = 12), p_Forms[1].LCoord.y = 4, p_Forms[1].RCoord.x = 13, p_Forms[1].RCoord.y = 3, p_Forms[1].Rank = 3;
	vector<MyForm> myforms;
	myforms.push_back(p_Forms[0]);
	myforms.push_back(p_Forms[1]);
	myforms.push_back(p_Forms[2]);
	/*
	for (i = 0; i < FormCount; ++i)
	{
		//int id= 0, lx = 0, ly = 0;
		printf("编号%d 左下角坐标：%d，%d 右下角坐标：%d，%d\n", (p_Forms[i].OrderId), (p_Forms[i].LCoord.x), (p_Forms[i].LCoord.y), (p_Forms[i].RCoord.x), (p_Forms[i].RCoord.y));
	}
	*/
#endif//窗口个数
#if 1 
	int ClickCount = 0;
	printf("点击次数\n");
	scanf("%d", &ClickCount);
	Coord* p_Coords = (Coord*)calloc(ClickCount, sizeof(Coord));

	for (i = 0; i < ClickCount; ++i)
	{
		printf("点哪了？还剩%d次\n", ClickCount - i - 1);
		scanf("%d%d", &(p_Coords[i].x), &(p_Coords[i].y));
	}

#endif //点击次数
#if 1 

	MyForm top = p_Forms[FormCount - 1];

	vector<MyForm> vec;
	for (i = 0; i < ClickCount; ++i)
	{
		int formindex = 0;
		for (formindex; formindex < FormCount; ++formindex)
		{
			if (p_Coords[i].x >= p_Forms[formindex].LCoord.x&&p_Coords[i].y <= p_Forms[formindex].RCoord.y)
			{
				if (top.Rank == p_Forms[formindex].Rank)
				{
					printf("点%d上了\n", top);
					return;
				}
				else
				{
					vec.push_back(p_Forms[formindex]);
				}
			}
		}
	}
	if (!vec.empty())
	{
		MyForm Backup = top;
		for (vector<MyForm>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			if (top.Rank < it->Rank)
			{
				top = *it;
			}
		}
		printf("点%d上了\n", top.OrderId);
		

	}
	


#endif // 1 判断点击的位置处于哪个窗口












	if (NULL != p_Forms)
	{
		free(p_Forms);
	}if (NULL != p_Coords)
	{
		free(p_Coords);
	}
}


int JieCheng(int n)
{
	int result = 1;
	while (n > 1)
	{
		result *= n;
		n--;
	}
	
	return result;
}


void JieChengNum(int num)
{
	int result = 0;
	if (num < 0)
	{
		return;
	}
	if(num % 10 != 0)
	{
		JieChengNum(num / 10);
	}
	if (num>0)
	{
		printf("%d! =%d  ", num%10, JieCheng(num%10));
	}
	
}


//输出矩阵
void PrintMatrix(size_t length, size_t width,char c)
{
	for (int i = 0; i < width; ++i)
	{
		int tmp = length;
		while (tmp)
		{
			printf("%c ", c);
			--tmp;
		}
		printf("\n");
	}



}




void BestLenSubString(char str[], char substr[])
{

}

//LCS问题就是求两个字符串最长公共子串的问题
char* LCS(char left[], char right[])
{
	//获取左子串的长度,获取右子串的长度
	int lenLeft = strlen(left), lenRight = strlen(right), k;
	//注意这里要写成char型,而不是int型,否则输入整型数据时会产生错误。
	//矩阵c纪录两串的匹配情况
	char*c = (char*)calloc(lenRight,sizeof(char)), *p;
	//int c[M][M]={0};//当将c申明为一个二维数组时
	int start, end, len, i, j;//start表明最长公共子串的起始点，end表明最长公共子串的终止点
	end = len = 0;//len表示最长公共子串的长度

	for (i = 0; i<lenLeft; i++) //串1从前向后比较
	{
		//串2从后向前比较,为什么要从后向前呢?是把一维数组c[ ]当二维数组来用,
		//如果要从前向后,可以将c申明为一个二维数组c[M][M].但程序要做相应调整.
		// for(j=0;j<lenRight;j++)//当c申明为一个二维数组时
		for (j = lenRight - 1; j >= 0; j--)
		{
			if (left[i] == right[j])//元素相等时
			{
				if (i == 0 || j == 0)
					c[j] = 1;//c[i][j]=1;
				else
				{
					c[j] = c[j - 1] + 1;//c[i][j]=c[i-1][j-1]+1;
				}
			}
			else
			{
				c[j] = 0;    //c[i][j]=0;
			}
				
			if (c[j] > len)   //if (c[i][j]>len)
			{
				len = c[j];   //len=c[i][j];
				end = j;
			}
		}
	}
	start = end - len + 1;

	//数组p纪录最长公共子串
	p = (char*)malloc(len + 1);
	for (i = start; i <= end; i++)
	{
		p[i - start] = right[i];
	}
	p[len] = '\0';
	return p;
}






void CompareStr(char str1[], char str2[])
{
	size_t s1len = strlen(str1);
	size_t s2len = strlen(str2);
	for (int i = 0; i < s1len; i++)
	{
		char* p = str2;
		while (*p)
		{
			if (*p == str1[i])
			{
				//std::cout << 1<<" ";
				printf("1 ");
			}
			else
			{
				printf("0 ");
			}
			++p;
		}
		std::cout << std::endl;
	}
	
}
































































































