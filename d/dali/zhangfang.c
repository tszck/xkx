//Room: /d/dali/zhangfang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","賬房");
	set("long",@LONG
這裏是鎮南王府的賬房，王府每天的銀米出入，往來消耗，
全由這裏經手，包括家丁下人的薪俸賞賜，在在都是麻煩多多。
這裏卻從來沒出過差錯。
LONG);
	set("objects", ([
	   __DIR__"npc/huo": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"wfdating",
	]));
	set("coor/x", -39010);
	set("coor/y", -70000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}