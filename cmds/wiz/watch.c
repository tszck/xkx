// Last Modified by winder on Apr. 25 2001
// 看臨時參數的命令文件
inherit F_CLEAN_UP;

#include <login.h>
#include <obj.h>


string time_period(int timep);

int main(object me, string arg)
{
    int i, j, tim, sum=0;

    i = LOGIN_D->get_dienpc();
       j = LOGIN_D->get_madlock();
    tim = DISASTER_D->query_hj_startT();
    tim = time() - tim;
    sum += DISASTER_D->query_children("/clone/haojie/pker9.c");
    sum += DISASTER_D->query_children("/clone/haojie/pker8.c");
    sum += DISASTER_D->query_children("/clone/haojie/pker7.c");
    sum += DISASTER_D->query_children("/clone/haojie/pker6.c");
    sum += DISASTER_D->query_children("/clone/haojie/pker5.c");
    sum += DISASTER_D->query_children("/clone/haojie/pker4.c");
    sum += DISASTER_D->query_children("/clone/haojie/pker3.c");
    sum += DISASTER_D->query_children("/clone/haojie/pker2.c");
    sum += DISASTER_D->query_children("/clone/haojie/pker1.c");
    write("被殺 NPC人數："+i+"\n");
    write("系統封鎖狀態："+j+"\n");
    write("封鎖持續時間："+time_period(tim)+"\n");
    write("當前殺手數量："+sum+"\n");
        return 1;
}

string time_period(int timep)
{
    int t, d, h, m, s;
    string time;
    if ( timep>=1800 ) return "已超時";
    t = timep;
    s = t % 60;	t /= 60;
    m = t % 60;	t /= 60;
    h = t % 24;	t /= 24;
    d = t;

    if(d) time = chinese_number(d) + "天";
    else time = "";

    if(h) time += chinese_number(h) + "小時";
    if(m) time += chinese_number(m) + "分";
    time += chinese_number(s) + "秒";
    return time;
}
