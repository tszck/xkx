#include <ansi.h>
inherit ITEM;

int query_autoload()
{
        return 1;
}

void create()
{
        set_name(HIY "仙丹" NOR, ({ "gift" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "這是一顆增加容貌的仙丹。\n" NOR);
                set("unit", "顆");
                set("value", 10000);
                set("weight", 50);

                // 增加天賦的種類
                set("gift_type", "per");

                // 天賦種類的名稱
                set("gift_name", "容貌");

                // 成功的幾率
                set("gift_point", 100);

                // 成功的描述
                set("gift_msg", HIC "突然間你的皮膚透過一道光澤。\n" NOR);
        }
        setup();
}
init()
{
	add_action("do_eat","eat");
	}
int do_eat(string arg)
{
     int point=query("gift_point");
     int max,top;
     object me=this_player();

			if (!id(arg)) 	return 0;
			if (me->is_busy()) 
			{
			write("你正忙着呢。\n");
			return 1;
			}
				//考慮特殊因素可以調節成功率
				
//     max = 10 + SCBORN_D->query_scborn_times(me) * 5;
     max = 10;
     if (SCBORN_D->query_scborn_times(me) == 6 ) max = 10000;
     top = 35 + SCBORN_D->query_scborn_times(me) * 5;
        message_vision(WHT "$N" WHT "一仰脖，吞下了一" +
                       query("unit") + name() + WHT
                       "。\n" NOR, me);

        if (me->query("gift/" + query("gift_type") + "/all") >= max 
        	|| me->query(query("gift_type"))>=top)
        {
                tell_object(me, "你覺得這藥好象沒什麼效果。\n");
        } else
        if (random(100) >= point)
        {
                tell_object(me, HIR "不過你覺得這藥好像沒起到什麼"
                                "作用。\n" NOR);

                // 記錄失敗的記號
                me->add("gift/" + query("gift_type") + "/fail", 1);
                log_file("gift/eat_dan",sprintf("%-20s eat %-10s(%s) fail [%s]\n",me->query("name")+"("+me->query("id")+")",this_object()->name(),this_object()->query("gift_type"),ctime(time())));
		     } 
		     else
       {
                tell_object(me, query("gift_msg"));
                tell_object(me, HIC "你的" + query("gift_name") +
                                HIC "永久增加一點。\n" NOR);

                // 記錄成功的記號
                me->add("gift/" + query("gift_type") + "/succeed", 1);
                log_file("gift/eat_dan",sprintf("%-20s eat %-10s(%s) success [%s]\n",me->query("name")+"("+me->query("id")+")",this_object()->name(),this_object()->query("gift_type"),ctime(time())));
		            log_file("gift/tianfu",
		                     sprintf("%-20s 喫下%-10s增加了%s(%s) [%s]\n",
		                     me->query("name")+"("+me->query("id")+")",
		                     base_name(this_object()),
		                     query("gift_name"),query("gift_type"),ctime(time())));        
 
                // 增加相應的天賦屬性
                me->add(query("gift_type"), 1);
        }

        // 記錄入喫丹的總量
        me->add("gift/" + query("gift_type") + "/all", 1);
        destruct(this_object());
        return 1;
}

