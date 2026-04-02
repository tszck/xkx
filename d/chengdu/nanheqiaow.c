// Room: nanheqiaow.c
// Date: Feb.14 1998 by Java
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;
void create()
{
	set("short","南河橋");
	set("long",@LONG
這裏是成都西門外南河橋。府河和南河夾城流過，呵護着這個天
府之國的首府之地。河水清新碧透。
LONG);
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */	    
		"east" : __DIR__"westgate",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8100);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

