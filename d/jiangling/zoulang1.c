//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "走廊");
	set ("long", @LONG
這是一條長長的走廊。走廊西邊是萬府大廳。東邊的盡頭是個小客堂。
LONG);
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/qifang" : 1, 
	]));
	set("exits", ([
		"west"  : __DIR__"dating",
		"east"  : __DIR__"ketang",
	]));
  
	set("coor/x", -1488);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!objectp(present("hu cheng", me)) &&
		dir == "east" &&
		objectp(present("qi fang", environment(me))))
		return notify_fail("戚芳攔住你説：我夫君中毒臥牀，請勿打擾。\n");

        return ::valid_leave(me, dir);
}