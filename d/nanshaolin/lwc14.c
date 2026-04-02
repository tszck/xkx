// Room: /d/nanshaolin/lwc14.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
這裏是少林寺的練武場。由無數塊巨大的花崗巖石板鋪就。上千年
的踩踏已使得這些石板如同鏡子般平整光滑。武場中央豎立着一個製作
精巧的練功銅人，一些壯年僧人正狠辣的向它出招。
LONG );
	set("exits", ([
		"east" : __DIR__"lwc13",
		"south" : __DIR__"lwc16",
	]));
	set("objects",([
		__DIR__"obj/tong-ren" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1850);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

