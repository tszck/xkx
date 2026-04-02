// sroad1.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG
川西多是崇山峻嶺，交通不便。一條山路蜿蜒在山間，連接着
藏邊和中原。
LONG );
	set("exits",([
		"north"  : "/d/chengdu/nanheqiaos",
		"westup" : __DIR__"sroad2",
	]));
	set("outdoors", "xueshan");
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -10000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
