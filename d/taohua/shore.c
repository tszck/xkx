// Room: /d/taohua/shore.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "岸邊");
	set("long", @LONG
你疑惑地看着四周，這裏就是桃花島麼？四周除了凌亂的礁石外，
什麼都沒有。往北面看，一座小山聳立在那裏，可以通過攀爬巖壁到達
山頂。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"northup" : __DIR__"hill",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 8500);
	set("coor/y", -4700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
