//room: restroom.c
//restroom
inherit ROOM;

void create()
{
	set("short","憩鳳閣");
	set("long",@LONG
這裏是靈鷲宮弟子睡覺的地方，一進門就聞到一陣悠悠的香氣，只
見房中點了一支大紅燭,照的滿室生春,牀上珠羅紗的帳子，白色緞被上
繡着一隻黃色的鳳凰，壁上掛着一幅工筆仕女圖。西首一張几上供着一
盆蘭花，架子上停着一隻白鸚鵡。
LONG );
	set("exits",([
		"west" : __DIR__"changl3",
	]));
	set("sleep_room", 1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_clean_up", 0);
	set("coor/x", -50970);
	set("coor/y", 30150);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}