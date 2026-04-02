// Room: /d/city/yaopu2.c
// Last modified by winder 2003.8.20

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "藥鋪內室");
	set("long", @LONG
這是藥鋪的內室，四壁都是藥櫃子，有開有關，半開的櫃子裏可以
看到半露的藥材。地上、板凳上也放置了一些零碎藥材，還有一些藥罐、
藥臼等配藥器具。你可以用分藥(fenyao)命令，幫助藥鋪老闆分配這些
中藥。
LONG
	);
	set("no_fight",1);
	set("no_steal",1);
	set("no_beg",1);

	set("exits", ([
		"west" : __DIR__"yaopu",
	]));
	set("coor/x", 16);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_fenyao","fenyao");
	add_action("do_ban","dazuo");
	add_action("do_ban","tuna");
	add_action("do_ban","du");
	add_action("do_ban","study");
	add_action("do_ban","exercise");

}
int do_ban()
{
	write ("你幹什麼這是別人的內室呀，不要影響別人工作。\n");
	return 1;
}
int do_fenyao()
{
	object mon, me = this_player();
	int bonus,exp,pot;

	if((int)me->query_temp("fengyaoover"))
		return notify_fail("你的藥已經分完了，快去找老闆要報酬吧。\n");	
	if( (int)me->query_temp("fengyao") ) 
		return notify_fail("你已經在工作了。\n");
	if (!(int)(me->query_temp("fengyaobegin")))
		return notify_fail("外間有人在喊：裏面的人在做什麼？快走快走。\n");
	message_vision("$N將袖子一緬，做出一副要大幹一場的樣子，唉，分個藥也要這麼樣嗎？\n\n",me);
	me->set_temp("fengyao",1);
	me->add("qi",-5);
	me->delete_temp("fengyaobegin");
	call_out("del_fengyao", 1, me, mon, bonus, exp, pot);
	return 1;
}
void del_fengyao(object me, object mon, int bonus, int exp, int pot)
{
	int xunhuan;

	xunhuan=random(4);
	xunhuan+=2;
	me->delete_temp("fengyao");
	while(xunhuan > 0)
	{
		if (random (8) <1)
		{
			message_vision( HIY"哎呀，$N累的滿頭大汗，一不小心分錯了藥。\n"NOR,me);
			me->add("qi",-5);
			me->start_busy(1);
			me->set_temp("fengyaow",1);
		}
		else
		{
			switch(random(5))
			{
				case 0: 
					message_vision("只見$N隨手一扔，藥居然剛好扔進藥箱，好運氣呀。\n",me); 
					me->add("qi",-1);
					break;
				case 1: 
					message_vision("$N分的好仔細呀，還要檢查一次。\n",me);
					me->add("qi",-3);
					break;
				default:
					message_vision("$N看着手上的藥材，想了半天終於還是沒有找到該放的地方。\n",me); 
					me->add("qi",-4);
					break;
			}
			me->start_busy(1);
		}
		xunhuan--;
	} 
	write(HIW"\n 終於完成了，累死人了，好了終於可以去休息一下了.\n對了我還要去拿報酬呢，可不能白乾。\n"NOR);
	me->set_temp("fengyaoover", 1);
	me->start_busy(3);
	return ;
}

