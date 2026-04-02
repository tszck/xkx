//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "南樓");
	set ("long", @LONG
這是萬門弟子住的地方。萬門一共有八個弟子，除第三個弟子萬圭
外，其餘的都住在這裏。牆上掛了幾把刀劍。
LONG);
	set("exits", ([
		"north" : __DIR__"dating",
		"east"  : __DIR__"chaifang",
	]));
	set("objects", ([
		__DIR__"npc/shencheng" : 1,
		__DIR__"npc/sunjun"    : 1,
		__DIR__"npc/boyuan"    : 1,
		__DIR__"npc/fengtan"   : 1,
	]));
  
	set("coor/x", -1489);
	set("coor/y", -2041);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
