//Edited by fandog, 02/18/2000
inherit ROOM;
void create()
{
	set("short", "東門");
	set("long", @LONG
這是荊州城的東門。城門不大，也無人看守。往南走出城，是一條
蜿蜒曲折的山道。
LONG );
	set("outdoors", "jiangling");
	set("exits", ([
               "south" : __DIR__"shandao5",
               "north" : __DIR__"dongjie2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}