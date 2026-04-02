// Room: /city/biaojuxf1.c

inherit ROOM;

void create()
{
	set("short", "西廂房");
	set("long", @LONG
房間裏佈置很簡單，只有一張小牀，一個小几，和幾張方凳。窗臺
上放着一個磁杯，杯裏插着幾枝無名小花。房間雖不大，但是給人整潔
舒適的感覺。
LONG
        );
	set("exits", ([
		"east" : __DIR__"biaojuhy",
	]));
	set("objects", ([
		__DIR__"npc/fu" : 1,
	]));
	set("coor/x", 1829);
	set("coor/y", -6296);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
