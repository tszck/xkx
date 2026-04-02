// Room: /d/chengdu/jiulou2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "銀杏酒樓二樓");
	set("long", @LONG
你坐在成都最豪華的酒樓上，看着樓下的凡人忙忙碌碌，心情很是
愉快，所謂“對酒當歌，人生幾何”，還猶豫什麼，盡情享受生活吧！
LONG );
	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));
	set("objects", ([
		  __DIR__"obj/chair" : 4,
	]));
	set("coor/x", -8030);
	set("coor/y", -3020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
