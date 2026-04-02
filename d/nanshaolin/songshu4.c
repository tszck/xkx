// Room: /d/nanshaolin/songshu4
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "松樹林");
	set("long", @LONG
這是一片松樹林。高高的大松樹簇在一塊，密實的枝葉象一蓬蓬巨
傘般伸向天空，把陽光遮得絲毫也無。一條潔淨的青石小徑蜿蜒林中。
東面的院落就是戒律院。院外站着兩名僧人嚴密的守護着。
LONG
	);
	set("outdoor","nanshaolin");
	set("exits", ([
		"west" : __DIR__ "songshu3",
		"east" : __DIR__ "jieluyuan",
	]));
	set("objects",([
		__DIR__"npc/zjseng" : 1,
		__DIR__"npc/slseng" : 1
		
	]));
	set("coor/x", 1830);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping fam;
	if (dir == "east")
	{
		if( mapp(fam = me->query("family")) &&
			fam["family_name"] == "南少林派" &&
			fam["generation"] <= 20 )
			return ::valid_leave(me, dir);
		if( me->query("guilty") == 0 || !userp(me) &&
			me->query("id") != "seng bing" )
		{
			return notify_fail("只聽院內傳來一個渾厚的聲音說道：你未經許可，不能進入戒律院。\n");
		}
	}
	return ::valid_leave(me, dir);
}

