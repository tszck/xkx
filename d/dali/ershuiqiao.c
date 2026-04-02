//Room: /d/dali/ershuiqiao.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","洱水橋");
	set("long",@LONG
一座長百餘步的青石橋。此橋橫跨洱水，連接下關城和大理城，
橋下清澈的洱水滾滾東去。橋北正是下關城的城門，橋南一路南行十
數裏即可到大理城。
LONG);
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"xiaguan",
	    "southeast"  : __DIR__"dalinorth",
	]));
	set("no_clean_up", 0);
	set("coor/x", -41000);
	set("coor/y", -58000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}