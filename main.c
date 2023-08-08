#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include <string.h>
//#pragma comment(lib,"Winmm.lib")

#define N 6 //常量N表示当前系统要求的最大妃子个数

int main()
{
    /*
        游戏规则：
        > 游戏一共进行10天；
        >每天结算好感度，一旦有三个或以上的嫔妃好感度低于60，则发生暴乱，游戏结束。

    */
    //PlaySound(TEXT("sounds \\ Victory.wav "),NULL, SND_FILENAME | SND_ASYNC | SND_RESOURCE | SND_LOOP);
    //printf("Hello world!\n");

    char emperorName[50];                //使用字符数组表示皇帝名号
    int choice;                          //皇帝的选择
    int i;                               //循环变量
    int count =5;                        //当前未打入冷宫的妃子个数
    int times ;                          //用于存放妃子好感度小于60个数量
    int days=10;                         //皇帝最长执政天数
    char tempNames[50] ;                 //用于存放皇帝宠幸妃子的名称
    /*
        我们需要使用数组来表示嫔妃以及嫔妃的各项状态（属性）
        1，嫔妃的姓名
        2，嫔妃的好感度
        3，嫔妃的级别
    */
    //用二维数组存放多个嫔妃的名称
    char names[6][10]={"貂蝉","杨玉环","赵飞燕","西施","东施"};
    //嫔妃的级别
    char levelNames[5][10]={"贵人","嫔妃","贵妃","皇贵妃","皇后"};
    //用来存放每位妃子的级别，每个数组元素对应每个妃子的当前级别，用数字表示，要与levelNames[]嫔妃的级别对应起来
    //0-贵人，1-嫔妃，2-贵妃，3-皇贵妃，4-皇后
    int levels[] ={1,2,3,2,0,-1};
    //lovers数组中的每个妃子的好感度,初始值都为100
    int loves[]={100,100,100,100,100,-1};
    printf("请输入皇帝名号：");
    scanf("%s",emperorName);
    /*
    printf("1,皇帝下旨选妃：\t(增加功能)\n");
    printf("2,翻盘宠幸：\t\t(修改状态功能)\n");
    printf("3,打入冷宫：\t\t(删除功能)\n");
    printf("4,单独召见爱妃去小树林做纯洁的事：\n");
    */
    printf("皇帝的选择：");
    scanf("%d",&choice);
    //皇帝只有1-4的选择，故用Switch-case结构
    switch(choice)
    {
    case 1://1,皇帝下旨选妃：（数组增加功能）
        /*
            1,增加需要判断数组names[]有没有空间
            2，增加数组元素，
              > names[] 增加一个妃子的名称
              > levels[] 增加一个妃子级别元素
              > lovers[] 增加一个妃子好感度元素
        */
        if(count < N )//当前妃子的个数小于系统最大妃子个数N
        {
            printf("请输入妃子的名讳：");
            scanf("%s",names[5]);//妃子个数为N
            //新增妃子names[N-1]的级别和好感度初始化
            levels[5]=0;
            loves[5]=0;
            //新增妃子后，查看各个妃子的状态
            printf("%-12s级别\t好感度\n","姓名");
            for(i=0;i< N; i++)
            {
                printf("%-12s%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
            }
        }
        else
        {
            printf("陛下，你的后宫妃子个数已经满了！");
        }
        break;
        case 2: //皇帝翻盘宠幸：(修改状态功能)
            /*
                1,选定妃子的名号
                2,妃子名号确定，其好感度加10，其级别加1
                3,其他妃子的好感度减10和级别减1
            */
            //重新妃子之前状态
            printf("%-12s级别\t好感度\n","姓名");
            for(i=0;i< count; i++)
            {
                printf("%-12s%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
            }
            do
            {
                printf("请皇帝输入要宠幸的妃子：");
                scanf("%s",tempNames);
                    for( i=0 ;i < count ; i++)
                    {
                        if(strcmp(tempNames,names[i])==0) //宠幸妃子的名称是否在数组names[i]中
                        {
                        //该妃子的级别加1且取值范围 0-4
                            if(levels[i]>=0 && levels[i] <=4)
                            {
                                levels[i] +=1;
                            }
                            if(loves[i] >=0 && loves[i]<=140) //该妃子的好感度小于0或大于140时，
                            {
                                loves[i] +=10;
                            }
                            else
                            {
                                printf("妃子好感度已无法预知！");
                                break;
                            }
                        }
                        else
                        {
                            loves[i]-=10;
                            //printf("请皇帝认真选择，切勿贪恋之外的女子！\n");
                        }
                        if(loves[i] <=60)
                        {
                            times++;
                            if(times >=3)
                            {
                                printf("皇帝管理五方，后宫造反，帝国覆灭！");
                                break;
                            }
                        }
                    }
                days--;
            }while(days <=0); //判断妃子好感度是否低于60，当其数量超过3时，皇帝被妃子干死了，帝国覆灭！
        break;
        case 3:
            printf("3,打入冷宫：\t\t(删除功能)\n");
        break;
        case 4:
            printf("4,单独召见爱妃去小树林做纯洁的事：\n");
            break;
        default:
        printf("君无戏言，请皇帝重新输入！");
    }
    return 0;
}
/*
    1，技能点回顾：分支结构；循环结构；数组；
    2，补充技能点：
        >使用字符串数组存放字符串；
        >常用字符串函数，如比较，复制
        >二维数组的使用
        >声音的播放：
        #include <window.h>
        #include <mmsystem.h>
        #pragma comment(lib,"Winmm.lib")
        //播放音乐
        PlaySound(TEXT("sounds\\背景音乐.wav")),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
*/
