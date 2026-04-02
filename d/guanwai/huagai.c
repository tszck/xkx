// /guanwai/huagai.c

inherit ROOM;

void create()
{
	set("short", "華蓋峯");
	set("long", @LONG
長白東側最高峯，自古以來，華蓋峯就是風雨雲霧的故道。雲霧起
處，恰似掀開鍋蓋一般，霧氣翻滾，池水雲天，一脈相連，氣壯華夏，
故名華蓋峯。
LONG );
	set("exits", ([
		"north"     : __DIR__"tianhuo",
		"westdown"  : __DIR__"tianchi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6200);
	set("coor/y", 5170);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}