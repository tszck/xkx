// Room: /d/heimuya/didao1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","祕道");
	set("long", @LONG
這是一條異常幽靜的走廊，四周漆黑一團，你好象什麼都看不見似
的走在裏面，你不覺想到這似乎在每個角落都藏着無限殺機，太恐怖了，
四周毫無聲息，好象掉下一根針都可能聽到。
LONG );

	set("exits",([
		"east"  : __DIR__"didao2",
		"west"  : __DIR__"didao1",
		"south" : __DIR__"didao5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4210);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}