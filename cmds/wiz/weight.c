// weight.c
// created by doing
inherit F_CLEAN_UP;

#include <ansi.h>



int help(object me);

int main(object me, string arg)
{
        object env;
        int origin;
	      string msg;
        string to;

        if (!arg)
        {
         	 write("你現在體重是"+me->query_weight()+"負重"+me->query_encumbrance()+"。\n");
           return 1;
        }
        else if (arg=="-1")
        {
         	me->set_weight(40000+(me->query("str") - 10)*2000);
          write("你的體重恢復到原來的"+me->query_weight()+"。\n");
          return 1;
        }
        else if (sscanf(arg,"%d",origin)==1)
        {
        	if ( origin < 200)
        	 origin=200;
         	me->set_weight(origin);
          write("你把體重調整爲"+me->query_weight()+"。\n");
          return 1;
        }
        else
          help(me);
       	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : wieght [數值| -1]
 
這個指令會使你的重量變化。如果參數是-1就恢復原來的體重。
 
HELP );
    return 1;
}
