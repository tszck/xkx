// Room: /d/luoyang/tongtuo.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create()
{
	set("short",  "銅駝暮雨");
	set("long",  @LONG
“銅駝暮雨”是洛陽八大景的最後一景。城東關外的中通巷，隋、
唐、宋時叫“銅駝陌”，它位於隋唐城的城東北隅。每當暮色茫茫，家
家炊煙裊裊上升，猶如濛濛煙雨，紛紛揚揚，這就是人們讚不絕口的“
銅駝暮雨”的由來。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"  : __DIR__"xiaoxiang",
		"north" : __DIR__"jingu",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -370);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
