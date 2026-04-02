// Room: /city/chanzhidadian.c

inherit ROOM;

void create()
{
	set("short", "禪智寺大殿");
	set("long", @LONG
正中修的是如來佛祖的金身塑像，兩邊列了十八羅漢。廟雖然不算
是大，但菩薩供得如此之全，倒也是少見，可以看出揚州一帶的富裕程
度了。殿上香火繚繞，誦經之聲不絕於耳。
LONG );
	set("exits", ([
		"east"   : __DIR__"chanzhixf",
		"south"  : __DIR__"chanzhisi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", -8);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}