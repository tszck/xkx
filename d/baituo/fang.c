// Room: /d/baituo/fang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","練功房");
	set("long", @LONG
這裏是白駝山弟子的練功房。裏面有幾個單間，是練功室。弟子們
在裏邊砌磋武藝，絕對不允許外人打攪。
LONG	);
	set("exits",([
		"west" : __DIR__"liangong",
		"1" : __DIR__"room1",
		"2" : __DIR__"room2",
		"3" : __DIR__"room3",
	]));
	set("objects",([
		__DIR__"npc/trainer" : 1,
	]));
	set("coor/x", -50000);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
}
int valid_leave(object who ,string dir)
{
	if((string)who->query("family/family_name")!="白駝山派" &&
		(dir!="west"))
		return notify_fail("那裏禁止外人進入！\n");
	return 1 ;
}
