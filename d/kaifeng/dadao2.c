// /kaifeng/dadao2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
一條斜斜的小路，向西去不遠有片樹林，看上去黑呼呼的自從不久
前樹林中出了野豬傷人後，這條道就少人走。只有貪圖路近的人還走這
條道。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"yezhulin",
		"northeast" : __DIR__"dadao1",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
