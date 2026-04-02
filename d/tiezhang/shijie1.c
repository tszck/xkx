// Room: /d/tiezhang/shijie1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "石階");
	set("long", @LONG
一排石階盤旋而下，消失在濃濃的黑暗中。石階上長滿的綠色的青
苔，滑不留腳。遠處黑暗的盡頭似乎有點昏黃的光亮。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"out"      : __DIR__"wmfeng",
		"eastdown" : __DIR__"shijie2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2050);
	set("coor/y", 1860);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}