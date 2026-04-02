// /d/meizhuang/didao4.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
你一到這裏，迎面就聞到一股腐爛的泥土的味道，不過從前面的亮
光中，你又看到了希望，你不禁開始加快腳步，想看看那裏到底有些什
麼東西。 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"up"    : __DIR__"didao3",
		"north" : __DIR__"didao5",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3490);
	set("coor/y", -1470);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
