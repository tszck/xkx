// Room: /city/yaopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "藥鋪");
	set("long", @LONG
這是一家藥鋪，一股濃濃的藥味讓你幾欲窒息，那是從藥櫃上的幾
百個小抽屜裏散發出來的。神醫平一指坐在茶几旁，獨自喝着茶，看也
不看你一眼。一名小夥計站在櫃檯後招呼着顧客。櫃檯上貼着一張發黃
的廣告(guanggao)。
LONG );
	set("item_desc", ([
		"guanggao" : "本店出售以下藥品：
金創藥：\t五十兩白銀
無常丹由桃花島黃藥師所配，生死肉骨．
朱睛冰蟾救治百毒，無效包換．
其他神藥與老闆面議。\n",
	]));
//	set("item_desc", ([
//		"guanggao" : "本店老闆平一指外出採藥未歸，今日暫停營業。\n",
//	]));
	set("objects", ([
//		__DIR__"npc/ping" : 1,
		"/kungfu/class/heimuya/ping" : 1,
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"shilijie6",
		"east" : __DIR__"yaopu2",
	]));
//	set("no_clean_up", 0);
	set("coor/x", 15);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
