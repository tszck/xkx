inherit ROOM;

void create()
{
	set("short", "全聚德酒樓");
	set("long", @LONG
方圓數百里內提起全聚德酒樓可以說是無人不知，無人不曉。樓
下佈置簡易，顧客多是匆匆的行人，買點包子、雞腿、米酒就趕路去
了。樓上是雅座。
LONG );
	set("exits", ([
		"east" : __DIR__"wangfu2",
		"up"   : __DIR__"jiulou2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
	set("coor/x", -190);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
