// Room: /d/lingxiao/shiya.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","石崖");
	set("long",@LONG
轉過山樑，幾塊青石相互交搭，組成了一個避風的石崖。外面朔風
飛揚，裏面卻爐火熊熊，松木流爆，傳來絲絲烤肉的香味，凌霄弟子巡
山至此，常在這裏避風休憩。旁邊有個小店，疲累飢渴時，可在裏面稍
事休息。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"east"     : __DIR__"bar", 
		"westdown" : __DIR__"sroad3",
		"northup"  : __DIR__"sroad4",
	]));
	set("objects",([ /* sizeof() == 1 */
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8980);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

