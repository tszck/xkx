// Room: /d/chengdu/xijie.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
這條街滿街的招牌幌子，隨風飄揚，兩邊是鱗立櫛比的店鋪，還有
一些小攤小販在路邊做生意，偶爾有官兵列隊經過。北邊一條小巷，進
進出出都是些衣冠楚楚的讀書人，南邊有個當鋪。再向西則是出城的路。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"xijie1",
		"west"  : __DIR__"westgate",
		"north" : __DIR__"xiaoxiang",
		"south" : __DIR__"dangpu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

