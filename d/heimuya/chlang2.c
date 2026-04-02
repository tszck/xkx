// Room: /d/heimuya/chlang2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","長廊");
	set("long", @LONG
這裏是非常氣派的長廊。但是卻沒什麼人在這裏，南邊是青龍堂的
大廳。
LONG  ); 
	set("outdoors", "heimuya");
	set("exits",([
		"north" : __DIR__"chlang1",
		"south" : __DIR__"qing",
	]));			   
	set("objects",([
		__DIR__"npc/shinu1"   :1,
	]));
	set("no_fight",0);
	set("no_steal",0);
//	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}