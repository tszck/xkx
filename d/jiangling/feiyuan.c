//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "廢園");
	set ("long", @LONG
一座廢棄的花園。月光下見到廢園角落的瓦礫之中，長着一朵小小
的紫花，迎風搖曳，頗有孤寂淒涼之意。荒草中，有一株凹凹凸凸樹幹
的老梅在寒風中傲立。
LONG);

	set("exits", ([ 
		"north" : __DIR__"lingtang",
		"east"  : __DIR__"loudi",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2039);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
