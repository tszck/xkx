//Room: /d/dali/chahua4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","茶花園");
	set("long",@LONG
大理茶花冠絕天下，鎮南王府的茶花自然更非凡品。你站在茶花
園中，北面是一片波光漣灩的湖面。靠岸的柳樹下，有幾盆茶花，嬌
豔照人，在滿園爛漫的茶花圍中，仍驕然出羣。
LONG);
	set("objects", ([
	   __DIR__"obj/chahua4": 1,
	]));
	set("outdoors", "daliwang");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : __DIR__"chahua5",
	    "northwest"  : __DIR__"chahua2",
	]));
	set("coor/x", -38950);
	set("coor/y", -70010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}