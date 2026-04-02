//htqdating.c
inherit ROOM;

void create()
{
	set("short", "厚土旗大廳");
	set("long", @LONG
這裏是厚土旗的大廳，廳中刀槍如林，黃旗招展，教衆穿着鐵甲鋼
盔，腰間別着鍬鏟錘鑽，一個個精神抖擻。正中端坐着個矮墩漢子，就
是厚土旗掌旗使顏垣。
LONG);
	set("exits", ([
		"out" : __DIR__"htqmen",
	]));
	set("objects", ([
		__DIR__"npc/yanyuan": 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 930);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}