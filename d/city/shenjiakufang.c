// Last Modified by Sir 9/15/2001
#include <ansi.h>
inherit ROOM;
int do_yuntang(string arg);

void create ()
{
  set ("short", "沈家庫房");
  set ("long", @LONG
你走過一條狹窄的小巷之後來到一間倉庫中。這裏整齊的堆碼着未經
熨燙的布匹和一些成衣。靠牆擺放着幾張大桌子，桌子上放着幾匹打溼的
布料和一個豎着一個已經燒得發燙的熨斗。你可以在這兒熨燙(yuntang)。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"baiyipu",
]));

  setup();
}
void init()
{
        add_action("do_yuntang","yuntang");
}

int do_yuntang(string arg)
{
        object me=this_player(); 
        object ob;
        if (!me->query_temp("gongzuo/yunbu"))
           return notify_fail("你現在沒有熨布的工作。\n");

        if(me->is_busy())
             return notify_fail("你正忙着熨布呢！\n");
             
        if ( (int)me->query("jing")<10)
           return notify_fail("你太累了，休息一下吧。\n");
           
        if ( (int)me->query("qi")<10)
           return notify_fail("你太累了，休息一下吧。\n");   

        if (me->query_temp("gongzuo/yunbu")==6)
           return notify_fail("布料已經熨好了，快把熨好的布交回去吧！\n");
   
  message_vision("$N拿起熨斗慢慢地在布料上來回移動，只見布料上立刻冒出白色的蒸氣。\n",me);
        
        if (random(10)>7)
        {
  message_vision(RED"$N在蒸氣繚繞之中逐漸開始漫不經心，只聽得“哧”的一聲$N的手被熨斗碰了一下。\n"NOR,me);     
       me->receive_damage("qi", 10);
         }   
      me->start_busy(2);            
      me->add("jing",-(2+random(5)));
      me->add("qi",-(5+random(5)));
      me->add_temp("gongzuo/yunbu",1);      
  if ( (int)me->query_temp("gongzuo/yunbu")==6)
 {
  message_vision(CYN"布匹在熨燙下逐漸平整，$N將布匹疊好後放在一邊。\n"NOR,me);
      me->set_temp("gongzuo/yunbuok",1);
      ob=new("/d/city/obj/bu.c");
      ob->move(me);      
 }
                 
  return 1;
} 
