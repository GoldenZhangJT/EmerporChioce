#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include <string.h>
//#pragma comment(lib,"Winmm.lib")

#define N 6 //����N��ʾ��ǰϵͳҪ���������Ӹ���

int main()
{
    /*
        ��Ϸ����
        > ��Ϸһ������10�죻
        >ÿ�����øжȣ�һ�������������ϵ������øжȵ���60���������ң���Ϸ������

    */
    //PlaySound(TEXT("sounds \\ Victory.wav "),NULL, SND_FILENAME | SND_ASYNC | SND_RESOURCE | SND_LOOP);
    //printf("Hello world!\n");

    char emperorName[50];                //ʹ���ַ������ʾ�ʵ�����
    int choice;                          //�ʵ۵�ѡ��
    int i;                               //ѭ������
    int count =5;                        //��ǰδ�����乬�����Ӹ���
    int times ;                          //���ڴ�����Ӻøж�С��60������
    int days=10;                         //�ʵ��ִ������
    char tempNames[50] ;                 //���ڴ�Żʵ۳������ӵ�����
    /*
        ������Ҫʹ����������ʾ�����Լ������ĸ���״̬�����ԣ�
        1������������
        2�������ĺøж�
        3�������ļ���
    */
    //�ö�ά�����Ŷ������������
    char names[6][10]={"����","����","�Է���","��ʩ","��ʩ"};
    //�����ļ���
    char levelNames[5][10]={"����","����","����","�ʹ���","�ʺ�"};
    //�������ÿλ���ӵļ���ÿ������Ԫ�ض�Ӧÿ�����ӵĵ�ǰ���������ֱ�ʾ��Ҫ��levelNames[]�����ļ����Ӧ����
    //0-���ˣ�1-������2-������3-�ʹ�����4-�ʺ�
    int levels[] ={1,2,3,2,0,-1};
    //lovers�����е�ÿ�����ӵĺøж�,��ʼֵ��Ϊ100
    int loves[]={100,100,100,100,100,-1};
    printf("������ʵ����ţ�");
    scanf("%s",emperorName);
    /*
    printf("1,�ʵ���ּѡ����\t(���ӹ���)\n");
    printf("2,���̳��ң�\t\t(�޸�״̬����)\n");
    printf("3,�����乬��\t\t(ɾ������)\n");
    printf("4,�����ټ�����ȥС������������£�\n");
    */
    printf("�ʵ۵�ѡ��");
    scanf("%d",&choice);
    //�ʵ�ֻ��1-4��ѡ�񣬹���Switch-case�ṹ
    switch(choice)
    {
    case 1://1,�ʵ���ּѡ�������������ӹ��ܣ�
        /*
            1,������Ҫ�ж�����names[]��û�пռ�
            2����������Ԫ�أ�
              > names[] ����һ�����ӵ�����
              > levels[] ����һ�����Ӽ���Ԫ��
              > lovers[] ����һ�����Ӻøж�Ԫ��
        */
        if(count < N )//��ǰ���ӵĸ���С��ϵͳ������Ӹ���N
        {
            printf("���������ӵ����䣺");
            scanf("%s",names[5]);//���Ӹ���ΪN
            //��������names[N-1]�ļ���ͺøжȳ�ʼ��
            levels[5]=0;
            loves[5]=0;
            //�������Ӻ󣬲鿴�������ӵ�״̬
            printf("%-12s����\t�øж�\n","����");
            for(i=0;i< N; i++)
            {
                printf("%-12s%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
            }
        }
        else
        {
            printf("���£���ĺ����Ӹ����Ѿ����ˣ�");
        }
        break;
        case 2: //�ʵ۷��̳��ң�(�޸�״̬����)
            /*
                1,ѡ�����ӵ�����
                2,��������ȷ������øжȼ�10���伶���1
                3,�������ӵĺøжȼ�10�ͼ����1
            */
            //��������֮ǰ״̬
            printf("%-12s����\t�øж�\n","����");
            for(i=0;i< count; i++)
            {
                printf("%-12s%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
            }
            do
            {
                printf("��ʵ�����Ҫ���ҵ����ӣ�");
                scanf("%s",tempNames);
                    for( i=0 ;i < count ; i++)
                    {
                        if(strcmp(tempNames,names[i])==0) //�������ӵ������Ƿ�������names[i]��
                        {
                        //�����ӵļ����1��ȡֵ��Χ 0-4
                            if(levels[i]>=0 && levels[i] <=4)
                            {
                                levels[i] +=1;
                            }
                            if(loves[i] >=0 && loves[i]<=140) //�����ӵĺøж�С��0�����140ʱ��
                            {
                                loves[i] +=10;
                            }
                            else
                            {
                                printf("���Ӻøж����޷�Ԥ֪��");
                                break;
                            }
                        }
                        else
                        {
                            loves[i]-=10;
                            //printf("��ʵ�����ѡ������̰��֮���Ů�ӣ�\n");
                        }
                        if(loves[i] <=60)
                        {
                            times++;
                            if(times >=3)
                            {
                                printf("�ʵ۹����巽�����췴���۹�����");
                                break;
                            }
                        }
                    }
                days--;
            }while(days <=0); //�ж����Ӻøж��Ƿ����60��������������3ʱ���ʵ۱����Ӹ����ˣ��۹�����
        break;
        case 3:
            printf("3,�����乬��\t\t(ɾ������)\n");
        break;
        case 4:
            printf("4,�����ټ�����ȥС������������£�\n");
            break;
        default:
        printf("����Ϸ�ԣ���ʵ��������룡");
    }
    return 0;
}
/*
    1�����ܵ�عˣ���֧�ṹ��ѭ���ṹ�����飻
    2�����似�ܵ㣺
        >ʹ���ַ����������ַ�����
        >�����ַ�����������Ƚϣ�����
        >��ά�����ʹ��
        >�����Ĳ��ţ�
        #include <window.h>
        #include <mmsystem.h>
        #pragma comment(lib,"Winmm.lib")
        //��������
        PlaySound(TEXT("sounds\\��������.wav")),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
*/
