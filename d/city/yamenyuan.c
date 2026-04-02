// Room: /city/yamenyuan.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "衙門大院");
	set("long", @LONG
一個不大的院子，幾個衙役面無表情的站着。北向升階而上為一朱
紅大門，上面有一匾額「揚州」，大門半掩着，依稀可以看到幾個人影。
東面是簽押房，朝西，是一月洞門，門額上刻着隸書「郡圃」。
LONG );
	set("exits", ([
		"south"   : __DIR__"yamen",
		"northup" : __DIR__"zhengtang",
		"east"    : __DIR__"qianyafang",
		"west"    : __DIR__"tianjing",
	]));
	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", -20);
	set("coor/y", 1);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if(!wizardp(me) && !me->query("officerlvl") && objectp(present("ya yi",environment(me)))&&dir=="north")
		return notify_fail("衙役喝道：“威……武……。”\n");
	return ::valid_leave(me, dir);
}