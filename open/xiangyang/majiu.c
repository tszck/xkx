// Room: /d/xiangyang/majiu.c 馬廄
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short","馬廄");
	set("long",@LONG
這裏是襄陽城內唯一一家車馬行。你可花錢租輛馬車到各
個地方去，能節約不少體力。近來因爲郭夫人----黃蓉正在組
織人力四處蒐集防城材料，馬伕積極響應，免費提供推車來運
送各種防城材料。
    西邊馬廄雨檐下的爛木柱上釘着一塊破木牌(paizi)。
LONG);
	set("outdoors", "xiangyang");
	set("no_fight", "1");
	set("no_beg", "1");
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
客人們只要給馬伕一兩白銀的租金就可以僱到一匹馬了。

前往      揚州城:  rideyz


TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"northroad2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
