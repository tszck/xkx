// wg_woshi.c

inherit ROOM;

void create()
{
	set("short","臥室");
	set("long", @LONG
這裏是武館館主的臥室，房子並不大，很整潔簡樸，被子疊的整整
齊齊，帳子掛了起來，靠窗邊擺了一盆盆景，一張小桌，放着幾本書。
LONG);
	set("exits", ([
		"west" : __DIR__"wg_lang5",
	]));
	set("objects", ([
		__DIR__"npc/wg_furen" : 1,
	]));
	set("coor/x", 41);
	set("coor/y", -40);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
