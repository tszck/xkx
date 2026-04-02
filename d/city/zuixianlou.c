// Room: /city/zuixianlou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "醉仙樓");
	set("long", @LONG
方圓數百里內提起醉仙樓可以説是無人不知，無人不曉。當年蘇學
士雲遊到此，對醉仙樓的花雕酒讚不絕口，欣然為其題匾，流下一段傳
遍海內的佳話，從此醉仙樓名聲大震。樓下佈置簡易，顧客多是匆匆的
行人，買點包子、雞腿、米酒就趕路去了。樓上是雅座。
LONG );
	set("exits", ([
		"south" : __DIR__"ganquanjie",
		"west"  : __DIR__"shilijie3",
		"up"    : __DIR__"zuixianlou2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}