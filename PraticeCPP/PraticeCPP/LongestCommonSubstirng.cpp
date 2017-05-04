
#include"LongestCommonSubstirng.hpp"


void LCS(string str1, string str2)
{
	 int len_s1 = str1.size();
	 int len_s2 = str2.size();
	 int MaxLen = 0,x=-1;
	int Note[100][100] = { {-1,-1} };
	//初始化二维数组
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			Note[i][j] = 0;//初始化的时候要用0  不能用-1  这样会导致第一次缓存左上角的标记的时候少加了一个1. 也可以在最后的结果+1.
		}
	}
	
	//比较字符
	for (int i = 1; i <= len_s1; ++i)//从1开始才会有左上角 从0开始就没有了
	{
		for (int j = 1; j <= len_s2; ++j)
		{
			if (str1.at(i-1) == str2.at(j-1))//比较的时候要从第一个开始比较 所以要各自减一，如果相等 就把结果缓存到它的右下角（即当前坐标的位置）。
			{
				Note[i][j] = Note[i-1][j-1]+1;//当前坐标等于其左上角的数字加1.
				if (Note[i][j]>MaxLen)
				{
					MaxLen = Note[i][j];
					x = i - 1;
				}
				continue;
			}
			Note[i][j] = 0;
		}
	}

	for (int i = 0; i < len_s1; ++i)//从1开始才会有左上角 从0开始就没有了
	{
		for (int j = 0; j < len_s2; ++j)
		{
			cout << Note[i][j] << " ";
		}
		cout << endl;
	}
	cout << "MaxLen:" << MaxLen << endl;
	string ret;
	ret.append(str1, x - (MaxLen - 1), MaxLen);//string 的 append方法 从 str1字串中的x - (MaxLen - 1)开始，加到MaxLen长度

	cout << ret << endl;
	

}



