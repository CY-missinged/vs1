#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXSIZE 100

/*商品信息结构体类型定�?*/
typedef struct goodstype
{
   long int num;
   char name[20];
   float price;
   int stock;
} DataType;

typedef long int KeyType;
/*KeyType为查找关键字类型*/

/*顺序表结构体类型定义*/
typedef struct
{
   DataType data[MAXSIZE + 1]; //存放线性表元素
   int len;                    //存放线性表表长
} SeqList;

/*菜单函数*/
int menu()
{
   int ch;
   printf("*****************************************\n");
   printf("*    1------------输入初始商品信息�?    *\n");
   printf("*    2------------显示商品信息�?        *\n");
   printf("*    3------------插入新商品信�?        *\n");
   printf("*    4------------删除指定位置商品信息  *\n");
   printf("*    5------------查找指定编号商品信息  *\n");
   printf("*    0------------退出商品信息管理程�?  *\n");
   printf("*****************************************\n");
   printf("请输入你的选择:(0-5)\n");
   scanf("%d", &ch);
   return (ch);
}

//从无到有构造一个空的顺序表
SeqList *Init_SeqList()
{
   SeqList *L;
   L = (SeqList *)malloc(sizeof(SeqList));
   L->len = 0; //空表的表长为0
   return L;
}

/*输入函数*/
void input(SeqList *L)
/*完成商品信息表的输入，即线性表的建立。以输入的商品编号为-1标识输入的结�?*/
{
   long tnum;
   int n = 0;
   printf("输入商品编号:");
   scanf("%ld", &tnum);
   while (tnum != -1)
   {
      n++;
      L->data[n].num = tnum;
      printf("输入商品名称:");
      scanf("%s", (L->data[n]).name);
      printf("输入商品单价:");
      scanf("%f", &(L->data[n].price));
      printf("输入商品库存�?:");
      scanf("%d", &(L->data[n].stock));
      printf("输入商品编号:");
      scanf("%ld", &tnum);
   }
   L->len = n;
}

/*输出函数*/
void output(SeqList *L)
{
   int i;
   printf("    编号           名称      单价   库存量\n");
   for (i = 1; i <= L->len; i++)
      printf("%6ld%16s%10.2f%6d\n", L->data[i].num, L->data[i].name, L->data[i].price, L->data[i].stock);
}

/*删除函数，实现在顺序表上的第i个位置上删除元素的功�?*/
int Delete_SeqList(SeqList *L, int i, DataType *px) //删除表中第i个元�?
{
   int j;
   if (L->len == 0)
   {
      printf("表为�?! ");
      return 0;
   } //返回0表示删除失败
   if (i < 1 || i > L->len)
   {
      printf("删除位置�?! ");
      return 0;
   }
   *px = L->data[i];                 //将待删除元素的值传回主调函�?
   for (j = i + 1; j <= L->len; j++) //元素依次前移
      L->data[j - 1] = L->data[j];
   L->len--; //表长�?1
   return 1; //返回1表示删除成功
}

/*查找函数，实现在顺序表上查找编号为tnum的商品信�?*/
int Locate_SeqList(SeqList *L, KeyType x)
{
   int i;
   i = L->len;
   while (i > 0 && L->data[i].num != x)
      i--;
   return i;
}

/*插入函数，实现在顺序表上的第i个位置上插入新元素x的功�?*/
int Insert_SeqList(SeqList *L, int i, DataType x) //在表L中第i个位置插入新元素x
{
   int j;
   if (L->len == MAXSIZE)
   {
      printf("表满，溢�?!");
      return 0;
   } //返回0表示插入失败
   if (i < 1 || i > L->len + 1)
   {
      printf("插入位置不合�?!");
      return 0;
   }
   for (j = L->len; j >= i; j--)
      L->data[j + 1] = L->data[j]; //元素依次后移
   L->data[i] = x;                 //插入x到第i个位�?
   L->len++;                       //表长�?1
   return 1;                       //返回1表示插入成功
}

/*本程序为一个简单的商品信息管理程序*/
int main()
{
   SeqList *L;
   DataType x;
   int k, j;
   int ch;
   long s_num;
   L = Init_SeqList();
   ch = 1;
   while (ch != 0)
   {
      ch = menu();
      switch (ch)
      {
      case 1:
         input(L);
         break;
      case 2:
         output(L);
         break;
      case 3:
         printf("输入新商品的插入位置:");
         scanf("%d", &k);
         printf("输入新商品的编号 名称 单价 库存�?:");
         scanf("%ld %s %f %d", &x.num, x.name, &x.price, &x.stock);
         //调用插入函数插入新商品信息并输出新商品信息表
         j = Insert_SeqList(L, k, x);
         if (j == 0)
            printf("插入失败!\n");
         else
         {
            printf("新商品已成功插入！\n");
            output(L);
         }
         break;
      case 4:
         printf("输入删除位置:");
         scanf("%d", &k);
         j = Delete_SeqList(L, k, &x);
         if (j == 1)
         {
            printf("%ld %s %.2f %d\n", x.num, x.name, x.price, x.stock);
            printf("该商品信息已经成功删�?!\n");
            output(L);
         }
         else
            printf("删除失败！\n");
         break;
      case 5:
         printf("输入待查商品的编�?:");
         scanf("%ld", &s_num);
         k = Locate_SeqList(L, s_num);
         if (k == 0)
            printf("未找到该商品信息!\n");
         else
         {
            printf("    编号           名称      单价   库存量\n");
            printf("%6ld%16s%10.2f%6d\n", L->data[k].num, L->data[k].name, L->data[k].price, L->data[k].stock);
         }
      } /*switch*/
      printf("按任意键继续......\n");
      getchar();
      getchar();
      system("cls");
   } /*while*/
   return 0;
}
