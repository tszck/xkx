// Room: /d/lingxiao/jianyuting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "監獄小廳");
	set("long", @LONG
這裏就是凌霄城的監獄入口。凌霄城的監獄專門用來關押犯了門規
的弟子，一些城中的作奸犯科，雞鳴狗盜之徒也順便收押在此。凌霄向
來一派所成，所以門規森嚴，倒也少有犯事者，但這裏是凌霄重地，防
守自也嚴密。
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("exits", ([
		"west" : __DIR__"iceroad3",
		"down" : __DIR__"laolang",
	]));
	set("objects", ([ 
		__DIR__"npc/yan" : 1,
		__DIR__"npc/dizi" : 3,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8900);
	set("coor/z", 140);
	setup(); 
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["master_id"] != "bai zizai") &&
		dir == "down" &&
		objectp(present("yan wanpeng", environment(me))))
		return notify_fail("燕萬鵬大喝一聲：此處乃本派禁地，這位" + RANK_D->query_respect(me) + "請止步！\n");
	return ::valid_leave(me, dir);
}

