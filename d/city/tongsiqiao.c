// Room: /yangzhou/tongsiqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","通泗橋");
	set("long",@LONG
通泗橋連接揚州舊城的中心十里街和官衙，寬敞平整，數輛大車可
以並行。橋的西頭圍出一大花壇，種着揚州的名花「芍藥」(shaoyao)，
更有一株老杏，橫臥水上，夭矯屈曲。橋的東頭，立一巨石，上書「通
泗橋」。橋上常有行人倚欄笑看船兒橋下過。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"caohexiaojie",
		"east"  : __DIR__"shilijie4",
	]));
	set("item_desc", ([
		"saoyao" : "揚州以盛產芍藥而名聞天下，其中又以「金帶圍」最為名貴。\n",
	]));
	set("objects", ([
		__DIR__"npc/liuyan" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}