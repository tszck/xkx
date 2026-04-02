// Room: /d/tiezhang/sslu1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "碎石路");
	set("long", @LONG
你走在一條用碎石鋪成的小路上。兩旁山勢低緩，長滿了翠綠的毛
竹，陣陣微風吹過，耳旁便響起一片沙沙聲。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"eastup"   : __DIR__"sslu2",
		"westdown" : __DIR__"pingtai",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2030);
	set("coor/y", -1910);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

