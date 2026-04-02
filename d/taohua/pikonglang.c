// Room: /d/taohua/pikonglang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "劈空欄");
	set("long", @LONG
這是一個裏面廊窗的小閣。透過窗縫，可以看到南面的試劍峯。東
面望去，是白浪滔滔的大海，海面上白鷗自由飛來飛去，真是“天高任
鳥飛”啊。欄的一端擺着一張長桌，桌上放着一列燭臺，點着一排的蠟
燭(lazhu)。
LONG
	);
        set("item_desc", ([ 
		"lazhu" : "蠟燭在海風中搖曳着一點昏黃的光，好象舉手一拍(pai)就會滅的樣子。\n",
	]));
        set("exits", ([ 
		"north" : __DIR__"zoulang4",
	]));
	set("outdoors","taohua");
	set("no_clean_up", 0);
	set("coor/x", 9020);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_pai", "pai");
}
int do_pai(string arg)
{       
        mapping fam;
	object me = this_player();

	if (arg != "lazhu")
		return notify_fail("你拍什麼拍？拍蚊子啊？\n");
	if (!living(me)) return 0;
	if (!(fam = me->query("family")) || fam["family_name"] != "桃花島")
		return notify_fail("你非本島弟子，不能在此練功！\n");

	if ( (int)me->query_skill("strike", 1) > 100)
		return notify_fail("你揮掌向着燭臺虛劈，嗤的一聲，燭火應手而滅。\n");
	if((int)me->query("qi")<30)
	{
		me->receive_damage("qi",10);
		write("揮掌向着燭臺虛劈，結果燭火連晃都沒晃一晃！\n");
		return 1;
	}
	me->receive_damage("qi", random(40));
	me->improve_skill("strike", me->query("int"));
	write( "揮掌向着燭臺虛劈，嗤的一聲，燭火搖搖晃晃居然沒滅！\n");
	return 1;
}