// Room: /d/tiezhang/lx.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "瀘溪");
	set("long", @LONG
這裏是湘西的一個小鎮。雖然地處偏僻，但這裏來往的行人仍然很
多。西面是一間供人休息打尖的小客店。西南方四十里處，就是此處有
名的猴爪山。
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 3 */
		"southwest" : __DIR__"road1",
		"west"      : __DIR__"kedian",
		"northeast" : "/d/henshan/hsroad6",
	]));
	set("no_clean_up", 0);

	set("coor/x", -2000);
	set("coor/y", -2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}