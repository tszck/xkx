// Room: /d/nanshaolin/wuxiangpai.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIB"無相牌"NOR);
	set("long", @LONG
通過無相牌進入無相禪師生前修真的密室，室內頗為灰暗，密不透
光。密室中擺着一個大銅缸，缸中盛滿淨水，波光粼粼。為室內添加一
點光亮據説無相大師當年受挫於崑崙高人之後，又尋張君寶不遇，憤懣
歸寺，既隱居於此練掌(strike)，將掌法練到登峯造極之地步。其一生
武學祕奧盡藏於此斗室之中。
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_strike","strike");
}
int do_strike(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("strike", 1), exp = me->query("combat_exp");

	if (arg!="shui") return 0;
	if (!living(me)) return 0;
	message("vision", me->name()+"對準銅缸中的水面發掌擊出。\n", environment(me), ({me}) );
	if (lvl<30)
	{
		write(HIR"你功力太淺，銅缸中連水花也沒濺出一點。\n"NOR);
 		return 1;
	}
	if (lvl * lvl * lvl / 10 < exp)
	{
		write(HIR"你經驗太淺，銅缸中連水花也沒濺出一點。\n"NOR);
		return 1;
	}
	if (lvl>100)
	{
		write(HIR"你掌力沉雄，銅缸內淨水為你掌力所激，已回應之力。\n"NOR);
		return 1;
	}
        if (lvl >= 30 && lvl <= 100&&arg=="shui" )
	{
		if ((int)me->query("jing")<30)
		{
			me->unconcious();     
			return 0;
		}
                me->receive_damage("jing", 30);
                me->improve_skill("strike", (me->query("int"))*3/2);
                write(HIB"你對着水面遙遙發掌，缸內激起片片水花。你覺的掌力頗有精進。\n"NOR);
		return 1;
	}
}

