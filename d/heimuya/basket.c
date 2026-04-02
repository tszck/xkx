// Room: /d/heimuya/basket.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "竹簍");
	set("long", @LONG
這是一隻大竹簍，足可裝得十來石米。抬頭上望，只見頭頂有天風
崖壁，這黑木崖着實高得厲害。
LONG );
	set("outdoors", "heimuya");
	set("no_clean_up", 0);
	set("coor/x", -3261);
	set("coor/y", 4200);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}