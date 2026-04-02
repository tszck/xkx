// Room: /d/nanshaolin/lwc13.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
這裏是少林寺的練武場。由無數塊巨大的花崗巖石板鋪就。上千年
的踩踏已使得這些石板如同鏡子般平整光滑。十來個僧人正在練習武技。
武場的一角有一組練功用的梅花樁(zhuang)。東南西三面各有一練武場。
LONG );
	set("exits", ([
		"east" : __DIR__"lwc12",
		"south" : __DIR__"lwc15",
		"west" : __DIR__"lwc14",
		]));
	set("objects",([
		__DIR__"obj/zhuang" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("item_desc", ([
		"zhuang":"這是一組青竹製成的木樁，高一丈兩寸，狀成梅花排列。\n",
	]));
	set("coor/x", 1860);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
