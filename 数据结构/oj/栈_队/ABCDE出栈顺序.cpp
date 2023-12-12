#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef char DataType;

typedef struct
{
    DataType data[MAXSIZE];
    int top;
} SeqStack;

SeqStack *InitStack() //��ʼ��ջs����Ϊ��ջ
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

int StackEmpty(SeqStack *s)
{ //�ж�s�Ƿ�Ϊ��ջ����Ϊ��ջ������1�����򷵻�0
    return s->top == -1;
}

int Push(SeqStack *s, DataType x)
{
    if (s->top == MAXSIZE - 1) //ջ��
    {
        printf("ջ����!\n");
        return 0; //��ջʧ�ܷ���0
    }
    s->top++;            //ջ��ָ������1
    s->data[s->top] = x; //����Ԫ�ظ�ֵ��ջ���ռ�
    return 1;            //��ջ�ɹ�����1
}

int Pop(SeqStack *s, DataType *px)
{
    if (StackEmpty(s))
    {
        printf("pջ��!\n");
        return 0; //��ջʧ�ܷ���0
    }
    *px = s->data[s->top]; // ��ջ��Ԫ�ظ�ֵ��pxָ��ı���
    s->top--;              // ջ��ָ���1
    return 1;              //��ջ�ɹ�����1
}

int GetTop(SeqStack *s, DataType *px)
{
    if (StackEmpty(s))
    {
        // printf("Gջ��!\n");
        return 0; //��ȡջ��Ԫ��ʧ�ܷ���0
    }
    *px = s->data[s->top]; // ��ջ��Ԫ�ظ�ֵ��pxָ��ı���
    return 1;              //��ջ��Ԫ�سɹ�����1
}

int JudgeSerial(char str[], int n)
{                              //������Ϊn���ַ�����str��Ӧ������ȷ�ĳ�ջ���У�����1�����򷵻�0
    SeqStack *s;               // sΪ˳��ջָ��
    char x;                    // x���ڱ����ջԪ�ػ��ȡ��ջ��Ԫ��
    char c[MAXSIZE] = "ABCDE"; // c���ڱ����ջ���ַ�����
    int i = 0, j = 0;          // i,j�ֱ����ڿ������ַ�����c��str�еĵ�ǰɨ��λ��
    //����ɨ��c��str�е��ַ����Ƚ�ջ��Ԫ��x��str��ǰ�ַ���ֵ
    //�����߲���ȣ���c��ǰ�ַ���ջ������c�е�ǰ�ַ�λ��
    //��������ȣ����ջ������str��ǰ�ַ�λ��
    s = InitStack();
    Push(s, c[i]);
    printf("%c��ջ\n", c[i]);
    for (i = 1, j = 0; i < 5, j < n;)
    {
        // printf("i:%d,j:%d\n", i, j);
        if (i > 5 || j > 5)
            break;
        if (GetTop(s, &x) == 0)
        {
            if (i >= 5)
            {
                break;
            }
            Push(s, c[i]);
            printf("%c��ջ\n", c[i]);
            i++;
            continue;
        }
        GetTop(s, &x);
        if (x == str[j])
        {
            Pop(s, &x);
            printf("%c��ջ\n", x);
            j++;
        }
        else
        {
                        if (i >= 5)
            {
                break;
            }
            Push(s, c[i]);
            printf("%c��ջ\n", c[i]);
            i++;
        }
        // system("pause");
    }
    if (StackEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    //ɨ�����ʱ��������str�е��ַ���˳����ջ����˵����Ϊ��ȷ�ĳ�ջ����
}

int main()
{
    char str[MAXSIZE];
    int n = 5;
    //������жϵ��ַ�����
    scanf("%s", str);
    if (JudgeSerial(str, n))
        printf("%s��һ����ȷ�ĳ�ջ����\n", str);
    else
        printf("%s����һ����ȷ�ĳ�ջ����\n", str);
    return 0;
}
