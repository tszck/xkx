// Room: /city/zoulang2.c
// Last modified by winder 2002.11.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "走廊");
	set("long", @LONG
這是賭場裏的走廊，來來往往的小二和罵罵咧咧賭徒，夾雜着滿空
氣裏彌散的菸酒汗氣，實在是繁雜。各個方向的房間裏，牌九、骰子和
麻將巧擊聲，桌椅板凳推倒敲砸聲，酒杯器皿的落地破碎聲，交雜成讓
讓人極其興奮的氣氛。你一走進這裏，不禁嘆道，真是好地方。
LONG);
	set("exits", ([
		"north"  : __DIR__"qiyiting",
		"south"  : __DIR__"youxiting",
		"west"   : __DIR__"zoulang1",
	]));
        set("no_fight","1");
	set("no_clean_up", 0);
	set("outdoors", "duchang");
	set("coor/x", 21);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
void init()
{
	object me = this_player();
	if (me->query("gender") != "男性")
		set("long", @LONG
這是賭場裏的走廊，來來往往的小二和罵罵咧咧賭徒，夾雜着滿空
氣裏彌散的菸酒汗氣，實在是繁雜。各個方向的房間裏，牌九、骰子和
麻將巧擊聲，桌椅板凳推倒敲砸聲，酒杯器皿的落地破碎聲，交雜成讓
讓人極其興奮的氣氛。你一走進這裏，就皺起眉頭：什麼鬼地方。
LONG);
	return;
}
