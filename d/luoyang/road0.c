//  Room:  /d/luoyang/road0.c

inherit  ROOM;

void  create  ()
{
	set("short",  "大官道");
	set("long",  @LONG
這是一條寬闊筆直的官道，足可容得下十馬並馳。往東通向脂粉之
都的揚州，而西面則是號稱“扼九州”的虎牢關了。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east" : __DIR__"road11",
		"west" : __DIR__"hulaoguan",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -170);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
