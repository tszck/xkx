// Room: /d/huashan/jzroad4.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short", "中條山森林");
	set("long", @LONG
你走在中條山路上。路徑狹小，周圍茂密森林裏，傳來陣陣野獸夜
禽的嘶鳴，聽來讓人毛骨悚然。
LONG );
	set("exits", ([
		"southup"  : __DIR__"jzroad5",
		"westdown" : __DIR__"jzroad3",
	]));
	set("outdoors", "zhongtiao");
	set("no_clean_up", 0);
	set("coor/x", -920);
	set("coor/y", 210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
