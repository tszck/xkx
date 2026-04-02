// Room: /d/city/jiaowai2.c
// Jan. 8.1998 by Venus
#include <room.h>
#include <ansi.h>
inherit ROOM;
#define MAX_EXP 2000

void create()
{
	set("short", "樹林");
	set("long", @LONG
揚州郊外的樹林，松枝挺拔，喬木橫斜。林間小道，逶迤隨遠。林
中蟬鳴廝鬧，鳥啼宛轉，使你頓時煩意盡消。無數的小鳥小雀在樹
梢上歡歌，一點也不怕人。這正是個打鳥（da）的好機會。
    地上落了很多樹枝石塊。
LONG );
	set("exits", ([
		"north" : __DIR__"jiaowai1",
		"south" : __DIR__"jiaowai3",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/qiu-wanjia": 1,
		__DIR__"obj/shuzhi": 1,
		__DIR__"obj/shitou": 1,
	]));
	set("outdoors", "yangzhoue");
	set("coor/x", 70);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();	
}

void init()
{
        add_action("do_da", "da");
}


int do_da()
{
        object me;
        int /*i,*/ kar/*, cps*/, add_exp, add_pot, add_score;
        me = this_player();

        if (me->query("combat_exp")>=MAX_EXP)
            return notify_fail("這樣的遊戲還是讓小孩們玩吧！\n");
        
        if(me->is_busy())
             return notify_fail("你還是等弓裝好了箭再打鳥吧！\n");

        if(me->query("qi")<10)
             return notify_fail(HIR"你太累了，還是先休息一下吧，射箭也要用力氣喲。。\n"NOR);
             

        me->start_busy(3);
        message_vision("$N拿起兒時玩耍用的小弓小箭，瞄準樹上的小雀射去......\n", me);
        message_vision("$N只聽樹上一陣鳥兒急鳴…\n",me);
        kar = random((int)me->query("kar"));
        
        if (kar<=5) 
           {
           	message_vision("$N什麼也沒打到。\n",me ); 
           	          	           	          
            }
        else 
        
           {    
                if (kar>5 && kar<=8) 
                   
                   {
                      message_vision("$N打到一隻"YEL"麻雀。\n"NOR, me);
                      add_exp=4+random(5);
                      add_pot=4+random(5);  
                   }
                 if (kar>8 && kar<=10) 

                    {
                      message_vision("$N打到一隻"HIG"鸚鵡。\n"NOR, me);
                      add_exp=6+random(5);
                      add_pot=6+random(5);                 
                     }  
                 if (kar>10 && kar<=15)
                
                   {
                      message_vision("$N打到一隻"HIY"金絲雀。\n"NOR, me);                    
                      add_exp=8+random(5);
                      add_pot=8+random(5);   
                    }       
                if (kar >15) 
                
                   {
                      message_vision("$N打到一隻"HIW"百靈鳥。\n"NOR, me);                    
                      add_exp=10+random(5);
                      add_pot=10+random(5);                                                                                                                              
                    }        
                    
                add_score=10+random(5);                               
                
                me->add("combat_exp",add_exp);
                me->add("potential",add_pot);
                me->add("score",add_score);
                tell_object(me,HIW"你得到了:"
                            + chinese_number(add_exp) + "點實戰經驗，"
                            + chinese_number(add_pot) + "點潛能，"
                            + chinese_number(add_score) + "點江湖閱歷。\n"NOR);

             }                   
         me->receive_damage("qi", 5);
         return 1;      
 }
       