//Room: majiu1.c 馬廄
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","馬廄");
	set("long",@LONG
這是客店後的馬廄，常年供應新鮮草料。北京自古天子腳下，啥都有
規矩，客店也特會伺候人，馬伕們會把馬牽到馬廄好生照看，將它們餵飽
飲足，再洗刷得幹乾淨淨，一直伺候到客人上路。馬廄雨檐下的爛木柱上
釘着一塊破木牌(paizi)。
    馬廄中堆放著幾堆草料，正中有一口泔槽。
LONG);
	set("outdoors", "beijing");
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

前往      揚  州  城:  rideyz
          赫圖阿拉城:  rideht


TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"west" : __DIR__"kedian",
		"up"   : SHOP_DIR"beijing_shop",
	]));
	set("coor/x", -180);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
