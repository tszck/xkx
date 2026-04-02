// /kaifeng/shanlu2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create ()
{
	set ("short", "山路");
	set ("long", @LONG
這是一條黃土飛揚的山路，因為離嵩山等幾處山脈還比較遠，所以
它很是寬闊，路上來往的行人很多，路邊相隔不遠就有個小亭子供行人
歇腳，北邊不遠便是嵩山。
LONG);

	set("outdoors", "kaifeng");
	set("exits", ([
		"north"  : "/d/songshan/taishique",
		"eastup" : __DIR__"shanlu1",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
