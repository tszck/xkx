inherit ROOM;

void create()
{
	set("short", "西廠大門");
	set("long", @LONG
這裏就是西廠大門，可以看到裏面有許多太監。穿着制服的官兵正
在操練，不時地傳來吶喊聲。如果你不想找死的話，最好還是趕快離開
吧。
LONG );
	set("exits", ([
		"south" : __DIR__"bingyin2",
		"north" : __DIR__"di_an4",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -210);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("官兵攔住了你的去路。\n");
	return ::valid_leave(me, dir);
}
