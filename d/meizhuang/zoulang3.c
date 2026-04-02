// /d/meizhuang/zoulang3.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
走廊到了這裏似乎就到了盡頭，從走廊的那一頭傳來陣陣的燒飯的
香味，飢腸漉漉的你，走到這裏，再也忍受不了那種撲面而來的香氣的
誘惑，只有加快腳步，去看個究竟。 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"chufang",
		"south" : __DIR__"zoulang2",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1360);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
