//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "小巷");
	set ("long", @LONG
這是荊州城內的小巷，兩旁是高高的圍牆，僻靜無人，聽不到街市
的喧譁。西邊是一條大街，但見許多行人來來往往。
LONG);

	set("outdoors", "jiangling");
	set("exits", ([
		"east"  : __DIR__"xiang1",
		"west"  : __DIR__"xijie2",
	]));

	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}