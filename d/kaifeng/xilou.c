// /kaifeng/xilou.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "戲樓");
	set("long", @LONG
一座木頭粗粗搭起的高臺，臺的後端用大的簾子遮了起來那後頭就
是戲子裝扮上臺的地方。由於是關帝廟的緣故，演的無非是桃園三結義、
單騎走千里、杯酒斬華雄等故事。
LONG);
	set("objects", ([
		__DIR__"npc/qingyi" : 1,
		__DIR__"npc/xiaosheng" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"paifang",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
