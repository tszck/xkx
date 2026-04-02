//Room: /d/dali/majiu.c
//Date: June. 29 1998 by Java

inherit ROOM;

void create()
{
	set("short","馬廄");
	set("long",@LONG
這是軍營邊上的馬廄，常年供應新鮮草料。據說此地民風淳樸，
客人只要帶馬來，馬伕們就會把馬牽到馬廄好生照看，將它們餵飽飲
足，再洗刷得幹乾淨淨。一直伺候到客人離城上路。馬廄雨檐下的爛
木柱上釘着一塊破木牌(paizi)。
    馬廄中堆放著幾堆草料，正中有一口泔槽。
LONG);
	set("outdoors", "dali");
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_clean_up", 0);
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
客人們只要給馬伕一兩白銀的租金就可以僱到一匹馬了。

前往      成都城:  ridecd

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"bingying",
		"up"   : SHOP_DIR"dali_shop",
	]));
	set("coor/x", -41010);
	set("coor/y", -71040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
