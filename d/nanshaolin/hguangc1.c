// Room: /d/nanshaolin/hguangc1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "後殿廣場");
	set("long", @LONG
這裏是後殿廣場，由大青石板拼成的地面上有幾處凹凸的踏痕，似
是以前有高手施展內功所遺留的印記。幾位執役僧正認真的進行清掃。
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"east"      : __DIR__ "hguangc2",
		"north"     : __DIR__ "hguangc4",
		"southwest" : __DIR__ "huaishu5",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
}

int init()
{
	add_action("do_ta","ta");
	add_action("do_ta","cai");
}

int do_ta(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("leg", 1), exp = me->query("combat_exp");
	if ( !living(me) || arg != "sign" ) return 0;
	if ((int)me->query_skill("leg", 1) > 31)
		return notify_fail("再踏腳印已經無法再提高你的基本腿法了！\n");
	if ( (int)me->query("jing")<30)
	{
		me->receive_damage("jing", 10);
		write("你太累了，已經沒有力氣來踩踏腳印了！\n");
		return 1;
	}
	if (lvl * lvl * lvl / 10 < exp)
	{
		me->receive_damage("jing", random(35));
		message_vision("$N正在踩踏地面上的腳印。\n", me);
		write("你覺得踩踏腳印對你的基本腿法有所促進。\n");
		me->improve_skill("leg", me->query("int"));
	}
	return 1;
}

