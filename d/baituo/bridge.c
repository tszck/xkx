// Room: /d/baituo/bridge.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "小橋");
	set("long", @LONG
這是一座小竹橋，『白駝山』上的冰雪融化形成一條清澈的小溪，
從橋下緩緩流過。不時有頑皮的小魚躍出水面，在陽光下劃出一條銀白
色的弧線。
LONG	);
	set("outdoors", "baituo");
//	set("no_clean_up", 0);
	set("exits", ([
		"northwest" : __DIR__"guangchang",
		"east"      : __DIR__"xijie",
	]));
	set("objects",([
		__DIR__"npc/cungu" : 1,
	]));
	set("coor/x", -50000);
	set("coor/y", 19980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
