//  Room:  /d/changan/road6.c

inherit  ROOM;

void  create  ()
{
	set("short",  "大官道");
	set("long",  @LONG
這是一條青石鋪就的寬闊筆直的官道，道旁種滿了路樹，足可容得
下十馬並馳。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"     :  __DIR__"northgate",
	]));
	set("outdoors", "guanzhong");
	set("no_clean_up", 0);
	set("coor/x", -5040);
	set("coor/y", 1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
