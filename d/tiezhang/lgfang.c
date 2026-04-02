// Room: /d/tiezhang/lgfang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>

inherit ROOM;
//void init();
//int do_chazhi();

void create()
{
        set("short",HIC"練功房"NOR);
	set("long", @LONG
這是一間用花崗巖砌成的石屋。室內一隻大爐中燃了洪炭，煮着熱
氣騰騰的一鑊(huo )東西，鑊旁兩個黑衣小童，一個使勁推拉風箱，另
一個用鐵鏟翻炒鑊中之物，聽這沙沙之聲，所炒的似是鐵沙。幾名幫中
弟子閉目盤膝坐在鍋前，或對着騰上的熱氣吐吶，或插指於鑊中苦練。
LONG
	);
        set("exits", ([ 
		"east" : __DIR__"guangchang",
	]));
	set("objects",([
		__DIR__"npc/heiyi" : 1,
	]));
	set("item_desc", ([
		"huo" : "這是一口巨大的鐵鍋，鍋中盛滿鐵沙，下面燃着炭火。\n",
	]));
	set("coor/x", -2050);
	set("coor/y", -1970);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_chazhi", "chazhi");
}


int do_chazhi(string arg)
{       
        mapping fam;
	object me;
        me = this_player();

	if (!living(me)) return 0;
	if ( !living(this_player()) || arg != "huo" )
	{
		write("你想往哪兒插呀！\n");
		return 1;
	}
	if (!(fam = me->query("family")) || fam["family_name"] != "鐵掌幫")
		return notify_fail("你非本幫弟子，不能在此練功！\n");

	if ( (int)me->query_skill("strike", 1) > 100)
		return notify_fail("你將雙手插入鑊中，發現鐵沙的溫度對你來說太低，已毫無意義了。\n");
 
	if((int)me->query("qi")<30)
	{
		me->receive_damage("qi",10);
		write("你覺得一股熱氣直逼上來，焦燥難當！\n");
		me->unconcious();
		return 1;
	}
	me->receive_damage("qi", random(40));
	me->improve_skill("strike", me->query("int"));
	message_vision("$N將雙手插進鑊中的鐵沙裏。\n", me);
	write("灼熱的鐵沙將你的雙手燙得通紅，你覺得雙手變得強壯有力。\n");
	return 1;
}
