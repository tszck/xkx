//Room: majiu2.c 馬廄
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","馬廄");
	set("long",@LONG
這是草棚邊的馬廄，常年供應新鮮草料。據說此地民風淳樸，馬伕們會把
馬牽到馬廄好生照看，將它們餵飽飲足，再洗刷得幹乾淨淨，一直伺候到客人
上路。馬廄中堆放著幾堆草料，正中有一口泔槽。
	馬廄雨檐下的爛木柱上釘着一塊破木牌(paizi)。
LONG);
	set("outdoors", "emei");
	set("no_fight", "1");
	set("no_beg", "1");
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/d/city/npc/camel": 1,
		"/clone/misc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
客人們只要給馬伕一兩白銀的租金就可以僱到一匹馬了。

前往	峨嵋山腳: rideem

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"huayanding",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6180);
	set("coor/y", -1070);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
