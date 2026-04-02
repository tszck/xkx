// Room: /d/nanshaolin/lwc15
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
這裏是少林寺的中心練武場。由無數塊巨大的花崗巖石板鋪就。上
千年的踩踏已使得這些石板如同鏡子般平整光滑。武場中央豎立着一個
金光閃閃的金人，幾位老僧神色莊嚴，腳踏八卦方位圍繞，緩緩發招。
LONG );
	set("exits", ([
		"east"  : __DIR__"lwc11",
		"west"  : __DIR__"lwc16",
		"north" : __DIR__"lwc13",
		"south" : __DIR__"lwc18",
	]));
	set("objects",([
		__DIR__"obj/jin-ren" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1860);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

