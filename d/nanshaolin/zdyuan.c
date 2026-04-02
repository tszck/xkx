// Room: /d/nanshaolin/zdyuan.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", BLU"證道院"NOR);
	set("long", @LONG
穿過西側廊，前面出現一片寬闊的院落。院門的匾額上寫着“證道
院”三個大字，這裏乃是僧人們日常唸經誦佛，參禪打坐的地方。院中
種滿了翠竹，顯得極是幽靜。從周圍的禪房中不斷傳出陣陣的梵唱和木
魚敲擊的聲音。
LONG );
	set("exits", ([
		"west" : __DIR__"chanfang-1",
		"east" : __DIR__"celang-2",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/dapi" : 1,
		__DIR__"npc/xiao-ku" : 1
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1800);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "南少林派") && dir == "west" &&
		objectp(present("dapi dashi", environment(me))))
		return notify_fail("大疲大師喝道：證道院乃本寺弟子禪修之處，你非本寺弟子，不能入內。\n");
	return ::valid_leave(me, dir);
}


