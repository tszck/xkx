inherit ROOM;

void create()
{
	set("name", "全聚德酒樓");
	set("short", "全聚德酒樓二樓");
	set("long", @LONG
這裏是雅座，文人學士經常在這裏吟詩作畫，富商土豪也在這裏
邊喫喝邊作交易。這裏也是城裏舉辦喜宴的最佳場所。牆上掛着價格
牌子(paizi)。你站在樓上眺望京城，只覺得心曠神怡。
LONG );
	set("item_desc", ([
		"paizi" : "本店出售烤鴨及上等花雕酒。\n",
	]));
	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));
	set("objects", ([
		__DIR__"npc/cheng":1,
	]));
	set("coor/x", -190);
	set("coor/y", 4060);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
