//room: /d/mingjiao/westdian.c
inherit ROOM;

void init();

void create()
{
	set("short","明教西側殿");
	set("long", @LONG
這裏是西側殿，是接待來賓的地方。殿內擺着幾張桌子，桌旁圍放
數把椅子。牆上懸着幾張硬弓，甚是雄壯，旁邊堆着一堆羽箭。窗外是
茫茫崑崙雪山，雪峯延綿。
LONG);
	set("exits",([
		"east"     : __DIR__"qiandian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52040);
	set("coor/y", 1060);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}