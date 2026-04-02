// Room: /yangzhou/beiliuxiang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","北柳巷");
	set("long",@LONG
一條窄窄的小巷，不時有小轎進進出出。小巷的兩邊樓閣都是高高
的挑着對紅燈籠，掛着青布幕簾，幾個年輕女子斜靠着樓門，對過往的
行人曖昧的笑着。南面的巷口立着個木牌坊，上面題着「北柳巷」。這
裏便是揚州的秦樓楚館聚集之地。
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"south"  : __DIR__"matou",
		"north"  : __DIR__"caiyijiekou",
		"west"   : __DIR__"lichunyuan",
		"east"   : __DIR__"meixiangyuan",
	]));
	set("objects", ([
		__DIR__"npc/popi1" : 1,
	]));
	set("coor/x", 40);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}