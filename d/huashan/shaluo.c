// shaluo.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "莎蘿坪");
	set("long", @LONG
沿着玉泉，踏過累累石澗，由山徑迤邐而上，就來到了莎蘿坪。從這
裏山路開始陡峭，南面一條迂迴盤旋的山道，稱作「十八盤」，通往山上。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"northwest" : __DIR__"path1",
		"northeast" : __DIR__"shanhongpb",
		"southup" : __DIR__"yunmen",
	]));
	set("objects", ([
		__DIR__"npc/haoke": 2,
		"/clone/misc/dache" : 1,
	]));
	set("outdoors", "huashan" );
	set("coor/x", -910);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
}
 
void init()
{
	object me = this_player();
	if (me->query_temp("xunshan")) me->set_temp("xunshan/shaluo", 1);
	return;
}
