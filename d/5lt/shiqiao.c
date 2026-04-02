// Room: /d/5lt/shiqiao.c

inherit ROOM;

void create()
{
	set("short", "石橋");
	set("long", @LONG
只是一座小石橋，雖然不大，卻非常精美。橋欄上雕刻了許多花草
動物，栩栩如生。
LONG
	);
	set("exits", ([
		"north"   : __DIR__"nroad2",
		"south"   : __DIR__"nroad1",

	]));
	set("outdoors", "5lt");
	set("no_clean_up", 0);

	set("coor/x", -150);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
