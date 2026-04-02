// Room: /d/tiezhang/shangu2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "山谷");
	set("long", @LONG
你走在一條狹窄的山谷之中，兩旁山峯壁立，直插雲霄。鳥鳴猿啼
之聲，迴盪在寂靜的空谷之中。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"juebi1",
		"southwest" : __DIR__"shangu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2020);
	set("coor/y", -1890);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}