// Room: path3.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "潭邊小路");
	set("long", @LONG
季節雖然已經是深秋，但日正當中的陽光，仍舊是十分炎熱的。四
周是一片芙蓉樹，遠山隱在雲霧之中，恍若迷離的美人，不遠處有着，
一叢叢的樹林，有一條溪流，沿着林旁蜿蜒流去。置身其中，讓人有發
古之幽思，又享大自然之浪漫。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"southwest"  : __DIR__"path4",
		"southeast"  : __DIR__"path2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8070);
	set("coor/y", -2960);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
