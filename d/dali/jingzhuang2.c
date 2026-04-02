//Room: /d/dali/jingzhuang2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","第二層");
	set("long",@LONG
爲四神坐像，各有表情，衣褶隆起，筋節畢現，肌肉暴起，極富
立體感。
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "up"    : __DIR__"jingzhuang3",
	    "down"  : __DIR__"jingzhuang1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36000);
	set("coor/y", -70400);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}