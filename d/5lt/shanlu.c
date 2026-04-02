// Room: /d/5lt/shanlu.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
這是一條上山的小路。小路兩邊雜草叢生，看來少有行人。不過路
泥卻甚是平滑，倒像常有人來往一般。前面是個鐵絲網，過了鐵絲網就
是五老峯了，你不由加快了腳步。
LONG );
	set("exits", ([
		"eastup"   : __DIR__"5laofeng",
		"westdown" : __DIR__"caodi",
	]));
        set("objects", ([
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -115);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}