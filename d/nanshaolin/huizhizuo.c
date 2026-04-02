// Room: /d/nanshaolin/huizhizuo.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIG"晦智聖座"NOR);
	set("long", @LONG
晦智禪師聖座內修真之處原是一間石洞，入得洞來只見青石鋪地竟
是頗爲寬敞，幾處鍾乳珠纓金絡，晶壁玉障。不但合洞通明亮入白晝；
玉牀碧幾，不染纖塵。而且石室修整，門戶井然，到處光華燦爛，目迷
五色。想是禪師有意於世俗富貴眩目之氣內修真，更增禪心。四壁各雕
了一座千手如來佛像姿態各不相同，栩栩如生，凝望之下令人忘俗。
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_ningwang",({"gaze","ningwang"}));
}
int do_ningwang(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("hand", 1), exp = me->query("combat_exp");
	if (arg!="foxiang") return notify_fail("你要凝望什麼？\n");
	if (!living(me)) return 0;
	if (!random(5))
	message("vision", me->name()+"正在對着牆壁凝神觀看佛像的手法。\n", environment(me), ({me}) );
	if (lvl < 30)
	{
		write("你凝望佛像，但覺千手繁複，實無半點脈絡可尋。\n");
		return 1;
	}
        if (lvl * lvl * lvl / 10 < exp)
        {
                write(HIR"你凝望佛像，心中似有所悟，但畢竟經驗尚淺，什麼也沒領悟到。\n"NOR);
                return 1;
        }
	if (lvl > 100)
	{
		write("佛像姿勢雖繁但你已盡數領悟於心。\n");
		return 1;
	}
        me->receive_damage("jing", 30);
        me->improve_skill("hand", (me->query("int"))*3/2);
        write("你望着佛像千奇百怪之手法，心中對基本手法有所領悟。\n");
	return 1;
}
