// /kaifeng/majiu.c
// Last modified by winder 2003.10.20

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "馬廄");
	set("long", @LONG
這是稻香居後的馬廄，常年供應新鮮草料。開封府自古乃軍事重地，
歷史悠久，民風淳樸。馬伕們會把馬牽到馬廄好生照看，將它們餵飽飲
足，再洗刷得幹乾淨淨，一直伺候到客人上路。馬廄雨檐下的爛木柱上
釘着一塊破木牌 (paizi)。馬廄中堆放著幾堆草料，正中有一口泔槽。
LONG);
	set("outdoors", "kaifeng");
	set("no_fight", "1");
	set("no_beg", "1");
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
	]));
	set("exits",([
		"west" : __DIR__"daoxiang1",
		"up"   : SHOP_DIR"kaifeng_shop",
	]));
	set("item_desc", ([
		"paizi": @TEXT
客人們只要給馬伕一兩白銀的租金就可以僱到一匹馬了。

前往      揚州城:  rideyz
TEXT]));
	setup();
	replace_program(ROOM);
}
