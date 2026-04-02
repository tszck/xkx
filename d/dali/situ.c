//Room: /d/dali/situ.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","司徒堂");
	set("long",@LONG
這裏是大理國司徒堂。大理君臣勤政愛民，三公勞作自不帶言。
堂內無餘物，奇怪的是地上角落還擺了些鐵鏟，孔明燈之類的物事。
LONG);
	set("objects", ([
	    CLASS_D("dali")+"/huahegen" : 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"zonglichu",
	]));
	set("coor/x", -39010);
	set("coor/y", -69990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}