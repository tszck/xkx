//westroad1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
這是一條直通西方的山路，向西遠望，羣山巍峨，雲霧飄渺，再往
前不遠，就要進入深山之中了。東面就是去中原的路。
LONG);
	set("exits",([
		"west" : __DIR__"westroad2",
		"east" : "/d/xingxiu/silk4",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -30000);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
