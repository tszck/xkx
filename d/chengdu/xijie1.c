// Room: /d/chengdu/xijie1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
這裏是成都的西大街，熙熙攘攘，熱鬧非凡，兩邊是鱗立櫛比的店
鋪，五顏六色的幌子滿街飄蕩煞是鮮豔。附近的百姓一般逢十就入城來
趕集，許多商賈也不失時機的推出各種平時買不到的東西。南邊是家藥
鋪，北面則是個占卜的鋪子。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"xijie2",
		"west"  : __DIR__"xijie",
		"north" : __DIR__"zhanbu",
		"south" : __DIR__"yaopu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8070);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

