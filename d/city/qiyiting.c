// Room: qiyiting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "棋藝廳");
	set("long", @LONG
這裏是棋藝廳，朝北的欄外是個小花園，綠草如茵，長枝委地，賭
場的繁雜聲響，在這裏都消失了。所有進出的人，也都屏息靜氣的。偶
爾有其他廳室來人心裏不爽，過來發瘋，立馬就招人架了出去。
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("outdoors", "duchang");
	set("exits", ([
		"west"       : __DIR__"weiqishi",
		"east"       : __DIR__"xiangqishi",
		"northwest"  : __DIR__"haizhanqi",
		"northeast"  : __DIR__"feixingqi",
		"south"      : __DIR__"zoulang2",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
