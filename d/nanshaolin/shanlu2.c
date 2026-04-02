// Room: /d/nanshaolin/shanlu2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石階路");
	set("long", @LONG
滿目望去，都是連片的馬尾松。松樹與松樹似乎都擠在一塊生長，
陽光到這裏變得格外黯淡，只在地上留下斑駁的碎影。靜聽不遠處格的
一聲，象是松枝斷落的聲音。這裏路近少林，路面都鋪上了石板。
LONG);

	set("exits", ([
		"southdown" : __DIR__"ting",
		"north"     : __DIR__"shanlu3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6340);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



