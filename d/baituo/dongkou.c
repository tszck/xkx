// Room: /d/baituo/dongkou.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long", @LONG
山賊的老窩的洞口藏在藤蔓之下，看起來有點陰森。洞口有一條石
砌就的門面，鋪上木板，勉強算個門。往常時光，都有兩個賊夥持刀護
衛，守備森嚴。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"north" : __DIR__"dongnei",
		"south" : __DIR__"xiaolu4",
	]));
	set("objects",([
		__DIR__"npc/shanzei2" : 2,
	]));
	set("coor/x", -49960);
	set("coor/y", 20030);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
