// Room: /yangzhou/ninghaiqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","寧海橋");
	set("long",@LONG
寧海橋是一座新建的聯拱石橋，座落在小秦淮河上，是連接揚州新
舊兩城的要道，因此修的極為寬闊平整，可供四輛馬車同時並行。橋名
由歐陽修親筆題寫，懸在橋的兩側。橋的東南邊有一個碼頭，許多船隻
停靠着。西邊是揚州舊城的甘泉街。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"ganquanjie",
		"east"  : __DIR__"matou",
	]));
	set("objects", ([
		SHOP_DIR"hesanqi" : 1,
		"/d/village/npc/kid" : random(5),
	]));
	set("coor/x", 30);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
