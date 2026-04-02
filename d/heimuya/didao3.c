// Room: /d/heimuya/didao3.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","祕道");
	set("long", @LONG
走在裏面，你不覺想到這似乎在每個角落都藏着無限殺機，你感到
近了近了，越來越近了。
LONG );

	set("exits",([
		"east"  : __DIR__"didao3",
		"west"  : __DIR__"didao3",
		"north" : __DIR__"didao4",
		"south" : __DIR__"didao1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4210);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}