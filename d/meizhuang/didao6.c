// /d/meizhuang/didao6.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "梅莊密道");
	set("long", @LONG
這是一條昏暗潮濕的地道，地道很長，兩邊點着兩根不太明亮的火
把，地道兩旁的牆壁上畫着很多不知道出自何人之手的壁畫，而且畫得
相當難看，你加快腳步，想知道地道的盡頭是什麼地方。 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"didao6",
		"south" : __DIR__"didao7",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3490);
	set("coor/y", -1470);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
