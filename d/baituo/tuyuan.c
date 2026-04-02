// Room: /d/baituo/tuyuan.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","兔苑");
	set("long", @LONG
這是個好玩的兔苑，幾隻大白兔靜靜地蹲在綠草地上喫草。西南方
是竹園。西面傳來陣陣猛獸的嚎叫，東面有一個蛇園。
LONG );
	set("exits",([
		"east"  : __DIR__"sheyuan",
		"west"  : __DIR__"shoushe",
		"southwest" : __DIR__"zhuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		__DIR__"npc/baitu" : 2,
	]));
	set("coor/x", -50000);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	me = this_player();
	myfam = (mapping)me->query("family");
	if((!myfam || (myfam["family_name"] != "白駝山派")) && (dir == "west"))
		return notify_fail("你不是白駝山弟子，不能進獸舍。\n");
	if((!myfam || (myfam["family_name"] != "白駝山派")) && (dir == "east"))
		return notify_fail("你不是白駝山弟子，不能進蛇園。\n");
	else return 1;
}
