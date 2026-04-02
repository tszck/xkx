// /kaifeng/zhuque.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "朱雀門");
	set("long", @LONG
這是內城的城門，高大的城牆用大青磚彌合米汁而成，時間的沖刷
使得牆磚變為鐵青色。東西兩邊是角樓，南面不遠處就是大相國寺的八
寶琉璃殿。
LONG);
	set("exits", ([
		"south" : __DIR__"road1",
		"north" : __DIR__"road2",
		"westup" : __DIR__"jiaolou1",
		"eastup" : __DIR__"jiaolou2",
	]));
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
