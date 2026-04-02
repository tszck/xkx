// /guanwai/damen.c

inherit ROOM;

void create()
{
	set("short", "達門");
	set("long", @LONG
天池三面壅注不流，惟獨北面偏東一線斜垂，白練飛舞，這就是達
門。池水經達門外流，水流清冷，在石壁間衝撞有聲。
LONG );
	set("exits", ([
		"southwest"  : __DIR__"longmen",
		"northwest"  : __DIR__"pubu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6200);
	set("coor/y", 5190);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}