//网上的查找最长子序列的方法
void TestNetLCS(string str1, string str2)
{
	int x_len = str1.length();
	int y_len = str2.length();

	int arr[50][50] = { { 0, 0 } };

	int i = 0;
	int j = 0;

	for (i = 1; i <= x_len; i++)
	{
		for (j = 1; j <= y_len; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{

				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}

		}
	}
	for (i = 0; i <= x_len; i++)
	{
		for (j = 0; j <= y_len; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
	for (i = x_len, j = y_len; i >= 1 && j >= 1;)
	{
		if (str1[i - 1] == str2[j - 1])
		{
			cout << str1[i - 1] << " ";//倒序打印的
			i--;
			j--;
		}
		else
		{
			//  if(arr[i][j -1] >= arr[i - 1][j])//打印：B A D B
			if (arr[i][j - 1] > arr[i - 1][j]) //打印:A B C B
			{
				j--;
			}
			else
			{
				i--;
			}
		}
	}
	cout << endl;
}




/*
以我在第1小节举的例子（S1={1,3,4,5,6,7,7,8}和S2={3,5,7,4,8,6,7,8,2}），并结合上图来说：
假如S1的最后一个元素 与 S2的最后一个元素相等，那么S1和S2的LCS就等于 {S1减去最后一个元素} 与 {S2减去最后一个元素} 的 LCS  再加上 S1和S2相等的最后一个元素。
假如S1的最后一个元素 与 S2的最后一个元素不等（本例子就是属于这种情况），那么S1和S2的LCS就等于 ： {S1减去最后一个元素} 与 S2 的LCS， {S2减去最后一个元素} 与 S1 的LCS 中的最大的那个序列。
*/

/**********
//重点在理解上面这两句话，其实代码很简单 就是对这两句话的映射。 理解的问题的关键是在理解那个公式。其实每个字符和另一个字符的比较可以认为是从0开始至比较字符的长度的字符 和另一个字符的每个长度相比  得出的最长子序列。因为是从第一个字符开始的，所以相当于从零开始。
 1.如果两个串的某个位置出现相等的字符，就是说它是整个字符串最长子序列的一员，同时也是两个字符串截止至此的的位置上最长子序列的最后一位，应该在他的位置做个标记。应该在此位置设为1。此位置的左上角是两个字符串各自减去一个字符长度的最长子序列位置。假如把他们加在一起，加到最后，正好是记录着最长子序列的长度。所以加上此位置相等，所以整体最长子序列的长度要+1；

 2.如果两个串的某个位置的字符不等,就是说两个串截止至此的字串的最长子序列出现在各自减1的位置上。由1可知，在辅助的二维数组上的位置分别为[i-1][j]或者[i][j-1]，所以当前位置依旧需要保存下截至到当前位置的最长子序列长度（选择两个长度中的最大的保存）。假如当前位置的Y轴不变X轴出现了相等的字符 那也不算 因为位置串了。不是子序列。

 3.全部算完以后，最后一个位置保存的一定是两个字符串的最长子序列的的长度。根据上面的两条特性可知，如果二维数组的的最后一个位置的的左上角X,Y坐标的位置的两个字符相等，那最后的长度就是左上角加1后的长度，既然是+1而来的，就是说这个字符也是最长子序列的一员，记录下来。如果左上角不等，那就看[j]和[i][j-1]谁大，谁大就是从谁那继承过来的，记录这个位置的字符,然后依此类推。直到二维数组中X,Y的值等于0，那么就是字序列断了。跳出循环。但是此时的字符是逆序的，需要处理。
**********/

/*
填的规则依据递归公式，简单来说：如果横竖（i,j）对应的两个元素相等，该格子的值 = c[i-1,j-1] + 1。如果不等，取c[i-1,j] 和 c[i,j-1]的最大值。首先初始化该表：
*/
void LCSubSence(string str1,string str2)
{
	int Len_Y = str1.length();
	int Len_X = str2.length();

	int Note[50][50];

	for (int i = 0; i <Len_Y+1; ++i)
	{
		for (int j = 0; j <Len_X+1; ++j)
		{
			Note[i][j] = 0;
		}
	}

	/*
	for (int i = 1; i <=Len_Y; ++i)
	{
		for (int j = 1; j <=Len_X; ++j)
		{
			char c = str1[i - 1];
			char ch = str2[j - 1];
			if (c== ch)
			{
				Note[i][j] = Note[i - 1][j - 1]+1;
			}
			else
			{
				Note[i][j] = max(Note[i - 1][j], Note[i][j-1]);
			}
		}
	}
	*/
	
	for (int i = 1; i <= Len_Y; ++i)//其实每个格子记录的是每个字符串的各个位置与对应字符串位置相比较的最长LCS的长度
	{
		for (int j = 1; j <= Len_X; ++j)
		{   //从1开始计算 为了空出横竖两排0  但是比较要从0开始
			if (str1.at(i - 1) == str2.at(j - 1))//两者相等就意味着 至此处两个字符串的最长子序列为 各自前一个字符的最长子序列加上这个字符 str1.at(i - 1)和str2.at(j - 1)的LCS长度等于他们各自减1后的LCS+1
			{
				Note[i][j] = Note[i-1][j-1] + 1;//等于各自前一个字串的LCS长度+1
			}
			else//如果不相等 此处的最长子序列就应该是 {此处}的str-1与 {此处}str2的最长子序列或者 {此处}的str2-1与{此处}的str-1的子序列比较的最大值
			{
				Note[i][j] = max(Note[i - 1][j], Note[i][j - 1]);
			}
		}
	}



	for (int k = 0; k <=Len_Y; ++k)//因为上面是从1开始计算，所以相当于把整个矩阵上，左各偏移了一个数字，所以要打印len+1长度 要不打印不全
	{
		for (int j =0; j <=Len_X; ++j)
		{
			cout<<Note[k][j] <<"  ";
		}
		cout << endl;
	}


	//截至到最后一个字符 就是记录的两个字符串的最长公共子序列
	int MaxLen = Note[Len_Y ][Len_X ];

	cout << "最长子序列的长度是：" << MaxLen << endl;

	//查找子序列的值
	int Y = Len_Y, X = Len_X,tmpval=MaxLen;
	while (Note[Y][X]>0)
	{
		if (str1.at(Y-1) == str2.at(X-1))//相等就是说当前的长度值来自它的左上角
		{
			cout << str1.at(Y-1) << " ";
			--Y; --X;//位置各自减1 即变为左上角的坐标
		}
		else//不相等就是说 它的值来自它的正上方或者正上方的左面
		{
			int t = Note[Y - 1][X];
			int tt = Note[Y][X-1];
			if ( t>= tt)
			{
				Y -= 1;
			}
			else
			{
				X -= 1;
			}
		}
	}
	
	



}



























































































