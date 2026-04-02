// Room: /d/shaolin/xiaojing2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "田埂邊");
	set("long", @LONG
轉過山坡只見幾棵果實累累的大棗樹孤零零地栽在田埂邊，上
面掛滿了紅熟的棗子，使人忍不住想摘下幾顆嚐嚐。田裏種着半熟
的青稞麥。西首有三間簡陋的土屋。
LONG );
	set("exits", ([
		"southdown" : __DIR__"xiaojing1",
		"west" : __DIR__"houshan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	set("coor/x", -20);
	set("coor/y", 710);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}