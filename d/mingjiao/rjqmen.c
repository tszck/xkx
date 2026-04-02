//RJQMEN.C

inherit ROOM;

void create()
{
	set("short", "側門");
	set("long", @LONG
這是鋭金旗的一個側門，大概只容得下一個人進出，每個教眾到此，
都必須出示一張腰牌，才可進入。
LONG );
	set("exits", ([
		"enter" : __DIR__"rjqyuan",
		"east" : __DIR__"torjq3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52010);
	set("coor/y", 860);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}