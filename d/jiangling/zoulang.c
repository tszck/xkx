//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "走廊");
	set ("long", @LONG
這是一條長長的走廊。走廊西邊是知府大人的書房。東邊盡頭的一
間房，門上披了一匹素幃，象是個靈堂。南邊是東廂房，是知府大人和
家眷住的地方。幾個閒着沒事的衙役正和一個丫鬟調笑着。
LONG);
	set("objects", ([
		"/d/city/npc/yayi"   : 3,
		__DIR__"npc/yahuan1" : 1, 
	]));
	set("exits", ([
		"west"  : __DIR__"shufang",
		"east"  : __DIR__"lingtang",
		"south" : __DIR__"dongxiang",
	]));
  
	set("coor/x", -1480);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
