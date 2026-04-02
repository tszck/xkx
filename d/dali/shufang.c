//Room: /d/dali/shufang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short", "書房");
	set("long", @LONG
這是大理國鎮南王的書房，靠窗放着一個大木桌桌上放着不少書，
靠牆的地方還有一個書架，鎮南王經常在這裏看書。
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"tingfang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38970);
	set("coor/y", -69990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}