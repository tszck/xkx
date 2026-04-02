// Room: /d/heimuya/shijie2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "石階");
	set("long", @LONG
越往上，山勢越陡峭，中間的石階越窄，僅能一人行走，從這裏往
上望，隱約望見一座石門。
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
		"eastdown" : __DIR__"shijie1",
		"westup"   : __DIR__"shimen",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/zhaohe" : 1, 
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3240);
	set("coor/y", 4200);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}