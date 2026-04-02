// wg_wuchang2.c

#include <ansi.h>
inherit ROOM;

int do_tiao(string arg);

void create()
{
	set("short", "南練武場");
	set("long", @LONG
這是露天練武場，好多人在這裏辛苦的練着，你走在場中，沒有人
回頭看你一眼，都在聚精匯神的練着自己的功夫，場子的東角有一個沙
坑(shakeng)。
LONG);
	set("exits", ([
		"east" : __DIR__"wg_wuchang4",
		"north" : __DIR__"wg_lang2",
	]));
	set("objects", ([
		__DIR__"npc/wg_mjbz" : 1,
	]));
	set("item_desc", ([
		"shakeng" : "這是一個大沙坑，幾個小夥子在沙坑中上下跳(tiao)躍着。\n",
	]));
	set("outdoors", "wuguan");
	setup();
}

void init()
{
	add_action("do_tiao", "tiao");
	
}
int do_tiao(string arg)
{
	object me;
	int costj, costq,c_exp,c_skill;

	me = this_player();
	if (me->is_busy()) return notify_fail("你現在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在戰鬥中，無法專心練功！\n");
	if ( !living(me)) return notify_fail("你發瘋了？\n");

	if ( !arg || arg != "shakeng" )
		return notify_fail("你在場子裏蹦蹦跳跳了半天，別人還以爲你發神經！\n");
	costj = random((int)me->query("con"))+1;
	costq = random((int)me->query("str"))+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N奮力一跳，結果腳一滑，在沙坑裏摔了個狗喫屎！\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);
	message_vision("$N氣從丹田提升，在大沙坑中奮力跳上跳下。\n", me);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("dodge",1);
	if ( (int)me->query("combat_exp") < 50000)
	{
		if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
			(int)me->query_skill("dodge", 1) < 30 && random(10)>6 )
		{
			write(HIM"你不斷的在沙坑中跳着，自己的基本輕功有了提高！\n"NOR);
			me->improve_skill("dodge", (int)(me->query("int") / 4));
		}
		me->add("potential",random(2));
		me->add("combat_exp",random((int)(me->query("dex") / 10)));
	}
	return 1;
}
