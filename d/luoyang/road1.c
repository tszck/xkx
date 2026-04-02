//  Room:  /d/luoyang/road1.c

inherit  ROOM;

void  create  ()
{
	set("short",  "大官道");
	set("long",  @LONG
這是一條寬闊筆直的官道，足可容得下十馬並馳。東邊遠遠可以看到
揚州的城垣了，西面則是通往中原的大道。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east" : "/d/city/ximen",
		"west" : __DIR__"road8",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -120);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
