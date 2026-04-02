// huroom.c
inherit ROOM;

void create()
{
	set("short", "醫居");
	set("long", @LONG
你走進了烈火旗的大院後進，這裏是個很寧靜的小屋。四周擺了不
少醫學典籍，還有很多散落堆放的膏、丸、散等。一個老頭在此呆呆出
神，似乎有無限心事。
LONG );
	set("exits", ([
		"out" : __DIR__"lhqyuan",
	]));
	set("objects", ([
		__DIR__"npc/hu" : 1,
	]));
	set("outdoors", "mingjiao");
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 990);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}