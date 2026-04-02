// Room: /d/nanshaolin/lwc2
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
這裏是少林寺的練武場。由無數塊巨大的花崗巖石板鋪就。上千年
的踩踏已使得這些石板如同鏡子般平整光滑。武場中央豎立着一個製作
精巧的木人，一些年青僧人正自圍着它練功。
LONG );
	set("exits", ([
		"west"  : __DIR__"lwc3",
		"south" : __DIR__"lwc1",
	]));
	set("objects",([
		__DIR__"obj/mu-ren" : 5,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1790);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

