//  Room:  /d/5lt/zhulin.c

inherit  ROOM;

void  create  ()
{
	set("short",  "竹林");
	set("long",  @LONG
一片綠茸般的竹林把燥熱擋在視野之外，這裏是一片清涼世界。
LONG);
	set("exits",  ([  /*  sizeof()  ==  1  */
		"southwest"  :  __DIR__"eroad2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -125);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}