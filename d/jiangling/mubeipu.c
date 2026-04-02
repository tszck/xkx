//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "墓碑鋪");
	set ("long", @LONG
説是一家店鋪，其實這是一個工場，幾個石匠正起勁地鑿打着石碑。
最近荊州城裏做喪事的人家還真不少，賣棺材、墓碑的便忙活起來了。
四處堆放了不少未完工的墓碑，一個監工正在巡視。
LONG);
	set("exits", ([ 
		"east" : __DIR__"xijie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -1110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
