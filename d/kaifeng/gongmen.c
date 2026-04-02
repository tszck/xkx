// /kaifeng/gongmen.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "石拱門");
	set("long", @LONG
用石頭搭起來的一個拱門，高越兩丈，上面鏤刻雲紋。兩邊是拴馬
的石柱。再往前邊一點的地方，有塊旗杆石，那是由兩塊巨大的石頭，
一半埋到地下，在和口的地方，有個大孔可以插旗杆。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"southup" : __DIR__"8bao",
		"northdown" : __DIR__"road1",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
