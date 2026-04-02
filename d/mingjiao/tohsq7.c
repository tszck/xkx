//TOHSQ7.C

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
這裏是瀑布上方一道窄窄的山樑，渾然天成。石樑上面人工鑿出一
格格階梯。邊上釘了幾棵木樁，繞上粗長的麻繩作為扶手。瀑布在腳下
奔騰而過，山腳下匯成一個深潭。
LONG );
	set("exits", ([
		"north" : __DIR__"hsqmen",
		"south" : __DIR__"tohsq6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52020);
	set("coor/y", 920);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}