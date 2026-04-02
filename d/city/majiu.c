//Room: /d/yangzhou/majiu1.c 馬廄
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","馬廄");
	set("long",@LONG
這是客寓後的馬廄，常年供應新鮮草料。揚州民風淳樸，馬伕們會
把馬牽到馬廄好生照看，將它們餵飽飲足，再洗刷得幹乾淨淨，一直伺
候到客人上路。馬廄雨檐下的爛木柱上釘着一塊破木牌(paizi)。
    馬廄中堆放著幾堆草料，正中有一口泔槽。
LONG);
	set("outdoors", "yangzhouw");
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/zaohongma": 1,
		__DIR__"npc/huangbiaoma": 1,
		__DIR__"npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
客人們只要給馬伕一兩白銀的租金就可以僱到一匹馬了。

前往      北京城:  ridebj
          蘇州城:  ridesz
          杭州城:  ridehz
          福州城:  ridefz
          無錫城:  ridewx
          成都城:  ridecd
          長安城:  rideca
          襄陽城:  ridexy
          開封城:  ridekf
          延平城:  rideyp
          永登城:  rideyd
          武昌鎮:  ridewc
          佛山鎮:  ridefs
          峨嵋山:  rideem

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"west" : __DIR__"kedian",
		"up"   : SHOP_DIR"yangzhou_shop",
	]));
	set("coor/x", 21);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
