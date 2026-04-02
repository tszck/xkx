// Room: /city/yamen.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "衙門大門");
	set("long", @LONG
這裏是衙門大門，兩扇朱木大門緊緊關閉着。“肅靜”“迴避”的
牌子分放兩頭石獅子的旁邊。門前側面架子擺着個皮鼓，掛着一對木棰。
顯然是供小民鳴冤用的。幾名衙役在門前巡邏。
LONG );
	set("exits", ([
		"south" : __DIR__"tongsijie",
		"north" : __DIR__"yamenyuan",
	]));
	set("objects", ([
		__DIR__"npc/yayi" : 2,
//		__DIR__"npc/xunbu" : 1,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", -20);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if(!wizardp(me) && !me->query("officerlvl") && objectp(present("ya yi",environment(me)))&&dir=="north")
		return notify_fail("衙役喝道：“威……武……。”\n");
	return ::valid_leave(me, dir);
}