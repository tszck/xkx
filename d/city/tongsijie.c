// Room: /yangzhou/tongsijie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","通泗街");
	set("long",@LONG
通泗街由大塊青石砌成，兩邊整齊的種着槐樹，樹下各有一道排水
溝。北邊是揚州官衙，門前立着一對石獅，門上掛一匾額「揚州」。行
人到此多加快腳步，免惹是非，車馬亦加上一鞭，加速通過。南面都是
民宅，幾條小巷曲折穿插其中，偶然有一頂轎子進出。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"      : __DIR__"ximen",
		"east"      : __DIR__"caohexiaojie",
		"north"     : __DIR__"yamen",
		"southwest" : __DIR__"caohecexiang",
	]));
	set("objects", ([
		__DIR__"npc/xunbu" : 1,
	]));
	set("coor/x", -20);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
