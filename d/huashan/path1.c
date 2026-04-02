// path1.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "華山腳下");
	set("long", @LONG
西嶽華山，巍然聳立於陝西省華陰縣城南。它北瞰黃河，南連秦嶺，
五座山峯高低錯落，各據一方，其間又有一段若斷若續的山嶺相連，疏
密有度，神韻天成，遠遠望去，狀若巨朵青蓮，外圍諸峯如蓮瓣，中間
三峯似蓮蕊，因此山便因“花”得名，取名華山。又因其西臨少華山，
故華山又稱太華。它素有「奇峯天下第一山」之稱，西面是小村。北是
玉泉院。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"west"      : "/d/village/eexit",
		"north"     : __DIR__"yuquan",
		"south"     : __DIR__"caishi",
		"southeast" : __DIR__"shaluo",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -920);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
 
