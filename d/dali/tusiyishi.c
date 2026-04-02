//Room: /d/dali/tusiyishi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","議事廳");
	set("long",@LONG
議事廳中央有神龕，龕下陳列着刀、叉、矛、戟等兵器。寬闊的大樓上
下，柱樑粗實。廳堂寬敞，前後各有一長排坐欄，供人納涼憩息。
LONG);
	set("objects", ([
	   __DIR__"npc/datusi": 1,
	   __DIR__"npc/zutouren": 2,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"  : __DIR__"tusimentang",
	]));
	set("coor/x", -41000);
	set("coor/y", -71010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}