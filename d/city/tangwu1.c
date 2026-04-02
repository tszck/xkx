// Room: /yangzhou/tangwu1.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "堂屋");
	set("long", @LONG
屋之南北飾一雕花窗欄隔扇，東西兩山牆闢有大塊窗格，四面空明。
正中壁上筆懸一幅鉅製梅樁中堂，筆力遒勁，墨氣飛動，左右掛一楹聯
(lian)。倚牆設一套紅木條幾，上陳古瓶，盆景。幾前一海梅雕花方桌，
桌旁一對海梅雕花太師椅。設竹榻，榻旁一架古書，縹湘零亂。
LONG );

	set("item_desc", ([
		"lian" : @LONG
                  ┌--┐          ┌--┐
                  │倚│          │登│
                  │欄│          │樓│
                  │潛│          │清│
                  │窺│          │聽│
                  │鳥│          │市│
                  │夢│          │聲│
                  │閒│          │遠│
                  └--┘          └--┘
LONG,
	]));
	set("exits", ([
		"south" : __DIR__"rongxiyuan",
	]));
	set("objects", ([
		__DIR__"npc/qiuhaoshi" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", -39);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
