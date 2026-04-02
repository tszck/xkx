// Room: /d/xingxiu/jushi.c
// Last Modified by winder on Apr. 25 2001

#include <ansi.h>
inherit ROOM;
int xxdazuo(object me);
int halt_xxdazuo(object me);
void create()
{
	set("short", HIB"巨石"NOR);
	set("long", @LONG
你落腳在一塊黑褐色的巨石上。你身在半空，向下一望，不由得頭暈目眩。
因此只好遠望對面山色。一陣山風吹來，令人心曠神怡，你才頓時發覺此乃練
功(liangong)一佳地。
LONG
	);
	set("exits", ([
		"down" : __DIR__"xiaolu",
	]));
	set("outdoors", "xingxiu");
	set("coor/x", -49900);
	set("coor/y", 20200);
	set("coor/z", 100);
	setup();
}

void init()
{
	object me = this_player();
	object ob = this_object();
	object	*inv = all_inventory( ob );
	
	if ( me->query("family/family_name") != "星宿派" && !wizardp(me))
		for ( int i = 0; i < sizeof(inv); i++ )
			if ( (userp(inv[i]) && inv[i] != me && !wizardp(inv[i]) ) || time()-me->query_temp("LAST_PKER_TIME")<7200)
			{	
				write( WHT"你爬上巨石，卻發現上面已無容身之處，只好悻悻的退了下來。\n"NOR );
				me->move( __DIR__"xiaolu" );
				return;
			}

	add_action("do_xxdazuo", "liangong");
}

int do_xxdazuo(string arg)
{     
	int xxdazuo_cost;
	mapping fam;
	object me;
	me = this_player();   
	fam = this_player()->query("family");

//	if (!fam || fam["family_name"] != "星宿派")
//	       return notify_fail("你偷上星宿派禁地，還敢在這裏打坐？\n");
    
	if (me->is_busy())
		return notify_fail("你現在正忙着呢。\n");

	if(me->query("max_qi") < 400)
		return notify_fail("你現在的氣太少了，無法在此練功。\n");

	if(me->query_skill("force") < 100 )
		return notify_fail("你的內功根基還不夠，在此練功有害無益。\n");

	if( !stringp(me->query_skill_mapped("force")) )
	return notify_fail("你必須先用 enable 選擇你要用的特殊內功。\n");

	      if ((me->query_skill("force")*8 +  me->query("combat_exp",1)/1000 ) <= me->query("max_neili") )
	      return notify_fail("這裏已經無助於你的修爲了。\n");

	if( !arg || !sscanf(arg, "%d", xxdazuo_cost))
		return notify_fail("你要花多少氣練功？\n");
	if (xxdazuo_cost < 10)
	return notify_fail("你無法控制內息運行到如此精細的程度！\n");

	if( (int)me->query("qi") < xxdazuo_cost )
		return notify_fail("你現在的氣太少了，無法產生內息運行全身經脈。\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你現在精不夠，無法控制內息的流動！\n");

	message_vision("$N盤膝坐下運功，身體漸漸被一股青煙所包圍。\n",me); 
	write(BLU"你坐在巨石上，運動丹田內勁，你感覺到在山風的壓迫下體內的內勁開始有所加強了。\n"NOR);

	me->set_temp("pending/xxdazuo", 1);
	me->set_temp("xxdazuo_cost", xxdazuo_cost);	
	me->start_busy((: xxdazuo :), (:halt_xxdazuo:));
	return 1;
}

int xxdazuo(object me)
{
	int xxdazuo_cost = (int)me->query_temp("xxdazuo_cost");
	int neili_gain = 1 + (int)me->query_skill("force") / 10
		* (1 + (int)me->query_skill("force") / 300);    

	if (neili_gain > xxdazuo_cost) neili_gain = xxdazuo_cost;
	neili_gain = neili_gain + random(neili_gain) / 2;
	me->add("neili", neili_gain);
	me->set_temp("xxdazuo_cost", xxdazuo_cost -= neili_gain);
	me->receive_damage("qi", neili_gain);

	if (xxdazuo_cost > 0) return 1;

	me->delete_temp("pending/exercise");
	me->delete_temp("pending/xxdazuo");
	message_vision("山風漸漸加強，$N終於忍耐不住，雙眼一睜，站了起來。\n", me);    
//	me->improve_skill("huagong-dafa", 1);
        if ((int)me->query_skill("force",1)<150)
	    me->improve_skill("force", 1); 
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
     if ((me->query_skill("force")*8 +  me->query("combat_exp",1)/1000 ) <= me->query("max_neili") ){
		write("你的內力修爲已經達到了此地所能幫助你的極限。\n"); 
		me->set("neili", (int)me->query("max_neili"));
		return 0;
	}
	me->add("max_neili", 1);
	me->set("neili", (int)me->query("max_neili"));
	write("你的內力修爲增加了！！\n");   
	return 0;
}



int halt_xxdazuo(object me)
{
	if ((int)me->query("neili") > (int)((int)me->query("max_neili") * 2)) 
	{
		message_vision("$N強壓住內息，雙眼一睜，站了起來。\n", me); 
		me->set("neili", (int)((int)me->query("max_neili") * 2)); 
	}
	me->delete_temp("pending/xxdazuo");
	return 1;
}
