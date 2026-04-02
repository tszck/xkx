// Room: /d/heimuya/shidao2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "石道");
	set("long", @LONG
一路上日月教教眾把守嚴密，經過三處山道，來到一處水灘之前，
西面有一道石階通往水灘。
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
		"westdown" : __DIR__"xingxingtan",
		"south"    : __DIR__"shidao1",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/wang" : 1,
		__DIR__"npc/heiyiren" : 2,
	]));
	set("no_clean_up", 0);
	set("coor/x", -3050);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}